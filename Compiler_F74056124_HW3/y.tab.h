/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    INC = 263,
    DEC = 264,
    MT = 265,
    LT = 266,
    MTE = 267,
    LTE = 268,
    EQ = 269,
    NE = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    LB = 274,
    RB = 275,
    LCB = 276,
    RCB = 277,
    LSB = 278,
    RSB = 279,
    COMMA = 280,
    PRINT = 281,
    IF = 282,
    ELSE = 283,
    FOR = 284,
    WHILE = 285,
    RET = 286,
    CONT = 287,
    BREAK = 288,
    QUOTA = 289,
    COMMENTLINE = 290,
    NEWLINE = 291,
    SEMICOLON = 292,
    I_CONST = 293,
    F_CONST = 294,
    STR_CONST = 295,
    TRUE = 296,
    FALSE = 297,
    ID = 298,
    INT = 299,
    FLOAT = 300,
    BOOL = 301,
    STRING = 302,
    VOID = 303,
    ASGN = 304,
    ADDASGN = 305,
    SUBASGN = 306,
    MULASGN = 307,
    DIVASGN = 308,
    MODASGN = 309
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define INC 263
#define DEC 264
#define MT 265
#define LT 266
#define MTE 267
#define LTE 268
#define EQ 269
#define NE 270
#define AND 271
#define OR 272
#define NOT 273
#define LB 274
#define RB 275
#define LCB 276
#define RCB 277
#define LSB 278
#define RSB 279
#define COMMA 280
#define PRINT 281
#define IF 282
#define ELSE 283
#define FOR 284
#define WHILE 285
#define RET 286
#define CONT 287
#define BREAK 288
#define QUOTA 289
#define COMMENTLINE 290
#define NEWLINE 291
#define SEMICOLON 292
#define I_CONST 293
#define F_CONST 294
#define STR_CONST 295
#define TRUE 296
#define FALSE 297
#define ID 298
#define INT 299
#define FLOAT 300
#define BOOL 301
#define STRING 302
#define VOID 303
#define ASGN 304
#define ADDASGN 305
#define SUBASGN 306
#define MULASGN 307
#define DIVASGN 308
#define MODASGN 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 84 "compiler_hw3.y" /* yacc.c:1909  */

	int i_val;
    double f_val;
	char string[256];

#line 168 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
