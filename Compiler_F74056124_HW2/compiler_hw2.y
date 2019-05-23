/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern int yylex();
void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
int scope = 0;
int symbol_num = 0;
int err_flag = 0;	// 0: No error;  1: syntatic error;  2: semantic error
char err_type[20];
char err_symbol[256];
char params[256];
int dump = 0;
int add_scope = 0;
int param_index[30];
int param_num = 0;
int lcb_count = 0;
int if_count = 0;


/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char *name, int scope_level, int symbol_num);
void create_symbol(int entry_num);
void insert_symbol(int index, char *name, char *entry_type, char *data_type, int scope_level, char *param, int forward);
void dump_symbol();

void semantic_error();
void set_err(int flag, char *type, char *symbol);

struct symbol
{
	int index;
	char name[256];
	char entry_type[10];
	char data_type[7];
	int scope_level;
	char param[256];
	int forward;
}**table;

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char string[256];
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA QUOTA
%token TRUE FALSE
%token COMMENTLINE
%token NEWLINE
%token RET CONT BREAK

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STR_CONST
%token <string> ID
%token <string> INT FLOAT BOOL STRING VOID 

/* Nonterminal with return, which need to sepcify type */
%type <string> type

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration
	| expression_stat
	| compound_stat 
	| jump_stat
    | print_func
	| COMMENTLINE
	| NEWLINE
		{ 
			if(strlen(buf) < 1)
				printf("%d:\n",yylineno);
			else
				printf("%d: %s\n", yylineno, buf); 
			if(err_flag == 2)
			{	
				semantic_error();
			}
			if(dump == 1)
			{
				dump_symbol(symbol_num,scope);
				if(add_scope==0)
					scope--;
				dump = 0;
				add_scope = 0;
			}
			memset(buf, 0, sizeof(buf));
		}

;

declaration
    : type ID ASGN initializer
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				insert_symbol(symbol_num, $2, "variable", $1, scope, NULL,0);
				symbol_num++;
			}
			else 
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
    | type ID
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				insert_symbol(symbol_num, $2, "variable", $1, scope, NULL,0);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
	| type ID LB parameter_list RB
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",$2);
			}

			int i;
			for(i=0; i<param_num; i++)
			{
				memset(table[param_index[i]], 0, sizeof(struct symbol));
				table[param_index[i]]->scope_level = -1;
			}
			symbol_num -= param_num;
			param_num = 0;
		
			if(lookup_result != -2 && lookup_result < 0)
			{
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp,1);
				symbol_num++;
			}
			memset(params,0,sizeof(params));
		}
	| type ID LB RB
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",$2);
			}
			else
			{
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL,1);
				symbol_num++;
			}
		}

;

expression_stat
	: SEMICOLON
	| expr SEMICOLON
;

expr
	: assignment_expr
	| expr COMMA assignment_expr
;

assignment_expr
	: conditional_expr
	| unary_expr assignment_operator assignment_expr
;

assignment_operator
	: ASGN
	| MULASGN
	| DIVASGN
	| MODASGN
	| ADDASGN
	| SUBASGN
;

conditional_expr
	: logical_or_expr
;

logical_or_expr
	: logical_and_expr
	| logical_or_expr OR logical_and_expr
;

logical_and_expr
	: relational_expr
	| logical_and_expr AND relational_expr
;

relational_expr
	: additive_expr
	| relational_expr EQ additive_expr
	| relational_expr NE additive_expr
	| relational_expr LT additive_expr
	| relational_expr MT additive_expr
	| relational_expr LTE additive_expr
	| relational_expr MTE additive_expr
;

additive_expr
	: multiplicative_expr
	| additive_expr ADD multiplicative_expr
	| additive_expr SUB multiplicative_expr
;

multiplicative_expr
	: cast_expr
	| multiplicative_expr MUL cast_expr
	| multiplicative_expr DIV cast_expr
	| multiplicative_expr MOD cast_expr
;

cast_expr
	: unary_expr
	| LB type RB cast_expr
;

unary_expr
	: postfix_expr
	| unary_operator cast_expr
;

unary_operator
	: ADD
	| SUB
	| NOT
;

postfix_expr
	: primary_expr
	| ID LB RB
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{	
				set_err(2,"Undeclared function",$1);
			}

		}
	| ID LB argument_list RB
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{	
				set_err(2,"Undeclared function",$1);
			}

		}	
	| postfix_expr INC
	| postfix_expr DEC

;

primary_expr
	: val
	| LB expr RB
;

compound_stat
	: IF LB expr RB LCB
		{
			lcb_count++;
			if_count++;
			scope++;
		}
	| RCB ELSE IF LB expr RB LCB
		{
			if(if_count<1 || lcb_count<1)
			{
				yyerror("syntax error");
				exit(0);
			}
			dump = 1;
			add_scope = 1;
		}
	| RCB ELSE LCB
		{
			dump = 1;
			add_scope = 1;
			if(if_count < 1 || lcb_count<1)
			{
				yyerror("syntax error");
				exit(0);
			}
			if_count--;
		}
	| WHILE LB expr RB LCB
		{
			lcb_count++;
			scope++;
		}
	| type ID LB parameter_list RB LCB
		{
			lcb_count++;
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -1 || lookup_result == -3)
			{
				char temp[256];
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp,0);
				symbol_num++;
				memset(params,0,sizeof(params));

			}
			else if(lookup_result >= 0)
			{
				if(table[lookup_result]->param==NULL)
				{
					char temp[256] = {0};
					strncpy(temp,params,strlen(params)-2);
					strcpy(table[lookup_result]->param, temp);
					memset(params,0,sizeof(params));
				}
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}
	
			scope++;
	}
	| type ID LB RB LCB
		{
			lcb_count++;
			int lookup_result = lookup_symbol($2, scope, symbol_num); 
			if(lookup_result == -1 || lookup_result == -3)
			{
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL,0);
				symbol_num++;
			}
			else if(lookup_result == -2)
			{
				set_err(2,"Redeclared function",$2);
			}

			scope++;
		}
	| RCB
		{	
			lcb_count--;
			if(lcb_count<0)
			{
				yyerror("syntax error");
				exit(0);
			}
			if_count = 0;
			dump = 1;
		}

;

jump_stat
	: CONT SEMICOLON
	| BREAK SEMICOLON
	| RET SEMICOLON
	| RET expr SEMICOLON
;

print_func
	: PRINT LB STR_CONST RB
	| PRINT LB ID RB
		{
			if(lookup_symbol($3, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$3);
			}
		}

;

initializer
	: I_CONST
	| F_CONST	
	| TRUE
	| FALSE
	| ID
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
		}
	| STR_CONST
	| expr
;

parameter_list
	: parameter
	| parameter_list COMMA parameter
;

parameter
	: type ID
		{
			if(lookup_symbol($2, scope+1, symbol_num) != -2)
			{
				insert_symbol(symbol_num, $2, "parameter", $1, scope+1, NULL,0);
				strcat(params,$1);
				strcat(params,", ");

				param_index[param_num] = symbol_num;
				symbol_num++;
				param_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",$2);
				strcat(params,$1);
				strcat(params,", ");

			}
		}
;

argument_list
	: argument
	| argument_list COMMA argument
;

argument
	: ID
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
		}

	| expr
;

val
	: ID
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
		}
	| I_CONST
	| F_CONST
	| STR_CONST
	| TRUE
	| FALSE
;


/* actions can be taken when meet the token or rule */
type
    : INT	{ strcpy($$, "int"); }
    | FLOAT { strcpy($$, "float"); } 
    | BOOL	{ strcpy($$, "bool"); } 
    | STRING	{ strcpy($$, "string"); }
    | VOID	{ strcpy($$, "void"); }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	memset(params,0,sizeof(params));
    yyparse();
	if(lcb_count>0 && err_flag!=1)
	{
		yyerror("syntax error");
		exit(0);
	}
	if(err_flag!=1)
	{
		dump_symbol(symbol_num,0);
		printf("\nTotal lines: %d \n",yylineno);
    }
	return 0;
}

void yyerror(char *s)
{
	printf("%d: %s\n", ++yylineno, buf); 
	if(err_flag==2)
	{	
		semantic_error();
	}
	printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	err_flag = 1;
	memset(buf,0,sizeof(buf));
}

void semantic_error()
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s %s", err_type, err_symbol);
    printf("\n|-----------------------------------------------|\n\n");
	err_flag = 0;
}

void set_err(int flag, char *type, char *symbol)
{
	err_flag = flag;
	strcpy(err_type, type);
	strcpy(err_symbol, symbol);
}

void create_symbol(int entry_num) 
{
	table = malloc(sizeof(struct symbol *) * entry_num);
}

void insert_symbol(int index, char *name, char *entry_type, char *data_type, int scope_level, char *param, int forward)
{
	if(index==0)
	{
		create_symbol(30);
	}
	struct symbol *entry = malloc(sizeof(struct symbol));
	table[index] = entry;
	table[index]->index = index;	
	strcpy(table[index]->name, name);
	strcpy(table[index]->entry_type, entry_type);
	strcpy(table[index]->data_type, data_type);
	table[index]->scope_level = scope_level;
	if(param!=NULL)
		strcpy(table[index]->param, param);
	table[index]->forward = forward;
}

/* Return -1 if the symbol with same name and same scope doesn't exist, so can be inserted;
	return -2 if the symbol with same name and same scope exists, so can't be redeclared;
	return -3 if the symbol with same name exists, and it is in seeable scope;
	return entry number if the symbol is a function and it has been forward declared
*/	
int lookup_symbol(char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; i++)
	{
		if(strcmp(name, table[i]->name)==0 && table[i]->scope_level==scope_level)
		{
			if(table[i]->forward==1)
				return i;
			else
				return -2;
		}
		else if(strcmp(name, table[i]->name)==0 && table[i]->scope_level<scope_level)
			return -3;
	}

	return -1;
}

void dump_symbol(int symbol_num, int scope) 
{
    int i,j;
	int insert = 0;
	for(i=0; i<symbol_num; i++)
	{
		if(table[i]->scope_level==scope)
		{
			insert = 1;
			break;
		}
	}
	if(insert==1)
	{
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           		"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		for(i=0,j=0; i<symbol_num; i++)
		{
			if(table[i]->scope_level==scope)
			{
				printf("%-10d%-10s%-12s%-10s%-10d", j, table[i]->name, table[i]->entry_type, table[i]->data_type, table[i]->scope_level);
				printf("%-s\n",table[i]->param);
				j++;
				memset(table[i],0,sizeof(struct symbol));
				table[i]->scope_level = -1;
			}
		}
		printf("\n");
	}
}
