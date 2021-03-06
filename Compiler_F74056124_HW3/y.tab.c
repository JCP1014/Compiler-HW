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
int gencode_flag = 1;
int while_flag = 0;

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


#line 148 "y.tab.c" /* yacc.c:339  */

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
#line 84 "compiler_hw3.y" /* yacc.c:355  */

	int i_val;
    double f_val;
	char string[256];

#line 302 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 319 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
       0,   136,   136,   137,   141,   142,   143,   144,   145,   146,
     147,   180,   246,   288,   411,   491,   536,   564,   565,   569,
     570,   574,   575,   641,   746,   810,   811,   812,   813,   814,
     818,   822,   823,   827,   828,   832,   833,   844,   855,   866,
     877,   888,   902,   913,   924,   935,   946,  1006,  1007,  1025,
    1045,  1046,  1063,  1085,  1111,  1112,  1116,  1117,  1121,  1122,
    1123,  1127,  1128,  1172,  1251,  1283,  1318,  1326,  1327,  1331,
    1374,  1419,  1428,  1470,  1670,  1844,  1870,  1880,  1881,  1882,
    1895,  1954,  1960,  1971,  1978,  1985,  1992,  2072,  2073,  2074,
    2075,  2079,  2080,  2084,  2129,  2130,  2134,  2138,  2265,  2287,
    2307,  2313,  2320,  2332,  2333,  2334,  2335,  2336
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
  "cast_expr", "unary_expr", "unary_operator", "postfix_expr", "func_id",
  "primary_expr", "compound_stat", "while", "jump_stat", "if", "elseif",
  "print_func", "initializer", "parameter_list", "parameter",
  "argument_list", "argument", "val", "type", YY_NULLPTR
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

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -91

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,    27,   -43,   -43,   -43,   -43,    85,   -24,    33,   -43,
     -43,   131,    62,    71,   -43,   -43,   -43,   246,   252,   -43,
     258,   264,    68,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -19,   -43,   113,   -43,    92,   126,   -43,   270,     4,
     185,   -43,   -43,   143,   -43,    97,   -43,   -43,   132,   -43,
     133,   -43,   -43,   102,    66,   138,    20,   141,    58,   -43,
      -8,   -43,   -43,   -43,   -43,   184,   184,   -43,   -43,   -43,
     -43,   -43,   -43,   184,   190,   190,   254,   254,   254,   254,
     254,   254,   143,   143,   143,   143,   143,   -43,   -43,   -43,
     -43,    42,   -43,   137,   184,   184,   -17,   -43,   143,   -43,
     -43,   184,   169,   175,   176,   177,   -43,   -43,   -43,   -43,
     236,   126,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   185,   185,   -43,   -43,   -43,   -43,
     173,    70,   -43,    82,   118,   -11,   -43,   196,   -43,   119,
     -43,   -43,   -43,   -43,   -43,   184,   180,   183,   -18,   128,
     -43,   162,     1,    11,   170,   100,   206,     3,   174,   189,
     -43,   -43,   -43,   -43,   -43,    18,   255,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    58,    59,    60,     0,    75,     0,    81,
      76,     0,     0,     0,     9,    10,    17,    98,    99,   100,
     101,   102,    97,   103,   104,   105,   106,   107,     2,     4,
       5,     0,    19,     0,    21,    30,    31,    33,     0,    35,
      47,    50,    54,     0,    56,     0,    61,     6,     0,     7,
       0,     8,    67,     0,     0,     0,     0,     0,     0,    79,
       0,    77,    78,    64,    65,     0,     0,    18,    28,    29,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   101,
     102,    97,    57,     0,     0,     0,     0,    68,     0,    71,
      82,     0,     0,     0,     0,     0,    80,    22,    20,    23,
      97,    32,    34,    42,    43,    44,    45,    46,    39,    38,
      41,    40,    36,    37,    48,    49,    51,    52,    53,    62,
      96,     0,    94,     0,     0,     0,    14,     0,    55,     0,
      83,    84,    85,    86,    63,     0,     0,     0,     0,     0,
      91,     0,    98,    99,   100,   101,   102,     0,     0,     0,
      95,    72,    69,    74,    16,     0,     0,    93,    12,    13,
      11,    70,    73,    15,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   -43,   -43,    -1,    19,   -43,   -43,   -43,
     -43,   139,   165,   210,   -43,    23,   -42,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
      40,   -43,    67,   -43,   153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    28,    29,    30,   130,    32,    33,    73,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    57,    51,   158,   149,
     150,   131,   132,    52,   151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    92,   135,   163,    56,    54,    66,    82,    83,   148,
      60,   -42,   -42,   -42,   -42,   -42,   -42,    66,    67,   164,
     136,   -43,   -43,   -43,   -43,   -43,   -43,     2,    66,   106,
       3,     4,   137,    23,    24,    25,    26,    27,   -87,   172,
     169,    99,   126,   127,   128,     5,     6,   100,   -88,     7,
      63,    64,    58,     8,     9,   173,   138,    10,    11,    12,
      13,   -66,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    63,    64,   -46,   -46,
     -46,   -46,   -46,   -46,   107,   108,    97,   -66,     3,     4,
     144,    66,   109,   133,   134,   145,   102,   103,   104,    61,
     139,   105,   146,     5,     6,   124,   125,    66,    62,    74,
     -44,   -44,   -44,   -44,   -44,   -44,    93,    65,   -24,   -24,
     -24,   -24,   -24,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     3,     4,   157,   -89,   147,   159,
       3,     4,    75,    66,    66,    96,     3,     4,   165,     5,
       6,    94,    95,   166,    53,     5,     6,   129,    98,    55,
     101,     5,     6,    68,    69,    70,    71,    72,    59,    17,
      18,    19,    20,    21,    22,    17,    18,    19,    20,    21,
      22,    87,    88,    19,    89,    90,    91,     3,     4,   140,
      84,    85,    86,     3,     4,   141,   142,   143,    66,     3,
       4,   161,     5,     6,   162,   167,   174,   168,     5,     6,
     171,   170,   160,   111,     5,     6,   -45,   -45,   -45,   -45,
     -45,   -45,    17,    18,    19,    20,    21,    22,    17,    18,
      19,    20,    21,   110,   152,   153,   154,   155,   156,    22,
     112,     0,     0,   -90,    63,    64,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -66,   -42,   -42,   -42,   -42,
     -42,   -42,   -43,   -43,   -43,   -43,   -43,   -43,   -44,   -44,
     -44,   -44,   -44,   -44,   -45,   -45,   -45,   -45,   -45,   -45,
      76,    77,    78,    79,    80,    81,   118,   119,   120,   121,
     122,   123,   113,   114,     0,   115,   116,   117,     0,    23,
      24,    25,    26,    27
};

static const yytype_int16 yycheck[] =
{
       1,    43,    19,    21,    28,     6,    25,     3,     4,    20,
      11,    10,    11,    12,    13,    14,    15,    25,    37,    37,
      37,    10,    11,    12,    13,    14,    15,     0,    25,    37,
       3,     4,    49,    44,    45,    46,    47,    48,    37,    21,
      37,    21,    84,    85,    86,    18,    19,    27,    37,    22,
       8,     9,    19,    26,    27,    37,    98,    30,    31,    32,
      33,    19,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     8,     9,    10,    11,
      12,    13,    14,    15,    65,    66,    20,    19,     3,     4,
      20,    25,    73,    94,    95,    25,    38,    39,    40,    37,
     101,    43,    20,    18,    19,    82,    83,    25,    37,    17,
      10,    11,    12,    13,    14,    15,    19,    49,    50,    51,
      52,    53,    54,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,     4,   137,    37,    20,    20,
       3,     4,    16,    25,    25,    43,     3,     4,    20,    18,
      19,    19,    19,    25,     1,    18,    19,    20,    20,     6,
      19,    18,    19,    50,    51,    52,    53,    54,    37,    38,
      39,    40,    41,    42,    43,    38,    39,    40,    41,    42,
      43,    38,    39,    40,    41,    42,    43,     3,     4,    20,
       5,     6,     7,     3,     4,    20,    20,    20,    25,     3,
       4,    21,    18,    19,    21,    43,   166,    37,    18,    19,
      21,    37,   145,    74,    18,    19,    10,    11,    12,    13,
      14,    15,    38,    39,    40,    41,    42,    43,    38,    39,
      40,    41,    42,    43,    38,    39,    40,    41,    42,    43,
      75,    -1,    -1,    37,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    76,    77,    78,    79,
      80,    81,    38,    39,    -1,    41,    42,    43,    -1,    44,
      45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,     0,     3,     4,    18,    19,    22,    26,    27,
      30,    31,    32,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    57,    58,
      59,    60,    61,    62,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    82,    88,    89,    60,    89,    28,    81,    19,    37,
      60,    37,    37,     8,     9,    49,    25,    37,    50,    51,
      52,    53,    54,    63,    17,    16,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,     7,    38,    39,    41,
      42,    43,    71,    19,    19,    19,    43,    20,    20,    21,
      27,    19,    38,    39,    40,    43,    37,    61,    61,    61,
      43,    66,    67,    38,    39,    41,    42,    43,    68,    68,
      68,    68,    68,    68,    70,    70,    71,    71,    71,    20,
      60,    86,    87,    60,    60,    19,    37,    49,    71,    60,
      20,    20,    20,    20,    20,    25,    20,    20,    20,    84,
      85,    89,    38,    39,    40,    41,    42,    60,    83,    20,
      87,    21,    21,    21,    37,    20,    25,    43,    37,    37,
      37,    21,    21,    37,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    78,    79,    79,    79,
      79,    80,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    85,    86,    86,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     3,     6,     5,     1,     2,     1,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     1,     1,
       1,     1,     3,     4,     2,     2,     1,     1,     3,     5,
       6,     3,     5,     6,     5,     1,     1,     2,     2,     2,
       3,     1,     2,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 148 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 247 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 289 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].string), scope, symbol_num) != -2)
			{
				if(scope==0)
				{
					insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, -1);
					if(strcmp((yyvsp[-4].string),"int")==0)
					{
						if(op_type == 0 || op_type == 'I')
							fprintf(file,"\tputstatic %s/%s I\n", CLASS_NAME, (yyvsp[-3].string));
						else if(op_type == 'F')
						{
							fprintf(file,"\tf2i\n"
										"\tputstatic %s/%s I\n", CLASS_NAME, (yyvsp[-3].string));
						}
					}
					else if(strcmp((yyvsp[-4].string), "float")==0)
					{
						if(op_type == 0 || op_type == 'F')
							fprintf(file,"\tputstatic %s/%s F\n", CLASS_NAME, (yyvsp[-3].string));
						else if(op_type == 'I')
						{
							fprintf(file,"\ti2f\n"
										"\tputstatic %s/%s F\n", CLASS_NAME, (yyvsp[-3].string));
						}
					}
					else if(strcmp((yyvsp[-4].string), "bool")==0)
						fprintf(file,"\tputstatic %s/%s Z\n", CLASS_NAME, (yyvsp[-3].string));
					else if(strcmp((yyvsp[-4].string), "void")==0)
						fprintf(file,"\tputstatic %s/%s V\n", CLASS_NAME, (yyvsp[-3].string));
					else if(strcmp((yyvsp[-4].string), "string")==0)
						fprintf(file,"\tputstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, (yyvsp[-3].string));
	
				}
				else
				{
					if(func_flag == 1)
					{
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, funcReg_num);
						if(strcmp((yyvsp[-4].string),"int")==0)
						{	
							if(op_type == 0 || op_type == 'I')
								fprintf(file,"\tistore %d\n",funcReg_num);
							else if(op_type == 'F')
							{
								fprintf(file,"\tf2i\n"
											"\tistore %d\n",funcReg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "float")==0)
						{	
							if(op_type == 0 || op_type == 'F')
								fprintf(file,"\tfstore %d\n", funcReg_num);
							else if(op_type == 'I')
							{
								fprintf(file,"\ti2f\n"
											"\tfstore %d\n",funcReg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "bool")==0)
						{
							if(op_type == 0 || op_type == 'I' || op_type =='Z')
								fprintf(file,"\tistore %d\n",funcReg_num);
							else if(op_type == 'F')
							{
								fprintf(file,"\tf2i\n"
											"\tistore %d\n",funcReg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "string")==0)
						{	
							fprintf(file,"\tastore %d\n", funcReg_num);
						}
						++funcReg_num;
					}
					else
					{
						insert_symbol(symbol_num, (yyvsp[-3].string), "variable", (yyvsp[-4].string), scope, NULL, 0, reg_num);
						if(strcmp((yyvsp[-4].string),"int")==0)
						{	
							if(op_type == 0 || op_type == 'I')
								fprintf(file,"\tistore %d\n",reg_num);
							else if(op_type == 'F')
							{
								fprintf(file,"\tf2i\n"
											"\tistore %d\n",reg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "float")==0)
						{	
							if(op_type == 0 || op_type == 'F')
								fprintf(file,"\tfstore %d\n", reg_num);
							else if(op_type == 'I')
							{
								fprintf(file,"\ti2f\n"
											"\tfstore %d\n",reg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "bool")==0)
						{
							if(op_type == 0 || op_type == 'I' || op_type == 'Z')
								fprintf(file,"\tistore %d\n",reg_num);
							else if(op_type == 'F')
							{
								fprintf(file,"\tf2i\n"
											"\tistore %d\n",reg_num);
							}
						}
						else if(strcmp((yyvsp[-4].string), "string")==0)
						{	
							fprintf(file,"\tastore %d\n", reg_num);
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
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 492 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			int lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			if(lookup_result == -2 || (lookup_result >= 0 && symbol_table[lookup_result]->forward==1) )
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
			else if(lookup_result>=0 && symbol_table[lookup_result]->forward==2)
			{
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);

				if(strcmp((yyvsp[-5].string), symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
				}
				else if(strcmp(temp, symbol_table[lookup_result]->param)!=0 || strlen(symbol_table[lookup_result]->param)==0)
				{
					set_err(3,"function formal parameter is not the same","");
				}

			}
			memset(params,0,sizeof(params));
			memset(param_index,0,sizeof(param_index));
		}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 537 "compiler_hw3.y" /* yacc.c:1646  */
    {			
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num);
			if( lookup_result == -2 || (lookup_result >= 0 && symbol_table[lookup_result]->forward==1) )
			{
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}
			else if(lookup_result != -2 && lookup_result < 0)
			{
				insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, NULL, 1, -1);
				++symbol_num;
			}
			else if(lookup_result>=0 && symbol_table[lookup_result]->forward==2)
			{
				if(strcmp((yyvsp[-4].string), symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
				}
				else if(strlen(symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
				}
			}
		}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 574 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 576 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 642 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(op_type == 'I' || op_type == 'Z')
			{	
				if(strcmp((yyvsp[-1].string), "+=")==0)
					fprintf(file, "\tiadd\n");
				else if(strcmp((yyvsp[-1].string), "-=")==0)
					fprintf(file, "\tisub\n");
				else if(strcmp((yyvsp[-1].string), "*=")==0)
					fprintf(file, "\timul\n");
				else if(strcmp((yyvsp[-1].string), "/=")==0)
				{
					if(zero_flag==1)
						set_err(3,"divide by zero","");
					else
						fprintf(file, "\tidiv\n");
				}
				else if(strcmp((yyvsp[-1].string), "%=")==0)
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
						fprintf(file, "\tirem\n");
				}
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
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
						fprintf(file, "\tfdiv\n");
				}
				else if(strcmp((yyvsp[-1].string), "%=")==0)
				{
					set_err(3,"Modulo operator with floating point operands","");
				}
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
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 747 "compiler_hw3.y" /* yacc.c:1646  */
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
						op_type = 'Z';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, (yyvsp[0].string));		
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
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 810 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "*="); }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 811 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "/="); }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 812 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "%="); }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 813 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string),"+="); }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 814 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "-="); }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 818 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 822 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 827 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 834 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 845 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 856 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 867 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 878 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 889 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 903 "compiler_hw3.y" /* yacc.c:1646  */
    {
			/*if(if_endFlag[scope-1]==1 && while_flag!=1 && )
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}*/
			fprintf(file, "\tldc %d\n", (yyvsp[0].i_val));
			op_type = 'I';
		}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 914 "compiler_hw3.y" /* yacc.c:1646  */
    {
			/*if(if_endFlag[scope-1]==1 && while_flag!=1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}*/
			fprintf(file, "\tldc %f\n", (yyvsp[0].f_val));
			op_type = 'F';
		}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 925 "compiler_hw3.y" /* yacc.c:1646  */
    {
			/*f(if_endFlag[scope-1]==1 && while_flag!=1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}*/
			fprintf(file, "\tldc 1\n");
			op_type = 'Z';
		}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 936 "compiler_hw3.y" /* yacc.c:1646  */
    {
			/*if(if_endFlag[scope-1]==1 && while_flag!=1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}*/
			fprintf(file, "\tldc 0\n");
			op_type = 'Z';
		}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 947 "compiler_hw3.y" /* yacc.c:1646  */
    {
			/*if(if_endFlag[scope-1]==1 && while_flag!=1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}*/

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
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1006 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1008 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1026 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1045 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1047 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1064 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(zero_flag==1)
				set_err(3,"Divide by zero","");
			else
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
		}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1086 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			
			switch(op_type)
			{
				case 'I':
				{
					if(zero_flag==1)
						set_err(3,"Divide by zero","");
					else
					{
						(yyval.f_val) = (int)(yyvsp[-2].f_val) % (int)(yyvsp[0].f_val);
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
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1111 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1116 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1127 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1129 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-2].string), scope, symbol_num);
			if(lookup_result == -1)
			{	
				set_err(2,"Undeclared function",(yyvsp[-2].string));
			}
			else if(strlen(symbol_table[lookup_result]->param)!=0)
			{
				set_err(3, "function formal parameter is not the same", "");
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s()", CLASS_NAME, (yyvsp[-2].string));
				char type[7] = {0};
				strcpy(type, get_type((yyvsp[-2].string),scope,symbol_num));
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
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1173 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num);	
			char temp[256] = {0};	
			strncpy(temp,invoke_arg,strlen(invoke_arg)-2);
			char *cut = strstr(temp, ", ");		
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared function",(yyvsp[-3].string));
			}
			else if(strlen(symbol_table[lookup_result]->param)==0 && strcmp(symbol_table[lookup_result]->param, cut+2)!=0)
			{	
				set_err(3,"function formal parameter is not the same","");
			}
			else
			{
				fprintf(file, "\tinvokestatic %s/%s(", CLASS_NAME, (yyvsp[-3].string));

				memset(temp,0,sizeof(temp));
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
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1252 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-1].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[-1].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[-1].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[-1].string));
				}
				else	// local variable
				{
					fprintf(file, "\tiload %d\n",reg);
				}

				fprintf(file,"\tldc 1\n"
							"\tiadd\n");

				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tputstatic %s/%s I\n", CLASS_NAME, (yyvsp[-1].string));
				}
				else	// local variable
				{
					fprintf(file, "\tistore %d\n",reg);
				}
			}
		}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1284 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-1].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[-1].string));
			}
			else
			{
				int reg = get_register(symbol_table, (yyvsp[-1].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tgetstatic %s/%s I\n", CLASS_NAME, (yyvsp[-1].string));
				}
				else	// local variable
				{
					fprintf(file, "\tiload %d\n",reg);
				}

				fprintf(file,"\tldc 1\n"
							"\tisub\n");

				if(reg==-1)		// global variable
				{	
					fprintf(file, "\tputstatic %s/%s I\n", CLASS_NAME, (yyvsp[-1].string));
				}
				else	// local variable
				{
					fprintf(file, "\tistore %d\n",reg);
				}
			}
		}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1319 "compiler_hw3.y" /* yacc.c:1646  */
    {
			invoke_flag = 1;
			strcpy((yyval.string),(yyvsp[0].string));
		}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1326 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val);  }
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1332 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1375 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1420 "compiler_hw3.y" /* yacc.c:1646  */
    {
			dump = 1;
			add_scope = 1;
			
			if_endFlag[scope-1] = 0;
			fprintf(file, "\tgoto  EXIT%d_%d\n", scope-1, if_group[scope-1]);
			fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
		}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1429 "compiler_hw3.y" /* yacc.c:1646  */
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
			while_flag = 0;
			fprintf(file, "\tgoto FALSE%d_%d\n", scope-1, while_group[scope-1]);
			fprintf(file, "TRUE%d_%d:\n", scope-1, while_group[scope-1]);
		}
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1471 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			if(lookup_result == -1 || lookup_result == -3)	// If function undeclared, insert it and its parameters
			{
				func_flag = 1;
				char temp[256]= {0};
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, (yyvsp[-4].string), "function", (yyvsp[-5].string), scope, temp, 2, -1);
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
			else if(lookup_result >= 0 && symbol_table[lookup_result]->forward!=2)		// If function forward declared, insert its attribute
			{
				func_flag = 1;
				char temp[256] = {0};
				strncpy(temp,params,strlen(params)-2);

				if(strcmp((yyvsp[-5].string), symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
					if(strcmp((yyvsp[-5].string),"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp((yyvsp[-5].string),"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp((yyvsp[-5].string),"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp((yyvsp[-5].string), "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp((yyvsp[-5].string), "void")==0)
					{
						return_type = 'V';
					}
				}
				else if(strcmp(temp,symbol_table[lookup_result]->param)!=0 || strlen(symbol_table[lookup_result]->param)==0)
				{
					set_err(3,"function formal parameter is not the same","");
					if(strcmp((yyvsp[-5].string),"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp((yyvsp[-5].string),"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp((yyvsp[-5].string),"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp((yyvsp[-5].string), "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp((yyvsp[-5].string), "void")==0)
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
			}
			else
			{
				set_err(2,"Redeclared function",(yyvsp[-4].string));
			}
		
				++scope;
		}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1671 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num); 
			if(lookup_result == -1 || lookup_result == -3)
			{
				func_flag = 1;
				insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, NULL, 2, -1);
				++symbol_num;

				if(strcmp((yyvsp[-3].string),"main")==0)
				{
					fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
									".limit stack 50\n"
									".limit locals 50\n");
					if(strcmp((yyvsp[-4].string),"int")==0)
						return_type = 'I';
					else if(strcmp((yyvsp[-4].string),"float")==0)
						return_type = 'F';
					else if(strcmp((yyvsp[-4].string),"bool")==0)
						return_type = 'Z';
					else if(strcmp((yyvsp[-4].string), "string")==0)
						return_type = 's';
					else if(strcmp((yyvsp[-4].string), "void")==0)
						return_type = 'V';
				}
				else
				{
					fprintf(file, ".method public static %s()", (yyvsp[-3].string));
					if(strcmp((yyvsp[-4].string),"int")==0)
					{
						return_type = 'I';
						fprintf(file, "I\n");
					}
					else if(strcmp((yyvsp[-4].string),"float")==0)
					{
						return_type = 'F';
						fprintf(file, "F\n");
					}
					else if(strcmp((yyvsp[-4].string),"bool")==0)
					{
						return_type = 'Z';
						fprintf(file, "Z\n");
					}
					else if(strcmp((yyvsp[-4].string), "string")==0)
					{
						return_type = 's';
						fprintf(file, "Ljava/lang/String;\n");
					}
					else if(strcmp((yyvsp[-4].string), "void")==0)
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
			else if(lookup_result >= 0 && symbol_table[lookup_result]->forward!=2)	// If function forward declared
			{
				func_flag = 1;
				if(strcmp((yyvsp[-4].string), symbol_table[lookup_result]->data_type)!=0)
				{
					set_err(3,"function return type is not the same","");
					if(strcmp((yyvsp[-4].string),"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp((yyvsp[-4].string),"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp((yyvsp[-4].string),"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp((yyvsp[-4].string), "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp((yyvsp[-4].string), "void")==0)
					{
						return_type = 'V';
					}
				}
				else if(strlen(symbol_table[lookup_result]->param)!=0)
				{
					set_err(3,"function formal parameter is not the same","");
					if(strcmp((yyvsp[-4].string),"int")==0)
					{
						return_type = 'I';
					}
					else if(strcmp((yyvsp[-4].string),"float")==0)
					{
						return_type = 'F';
					}
					else if(strcmp((yyvsp[-4].string),"bool")==0)
					{
						return_type = 'Z';
					}	
					else if(strcmp((yyvsp[-4].string), "string")==0)
					{
						return_type = 's';
					}
					else if(strcmp((yyvsp[-4].string), "void")==0)
					{
						return_type = 'V';
					}
				}
				else
				{
					
					if(strcmp((yyvsp[-3].string),"main")==0)
					{
						fprintf(file, ".method public static main([Ljava/lang/String;)V\n"
										".limit stack 50\n"
										".limit locals 50\n");
						if(strcmp((yyvsp[-4].string),"int")==0)
							return_type = 'I';
						else if(strcmp((yyvsp[-4].string),"float")==0)
							return_type = 'F';
						else if(strcmp((yyvsp[-4].string),"bool")==0)
							return_type = 'Z';
						else if(strcmp((yyvsp[-4].string), "string")==0)
							return_type = 's';
						else if(strcmp((yyvsp[-4].string), "void")==0)
							return_type = 'V';
					}
					else
					{
						fprintf(file, ".method public static %s()",(yyvsp[-3].string));
						int i = 0;
						if(strcmp((yyvsp[-4].string),"int")==0)
						{
							return_type = 'I';
							fprintf(file, "I\n");
						}
						else if(strcmp((yyvsp[-4].string),"float")==0)
						{
							return_type = 'F';
							fprintf(file, "F\n");
						}
						else if(strcmp((yyvsp[-4].string),"bool")==0)
						{
							return_type = 'Z';
							fprintf(file, "Z\n");
						}
						else if(strcmp((yyvsp[-4].string), "string")==0)
						{
							return_type = 's';
							fprintf(file, "Ljava/lang/String;\n");
						}
						else if(strcmp((yyvsp[-4].string), "void")==0)
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
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}

			++scope;
		}
#line 3398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1845 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 3424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1871 "compiler_hw3.y" /* yacc.c:1646  */
    {
			while_flag = 1;
			++while_group[scope];
			while_exitFlag[scope] = 1;
			fprintf(file, "BEGIN%d_%d:\n", scope, while_group[scope]);
		}
#line 3435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1883 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 3452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1896 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 3512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1955 "compiler_hw3.y" /* yacc.c:1646  */
    {
		}
#line 3519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1961 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(if_endFlag[scope-1]==1 && while_flag!=1)
			{
				fprintf(file, "\tgoto EXIT%d_%d\n", scope-1, if_group[scope-1]);
				fprintf(file, "END%d_%d_%d:\n", scope-1, if_group[scope-1], if_branch[scope-1]);
				if_endFlag[scope-1] = 0; 
			}
		}
#line 3532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1972 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc %d\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(I)V\n", (yyvsp[-1].i_val));
		}
#line 3543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1979 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc %f\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(F)V\n", (yyvsp[-1].f_val));
		}
#line 3554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1986 "compiler_hw3.y" /* yacc.c:1646  */
    {
			fprintf(file, "\tldc \"%s\"\n"
						"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
						"\tswap\n"
						"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", (yyvsp[-1].string));
		}
#line 3565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1993 "compiler_hw3.y" /* yacc.c:1646  */
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
						fprintf(file, "\tgetstatic compiler_hw3/%s Z\n"
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
#line 3645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2072 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = (yyvsp[0].i_val);	}
#line 3651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2073 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = (yyvsp[0].f_val);	}
#line 3657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2074 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = 1;	}
#line 3663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 2075 "compiler_hw3.y" /* yacc.c:1646  */
    {	(yyval.f_val) = 0;	}
#line 3669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2085 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 3715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 2139 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[0].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
			else
			{
				char type[7] = {0};
				strcpy(type, get_type((yyvsp[0].string), scope, symbol_num));
				if(invoke_flag==1)
				{
					strcat(invoke_arg, type);
					strcat(invoke_arg, ", ");	
				}

				int reg = get_register(symbol_table, (yyvsp[0].string), scope, symbol_num);
				if(reg==-1)		// global variable
				{	
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

						fprintf(file, "\tgetstatic %s/%s Z\n", CLASS_NAME, (yyvsp[0].string));
						op_type = 'Z';
					}
					else if(strcmp(type, "string")==0)
					{
						fprintf(file, "\tgetstatic %s/%s Ljava/lang/String;\n", CLASS_NAME, (yyvsp[0].string));
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
#line 3846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 2266 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			
			strcat(invoke_arg,"int, ");
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
			if(zero_flag == 1)
				zero_flag = 0;
			if((yyval.f_val) == 0)
				zero_flag = 1;
		}
#line 3872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 2288 "compiler_hw3.y" /* yacc.c:1646  */
    {		
			strcat(invoke_arg,"float, ");			
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
			if(zero_flag == 1)
				zero_flag = 0;
			if((yyval.f_val) == 0)
				zero_flag = 1;
		}
#line 3896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 2308 "compiler_hw3.y" /* yacc.c:1646  */
    {
			strcat(invoke_arg,"string, ");
			fprintf(file, "\tldc \"%s\"\n", (yyvsp[0].string));
			op_type = 's';
		}
#line 3906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 2314 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			strcat(invoke_arg,"bool, ");
			fprintf(file, "\tldc %d\n", (int)1);
			(yyval.f_val) = (int)1;
			op_type = 'Z';
		}
#line 3917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 2321 "compiler_hw3.y" /* yacc.c:1646  */
    {	
			strcat(invoke_arg,"bool, ");
			fprintf(file, "\tldc %d\n", (int)0);
			(yyval.f_val) = (int)0;
			op_type = 'Z';
		}
#line 3928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 2332 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "int"); }
#line 3934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 2333 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "float"); }
#line 3940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 2334 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "bool"); }
#line 3946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 2335 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "string"); }
#line 3952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 2336 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "void"); }
#line 3958 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3962 "y.tab.c" /* yacc.c:1646  */
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
#line 2339 "compiler_hw3.y" /* yacc.c:1906  */


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

	if(gencode_flag != 1)
	{
		remove("compiler_hw3.j");
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
	gencode_flag = 0;
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
	gencode_flag = 0;
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
