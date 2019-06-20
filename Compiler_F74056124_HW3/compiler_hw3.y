/*	Definition section */
%{
#include "stdio.h" 
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define BUF_SIZE 256
#define CLASS_NAME "compiler_hw3"

extern int yylineno;
extern int yylex();
extern char *yytext; // Get current token from lex
extern char buf[BUF_SIZE]; // Get current code line from lex
extern char* yytext;   // Get current token from lex
int scope = 0;
int symbol_num = 0;
int err_flag = 0;	// 0: No error;  1: Syntatic error;  2: Undeclared or Redeclared;  3: Arithmetic error or Function error
char err_type[20]  = {0};
char err_symbol[BUF_SIZE] = {0};
char params[BUF_SIZE] = {0};	// buffer for types of parameters
int dump = 0;
int add_scope = 0;
int func_flag = 0;	// Enter function, use function register
int param_index[50] = {0};
int param_num = 0;
int funcReg_num = 0;	// number of variables in function definition
char funcReg_type[50] = {0}; // type of parameters in the form of jasmin type descriptoir
char return_type = 0;
int reg_num = 0;
char reg_type[50][7] = {0};
char op_type = 0;	// operand type
double op_val = 0;	// operand value
char relation_flag = 0;
int if_group[50] = {0};	// number of if_groups in each scope
int if_branch[50] = {0};	// number of branches in current if_group in each scope
int if_endFlag[50] = {0};	// whether current branch should be ended later
int if_exitFlag[50] = {0};	// whether current if_group should exit later
int while_group[50] = {0};	// number of while_group in each scope
int while_exitFlag[50] = {0};	// whether current while_group should exit later
int zero_flag = 0;
int invoke_flag = 0;
char invoke_arg[BUF_SIZE] = {0};

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
	int value_i;
	double value_f;

}**symbol_table;

void yyerror(char *s);

/* symbol table functions */
int lookup_symbol(char *name, int scope_level, int symbol_num);
void create_symbol(int entry_num);
void insert_symbol(int index, char *name, char *entry_type, char *data_type, int scope_level, char *param, int forward, int reg);
void dump_symbol();
int get_register(struct symbol **table, char *name, int scope_level, int symbol_num);
char* get_type(char *name, int scope_level, int symbol_num);
char* get_attribute(char *name, int scope_level, int symbol_num);
void store_value(char *name, int scope_level, int symbol_num, double value);

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
%token <string> ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN

/* Nonterminal with return, which need to sepcify type */
%type <string> type
%type <f_val> initializer
%type <f_val> val
%type <f_val> expression_stat
%type <f_val> expr
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
%type <string> opassign_operator
%type <string> opassign_operand
%type <string> func_id

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
			if(err_flag == 2 || err_flag == 3)
			{	
				semantic_error();
			}
			if(dump == 1)
			{
				dump_symbol(symbol_num,scope);
				if(add_scope==0)	// If the flag is 1, the increment will be cancel out, so no need to decrease scope	
					--scope;
				dump = 0;	// Reset
				add_scope = 0;	// Reset
				if(func_flag==1 && scope==0)
					func_flag = 0;
			}
			if(func_flag==0)
			{
				funcReg_num  = 0;
			}
			memset(buf, 0, sizeof(buf));	// Clear buffer
			op_type = 0;
			relation_flag = 0;
			zero_flag = 0;
		}

;

declaration
    : type ID ASGN initializer SEMICOLON
		{			
			if(lookup_symbol($2, scope, symbol_num) != -2)
			{
				
				if(scope==0)
				{
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"int")==0)
						fprintf(file,".field public static %s I = %d\n", $2, (int)$4);
					else if(strcmp($1, "float")==0)
						fprintf(file,".field public static %s F = %f\n", $2, (double)$4);
					else if(strcmp($1, "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", $2, (int)$4);	
				}
				else
				{
					if(func_flag==1)
					{
						insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, funcReg_num);
						if(strcmp($1,"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)$4, funcReg_num);
						}
						else if(strcmp($1, "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)$4, funcReg_num);
						}
						else if(strcmp($1, "bool")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)$4, funcReg_num);
						}
						++funcReg_num;
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
										"\tfstore %d\n", (double)$4, reg_num);
						}
						else if(strcmp($1, "bool")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)$4, reg_num);
						}
						++reg_num;
					}
					
				}
				++symbol_num;
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
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"string")==0)
					{	
						fprintf(file,".field public static %s Ljava/lang/String; = \"%s\"\n", $2, $4);	
					}
				}
				else
				{
					if(func_flag == 1)
					{
						insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, funcReg_num);
						if(strcmp($1,"string")==0)
						{	
							fprintf(file,"\tldc \"%s\"\n"
									"\tastore %d\n", $4, funcReg_num);	
						}
						++funcReg_num;
					}
					else
					{
						insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, reg_num);
						if(strcmp($1,"string")==0)
						{	
							fprintf(file,"\tldc \"%s\"\n"
									"\tastore %d\n", $4, reg_num);	
						}
						++reg_num;
					}
				}
				++symbol_num;
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
					insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, -1);
					if(strcmp($1,"int")==0)
						fprintf(file,".field public static %s I = %d\n", $2, (int)0);
					else if(strcmp($1, "float")==0)
						fprintf(file,".field public static %s F\n", $2);
					else if(strcmp($1, "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", $2, (int)0);
					else if(strcmp($1, "void")==0)
						fprintf(file,".field public static %s V\n", $2);
					else if(strcmp($1, "string")==0)
						fprintf(file,".field public static %s Ljava/lang/String; = \"\"\n", $2);
	
				}
				else
				{
					if(func_flag == 1)
					{
						insert_symbol(symbol_num, $2, "variable", $1, scope, NULL, 0, funcReg_num);
						if(strcmp($1,"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, funcReg_num);
						}
						else if(strcmp($1, "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)0, funcReg_num);
						}
						else if(strcmp($1, "bool")==0)
						{
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, funcReg_num);
						}
						else if(strcmp($1, "string")==0)
						{	
							fprintf(file,"\tldc \"\"\n"
										"\tastore %d\n", funcReg_num);
						}
						++funcReg_num;
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
										"\tfstore %d\n", (double)0, reg_num);
						}
						else if(strcmp($1, "bool")==0)
						{
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, reg_num);
						}
						else if(strcmp($1, "string")==0)
						{	
							fprintf(file,"\tldc \"\"\n"
										"\tastore %d\n", reg_num);
						}
						++reg_num;
					}
				}
				++symbol_num;
			}
			else
			{
				set_err(2,"Redeclared variable",$2);
			}
		}
		
	| type ID LB parameter_list RB SEMICOLON
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -2 || (lookup_result >= 0 && symbol_table[lookup_result]->forward==1) )
			{
				set_err(2,"Redeclared function",$2);
			}

			/* Dont't insert parameters to table when function declaration */
			int i;
			for(i=0; i<param_num; ++i)
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
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp, 1, -1);
				++symbol_num;
			}
			else if(lookup_result>=0 && symbol_table[lookup_result]->forward==2)
			{
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);

				if(strcmp($1, symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
				}
				else if(strcmp(temp, symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
				}

			}
			memset(params,0,sizeof(params));
			memset(param_index,0,sizeof(param_index));
		}
	| type ID LB RB SEMICOLON
		{			
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if( lookup_result == -2 || (lookup_result >= 0 && symbol_table[lookup_result]->forward==1) )
			{
				set_err(2,"Redeclared function",$2);
			}
			else if(lookup_result != -2 && lookup_result < 0)
			{
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL, 1, -1);
				++symbol_num;
			}
			else if(lookup_result>=0 && symbol_table[lookup_result]->forward==2)
			{
				if(strcmp($1, symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
				}
				else if(strlen(symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
				}
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
	| ID ASGN assignment_expr
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
					fprintf(file, "\tputstatic %s/%s ", CLASS_NAME, $1);
					char type[7] = {0};
					strcpy(type, get_type($1, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "I\n");
					}
					else if(strcmp(type,"float")==0)
					{
						fprintf(file, "F\n");
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "Z\n");
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
						if(op_type == 'I' || op_type == 'Z')
							fprintf(file, "\tistore %d\n",reg);
						else if(op_type == 'F')
						{
							fprintf(file, "\tf2i\n"
										"\tistore %d\n",reg);
						}	
					}
					else if(strcmp(reg_type[reg],"float")==0)
					{
						if(op_type == 'F')
							fprintf(file, "\tfstore %d\n",reg);
						else if(op_type == 'I' || op_type == 'Z')
						{
							fprintf(file, "\ti2f\n"
										"\tfstore %d\n",reg);
						}
					}
					else if(strcmp(reg_type[reg],"bool")==0)
					{	
						fprintf(file, "\tistore %d\n",reg);	
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\tastore %d\n",reg);
					}
				}		
				op_type = 0;
			}
		}
	| opassign_operand opassign_operator assignment_expr
		{
			if(op_type == 'I' || op_type == 'Z')
			{	
				if(strcmp($2, "+=")==0)
					fprintf(file, "\tiadd\n");
				else if(strcmp($2, "-=")==0)
					fprintf(file, "\tisub\n");
				else if(strcmp($2, "*=")==0)
					fprintf(file, "\timul\n");
				else if(strcmp($2, "/=")==0)
				{
					if(zero_flag==1)
						set_err(3,"divide by zero","");
					else
						fprintf(file, "\tidiv\n");
				}
				else if(strcmp($2, "%=")==0)
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
						fprintf(file, "\tirem\n");
				}
			}
			else if(op_type == 'F')
			{
				if(strcmp($2, "+=")==0)
					fprintf(file, "\tfadd\n");
				else if(strcmp($2, "-=")==0)
					fprintf(file, "\tfsub\n");
				else if(strcmp($2, "*=")==0)
					fprintf(file, "\tfmul\n");
				else if(strcmp($2, "/=")==0)
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
						fprintf(file, "\tfdiv\n");
				}
				else if(strcmp($2, "%=")==0)
				{
					set_err(3,"Modulo operator with floating point operands","");
				}
			}
				
			int reg = get_register(symbol_table, $1, scope, symbol_num);
			if(reg==-1)		// global variable
			{
				fprintf(file, "\tputstatic %s/%s ", CLASS_NAME, $1);
				char type[7] = {0};
				strcpy(type, get_type($1, scope, symbol_num));
				if(strcmp(type,"int")==0)
				{
					fprintf(file, "I\n");
				}
				else if(strcmp(type,"float")==0)
				{
					fprintf(file, "F\n");
				}
				else if(strcmp(type,"bool")==0)
				{
					fprintf(file, "Z\n");
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
					if(op_type == 'I' || op_type == 'Z')
						fprintf(file, "\tistore %d\n",reg);
					else if(op_type == 'F')
					{
						fprintf(file, "\tf2i\n"
									"\tistore %d\n",reg);
					}
				}
				else if(strcmp(reg_type[reg],"float")==0)
				{
					if(op_type == 'F')
						fprintf(file, "\tfstore %d\n",reg);
					else if(op_type == 'I' || op_type == 'Z')
					{
						fprintf(file, "\ti2f\n"
									"\tfstore %d\n",reg);
					}
				}
				else if(strcmp(reg_type[reg],"bool")==0)
				{	
					fprintf(file, "\tistore %d\n",reg);	
				}
				else if(strcmp(reg_type[reg], "string")==0)
				{	
					fprintf(file, "\tastore %d\n",reg);
				}
			}
			op_type = 0;
		}
;

opassign_operand
	: ID
		{
			strcpy($$, $1);	
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
					char type[7] = {0};
					strcpy(type, get_type($1, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{	
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, $1);
							op_type = 'F';				
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, $1);
						op_type = 'Z';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, $1);		
						op_type = 's';
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
						op_type = 'Z';
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\taload %d\n",reg);
						op_type = 's';
					}
				}
			}
		}	
;

opassign_operator
	: MULASGN	{ strcpy($$, "*="); }
	| DIVASGN	{ strcpy($$, "/="); }
	| MODASGN	{ strcpy($$, "%="); }
	| ADDASGN	{ strcpy($$,"+="); }
	| SUBASGN	{ strcpy($$, "-="); }
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
	| relational_operand EQ relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}	
			relation_flag = 'E';
		}
	| relational_operand NE relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}
			relation_flag = 'N';
		}
	| relational_operand LT relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{	
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}
			relation_flag = 'l';
		}
	| relational_operand MT relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}
			relation_flag = 'm';
		}
	| relational_operand LTE relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}
			relation_flag = 'L';
		}
	| relational_operand MTE relational_operand
		{
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
			{	
				fprintf(file,"\tfsub\n"
							"\tf2i\n");
			}
			relation_flag = 'M';
		}
;

relational_operand
	: I_CONST
		{
			if(if_endFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
			fprintf(file, "\tldc %d\n", $1);
			op_type = 'I';
		}
	| F_CONST
		{
			if(if_endFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
			fprintf(file, "\tldc %f\n", $1);
			op_type = 'F';
		}
	| TRUE
		{
			if(if_endFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
			fprintf(file, "\tldc 1\n");
			op_type = 'Z';
		}
	| FALSE
		{
			if(if_endFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
			fprintf(file, "\tldc 0\n");
			op_type = 'Z';
		}
	| ID
		{
			if(if_endFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}

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
					char type[7] = {0};
					strcpy(type, get_type($1, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{	
						fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, $1);				
						op_type = 'F';
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, $1);
						op_type = 'Z';
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
						op_type = 'Z';
					}
				}
			}
		}
;

additive_expr
	: multiplicative_expr	{ $$ = $1; }//printf("----------add_expr = %f\n",$$)
	| additive_expr ADD multiplicative_expr
		{
			$$ = $1 + $3;
			//printf("------------%f\n", $$);
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
	: cast_expr	{ $$ = $1; }//printf("----------mul_expr = %f\n",$$)
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
			if(zero_flag==1)
				set_err(3,"Divide by zero","");
			else
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
		}
	| multiplicative_expr MOD cast_expr
		{	
			
			switch(op_type)
			{
				case 'I':
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
					{
						$$ = (int)$1 % (int)$3;
						fprintf(file, "\tirem\n");
					}
					break;
				}
				case 'F':
				{
					set_err(3,"Modulo operator with floating point operands","");
					break;
				}
			}
		}
;

cast_expr
	: unary_expr	{ $$ = $1; } //printf("----------cast_expr = %f\n",$$)
	| LB type RB cast_expr
;

unary_expr
	: postfix_expr	{ $$ = $1; }//printf("----------unary_expr = %f\n",$$)
	| unary_operator cast_expr
;

unary_operator
	: ADD
	| SUB
	| NOT
;

postfix_expr
	: primary_expr	{ $$ = $1; }//printf("----------postfix_expr = %f\n",$$)
	| func_id LB RB
		{
			int lookup_result = lookup_symbol($1, scope, symbol_num);
			if(lookup_result == -1)
			{	
				set_err(2,"Undeclared function",$1);
			}
			else if(strlen(symbol_table[lookup_result]->param)!=0)
			{
				set_err(3, "function formal parameter is not the same", "");
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s()", CLASS_NAME, $1);
				char type[7] = {0};
				strcpy(type, get_type($1,scope,symbol_num));
				if(strcmp(type, "int")==0)
				{
					fprintf(file, "I\n");
					op_type = 'I';
				}
				else if(strcmp(type, "float")==0)
				{
					fprintf(file, "F\n");
					op_type = 'F';
				}
				else if(strcmp(type, "bool")==0)
				{
					fprintf(file, "Z\n");
					op_type = 'Z';
				}
				else if(strcmp(type, "void")==0)
				{
					fprintf(file, "V\n");
					op_type = 'V';
				}
				else if(strcmp(type, "string")==0)
				{
					fprintf(file, "Ljava/lang/String;\n");
					op_type = 's';
				}
			}
			memset(invoke_arg,0,sizeof(invoke_arg));
			invoke_flag = 0;
		}
	| func_id LB argument_list RB
		{
			int lookup_result = lookup_symbol($1, scope, symbol_num);	
			char temp[256] = {0};	
			strncpy(temp,invoke_arg,strlen(invoke_arg)-2);
			char *cut = strstr(temp, ", ");	

			if(lookup_result == -1)
			{
				set_err(2,"Undeclared function",$1);
			}
			else if(strcmp(symbol_table[lookup_result]->param, cut+2)!=0)
			{	
				set_err(3,"function formal parameter is not the same","");
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s(", CLASS_NAME, $1);

				memset(temp,0,sizeof(temp));
				strcpy(temp, get_attribute($1, scope, symbol_num));
				char *arg_type;
				arg_type = strtok(temp,", ");
				while(arg_type != NULL)
				{
					if(strcmp(arg_type, "int")==0)
					{
						fprintf(file, "I");
					}
					else if(strcmp(arg_type, "float")==0)
					{
						fprintf(file, "F");
					}
					else if(strcmp(arg_type, "bool")==0)
					{
						fprintf(file, "Z");
					}
					else if(strcmp(arg_type, "void")==0)
					{
						fprintf(file, "V");
					}
					else if(strcmp(arg_type, "string")==0)
					{
						fprintf(file, "Ljava/lang/String;");
					}

					arg_type = strtok(NULL, ", ");
				}
				fprintf(file, ")");

				char type[7] = {0};
				strcpy(type, get_type($1,scope,symbol_num));
				if(strcmp(type, "int")==0)
				{
					fprintf(file, "I\n");
				}
				else if(strcmp(type, "float")==0)
				{
					fprintf(file, "F\n");
				}
				else if(strcmp(type, "bool")==0)
				{
					fprintf(file, "Z\n");
				}
				else if(strcmp(type, "void")==0)
				{
					fprintf(file, "V\n");
				}
				else if(strcmp(type, "string")==0)
				{
					fprintf(file, "Ljava/lang/String;\n");
				}			
			}
			memset(invoke_arg,0,sizeof(invoke_arg));
			invoke_flag = 0;
		}	
	| ID INC
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
					fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
				}
				else	// local variable
				{
					fprintf(file, "\tiload %d\n",reg);
				}

				fprintf(file,"\tldc 1\n"
							"\tiadd\n");

				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tputstatic %s/%s I\n", CLASS_NAME, $1);
				}
				else	// local variable
				{
					fprintf(file, "\tistore %d\n",reg);
				}
			}
		}
	| ID DEC
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
					fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
				}
				else	// local variable
				{
					fprintf(file, "\tiload %d\n",reg);
				}

				fprintf(file,"\tldc 1\n"
							"\tisub\n");

				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tputstatic %s/%s I\n", CLASS_NAME, $1);
				}
				else	// local variable
				{
					fprintf(file, "\tistore %d\n",reg);
				}
			}
		}
;

func_id
	: ID
		{
			invoke_flag = 1;
			strcpy($$,$1);
		}
;

primary_expr
	: val	{ $$ = $1;  }//printf("----------primary_expr = %f\n",$$)
	| LB expr RB
;

compound_stat
	: IF LB expr RB LCB
		{
			++scope;
			++if_group[scope-1];
			if_branch[scope-1] = 1;
			if_endFlag[scope-1] = 1;
			if_exitFlag[scope-1] = 1;
			switch(relation_flag)
			{
				case 'E':
				{
					fprintf(file, "\tifeq LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'N':
				{
					fprintf(file, "\tifne LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'l':
				{
					fprintf(file, "\tiflt LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'm':
				{
					fprintf(file, "\tifgt LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'L':
				{
					fprintf(file, "\tifle LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'M':
				{
					fprintf(file, "\tifge LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
			}
			fprintf(file, "\tgoto END%d_%d_%d\n", scope-1, if_group[scope-1],if_branch[scope-1]);
			fprintf(file, "LABEL%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
		}
	| RCB ELSE IF LB expr RB LCB
		{
			dump = 1;
			add_scope = 1;
			
			++if_branch[scope-1];
			if_endFlag[scope-1] = 1;
			switch(relation_flag)
			{
				case 'E':
				{
					fprintf(file, "\tifeq LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'N':
				{
					fprintf(file, "\tifne LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'l':
				{
					fprintf(file, "\tiflt LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'm':
				{
					fprintf(file, "\tifgt LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'L':
				{
					fprintf(file, "\tifle LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
				case 'M':
				{
					fprintf(file, "\tifge LABEL%d_%d_%d\n", scope-1, if_group[scope-1], if_branch[scope-1]);
					break;
				}
			}
			relation_flag = 0;
			fprintf(file, "\tgoto END%d_%d_%d\n", scope-1, if_group[scope-1],if_branch[scope-1]);
			fprintf(file, "LABEL%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);

		}
	| RCB ELSE LCB
		{
			dump = 1;
			add_scope = 1;
			
			if_endFlag[scope-1] = 0;
			fprintf(file, "\tgoto  EXIT%d_%d\n", scope-1, if_group[scope-1]);
			fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
		}
	| while LB expr RB LCB
		{
			++scope;
			
			switch(relation_flag)
			{
				case 'E':
				{
					fprintf(file, "\tifeq TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
				case 'N':
				{
					fprintf(file, "\tifne TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
				case 'l':
				{
					fprintf(file, "\tiflt TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
				case 'm':
				{
					fprintf(file, "\tifgt TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
				case 'L':
				{
					fprintf(file, "\tifle TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
				case 'M':
				{
					fprintf(file, "\tifge TRUE%d_%d\n", scope-1, while_group[scope-1]);
					break;
				}
			}
			relation_flag = 0;
			fprintf(file, "\tgoto FALSE%d_%d\n", scope-1, while_group[scope-1]);
			fprintf(file, "TRUE%d_%d:\n", scope-1, while_group[scope-1]);
		}
	| type ID LB parameter_list RB LCB
		{
			int lookup_result = lookup_symbol($2, scope, symbol_num);
			if(lookup_result == -1 || lookup_result == -3)	// If function undeclared, insert it and its parameters
			{
				func_flag = 1;
				char temp[256]= {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, $2, "function", $1, scope, temp, 2, -1);
				++symbol_num;
				memset(params,0,sizeof(params));
				
				fprintf(file, ".method public static %s(",$2);
				int i = 0;
				for(i=0; i<param_num;++i)
				{
					if(funcReg_type[i]=='I')
						fprintf(file, "I");
					else if(funcReg_type[i]=='F')
						fprintf(file, "F");
					else if(funcReg_type[i]=='Z')
						fprintf(file, "Z");
					else if(funcReg_type[i]=='s')
						fprintf(file, "Ljava/lang/String;");
					else if(funcReg_type[i]=='V')
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

				/*for(i=0; i<param_num;i++)
				{
					if(funcReg_type[i]=='I')
						fprintf(file, "\tiload %d\n", i);
					else if(funcReg_type[i]=='F')
						fprintf(file, "\tfload %d\n", i);
					else if(funcReg_type[i]=='Z')
						fprintf(file, "\tiload %d\n", i);
					else if(funcReg_type[i]=='s')
						fprintf(file, "\taload %d\n", i);
				}*/

				param_num = 0;
				funcReg_num = 0;
				memset(funcReg_type, 0, sizeof(funcReg_type));
			}
			else if(lookup_result >= 0 && symbol_table[lookup_result]->forward!=2)		// If function forward declared, insert its attribute
			{
				func_flag = 1;
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);

				if(strcmp($1, symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
					if(strcmp($1,"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp($1,"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp($1,"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp($1, "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp($1, "void")==0)
					{
						return_type = 'V';
					}
				}
				else if(strcmp(temp,symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
					if(strcmp($1,"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp($1,"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp($1,"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp($1, "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp($1, "void")==0)
					{
						return_type = 'V';
					}
				}
				else 
				{
					if(symbol_table[lookup_result]->param==NULL)
					{
						strcpy(symbol_table[lookup_result]->param, temp);
						memset(params,0,sizeof(params));
					}
	
					fprintf(file, ".method public static %s(",$2);
					int i = 0;
					for(i=0; i<param_num;++i)
					{
						if(funcReg_type[i]=='I')
							fprintf(file, "I");
						else if(funcReg_type[i]=='F')
							fprintf(file, "F");
						else if(funcReg_type[i]=='Z')
							fprintf(file, "Z");
						else if(funcReg_type[i]=='s')
							fprintf(file, "Ljava/lang/String;");
						else if(funcReg_type[i]=='V')
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

					/*for(i=0; i<param_num;i++)
					{
						if(funcReg_type[i]=='I')
							fprintf(file, "\tiload %d\n", i);
						else if(funcReg_type[i]=='F')
							fprintf(file, "\tfload %d\n", i);
						else if(funcReg_type[i]=='Z')
							fprintf(file, "\tiload %d\n", i);
						else if(funcReg_type[i]=='s')
							fprintf(file, "\taload %d\n", i);
					}*/

					param_num = 0;
					funcReg_num = 0;
					memset(funcReg_type, 0, sizeof(funcReg_type));
				}
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}
		
				++scope;
		}
	| type ID LB RB LCB
		{
			int lookup_result = lookup_symbol($2, scope, symbol_num); 
			if(lookup_result == -1 || lookup_result == -3)
			{
				func_flag = 1;
				insert_symbol(symbol_num, $2, "function", $1, scope, NULL, 2, -1);
				++symbol_num;

				if(strcmp($2,"main")==0)
				{
					fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
									".limit stack 50\n"
									".limit locals 50\n");
					if(strcmp($1,"int")==0)
						return_type = 'I';
					else if(strcmp($1,"float")==0)
						return_type = 'F';
					else if(strcmp($1,"bool")==0)
						return_type = 'Z';
					else if(strcmp($1, "string")==0)
						return_type = 's';
					else if(strcmp($1, "void")==0)
						return_type = 'V';
				}
				else
				{
					fprintf(file, ".method public static %s()", $2);
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
				}
				param_num = 0;
				funcReg_num = 0;
				memset(funcReg_type, 0, sizeof(funcReg_type));
			}
			else if(lookup_result >= 0 && symbol_table[lookup_result]->forward!=2)	// If function forward declared
			{
				func_flag = 1;
				if(strcmp($1, symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
					if(strcmp($1,"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp($1,"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp($1,"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp($1, "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp($1, "void")==0)
					{
						return_type = 'V';
					}
				}
				else if(strlen(symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
					if(strcmp($1,"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp($1,"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp($1,"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp($1, "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp($1, "void")==0)
					{
						return_type = 'V';
					}
				}
				else
				{
					
					if(strcmp($2,"main")==0)
					{
						fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
										".limit stack 50\n"
										".limit locals 50\n");
						if(strcmp($1,"int")==0)
							return_type = 'I';
						else if(strcmp($1,"float")==0)
							return_type = 'F';
						else if(strcmp($1,"bool")==0)
							return_type = 'Z';
						else if(strcmp($1, "string")==0)
							return_type = 's';
						else if(strcmp($1, "void")==0)
							return_type = 'V';
					}
					else
					{
						fprintf(file, ".method public static %s()",$2);
						int i = 0;
						if(strcmp($1,"int")==0)
						{
							return_type = 'I';
							fprintf(file, "I\n");
						}
						else if(strcmp($1,"float")==0)
						{
							return_type = 'F';
							fprintf(file, "F\n");
						}
						else if(strcmp($1,"bool")==0)
						{
							return_type = 'Z';
							fprintf(file, "Z\n");
						}
						else if(strcmp($1, "string")==0)
						{
							return_type = 's';
							fprintf(file, "Ljava/lang/String;\n");
						}
						else if(strcmp($1, "void")==0)
						{
							return_type = 'V';
							fprintf(file, "V\n");
						}
						fprintf(file, ".limit stack 50\n"
									".limit locals 50\n");
					}
					param_num = 0;
					funcReg_num = 0;
					memset(funcReg_type, 0, sizeof(funcReg_type));
				}
			}
			else
			{
				set_err(2,"Redeclared function",$2);
			}

			++scope;
		}
	| RCB
		{	
			dump = 1;	// flag to indicate to dump table when meet NEWLINE later
			if(if_endFlag[scope-1] == 1)
			{
				//fprintf(file, "\tgoto EXIT%d_%d\n", scope, if_group[scope]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
			if(if_exitFlag[scope-1] == 1)
			{
				fprintf(file, "EXIT%d_%d:\n", scope-1, if_group[scope-1]);
				if_exitFlag[scope-1] = 0;
			}
			if(while_exitFlag[scope-1]==1)
			{
				fprintf(file, "\tgoto BEGIN%d_%d\n", scope-1, while_group[scope-1]);
				fprintf(file, "FALSE%d_%d:\n", scope-1, while_group[scope-1]);
				while_exitFlag[scope-1] = 0;
			}
		}

;

while
	: WHILE
		{
			++while_group[scope];
			while_exitFlag[scope] = 1;
			fprintf(file, "BEGIN%d_%d:\n", scope, while_group[scope]);
		}
;

jump_stat
	: CONT SEMICOLON
	| BREAK SEMICOLON
	| RET SEMICOLON
		{
			if(return_type == 'V')
			{
				fprintf(file, "\treturn\n"
								".end method\n");
			}
			else
			{
				set_err(3,"function return type is not the same","");
			}
			return_type = 0;
		}
	| RET expr SEMICOLON
		{
			if(return_type == 'I')
			{	
				if(op_type=='I')
				{	
					fprintf(file, "\tireturn\n"
								".end method\n");
				}
				else
				{
					set_err(3,"function return type is not the same","");
				}
			}
			else if(return_type == 'F')
			{	
				if(op_type == 'F')
				{
					fprintf(file, "\tfreturn\n"
								".end method\n");
				}
				else
				{
					set_err(3,"function return type is not the same","");
				}
			}
			else if(return_type == 'Z')
			{	
				if(op_type == 'Z')
				{
					fprintf(file, "\tireturn\n"
								".end method\n");
				}
				else
				{
					set_err(3,"function return type is not the same","");
				}
			}
			else if(return_type == 's')
			{	
				if(op_type == 's')
				{ 
					fprintf(file, "\tareturn\n"
							".end method\n");
				}
				else
				{
					set_err(3,"function return type is not the same","");
				}
			}
			else if(return_type == 'V')
			{
				set_err(3,"function return type is not the same","");
			}
			return_type = 0;
		}
;

print_func
	: PRINT LB I_CONST RB
		{
			fprintf(file, "\tldc %d\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(I)V\n", $3);
		}
	| PRINT LB F_CONST RB
		{
			fprintf(file, "\tldc %f\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(F)V\n", $3);
		}
	| PRINT LB STR_CONST RB
		{
			fprintf(file, "\tldc \"%s\"\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", $3);
		}
	| PRINT LB ID RB
		{
			if(lookup_symbol($3, scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",$3);
			}
			else
			{
				int reg = get_register(symbol_table, $3, scope, symbol_num);
				if(reg==-1)		// global variable
				{
					char type[7] = {0};
					strcpy(type, get_type($3, scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s I\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", $3);
					}
					else if(strcmp(type,"float")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s F\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(F)V\n", $3);				
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s Z\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", $3);
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s Ljava/lang/String;\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", $3);		
					}
				}
				else	// local variable
				{
					if(strcmp(reg_type[reg],"int")==0)
					{
						fprintf(file, "\tiload %d\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", reg);
					}
					else if(strcmp(reg_type[reg],"float")==0)
					{
						fprintf(file, "\tfload %d\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(F)V\n", reg);

					}
					else if(strcmp(reg_type[reg],"bool")==0)
					{	
						fprintf(file, "\tiload %d\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", reg);
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\taload %d\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", reg);
					}
				}
			}
		}

;

initializer
	: I_CONST	{	$$ = $1;	}
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
				insert_symbol(symbol_num, $2, "parameter", $1, scope+1, NULL, 0, funcReg_num);
				strcat(params,$1);
				strcat(params,", ");
				param_index[param_num] = symbol_num;	// Record the index for removing later when function declaration
				
				if(strcmp($1,"int")==0)
				{
					funcReg_type[param_num] = 'I';
				}
				else if(strcmp($1,"float")==0)
				{		
					funcReg_type[param_num] = 'F';
				}
				else if(strcmp($1,"bool")==0)
				{	
					funcReg_type[param_num] = 'Z';
				}
				else if(strcmp($1, "string")==0)
				{	
					funcReg_type[param_num] = 's';
				}
				else if(strcmp($1, "void")==0)
				{	
					funcReg_type[param_num] = 'V';
				}
			
				++symbol_num;
				++param_num;
				++funcReg_num;
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
	: expr
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
				char type[7] = {0};
				strcpy(type, get_type($1, scope, symbol_num));
				if(invoke_flag==1)
				{
					strcat(invoke_arg, type);
					strcat(invoke_arg, ", ");
				}

				int reg = get_register(symbol_table, $1, scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					if(strcmp(type,"int")==0)
					{
						
						if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, $1);
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}
					}
					else if(strcmp(type,"float")==0)
					{	
						if(op_type=='I')
						{
							fprintf(file, "\ti2f\n");
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, $1);
							op_type = 'F';
						}
						else if(op_type == 0 || op_type =='F')
						{
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, $1);
							op_type = 'F';
						}					
					}
					else if(strcmp(type,"bool")==0)
					{
						/*if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, $1);
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, $1);
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}*/

						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, $1);
						op_type = 'Z';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, $1);
						op_type = 's';		
					}
				}
				else	// local variable
				{
					if(strcmp(reg_type[reg],"int")==0)
					{	
						if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tiload %d\n",reg);
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tiload %d\n",reg);
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}
					}
					else if(strcmp(reg_type[reg],"float")==0)
					{
						if(op_type=='I')
						{
							fprintf(file, "\ti2f\n");
							fprintf(file, "\tfload %d\n",reg);
							op_type = 'F';
						}
						else if(op_type == 0 || op_type == 'F')
						{
							fprintf(file, "\tfload %d\n",reg);
							op_type = 'F';
						}
					}
					else if(strcmp(reg_type[reg],"bool")==0)
					{	
						/*if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tiload %d\n",reg);
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tiload %d\n",reg);
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}*/		

						fprintf(file, "\tiload %d\n",reg);
						op_type = 'Z';
					}
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\taload %d\n",reg);
						op_type = 's';
					}
				}
			}
		}
	| I_CONST	
		{	
			
			strcpy(invoke_arg,"int, ");

			if(op_type==0 || op_type=='I')
			{
				$$ = (int)$1;
				fprintf(file, "\tldc %d\n", (int)$1);
				op_type = 'I';
			}
			else if(op_type == 'F')
			{
				$$ = (double)$1;
				fprintf(file, "\tldc %d\n", (int)$1);
				fprintf(file, "\ti2f\n");
				op_type = 'F';
			}
			if(zero_flag == 1)
				zero_flag = 0;
			if($$ == 0)
				zero_flag = 1;
		}
	| F_CONST
		{		
			strcpy(invoke_arg,"float, ");			
			$$ = (double)$1;
			if(op_type=='I')
			{
				fprintf(file, "\ti2f\n");
				fprintf(file, "\tldc %f\n", (double)$1);
				op_type = 'F';
			}
			else if(op_type==0 || op_type =='F')
			{
				fprintf(file, "\tldc %f\n", (double)$1);
				op_type = 'F';
			}
			if(zero_flag == 1)
				zero_flag = 0;
			if($$ == 0)
				zero_flag = 1;
		}
	| STR_CONST	
		{
			strcpy(invoke_arg,"string, ");
			fprintf(file, "\tldc \"%s\"\n", $1);
			op_type = 's';
		}
	| TRUE	
		{	
			strcpy(invoke_arg,"bool, ");
			fprintf(file, "\tldc %d\n", (int)1);
			$$ = (int)1;
			op_type = 'Z';
		}
	| FALSE	
		{	
			strcpy(invoke_arg,"bool, ");
			fprintf(file, "\tldc %d\n", (int)0);
			$$ = (int)0;
			op_type = 'Z';
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
	if(err_flag==2)
		printf("| %s %s", err_type, err_symbol);
	else if(err_flag==3)
		printf("| %s", err_type);
    printf("\n|-----------------------------------------------|\n\n");
	err_flag = 0;	// reset
}

void set_err(int flag, char *type, char *symbol)
{
	err_flag = flag;	// 0: No error;  1: Syntatic error;  2: Undeclared or Redeclared;  3: Arithmetic error or Function error
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
	return entry number if the symbol is a function and it has been forward declared of defined
*/	
int lookup_symbol(char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; ++i)
	{
		if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level==scope_level)
		{
			if(symbol_table[i]->forward==1 || symbol_table[i]->forward==2)
				return i;
			else
				return -2;
		}
		else if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->forward>0)
		{
			return i;
		}
		else if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level<scope_level)
		{
			return -3;
		}
	}

	return -1;
}

void dump_symbol(int symbol_num, int scope) 
{
    int i,j;
	int insert = 0;
	for(i=0; i<symbol_num; ++i)
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
		for(i=0,j=0; i<symbol_num; ++i)
		{
			if(symbol_table[i]->scope_level==scope)
			{
				printf("%-10d%-10s%-12s%-10s%-10d", j, symbol_table[i]->name, symbol_table[i]->entry_type, symbol_table[i]->data_type, symbol_table[i]->scope_level);
				printf("%-s\n",symbol_table[i]->param);
				++j;
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
	for(i=0; i<symbol_num; ++i)
	{
		if(strcmp(name, table[i]->name)==0 && table[i]->scope_level<=scope_level)
		{
			return table[i]->reg;
		}
	}

	return -2;	// Not found
}

char* get_type(char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; ++i)
	{
		if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level<=scope_level)
		{
			return symbol_table[i]->data_type;
		}
	}
	return 0;
}

char* get_attribute(char *name, int scope_level, int symbol_num)
{
	int i = 0;
	for(i=0; i<symbol_num; ++i)
	{
		if(strcmp(name, symbol_table[i]->name)==0 && symbol_table[i]->scope_level<=scope_level)
		{
			return symbol_table[i]->param;
		}
	}
	return 0;
}


/* code generation functions */
void gencode_function() {}
