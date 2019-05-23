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
#line 2 "compiler_hw2.y" /* yacc.c:339  */

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


#line 106 "y.tab.c" /* yacc.c:339  */

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
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    SEMICOLON = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    INC = 269,
    DEC = 270,
    MT = 271,
    LT = 272,
    MTE = 273,
    LTE = 274,
    EQ = 275,
    NE = 276,
    ASGN = 277,
    ADDASGN = 278,
    SUBASGN = 279,
    MULASGN = 280,
    DIVASGN = 281,
    MODASGN = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LB = 286,
    RB = 287,
    LCB = 288,
    RCB = 289,
    LSB = 290,
    RSB = 291,
    COMMA = 292,
    QUOTA = 293,
    TRUE = 294,
    FALSE = 295,
    COMMENTLINE = 296,
    NEWLINE = 297,
    RET = 298,
    CONT = 299,
    BREAK = 300,
    I_CONST = 301,
    F_CONST = 302,
    STR_CONST = 303,
    ID = 304,
    INT = 305,
    FLOAT = 306,
    BOOL = 307,
    STRING = 308,
    VOID = 309
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define MT 271
#define LT 272
#define MTE 273
#define LTE 274
#define EQ 275
#define NE 276
#define ASGN 277
#define ADDASGN 278
#define SUBASGN 279
#define MULASGN 280
#define DIVASGN 281
#define MODASGN 282
#define AND 283
#define OR 284
#define NOT 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define QUOTA 293
#define TRUE 294
#define FALSE 295
#define COMMENTLINE 296
#define NEWLINE 297
#define RET 298
#define CONT 299
#define BREAK 300
#define I_CONST 301
#define F_CONST 302
#define STR_CONST 303
#define ID 304
#define INT 305
#define FLOAT 306
#define BOOL 307
#define STRING 308
#define VOID 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char string[256];

#line 260 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

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
       0,    82,    82,    83,    87,    88,    89,    90,    91,    92,
      93,   115,   127,   139,   161,   177,   178,   179,   180,   188,
     192,   193,   194,   198,   199,   200,   201,   202,   206,   207,
     208,   212,   213,   214,   215,   216,   217,   221,   225,   226,
     227,   231,   260,   275,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   295,   296,   307,   308,   309,   310,   311,
     318,   319,   323,   324,   328,   351,   352,   356,   364,   368,
     375,   376,   377,   378,   379,   385,   386,   387,   388,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT",
  "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN",
  "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "COMMA", "QUOTA", "TRUE", "FALSE", "COMMENTLINE",
  "NEWLINE", "RET", "CONT", "BREAK", "I_CONST", "F_CONST", "STR_CONST",
  "ID", "INT", "FLOAT", "BOOL", "STRING", "VOID", "$accept", "program",
  "stat", "declaration", "expression_stat", "expr", "term", "unary",
  "assignment", "compound_stat", "condition", "print_func", "initializer",
  "parameter_list", "parameter", "argument_list", "argument", "val",
  "type", YY_NULLPTR
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

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,    70,   -36,   -26,   -22,   -17,   127,    16,   -36,   -36,
     -36,   -36,   127,   -36,   -36,   -36,   233,   -36,   -36,   -36,
     -36,   -36,   -36,    26,   226,   -36,   -36,    -6,    28,   116,
      11,   -20,   127,   127,   249,    -2,     0,   232,   127,   127,
     127,   127,   127,   127,   102,   -36,   -36,   127,   127,   127,
     127,   127,   127,   127,   127,   -36,    97,    97,    97,    97,
      97,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -19,    13,
      35,   176,   182,    37,   -36,   -36,   249,   249,   249,   249,
     249,   249,   -36,   201,   249,   -30,   -36,   249,   249,   249,
     249,   249,   249,    51,    53,   116,   116,   116,   116,   116,
     131,    12,   -36,   -36,    36,    38,   127,   -36,   142,   -36,
     -36,   -36,   -36,   -36,    64,    67,    68,    76,    78,    -7,
     249,   -36,    45,   -24,   -36,    40,   -36,   -36,   199,   -36,
     -36,    54,   133,   -36,    63,   -36,   -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,    43,    73,    74,
       9,    10,     0,    70,    71,    72,    69,    75,    76,    77,
      78,    79,     2,     0,     0,    16,     6,    17,     0,    27,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    29,    30,    69,    15,    22,    23,    28,    12,     0,
       0,     0,     0,     0,    39,     8,    31,    32,    33,    34,
      35,    36,    19,    69,    68,     0,    65,    44,    45,    46,
      47,    48,    49,    17,    17,    27,    27,    27,    27,    27,
       0,     0,    53,    54,     0,     0,     0,    18,     0,    20,
      21,    24,    25,    26,    73,    74,    70,    71,    72,    69,
      61,    11,    14,     0,    62,     0,    37,    40,     0,    66,
      42,    13,     0,    64,     0,    41,    63,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,    -1,   114,   -36,   -36,   -36,   -36,
       4,   -36,   -36,   -36,   -35,   -36,   -10,    -4,   100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    22,    23,    34,    64,    65,    66,    25,    26,
      27,    28,   121,   123,   124,    85,    86,    29,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   -59,   107,   100,    73,    31,   -52,   108,   131,    32,
      35,    37,   101,   132,    33,    38,    39,    40,    41,    42,
      43,    36,    53,    54,    44,    67,    53,    54,    69,    70,
     -52,    71,    72,    74,    45,   -52,    55,    76,    77,    78,
      79,    80,    81,    84,   122,   102,    87,    88,    89,    90,
      91,    92,    95,    96,    97,    98,    99,    93,    94,   -50,
      68,   -51,    17,    18,    19,    20,    21,   103,   106,   126,
       2,   127,   -57,     3,     4,   -58,   -55,     5,   130,    53,
      54,    53,    54,   -50,   -56,   -51,   -60,   135,   -50,   133,
     -51,    67,    67,    67,    67,    67,   137,   136,   129,   120,
       6,    30,     0,     0,     7,   128,     0,    84,     0,     8,
       9,    10,    11,    12,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    56,    57,    58,    59,    60,
      61,    62,     6,     0,    82,     0,     8,     9,     0,     0,
       0,     8,     9,    13,    14,    15,    63,     0,    13,    14,
      15,    83,     0,     0,     0,     8,     9,     6,     0,     0,
       0,     6,    13,    14,    15,    63,     8,     9,     0,     0,
     114,   115,     6,    13,    14,    15,    16,   116,   117,   118,
     119,     8,     9,    17,    18,    19,    20,    21,    13,    14,
      15,    83,    47,    48,    49,    50,    51,    52,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,   104,   109,
     110,   111,   112,   113,   105,    47,    48,    49,    50,    51,
      52,     0,     0,    38,    39,    40,    41,    42,    43,     0,
       0,   134,    44,   -67,    46,     0,     0,     0,   -67,     0,
      75,     0,    47,    48,    49,    50,    51,    52,    47,    48,
      49,    50,    51,    52,     0,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    44,    47,    48,    49,    50,    51,
      52
};

static const yytype_int16 yycheck[] =
{
       1,     8,    32,    22,     4,    31,     8,    37,    32,    31,
       6,    12,    31,    37,    31,    22,    23,    24,    25,    26,
      27,     5,    28,    29,    31,    29,    28,    29,    48,    49,
      32,    32,    33,    33,     8,    37,     8,    38,    39,    40,
      41,    42,    43,    44,    32,    32,    47,    48,    49,    50,
      51,    52,    56,    57,    58,    59,    60,    53,    54,     8,
      49,     8,    50,    51,    52,    53,    54,    32,    31,    33,
       0,    33,     8,     3,     4,     8,     8,     7,    33,    28,
      29,    28,    29,    32,     8,    32,     8,    33,    37,    49,
      37,    95,    96,    97,    98,    99,    33,   132,   108,   100,
      30,     1,    -1,    -1,    34,   106,    -1,   108,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     9,    10,    11,    12,    13,
      14,    15,    30,    -1,    32,    -1,    39,    40,    -1,    -1,
      -1,    39,    40,    46,    47,    48,    49,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    39,    40,    30,    -1,    -1,
      -1,    30,    46,    47,    48,    49,    39,    40,    -1,    -1,
      39,    40,    30,    46,    47,    48,    49,    46,    47,    48,
      49,    39,    40,    50,    51,    52,    53,    54,    46,    47,
      48,    49,    16,    17,    18,    19,    20,    21,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    32,    95,
      96,    97,    98,    99,    32,    16,    17,    18,    19,    20,
      21,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    32,    31,    32,     8,    -1,    -1,    -1,    37,    -1,
       8,    -1,    16,    17,    18,    19,    20,    21,    16,    17,
      18,    19,    20,    21,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    16,    17,    18,    19,    20,
      21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,     0,     3,     4,     7,    30,    34,    39,    40,
      41,    42,    43,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    57,    58,    59,    63,    64,    65,    66,    72,
      73,    31,    31,    31,    59,    65,     5,    59,    22,    23,
      24,    25,    26,    27,    31,     8,     8,    16,    17,    18,
      19,    20,    21,    28,    29,     8,     9,    10,    11,    12,
      13,    14,    15,    49,    60,    61,    62,    72,    49,    48,
      49,    59,    59,     4,    33,     8,    59,    59,    59,    59,
      59,    59,    32,    49,    59,    70,    71,    59,    59,    59,
      59,    59,    59,    65,    65,    72,    72,    72,    72,    72,
      22,    31,    32,    32,    32,    32,    31,    32,    37,    60,
      60,    60,    60,    60,    39,    40,    46,    47,    48,    49,
      59,    67,    32,    68,    69,    73,    33,    33,    59,    71,
      33,    32,    37,    49,    32,    33,    69,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     1,     2,     3,     1,
       1,     4,     2,     5,     4,     2,     1,     1,     4,     3,
       3,     3,     1,     1,     3,     3,     3,     0,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     5,     7,     3,
       5,     6,     5,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 94 "compiler_hw2.y" /* yacc.c:1646  */
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
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "compiler_hw2.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-2].string), scope, symbol_num) == -1)
			{
				insert_symbol(symbol_num, (yyvsp[-2].string), "variable", (yyvsp[-3].string), scope, NULL,0);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",(yyvsp[-2].string));
			}
		}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "compiler_hw2.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[0].string), scope, symbol_num) == -1)
			{
				insert_symbol(symbol_num, (yyvsp[0].string), "variable", (yyvsp[-1].string), scope, NULL,0);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",(yyvsp[0].string));
			}
		}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-3].string), scope, symbol_num) != -1)
			{
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}

			int i;
			for(i=0; i<param_num; i++)
			{
				memset(table[param_index[i]], 0, sizeof(struct symbol));
				table[param_index[i]]->scope_level = -1;
			}
			symbol_num -= param_num;
			param_num = 0;
		
			char temp[256] = {0};
			strncpy(temp,params,strlen(params)-2);
			insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, temp,1);
			symbol_num++;
			memset(params,0,sizeof(params));
		}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "compiler_hw2.y" /* yacc.c:1646  */
    {			
			if(lookup_symbol((yyvsp[-2].string), scope, symbol_num) == -1)
			{
				insert_symbol(symbol_num, (yyvsp[-2].string), "function", (yyvsp[-3].string), scope, NULL,1);
				symbol_num++;
			}
			else
			{
				set_err(2,"Redeclared function",(yyvsp[-2].string));
			}
		}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[-3].string), scope, symbol_num) == -1)
			{	
				set_err(2,"Undeclared function",(yyvsp[-3].string));
			}

		}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 222 "compiler_hw2.y" /* yacc.c:1646  */
    {
			scope++;
		}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    {
			scope++;
		}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 232 "compiler_hw2.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-4].string), scope, symbol_num);
			if(lookup_result == -1)
			{
				char temp[256];
				strncpy(temp,params,strlen(params)-2);
				insert_symbol(symbol_num, (yyvsp[-4].string), "function", (yyvsp[-5].string), scope, temp,0);
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
				set_err(2,"Redeclared function",(yyvsp[-4].string));
			}
	
			scope++;
	}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "compiler_hw2.y" /* yacc.c:1646  */
    {
			int lookup_result = lookup_symbol((yyvsp[-3].string), scope, symbol_num); 
			if(lookup_result == -1)
			{
				insert_symbol(symbol_num, (yyvsp[-3].string), "function", (yyvsp[-4].string), scope, NULL,0);
				symbol_num++;
			}
			else if(lookup_result == -2)
			{
				set_err(2,"Redeclared function",(yyvsp[-3].string));
			}

			scope++;
		}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "compiler_hw2.y" /* yacc.c:1646  */
    {	
			dump = 1;
		}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 297 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[-1].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[-1].string));
			}
		}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 312 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
		}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 329 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope+1, symbol_num) == -1)
			{
				insert_symbol(symbol_num, (yyvsp[0].string), "parameter", (yyvsp[-1].string), scope+1, NULL,0);
				strcat(params,(yyvsp[-1].string));
				strcat(params,", ");

				param_index[param_num] = symbol_num;
				symbol_num++;
				param_num++;
			}
			else
			{
				set_err(2,"Redeclared variable",(yyvsp[0].string));
				strcat(params,(yyvsp[-1].string));
				strcat(params,", ");

			}
		}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 357 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
		}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 369 "compiler_hw2.y" /* yacc.c:1646  */
    {
			if(lookup_symbol((yyvsp[0].string), scope, symbol_num) == -1)
			{
				set_err(2,"Undeclared variable",(yyvsp[0].string));
			}
		}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 385 "compiler_hw2.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "int"); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 386 "compiler_hw2.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "float"); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 387 "compiler_hw2.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "bool"); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 388 "compiler_hw2.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "string"); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 389 "compiler_hw2.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "void"); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1757 "y.tab.c" /* yacc.c:1646  */
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
#line 392 "compiler_hw2.y" /* yacc.c:1906  */


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