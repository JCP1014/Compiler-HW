/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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
int err_flag = 0;	// 0: No error;  1: syntatic error;  2: semantic error
char err_type[20]  = {0};
char err_symbol[BUF_SIZE] = {0};
char params[BUF_SIZE] = {0};
int dump = 0;
int add_scope = 0;
int func_flag = 0;
int param_index[50] = {0};
int param_num = 0;
int funcReg_num = 0;	// number of variables in function definition
char funcReg_type[50] = {0}; // type of parameters in the form of jasmin type descriptoir
char return_type = 0;
int reg_num = 0;
char reg_type[50][7] = {0};
char op_type = 0;	// operand type
char relation_flag = 0;
int group[50] = {0};
int branch[50] = {0};
int end_flag[50] = {0};
int exit_flag[50] = {0};

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


#line 140 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 76 "compiler_hw3.y" /* yacc.c:355  */

	int i_val;
    double f_val;
	char string[256];

#line 294 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 311 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   128,   132,   133,   134,   135,   136,   137,
     138,   170,   236,   278,   358,   388,   405,   406,   410,   411,
     415,   416,   482,   568,   630,   631,   632,   633,   634,   638,
     642,   643,   647,   648,   652,   653,   661,   669,   677,   685,
     693,   704,   715,   726,   737,   748,   808,   809,   827,   847,
     848,   865,   882,   902,   903,   907,   908,   912,   913,   914,
     918,   919,   953,  1021,  1022,  1027,  1028,  1032,  1075,  1119,
    1128,  1132,  1280,  1338,  1359,  1360,  1361,  1367,  1394,  1401,
    1408,  1415,  1495,  1496,  1497,  1498,  1499,  1506,  1510,  1511,
    1515,  1560,  1561,  1565,  1569,  1683,  1699,  1714,  1718,  1724,
    1735,  1736,  1737,  1738,  1739
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "INC",
  "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "AND", "OR", "NOT", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "PRINT", "IF", "ELSE", "FOR",
  "WHILE", "RET", "CONT", "BREAK", "QUOTA", "COMMENTLINE", "NEWLINE",
  "SEMICOLON", "I_CONST", "F_CONST", "STR_CONST", "TRUE", "FALSE", "ID",
  "INT", "FLOAT", "BOOL", "STRING", "VOID", "ASGN", "ADDASGN", "SUBASGN",
  "MULASGN", "DIVASGN", "MODASGN", "$accept", "program", "stat",
  "declaration", "expression_stat", "expr", "assignment_expr",
  "opassign_operand", "opassign_operator", "conditional_expr",
  "logical_or_expr", "logical_and_expr", "relational_expr",
  "relational_operand", "additive_expr", "multiplicative_expr",
  "cast_expr", "unary_expr", "unary_operator", "postfix_expr",
  "primary_expr", "compound_stat", "jump_stat", "print_func",
  "initializer", "parameter_list", "parameter", "argument_list",
  "argument", "val", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -58,    31,   -58,   -58,   -58,   -58,   109,   -15,    -2,    25,
      28,   126,    14,    23,   -58,   -58,   -58,   168,   236,   -58,
     270,   276,    85,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -21,   -58,   261,   -58,    75,    92,   -58,   282,    26,
      83,   -58,   -58,   167,   -58,   -58,   -58,   -58,   -58,   -58,
      58,   -11,   100,    38,   161,   173,   173,   -58,   -19,   -58,
     -58,   -58,   -58,   155,   173,   173,   -58,   -58,   -58,   -58,
     -58,   -58,   173,   184,   184,    64,    64,    64,    64,    64,
      64,   167,   167,   167,   167,   167,   -58,   -58,   -58,   -58,
      37,   -58,   -17,   -58,   167,   -58,   113,   120,   122,   123,
     140,     8,   164,   -58,   -58,   121,   238,   -58,   -58,   -58,
     -58,   260,    92,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    83,    83,   -58,   -58,   -58,
      -8,   -58,   214,   -58,   173,   -58,   -58,   -58,   -58,   141,
     151,   -58,   173,   -18,   239,   -58,   118,    11,   104,   153,
     224,   230,    72,   121,   182,   240,   -58,   -58,   -58,   -58,
     -58,   -10,   272,   -58,   -58,   -58,   199,   -58,   -58,   -58,
     -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    57,    58,    59,     0,    73,     0,     0,
       0,     0,     0,     0,     9,    10,    16,    95,    96,    97,
      98,    99,    94,   100,   101,   102,   103,   104,     2,     4,
       5,     0,    18,     0,    20,    29,    30,    32,     0,    34,
      46,    49,    53,     0,    55,    60,     6,     7,     8,    65,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    74,
      75,    63,    64,     0,     0,     0,    17,    27,    28,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    98,    99,
      94,    56,     0,    66,     0,    69,     0,     0,     0,     0,
       0,     0,     0,    77,    61,    93,     0,    91,    21,    19,
      22,    94,    31,    33,    41,    42,    43,    44,    45,    38,
      37,    40,    39,    35,    36,    47,    48,    50,    51,    52,
       0,    13,     0,    54,     0,    78,    79,    80,    81,     0,
       0,    62,     0,     0,     0,    88,     0,    95,    96,    97,
      98,    99,    94,    87,     0,     0,    67,    70,    92,    72,
      15,     0,     0,    90,    12,    11,     0,    71,    14,    89,
      68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,    -1,   -57,   -58,   -58,   -58,
     -58,   148,   154,   223,   -58,    29,   -42,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,    67,   -58,    88,   -58,
     303
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    28,    29,    30,   105,    32,    33,    72,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   154,   144,   145,   106,   107,    49,
     146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    91,   130,   159,    65,    51,    65,   108,   109,    93,
      58,   167,   143,    53,    65,   110,    66,    54,   103,   160,
     131,   -41,   -41,   -41,   -41,   -41,   -41,   168,   139,    81,
      82,     2,   132,    65,     3,     4,    23,    24,    25,    26,
      27,   127,   128,   129,    55,    61,    62,    56,   -82,     5,
       6,    59,   133,     7,   101,   102,    63,     8,     9,    95,
      60,    10,    11,    12,    13,    96,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      61,    62,   -45,   -45,   -45,   -45,   -45,   -45,    83,    84,
      85,    63,    73,    61,    62,   -45,   -45,   -45,   -45,   -45,
     -45,    92,   114,   115,    63,   116,   117,   118,    74,   -86,
     125,   126,     3,     4,   -42,   -42,   -42,   -42,   -42,   -42,
      94,    64,   -23,   -23,   -23,   -23,   -23,     5,     6,     3,
       4,   153,   134,   155,    64,   -23,   -23,   -23,   -23,   -23,
     135,   -83,   136,   137,     5,     6,    65,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,     4,
     138,   163,   156,    57,    17,    18,    19,    20,    21,    22,
       3,     4,   157,     5,     6,   104,     3,     4,   -41,   -41,
     -41,   -41,   -41,   -41,   140,     5,     6,     3,     4,    65,
     164,     5,     6,    17,    18,    19,    20,    21,    22,    97,
      98,    99,     5,     6,   100,    86,    87,    19,    88,    89,
      90,    17,    18,    19,    20,    21,    22,     3,     4,   165,
     170,   112,    17,    18,    19,    20,    21,   111,   113,   169,
     158,     0,     5,     6,   -43,   -43,   -43,   -43,   -43,   -43,
     -44,   -44,   -44,   -44,   -44,   -44,   -42,   -42,   -42,   -42,
     -42,   -42,   147,   148,   149,   150,   151,   152,   141,   161,
     166,   -84,     0,   142,   162,    65,     0,   -85,    61,    62,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,    63,
     -43,   -43,   -43,   -43,   -43,   -43,   -44,   -44,   -44,   -44,
     -44,   -44,    75,    76,    77,    78,    79,    80,   119,   120,
     121,   122,   123,   124,    50,     0,     0,     0,     0,    52,
       0,    67,    68,    69,    70,    71,    23,    24,    25,    26,
      27
};

static const yytype_int16 yycheck[] =
{
       1,    43,    19,    21,    25,     6,    25,    64,    65,    20,
      11,    21,    20,    28,    25,    72,    37,    19,    37,    37,
      37,    10,    11,    12,    13,    14,    15,    37,    20,     3,
       4,     0,    49,    25,     3,     4,    44,    45,    46,    47,
      48,    83,    84,    85,    19,     8,     9,    19,    37,    18,
      19,    37,    94,    22,    55,    56,    19,    26,    27,    21,
      37,    30,    31,    32,    33,    27,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       8,     9,    10,    11,    12,    13,    14,    15,     5,     6,
       7,    19,    17,     8,     9,    10,    11,    12,    13,    14,
      15,    43,    38,    39,    19,    41,    42,    43,    16,    37,
      81,    82,     3,     4,    10,    11,    12,    13,    14,    15,
      20,    49,    50,    51,    52,    53,    54,    18,    19,     3,
       4,   132,    19,   134,    49,    50,    51,    52,    53,    54,
      20,    37,    20,    20,    18,    19,    25,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     3,     4,
      20,    43,    21,    37,    38,    39,    40,    41,    42,    43,
       3,     4,    21,    18,    19,    20,     3,     4,    10,    11,
      12,    13,    14,    15,    20,    18,    19,     3,     4,    25,
      37,    18,    19,    38,    39,    40,    41,    42,    43,    38,
      39,    40,    18,    19,    43,    38,    39,    40,    41,    42,
      43,    38,    39,    40,    41,    42,    43,     3,     4,    37,
      21,    73,    38,    39,    40,    41,    42,    43,    74,   162,
     142,    -1,    18,    19,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    38,    39,    40,    41,    42,    43,    20,    20,
      20,    37,    -1,    25,    25,    25,    -1,    37,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    75,    76,
      77,    78,    79,    80,     1,    -1,    -1,    -1,    -1,     6,
      -1,    50,    51,    52,    53,    54,    44,    45,    46,    47,
      48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,     0,     3,     4,    18,    19,    22,    26,    27,
      30,    31,    32,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    57,    58,
      59,    60,    61,    62,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    84,
      85,    60,    85,    28,    19,    19,    19,    37,    60,    37,
      37,     8,     9,    19,    49,    25,    37,    50,    51,    52,
      53,    54,    63,    17,    16,    10,    11,    12,    13,    14,
      15,     3,     4,     5,     6,     7,    38,    39,    41,    42,
      43,    71,    43,    20,    20,    21,    27,    38,    39,    40,
      43,    60,    60,    37,    20,    60,    82,    83,    61,    61,
      61,    43,    66,    67,    38,    39,    41,    42,    43,    68,
      68,    68,    68,    68,    68,    70,    70,    71,    71,    71,
      19,    37,    49,    71,    19,    20,    20,    20,    20,    20,
      20,    20,    25,    20,    80,    81,    85,    38,    39,    40,
      41,    42,    43,    60,    79,    60,    21,    21,    83,    21,
      37,    20,    25,    43,    37,    37,    20,    21,    37,    81,
      21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    82,    82,    83,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     3,     6,     5,     1,     2,     1,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     4,     1,     2,     1,     1,     1,
       1,     3,     4,     2,     2,     1,     3,     5,     7,     3,
       5,     6,     5,     1,     2,     2,     2,     3,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
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
		}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-3].string), scope, symbol_num) != -2)
			{
				
				if(scope==0)
				{
					insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, -1);
					if(strcmp((yyvsp[-4].string),"int")==0)
						fprintf(file,".field public static %s I = %d\n", (yyvsp[-3].string), (int)(yyvsp[-1].f_val));
					else if(strcmp((yyvsp[-4].string), "float")==0)
						fprintf(file,".field public static %s F = %f\n", (yyvsp[-3].string), (double)(yyvsp[-1].f_val));
					else if(strcmp((yyvsp[-4].string), "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", (yyvsp[-3].string), (int)(yyvsp[-1].f_val));	
				}
				else
				{
					if(func_flag==1)
					{
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, funcReg_num);
						if(strcmp((yyvsp[-4].string),"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)(yyvsp[-1].f_val), funcReg_num);
						}
						else if(strcmp((yyvsp[-4].string), "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)(yyvsp[-1].f_val), funcReg_num);
						}
						else if(strcmp((yyvsp[-4].string), "bool")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)(yyvsp[-1].f_val), funcReg_num);
						}
						++funcReg_num;
					}
					else
					{	
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, reg_num);
						if(strcmp((yyvsp[-4].string),"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)(yyvsp[-1].f_val), reg_num);
						}
						else if(strcmp((yyvsp[-4].string), "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)(yyvsp[-1].f_val), reg_num);
						}
						else if(strcmp((yyvsp[-4].string), "bool")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)(yyvsp[-1].f_val), reg_num);
						}
						++reg_num;
					}
					
				}
				++symbol_num;
			}
			else 
			{
				set_err(2,"Redeclared variable",(yyvsp[-3].string));
			}
		}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 237 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-3].string), scope, symbol_num) != -2)
			{
				if(scope==0)
				{
					insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, -1);
					if(strcmp((yyvsp[-4].string),"string")==0)
					{	
						fprintf(file,".field public static %s Ljava/lang/String; = \"%s\"\n", (yyvsp[-3].string), (yyvsp[-1].string));	
					}
				}
				else
				{
					if(func_flag == 1)
					{
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, funcReg_num);
						if(strcmp((yyvsp[-4].string),"string")==0)
						{	
							fprintf(file,"\tldc \"%s\"\n"
									"\tastore %d\n", (yyvsp[-1].string), funcReg_num);	
						}
						++funcReg_num;
					}
					else
					{
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, reg_num);
						if(strcmp((yyvsp[-4].string),"string")==0)
						{	
							fprintf(file,"\tldc \"%s\"\n"
									"\tastore %d\n", (yyvsp[-1].string), reg_num);	
						}
						++reg_num;
					}
				}
				++symbol_num;
			}
			else 
			{
				set_err(2,"Redeclared variable",(yyvsp[-3].string));
			}
		}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 279 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-1].string), scope, symbol_num) != -2)
			{
				if(scope==0)
				{
					insert_symbol(symbol_num, (yyvsp[-1].string), "variable", (yyvsp[-2].string), scope, NULL, 0, -1);
					if(strcmp((yyvsp[-2].string),"int")==0)
						fprintf(file,".field public static %s I = %d\n", (yyvsp[-1].string), (int)0);
					else if(strcmp((yyvsp[-2].string), "float")==0)
						fprintf(file,".field public static %s F\n", (yyvsp[-1].string));
					else if(strcmp((yyvsp[-2].string), "bool")==0)
						fprintf(file,".field public static %s Z = %d\n", (yyvsp[-1].string), (int)0);
					else if(strcmp((yyvsp[-2].string), "void")==0)
						fprintf(file,".field public static %s V\n", (yyvsp[-1].string));
					else if(strcmp((yyvsp[-2].string), "string")==0)
						fprintf(file,".field public static %s Ljava/lang/String; = \"\"\n", (yyvsp[-1].string));
	
				}
				else
				{
					if(func_flag == 1)
					{
						insert_symbol(symbol_num, (yyvsp[-1].string), "variable", (yyvsp[-2].string), scope, NULL, 0, funcReg_num);
						if(strcmp((yyvsp[-2].string),"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, funcReg_num);
						}
						else if(strcmp((yyvsp[-2].string), "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)0, funcReg_num);
						}
						else if(strcmp((yyvsp[-2].string), "bool")==0)
						{
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, funcReg_num);
						}
						else if(strcmp((yyvsp[-2].string), "string")==0)
						{	
							fprintf(file,"\tldc \"\"\n"
										"\tastore %d\n", funcReg_num);
						}
						++funcReg_num;
					}
					else
					{
						insert_symbol(symbol_num, (yyvsp[-1].string), "variable", (yyvsp[-2].string), scope, NULL, 0, reg_num);
						if(strcmp((yyvsp[-2].string),"int")==0)
						{	
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, reg_num);
						}
						else if(strcmp((yyvsp[-2].string), "float")==0)
						{	
							fprintf(file,"\tldc %f\n"
										"\tfstore %d\n", (double)0, reg_num);
						}
						else if(strcmp((yyvsp[-2].string), "bool")==0)
						{
							fprintf(file,"\tldc %d\n"
										"\tistore %d\n", (int)0, reg_num);
						}
						else if(strcmp((yyvsp[-2].string), "string")==0)
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
				set_err(2,"Redeclared variable",(yyvsp[-1].string));
			}
		}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			int lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",(yyvsp[-4].string));
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
		
			lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			/* Insert funcion */
			if(lookup_result != -2 && lookup_result < 0)
			{
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, (yyvsp[-4].string), "function", (yyvsp[-5].string), scope, temp, 1, -1);
				++symbol_num;
			}
			memset(params,0,sizeof(params));
			memset(param_index,0,sizeof(param_index));
		}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 389 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num);
			if(lookup_result == -2 || lookup_result >= 0)
			{
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}
			else
			{
				insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, NULL, 1, -1);
				++symbol_num;
			}
		}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 415 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 417 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-2].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[-2].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[-2].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{
					fprintf(file, "\tputstatic %s/%s ", CLASS_NAME, (yyvsp[-2].string));
					char type[7] = {0};
					strcpy(type, get_type((yyvsp[-2].string), scope, symbol_num));
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
						if(op_type == 'I')
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
						else if(op_type == 'I')
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
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 483 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
			{	
				if(strcmp((yyvsp[-1].string), "+=")==0)
					fprintf(file, "\tiadd\n");
				else if(strcmp((yyvsp[-1].string), "-=")==0)
					fprintf(file, "\tisub\n");
				else if(strcmp((yyvsp[-1].string), "*=")==0)
					fprintf(file, "\timul\n");
				else if(strcmp((yyvsp[-1].string), "/=")==0)
					fprintf(file, "\tidiv\n");
				else if(strcmp((yyvsp[-1].string), "%=")==0)
					fprintf(file, "\tirem\n");
			}
			else if(op_type == 'F')
			{
				if(strcmp((yyvsp[-1].string), "+=")==0)
					fprintf(file, "\tfadd\n");
				else if(strcmp((yyvsp[-1].string), "-=")==0)
					fprintf(file, "\tfsub\n");
				else if(strcmp((yyvsp[-1].string), "*=")==0)
					fprintf(file, "\tfmul\n");
				else if(strcmp((yyvsp[-1].string), "/=")==0)
					fprintf(file, "\tfdiv\n");
			}
				
			int reg = get_register(symbol_table, (yyvsp[-2].string), scope, symbol_num);
			if(reg==-1)		// global variable
			{
				fprintf(file, "\tputstatic %s/%s ", CLASS_NAME, (yyvsp[-2].string));
				char type[7] = {0};
				strcpy(type, get_type((yyvsp[-2].string), scope, symbol_num));
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
					if(op_type == 'I')
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
					else if(op_type == 'I')
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
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 569 "compiler_hw3.y" /* yacc.c:1646  */
    {
			strcpy((yyval.string), (yyvsp[0].string));
			int lookup_result = lookup_symbol((yyvsp[0].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[0].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					char type[7] = {0};
					strcpy(type, get_type((yyvsp[0].string), scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[0].string));
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{	
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, (yyvsp[0].string));
							op_type = 'F';				
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, (yyvsp[0].string));
						op_type = 'I';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, (yyvsp[0].string));		
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
						fprintf(file, "\taload %d\n",reg);
					}
				}
			}
		}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 630 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "*="); }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 631 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "/="); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 632 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "%="); }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 633 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string),"+="); }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 634 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "-="); }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 638 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 642 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 647 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 652 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 654 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'E';
		}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 662 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'N';
		}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'l';
		}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 678 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'm';
		}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 686 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'L';
		}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 694 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I')
				fprintf(file, "\tisub\n");
			else if(op_type == 'F')
				fprintf(file, "\tfsub\n");
			relation_flag = 'M';
		}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 705 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(end_flag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				end_flag[scope-1] = 0; 
			}
			fprintf(file, "\tldc %d\n", (yyvsp[0].i_val));
			op_type = 'I';
		}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 716 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(end_flag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				end_flag[scope-1] = 0; 
			}
			fprintf(file, "\tldc %f\n", (yyvsp[0].f_val));
			op_type = 'F';
		}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 727 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(end_flag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				end_flag[scope-1] = 0; 
			}
			fprintf(file, "\tldc 1\n");
			op_type = 'I';
		}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 738 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(end_flag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				end_flag[scope-1] = 0; 
			}
			fprintf(file, "\tldc 0\n");
			op_type = 'I';
		}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 749 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(end_flag[scope-1]==1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				end_flag[scope-1] = 0; 
			}

			int lookup_result = lookup_symbol((yyvsp[0].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[0].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					char type[7] = {0};
					strcpy(type, get_type((yyvsp[0].string), scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[0].string));
						op_type = 'I';
					}
					else if(strcmp(type,"float")==0)
					{	
						fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, (yyvsp[0].string));				
						op_type = 'F';
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, (yyvsp[0].string));
						op_type = 'I';
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
				}
			}
		}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 808 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 810 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.f_val) = (yyvsp[-2].f_val) + (yyvsp[0].f_val);
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
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 828 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.f_val) = (yyvsp[-2].f_val) - (yyvsp[0].f_val);
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
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 847 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 849 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.f_val) = (yyvsp[-2].f_val) * (yyvsp[0].f_val);
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
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 866 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.f_val) = (yyvsp[-2].f_val) / (yyvsp[0].f_val);
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
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 883 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			switch(op_type)
			{
				case 'I':
				{
					(yyval.f_val) = (int)(yyvsp[-2].f_val) % (int)(yyvsp[0].f_val);
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
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 902 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 907 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 918 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 920 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-2].string), scope, symbol_num);
			if(lookup_result == -1)
			{	
				set_err(2,"Undeclared function",(yyvsp[-2].string));
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s()", CLASS_NAME, (yyvsp[-2].string));
				char type[7] = {0};
				strcpy(type, get_type((yyvsp[-2].string),scope,symbol_num));
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
		}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 954 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared function",(yyvsp[-3].string));
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s(", CLASS_NAME, (yyvsp[-3].string));
				
				char temp[256] = {0};
				strcpy(temp, get_attribute((yyvsp[-3].string), scope, symbol_num));
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
				strcpy(type, get_type((yyvsp[-3].string),scope,symbol_num));
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

		}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1027 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val);  }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1033 "compiler_hw3.y" /* yacc.c:1646  */
    {
			++scope;
			++group[scope-1];
			branch[scope-1] = 1;
			end_flag[scope-1] = 1;
			exit_flag[scope-1] = 1;
			switch(relation_flag)
			{
				case 'E':
				{
					fprintf(file, "\tifeq LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'N':
				{
					fprintf(file, "\tifne LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'l':
				{
					fprintf(file, "\tiflt LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'm':
				{
					fprintf(file, "\tifgt LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'L':
				{
					fprintf(file, "\tifle LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'M':
				{
					fprintf(file, "\tifge LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
			}
			fprintf(file, "\tgoto END%d_%d_%d\n", scope-1, group[scope-1],branch[scope-1]);
			fprintf(file, "LABEL%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
		}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1076 "compiler_hw3.y" /* yacc.c:1646  */
    {
			dump = 1;
			add_scope = 1;
			
			++branch[scope-1];
			end_flag[scope-1] = 1;
			switch(relation_flag)
			{
				case 'E':
				{
					fprintf(file, "\tifeq LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'N':
				{
					fprintf(file, "\tifne LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'l':
				{
					fprintf(file, "\tiflt LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'm':
				{
					fprintf(file, "\tifgt LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'L':
				{
					fprintf(file, "\tifle LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
				case 'M':
				{
					fprintf(file, "\tifge LABEL%d_%d_%d\n", scope-1, group[scope-1], branch[scope-1]);
					break;
				}
			}
			fprintf(file, "\tgoto END%d_%d_%d\n", scope-1, group[scope-1],branch[scope-1]);
			fprintf(file, "LABEL%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);

		}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1120 "compiler_hw3.y" /* yacc.c:1646  */
    {
			dump = 1;
			add_scope = 1;
			
			end_flag[scope-1] = 0;
			fprintf(file, "\tgoto  EXIT%d_%d\n", scope-1, group[scope-1]);
			fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
		}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1129 "compiler_hw3.y" /* yacc.c:1646  */
    {
			++scope;
		}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1133 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			if(lookup_result == -1 || lookup_result == -3)	// If function undeclared, insert it and its parameters
			{
				func_flag = 1;
				char temp[256]= {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, (yyvsp[-4].string), "function", (yyvsp[-5].string), scope, temp, 0, -1);
				++symbol_num;
				memset(params,0,sizeof(params));
				
				fprintf(file, ".method public static %s(",(yyvsp[-4].string));
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
				if(strcmp((yyvsp[-5].string),"int")==0)
				{
					return_type = 'I';
					fprintf(file, ")I\n");
				}
				else if(strcmp((yyvsp[-5].string),"float")==0)
				{
					return_type = 'F';
					fprintf(file, ")F\n");
				}
				else if(strcmp((yyvsp[-5].string),"bool")==0)
				{
					return_type = 'Z';
					fprintf(file, ")Z\n");
				}
				else if(strcmp((yyvsp[-5].string), "string")==0)
				{
					return_type = 's';
					fprintf(file, ")Ljava/lang/String;\n");
				}
				else if(strcmp((yyvsp[-5].string), "void")==0)
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
			else if(lookup_result >= 0)	// If function forward declared, insert its attribute
			{
				func_flag = 1;
				if(symbol_table[lookup_result]->param==NULL)
				{
					char temp[256] = {0};
					strncpy(temp,params,strlen(params)-2);
					strcpy(symbol_table[lookup_result]->param, temp);
					memset(params,0,sizeof(params));
				}

				fprintf(file, ".method public static %s(",(yyvsp[-4].string));
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
				if(strcmp((yyvsp[-5].string),"int")==0)
				{
					return_type = 'I';
					fprintf(file, ")I\n");
				}
				else if(strcmp((yyvsp[-5].string),"float")==0)
				{
					return_type = 'F';
					fprintf(file, ")F\n");
				}
				else if(strcmp((yyvsp[-5].string),"bool")==0)
				{
					return_type = 'Z';
					fprintf(file, ")Z\n");
				}
				else if(strcmp((yyvsp[-5].string), "string")==0)
				{
					return_type = 's';
					fprintf(file, ")Ljava/lang/String;\n");
				}
				else if(strcmp((yyvsp[-5].string), "void")==0)
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
			else
			{
				set_err(2,"Redeclared function",(yyvsp[-4].string));
			}
	
			++scope;
	}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1281 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num); 
			if(lookup_result == -1 || lookup_result == -3)
			{
				func_flag = 1;
				insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, NULL, 0, -1);
				++symbol_num;

				if(strcmp((yyvsp[-3].string),"main")==0)
				{
					fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
									".limit stack 50\n"
									".limit locals 50\n");	
				}
				else
				{
					fprintf(file, ".method public static %s()", (yyvsp[-3].string));
					if(strcmp((yyvsp[-4].string),"int")==0)
					{
						return_type = 'I';
						fprintf(file, ")I\n");
					}
					else if(strcmp((yyvsp[-4].string),"float")==0)
					{
						return_type = 'F';
						fprintf(file, ")F\n");
					}
					else if(strcmp((yyvsp[-4].string),"bool")==0)
					{
						return_type = 'Z';
						fprintf(file, ")Z\n");
					}
					else if(strcmp((yyvsp[-4].string), "string")==0)
					{
						return_type = 's';
						fprintf(file, ")Ljava/lang/String;\n");
					}
					else if(strcmp((yyvsp[-4].string), "void")==0)
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
			
			else if(lookup_result == -2)
			{
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}

			++scope;
		}
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1339 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			dump = 1;	// flag to indicate to dump table when meet NEWLINE later
			if(end_flag[scope-1] == 1)
			{
				printf("XXXXXXXXXXXXXXXXXXXX\n");
				//fprintf(file, "\tgoto EXIT%d_%d\n", scope, group[scope]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, group[scope-1], branch[scope-1]);
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, group[scope-1]);
				end_flag[scope-1] = 0; 
			}
			if(exit_flag[scope-1] == 1)
			{
				fprintf(file, "EXIT%d_%d:\n", scope-1, group[scope-1]);
				exit_flag[scope-1] = 0;
			}
		}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1362 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\treturn\n"
							".end method\n");
			return_type = 0;
		}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1368 "compiler_hw3.y" /* yacc.c:1646  */
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
				fprintf(file, "\tareturn\n"
							".end method\n");
			}
			return_type = 0;
		}
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1395 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc %d\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(I)V\n", (yyvsp[-1].i_val));
		}
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1402 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc %f\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(F)V\n", (yyvsp[-1].f_val));
		}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1409 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc \"%s\"\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", (yyvsp[-1].string));
		}
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1416 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[-1].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[-1].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[-1].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{
					char type[7] = {0};
					strcpy(type, get_type((yyvsp[-1].string), scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s I\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", (yyvsp[-1].string));
					}
					else if(strcmp(type,"float")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s F\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(F)V\n", (yyvsp[-1].string));				
					}
					else if(strcmp(type,"bool")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s I\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(I)V\n", (yyvsp[-1].string));
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic compiler_hw3/%s Ljava/lang/String;\n"
									"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", (yyvsp[-1].string));		
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
#line 3053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1495 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = (yyvsp[0].i_val);	}
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1496 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = (yyvsp[0].f_val);	}
#line 3065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1497 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = 1;	}
#line 3071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1498 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = 0;	}
#line 3077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1500 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
		}
#line 3088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1516 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope+1, symbol_num) != -2)
			{
				insert_symbol(symbol_num, (yyvsp[0].string), "parameter", (yyvsp[-1].string), scope+1, NULL, 0, funcReg_num);
				strcat(params,(yyvsp[-1].string));
				strcat(params,", ");
				param_index[param_num] = symbol_num;	// Record the index for removing later when function declaration
				
				if(strcmp((yyvsp[-1].string),"int")==0)
				{
					funcReg_type[param_num] = 'I';
				}
				else if(strcmp((yyvsp[-1].string),"float")==0)
				{		
					funcReg_type[param_num] = 'F';
				}
				else if(strcmp((yyvsp[-1].string),"bool")==0)
				{	
					funcReg_type[param_num] = 'Z';
				}
				else if(strcmp((yyvsp[-1].string), "string")==0)
				{	
					funcReg_type[param_num] = 's';
				}
				else if(strcmp((yyvsp[-1].string), "void")==0)
				{	
					funcReg_type[param_num] = 'V';
				}
			
				++symbol_num;
				++param_num;
				++funcReg_num;
			}
			else
			{
				set_err(2,"Redeclared variable",(yyvsp[0].string));
				strcat(params,(yyvsp[-1].string));
				strcat(params,", ");

			}
		}
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1570 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[0].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[0].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					char type[7] = {0};
					strcpy(type, get_type((yyvsp[0].string), scope, symbol_num));
					if(strcmp(type,"int")==0)
					{
						
						if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[0].string));
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[0].string));
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}
					}
					else if(strcmp(type,"float")==0)
					{	
						if(op_type=='I')
						{
							fprintf(file, "\ti2f\n");
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, (yyvsp[0].string));
							op_type = 'F';
						}
						else if(op_type == 0 || op_type =='F')
						{
							fprintf(file, "\tgetstatic %s/%s F\n", CLASS_NAME, (yyvsp[0].string));
							op_type = 'F';
						}					
					}
					else if(strcmp(type,"bool")==0)
					{
						if(op_type==0 || op_type=='I')
						{
							fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, (yyvsp[0].string));
							op_type = 'I';
						}
						else if(op_type == 'F')
						{
							fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, (yyvsp[0].string));
							fprintf(file, "\ti2f\n");
							op_type = 'F';
						}

					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, (yyvsp[0].string));		
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
					else if(strcmp(reg_type[reg], "string")==0)
					{	
						fprintf(file, "\taload %d\n",reg);
					}
				}
			}
		}
#line 3252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1684 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			if(op_type==0 || op_type=='I')
			{
				(yyval.f_val) = (int)(yyvsp[0].i_val);
				fprintf(file, "\tldc %d\n", (int)(yyvsp[0].i_val));
				op_type = 'I';
			}
			else if(op_type == 'F')
			{
				(yyval.f_val) = (double)(yyvsp[0].i_val);
				fprintf(file, "\tldc %d\n", (int)(yyvsp[0].i_val));
				fprintf(file, "\ti2f\n");
				op_type = 'F';
			}
		}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1700 "compiler_hw3.y" /* yacc.c:1646  */
    {		
			(yyval.f_val) = (double)(yyvsp[0].f_val);
			if(op_type=='I')
			{
				fprintf(file, "\ti2f\n");
				fprintf(file, "\tldc %f\n", (double)(yyvsp[0].f_val));
				op_type = 'F';
			}
			else if(op_type==0 || op_type =='F')
			{
				fprintf(file, "\tldc %f\n", (double)(yyvsp[0].f_val));
				op_type = 'F';
			}
		}
#line 3291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1715 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc \"%s\"\n", (yyvsp[0].string));
		}
#line 3299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1719 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			fprintf(file, "\tldc %d\n", (int)1);
			(yyval.f_val) = (int)1;
			op_type = 'I';
		}
#line 3309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1725 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			fprintf(file, "\tldc %d\n", (int)0);
			(yyval.f_val) = (int)0;
			op_type = 'I';
		}
#line 3319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1735 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "int"); }
#line 3325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1736 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "float"); }
#line 3331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1737 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "bool"); }
#line 3337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1738 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "string"); }
#line 3343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1739 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "void"); }
#line 3349 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3353 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1742 "compiler_hw3.y" /* yacc.c:1906  */


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
	for(i=0; i<symbol_num; ++i)
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

	return -1;
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