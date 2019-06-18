/*	Definition section */
%{
#include "stdio.h" 
#include "stdlib.h"
#include "string.h" 
#define BUF_SIZE 256
#define CLASS_NAME "compiler_hw3"

extern int yylineno;
extern int yylex();
extern char *yytext; // Get current token from lex
extern char buf[BUF_SIZE]; // Get current code line from lex
extern char* yytext;   // Get current token from lex
int scope = 0;
int symbol_num = 0;
int err_flag = 0;	// 0: No error;  1: syntatic error;  2: semantic error
char err_type[20]  = {0};
char err_symbol[BUF_SIZE] = {0};
char params[BUF_SIZE] = {0};
int dump = 0;
int add_scope = 0;
int param_index[50] = {0};
int param_num = 0;
int global_num = 0; // number of global variable
int func_num = 0;	// number of function sybol
char param_type[50] = {0}; // type of parameters in the form of jasmin type descriptoir
char return_type = 0;
int reg_num = 0;
char reg_type[50][7] = {0};
char op_type = 0;	// operand type

FILE *file; // To generate .j file for Jasmin

struct symbol
{
	int index;
	char name[256];
	char entry_type[10];
	char data_type[7];
	int scope_level;
	char param[256];
	int forward;
	int reg;
}**symbol_table;

void yyerror(char *s);

/* symbol table functions */
int lookup_symbol(char *name, int scope_level, int symbol_num);
void create_symbol(int entry_num);
void insert_symbol(int index, char *name, char *entry_type, char *data_type, int scope_level, char *param, int forward, int reg);
void dump_symbol();
int get_register(struct symbol **table, char *name, int scope_level, int symbol_num);
char* get_type(char *name, int scope_level, int symbol_num);

/* error functions */
void semantic_error();
void set_err(int flag, char *type, char *symbol);

/* code generation functions, just an example! */
void gencode_function();

%}

%union {
	int i_val;
    double f_val;
	char string[256];
}

/* Token without return */
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT IF ELSE FOR WHILE
%token RET CONT BREAK
%token QUOTA COMMENTLINE NEWLINE SEMICOLON

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STR_CONST
%token <i_val> TRUE FALSE
%token <string> ID
%token <string> INT FLOAT BOOL STRING VOID 

/* Nonterminal with return, which need to sepcify type */
%type <string> type
%type <f_val> initializer
%type <f_val> val
%type <f_val> assignment_expr
%type <f_val> conditional_expr
%type <f_val> logical_or_expr
%type <f_val> logical_and_expr
%type <f_val> relational_expr
%type <f_val> additive_expr
%type <f_val> multiplicative_expr
%type <f_val> cast_expr
%type <f_val> unary_expr
%type <f_val> postfix_expr
%type <f_val> primary_expr

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
			if(strlen(buf) < 1)	// If there is no code in the line, don't print the blank after line number 
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
				if(add_scope==0)	// If the flag is 1, the increment will be cancel out, so no need to decrease scope	
					scope--;
				dump = 0;	// Reset
				add_scope = 0;	// Reset
			}
			memset(buf, 0, sizeof(buf));	// Clear buffer
		}

;

declaration
    : type ID ASGN initializer SEMICOLON
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				
				if(scope==0)
				{
					global_num++;
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"int")==0)
						fprintf(file,".field public static %s I = %d\n", $2, (int)$4);
					else if(strcmp($1, "float")==0)
						fprintf(file,".field public static %s F = %f\n", $2, (float)$4);
					else if(strcmp($1, "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", $2, (int)$4);	
				}
				else
				{
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, reg_num);
					if(strcmp($1,"int")==0)
					{	
						fprintf(file,"\tldc %d\n"
									"\tistore %d\n", (int)$4, reg_num);
					}
					else if(strcmp($1, "float")==0)
					{	
						fprintf(file,"\tldc %f\n"
									"\tfstore %d\n", (float)$4, reg_num);
					}
					else if(strcmp($1, "bool")==0)
					{	
						fprintf(file,"\tldc %d\n"
									"\tistore %d\n", (int)$4, reg_num);
					}
					reg_num++;
				}
				symbol_num++;
			}
			else 
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
	| type ID ASGN STR_CONST SEMICOLON
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				if(scope==0)
				{
					global_num++;
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"string")==0)
					{	
						fprintf(file,".field public static %s Ljava/lang/String; = \"%s\"\n", $2, $4);	
					}
				}
				else
				{
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, reg_num);
					if(strcmp($1,"string")==0)
					{	
						fprintf(file,"\tldc \"%s\"\n"
									"\tistore %d\n", $4, reg_num);	
					}
					reg_num++;
				}
				symbol_num++;
			}
			else 
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
   	| type ID SEMICOLON
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				if(scope==0)
				{
					global_num++;
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"int")==0)
						fprintf(file,".field public static %s I = %d\n", $2, (int)0);
					else if(strcmp($1, "float")==0)
						fprintf(file,".field public static %s F = %f\n", $2, (float)0);
					else if(strcmp($1, "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", $2, (int)0);
					else if(strcmp($1, "void")==0)
						fprintf(file,".field public static %s V\n", $2);
					else if(strcmp($1, "string")==0)
						fprintf(file,".field public static %s Ljava/lang/String; = \"\"\n", $2);
	
				}
				else
				{
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, reg_num);
					if(strcmp($1,"int")==0)
					{	
						fprintf(file,"\tldc %d\n"
									"\tistore %d\n", (int)0, reg_num);
					}
					else if(strcmp($1, "float")==0)
					{	
						fprintf(file,"\tldc %f\n"
									"\tfstore %d\n", (float)0, reg_num);
					}
					else if(strcmp($1, "bool")==0)
					{
						fprintf(file,"\tldc %d\n"
									"\tistore %d\n", (int)0, reg_num);
					}
					else if(strcmp($1, "string")==0)
					{	
						fprintf(file,"\tldc \"\"\n"
									"\tistore %d\n", reg_num);
					}
					reg_num++;
				}
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
| type ID LB parameter_list RB SEMICOLON
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",$2);
			}

			/* Dont't insert parameters to table when function declaration */
			int i;
			for(i=0; i<param_num; i++)
			{
				memset(symbol_table[param_index[i]], 0, sizeof(struct symbol));
				symbol_table[param_index[i]]->scope_level = -1;
			}
			symbol_num -= param_num;
			param_num = 0;
		
			lookup_result = lookup_symbol($2, scope, symbol_num);
			/* Insert funcion */
			if(lookup_result != -2 && lookup_result < 0)
			{
				func_num++;
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp, 1, -1);
				symbol_num++;
			}
			memset(params,0,sizeof(params));
		}
	| type ID LB RB SEMICOLON
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",$2);
			}
			else
			{
				func_num++;
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL, 1, -1);
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
	: conditional_expr	{ $$ = $1; }
	| ID assignment_operator assignment_expr
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
			else
			{
				
				int reg = get_register(symbol_table, $1, scope, symbol_num);
				if(reg==-1)		// global variable
				{
					/*fprintf(file, "\tgetstatic %s/%s ", CLASS_NAME, $1);
					printf("----cmp = %d\n",reg);
					char type[7] = {0};
					strcpy(type, get_type($1, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "I\n");
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{
						fprintf(file, "F\n");
						op_type = 'F';
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "Z\n");
						op_type = 'I';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "Ljava/lang/String;\n");		
					}*/
				}
				else	// local variable
				{
					if(strcmp(reg_type[reg],"int")==0)
					{
						fprintf(file, "\tistore %d\n",reg);
					}
					else if(strcmp(reg_type[reg],"float")==0)
					{
						fprintf(file, "\tfstore %d\n",reg);
					}
					else if(strcmp(reg_type[reg],"bool")==0)
					{	
						fprintf(file, "\tistore %d\n",reg);	
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\tistore %d\n",reg);
					}
				}
			}
		}
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
	: logical_or_expr	{ $$ = $1; }
;

logical_or_expr
	: logical_and_expr	{ $$ = $1; }
	| logical_or_expr OR logical_and_expr
;

logical_and_expr
	: relational_expr	{ $$ = $1; }
	| logical_and_expr AND relational_expr
;

relational_expr
	: additive_expr	{ $$ = $1; }
	| relational_expr EQ additive_expr
	| relational_expr NE additive_expr
	| relational_expr LT additive_expr
	| relational_expr MT additive_expr
	| relational_expr LTE additive_expr
	| relational_expr MTE additive_expr
;

additive_expr
	: multiplicative_expr	{ $$ = $1; printf("----------add_expr = %f\n",$$);}
	| additive_expr ADD multiplicative_expr
		{
			$$ = $1 + $3;
			printf("------------%f\n", $$);
			switch(op_type)
			{
				case 'I':
				{
					fprintf(file, "\tiadd\n");
					break;
				}
				case 'F':
				{
					fprintf(file, "\tfadd\n");
					break;
				}
			}
		}
	| additive_expr SUB multiplicative_expr
		{
			$$ = $1 - $3;
			switch(op_type)
			{
				case 'I':
				{
					fprintf(file, "\tisub\n");
					break;
				}
				case 'F':
				{
					fprintf(file, "\tfsub\n");
					break;
				}
			}
		}
;

multiplicative_expr
	: cast_expr	{ $$ = $1; printf("----------mul_expr = %f\n",$$);}
	| multiplicative_expr MUL cast_expr
		{
			$$ = $1 * $3;
			switch(op_type)
			{
				case 'I':
				{
					fprintf(file, "\timul\n");
					break;
				}
				case 'F':
				{
					fprintf(file, "\tfmul\n");
					break;
				}
			}
		}
	| multiplicative_expr DIV cast_expr
		{
			$$ = $1 / $3;
			switch(op_type)
			{
				case 'I':
				{
					fprintf(file, "\tidiv\n");
					break;
				}
				case 'F':
				{
					fprintf(file, "\tfdiv\n");
					break;
				}
			}
		}
	| multiplicative_expr MOD cast_expr
		{	
			switch(op_type)
			{
				case 'I':
				{
					$$ = (int)$1 % (int)$3;
					fprintf(file, "\tirem\n");
					break;
				}
				case 'F':
				{
					// error
					break;
				}
			}
		}
;

cast_expr
	: unary_expr	{ $$ = $1; printf("----------cast_expr = %f\n",$$);}
	| LB type RB cast_expr
;

unary_expr
	: postfix_expr	{ $$ = $1; printf("----------unary_expr = %f\n",$$);}
	| unary_operator cast_expr
;

unary_operator
	: ADD
	| SUB
	| NOT
;

postfix_expr
	: primary_expr	{ $$ = $1; printf("----------postfix_expr = %f\n",$$);}
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
	| ID INC
	| ID DEC

;

primary_expr
	: val	{ $$ = $1;  printf("----------primary_expr = %f\n",$$);}
	| LB expr RB
;

compound_stat
	: IF LB expr RB LCB
		{
			scope++;
		}
	| RCB ELSE IF LB expr RB LCB
		{
			dump = 1;
			add_scope = 1;
		}
	| RCB ELSE LCB
		{
			dump = 1;
			add_scope = 1;
		}
	| WHILE LB expr RB LCB
		{
			scope++;
		}
	| type ID LB parameter_list RB LCB
		{
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -1 || lookup_result == -3)	// If function undeclared, insert it and its parameters
			{
				func_num++;
				char temp[256]= {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp,0, -1);
				symbol_num++;
				memset(params,0,sizeof(params));

				fprintf(file, ".method public static %s(",$2);
				int i = 0;
				for(i=0; i<param_num;i++)
				{
					if(param_type[i]=='I')
						fprintf(file, "I");
					else if(param_type[i]=='F')
						fprintf(file, "F");
					else if(param_type[i]=='Z')
						fprintf(file, "Z");
					else if(param_type[i]=='s')
						fprintf(file, "Ljava/lang/String;");
					else if(param_type[i]=='V')
						fprintf(file, "V");
				}
				if(strcmp($1,"int")==0)
				{
					return_type = 'I';
					fprintf(file, ")I\n");
				}
				else if(strcmp($1,"float")==0)
				{
					return_type = 'F';
					fprintf(file, ")F\n");
				}
				else if(strcmp($1,"bool")==0)
				{
					return_type = 'Z';
					fprintf(file, ")Z\n");
				}
				else if(strcmp($1, "string")==0)
				{
					return_type = 's';
					fprintf(file, ")Ljava/lang/String;\n");
				}
				else if(strcmp($1, "void")==0)
				{
					return_type = 'V';
					fprintf(file, ")V\n");
				}
				fprintf(file, ".limit stack 50\n"
								".limit locals 50\n");
				param_num = 0;
			}
			else if(lookup_result >= 0)	// If function forward declared, insert its attribute
			{
				if(symbol_table[lookup_result]->param==NULL)
				{
					char temp[256] = {0};
					strncpy(temp,params,strlen(params)-2);
					strcpy(symbol_table[lookup_result]->param, temp);
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
			int lookup_result = lookup_symbol($2, scope, symbol_num); 
			if(lookup_result == -1 || lookup_result == -3)
			{
				func_num++;
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL, 0, -1);
				symbol_num++;

				if(strcmp($2,"main")==0)
				{
					fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
									".limit stack 50\n"
									".limit locals 50\n");
				}
			}
			
			else if(lookup_result == -2)
			{
				set_err(2,"Redeclared function",$2);
			}

			scope++;
		}
	| RCB
		{	
			dump = 1;	// flag to indicate to dump table when meet NEWLINE later
		}

;

jump_stat
	: CONT SEMICOLON
	| BREAK SEMICOLON
	| RET SEMICOLON
		{
			fprintf(file, "\treturn\n"
							".end method\n");
		}
	| RET expr SEMICOLON
		{
			if(return_type == 'I')
			{	
				fprintf(file, "\tireturn\n"
							".end method\n");
			}
			else if(return_type == 'F')
			{	
				fprintf(file, "\tfreturn\n"
							".end method\n");
			}
			else if(return_type == 'Z')
			{	
				fprintf(file, "\tireturn\n"
							".end method\n");
			}
			else if(return_type == 's')
			{	
				//fprintf(file, "\tireturn\n"
				//			".end method\n");
			}
		}
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
	: I_CONST	{		$$ = $1;	}
	| F_CONST	{	$$ = $1;	}
	| TRUE	{	$$ = 1;	}
	| FALSE	{	$$ = 0;	}
	| ID
		{
			if(lookup_symbol($1, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
		}
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
				insert_symbol(symbol_num, $2, "parameter", $1, scope+1, NULL, 0, -1);
				strcat(params,$1);
				strcat(params,", ");

				param_index[param_num] = symbol_num;	// Record the index for removing later when function declaration
				symbol_num++;

				if(strcmp($1,"int")==0)
					param_type[param_num] = 'I';
				else if(strcmp($1,"float")==0)
					param_type[param_num] = 'F';
				else if(strcmp($1,"bool")==0)
					param_type[param_num] = 'Z';
				else if(strcmp($1, "string")==0)
					param_type[param_num] = 's';
				else if(strcmp($1, "void")==0)
					param_type[param_num] = 'V';

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
			int lookup_result = lookup_symbol($1, scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",$1);
			}
			else
			{
				int reg = get_register(symbol_table, $1, scope, symbol_num);
				if(reg==-1)		// global variable
				{
					fprintf(file, "\tgetstatic %s/%s ", CLASS_NAME, $1);
					printf("----cmp = %d\n",reg);
					char type[7] = {0};
					strcpy(type, get_type($1, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "I\n");
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{
						fprintf(file, "F\n");
						op_type = 'F';
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "Z\n");
						op_type = 'I';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "Ljava/lang/String;\n");		
					}
				}
				else	// local variable
				{
					if(strcmp(reg_type[reg],"int")==0)
					{
						fprintf(file, "\tiload %d\n",reg);
						op_type = 'I';
					}
					else if(strcmp(reg_type[reg],"float")==0)
					{
						fprintf(file, "\tfload %d\n",reg);
						op_type = 'F';
					}
					else if(strcmp(reg_type[reg],"bool")==0)
					{	
						fprintf(file, "\tiload %d\n",reg);
						op_type = 'I';
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\tiload %d\n",reg);
					}
				}
			}
		}
	| I_CONST	
		{	
			$$ = $1;
			fprintf(file, "\tldc %d\n", $1);
			op_type = 'I';
		}
	| F_CONST
		{	
			$$ = $1;	
			fprintf(file, "\tldc %f\n", $1);
			op_type = 'F';
		}
	| STR_CONST	
		{
			fprintf(file, "\tldc \"%s\"\n", $1);
		}
	| TRUE	
		{	
			$$ = 1;
			fprintf(file, "\tldc 1\n");
			op_type = 'I';
		}
	| FALSE	
		{	
			$$ = 0;
			fprintf(file, "\tldc 0\n");
			op_type = 'I';
		}
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

/* C code section */
int main(int argc, char** argv)
{
	memset(params,0,sizeof(params));  
	yylineno = 0;

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    yyparse();
	if(err_flag!=1)	// If no syntax error, dump global symbol at the end
	{
		dump_symbol(symbol_num,0);
		printf("\nTotal lines: %d \n",yylineno);
    }
    fclose(file);
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
	err_flag = 0;	// reset
}

void set_err(int flag, char *type, char *symbol)
{
	err_flag = flag;	// 0: No error;  1: syntatic error;  2: semantic error
	strcpy(err_type, type);
	strcpy(err_symbol, symbol);
}

/* symbol table functions */
void create_symbol(int entry_num) 
{
	symbol_table = malloc(sizeof(struct symbol *) * entry_num);
}

void insert_symbol(int index, char *name, char *entry_type, char *data_type, int scope_level, char *param, int forward, int reg)
{
	if(index==0)
	{
		create_symbol(50);
	}
	struct symbol *entry = malloc(sizeof(struct symbol));
	symbol_table[index] = entry;
	symbol_table[index]->index = index;	
	strcpy(symbol_table[index]->name, name);
	strcpy(symbol_table[index]->entry_type, entry_type);
	strcpy(symbol_table[index]->data_type, data_type);
	symbol_table[index]->scope_level = scope_level;
	if(param!=NULL)
	{
		strncpy(symbol_table[index]->param, param,strlen(param));
	}
	symbol_table[index]->forward = forward;
	symbol_table[index]->reg = reg;
	if(reg>=0)
	{
		strcpy(reg_type[reg], data_type);
	}
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
		if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level==scope_level)
		{
			if(symbol_table[i]->forward==1)
				return i;
			else
				return -2;
		}
		else if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level<scope_level)
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
		if(symbol_table[i]->scope_level==scope)
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
			if(symbol_table[i]->scope_level==scope)
			{
				printf("%-10d%-10s%-12s%-10s%-10d", j, symbol_table[i]->name, symbol_table[i]->entry_type, symbol_table[i]->data_type, symbol_table[i]->scope_level);
				printf("%-s\n",symbol_table[i]->param);
				j++;
				memset(symbol_table[i],0,sizeof(struct symbol));
				symbol_table[i]->scope_level = -1;
			}
		}
		printf("\n");
	}
}

int get_register(struct symbol **table, char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; i++)
	{
		if(strcmp(name, table[i]->name)==0 && table[i]->scope_level<=scope_level)
		{
			return table[i]->reg;
		}
	}

	return -1;
}

char *get_type(char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; i++)
	{
		if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level<=scope_level)
		{
			return symbol_table[i]->data_type;
		}
	}

	return 0;

}


/* code generation functions */
void gencode_function() {}
