/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
int scope = 0;
int symbol_num = 0;
int err_flag = 0;	// 0: No error;  1: syntatic error;  2: semantic error
char err_type[20];
char err_symbol[256];
char params[256];
int dump = 0;
int param_index[30];
int param_num = 0;

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
    : declaration SEMICOLON 
	| expression_stat SEMICOLON
	| compound_stat 
    | print_func SEMICOLON
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
				scope--;
				dump = 0;
			}
			memset(buf, 0, sizeof(buf));
		}

;

declaration
    : type ID ASGN initializer
		{			
			if(lookup_symbol($2, scope, symbol_num) == -1)
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
			if(lookup_symbol($2, scope, symbol_num) == -1)
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
			if(lookup_symbol($2, scope, symbol_num) == -1)
			{
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL,1);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}

			int i,j;
			for(i=0; i<param_num; i++)
			{
				for(j=0; j<=symbol_num; j++)
				{
					if(table[j]->index == param_index[i])
					{	
						memset(table[i], 0, sizeof(struct symbol));
						table[i]->scope_level = -1;
						break;
					}
				}
			}
			symbol_num -= param_num;
		}
	| type ID LB RB
		{			
			if(lookup_symbol($2, scope, symbol_num) == -1)
			{
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL,1);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}
		}

;

expression_stat
	: val expr
	| assignment
	| condition
	| RET expr
	| ID LB argument_list RB
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{	
				set_err(2,"Undeclared function",$1);
			}

		}
	| ID LB RB
;

expr
	: ADD val expr
	| SUB val expr
	| term
;

term
	: unary
	| MUL val expr
	| DIV val expr
	| MOD val expr 
	| 
;

unary
	: val
	| INC
	| DEC
;

assignment
	: ID ASGN expression_stat
	| ID ADDASGN expression_stat
	| ID SUBASGN expression_stat
	| ID MULASGN expression_stat
	| ID DIVASGN expression_stat
	| ID MODASGN expression_stat
;

compound_stat
	: IF LB expression_stat RB LCB
		{
			scope++;
		}
	| RCB ELSE IF LB expression_stat RB LCB
	| RCB ELSE LCB
	| WHILE LB expression_stat RB LCB
		{
			scope++;
		}
	| type ID LB parameter_list RB LCB
		{
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -1)
			{
				char temp[256];
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp,0);
				symbol_num++;
				memset(params,0,sizeof(params));

			}
			else if(lookup_result >= 0)
			{
				char temp[256];
				strncpy(temp,params,strlen(params)-2);
				strcpy(table[lookup_result]->param, temp);
				memset(params,0,sizeof(params));
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}
	
			scope++;
	}
	| type ID LB RB LCB
		{
			int lookup_result = lookup_symbol($2, scope, symbol_num); 
			if(lookup_result == -1)
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
			dump = 1;
		}

;

condition
	: expression_stat MT expression_stat 	
	| expression_stat LT expression_stat
	| expression_stat MTE expression_stat
	| expression_stat LTE expression_stat
	| expression_stat EQ expression_stat
	| expression_stat NE expression_stat
	| condition AND condition
	| condition OR condition
	| NOT condition
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
	| expression_stat
;

parameter_list
	: parameter
	| parameter_list COMMA parameter
;

parameter
	: type ID
		{
			if(lookup_symbol($2, scope+1, symbol_num) == -1)
			{
				insert_symbol(symbol_num, $2, "parameter", $1, scope+1, NULL,0);
				symbol_num++;
				strcat(params,$1);
				strcat(params,", ");

				param_index[param_num] = symbol_num;
				param_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",$2);
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

	| expression_stat
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
