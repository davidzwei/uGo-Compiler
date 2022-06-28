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


#include "common.h" //Extern variables that communicate with lex
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>    

// #define YYDEBUG 1
    // int yydebug = 1;

extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

FILE *file;	//for test.j

void yyerror (char const *s)
    {
	printf("error:%d: %s\n", yylineno, s);
    }

/* Symbol table function - you can add new function if needed. */
 //   static void create_symbol();
    static void insert_symbol(char* name,char* types, int type_mode);
    int lookup_symbol(char *id, int flag, int check);
    void dump_symbol();
	static void assign_symbol(int id, double data);

	int is_array = 0;
	int address_num = 0;
	int var_num = 0;
	int scope_flag = 0;
	int print_mode = 0;
	char *string_value;
	char *bool_value;
	int array_mode = 0;
	int for_flag = 0;
	int now_id = 0;
	int declare = 0;
	int pre_id = 0;
	int next_id = 0;
	int mid = 0;

	int print_flag = 0;
	int bool_val;

	int label_num[20] = {0};
	int exit_num[20] = {0};
	//if,for
	int ftype = 0;
	int flabel_num[20] = {0};
	int fexit_num[20] = {0};	
	int fornum = 0;
	int error_count = 0;
//for table
struct data{
	int index;	//0,1,2,3
	char type[10];	//int, float,
	char name[10];	//x,y,z
	int address;
	int lineno;
	char element[10];
	int type_mode;	

//content
	int int_value;
	double dou_value;
	char *str_value[10];
	char bool_val[6];

	int assign_bit;
	int scope;
	int be_dumped;
	//int f_bit;
	}symbol_table[100];


#line 146 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    VOID = 263,
    AND = 264,
    OR = 265,
    LBRACE = 266,
    RBRACE = 267,
    INC = 268,
    DEC = 269,
    ASSIGN = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    MUL_ASSIGN = 273,
    QUO_ASSIGN = 274,
    REM_ASSIGN = 275,
    PRINT = 276,
    PRINTLN = 277,
    NEWLINE = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    SEMICOLON = 282,
    COMMA = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    IDENT = 287,
    BOOL_LIT = 288,
    LOR = 289,
    LAND = 290,
    NEQ = 291,
    LSS = 292,
    LEQ = 293,
    GTR = 294,
    GEQ = 295,
    EQL = 296,
    ADD = 297,
    SUB = 298,
    MUL = 299,
    DIV = 300,
    REMAIN = 301,
    NOT = 302,
    LPAREN = 303,
    RPAREN = 304,
    LBRACK = 305,
    RBRACK = 306
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define VOID 263
#define AND 264
#define OR 265
#define LBRACE 266
#define RBRACE 267
#define INC 268
#define DEC 269
#define ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define MUL_ASSIGN 273
#define QUO_ASSIGN 274
#define REM_ASSIGN 275
#define PRINT 276
#define PRINTLN 277
#define NEWLINE 278
#define IF 279
#define ELSE 280
#define FOR 281
#define SEMICOLON 282
#define COMMA 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define IDENT 287
#define BOOL_LIT 288
#define LOR 289
#define LAND 290
#define NEQ 291
#define LSS 292
#define LEQ 293
#define GTR 294
#define GEQ 295
#define EQL 296
#define ADD 297
#define SUB 298
#define MUL 299
#define DIV 300
#define REMAIN 301
#define NOT 302
#define LPAREN 303
#define RPAREN 304
#define LBRACK 305
#define RBRACK 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 295 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 312 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   143,   144,   148,   149,   150,   151,   152,
     153,   154,   158,   224,   279,   283,   279,   292,   298,   299,
     300,   303,   303,   327,   327,   340,   340,   348,   348,   356,
     356,   364,   364,   374,   375,   394,   412,   428,   443,   451,
     467,   479,   496,   511,   526,   543,   558,   573,   576,   577,
     578,   583,   588,   589,   590,   592,   600,   601,   667,   671,
     674,   679,   688,   706,   713,   713,   745,   745,   756,   756,
     756,   757,   757,   760,   762,   761,   773,   780,   780,   791,
     792,   793,   791,   800,   800,   847,   847,   893,   910,   925,
     926,   930,   931,   932,   933,   936
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "VOID", "AND", "OR", "LBRACE", "RBRACE", "INC", "DEC", "ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "PRINT", "PRINTLN", "NEWLINE", "IF", "ELSE", "FOR", "SEMICOLON", "COMMA",
  "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT", "BOOL_LIT", "LOR", "LAND",
  "NEQ", "LSS", "LEQ", "GTR", "GEQ", "EQL", "ADD", "SUB", "MUL", "DIV",
  "REMAIN", "NOT", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "$accept",
  "Program", "StatementList", "Statement", "DeclarationStmt", "BLOCK",
  "$@1", "$@2", "SimpleStmt", "AssignmentStmt", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "Expression", "UnaryExpr", "PrimaryExpr", "IndexExpr",
  "Operand", "Literal", "ConversionExpr", "Condition", "FBLOCK", "$@9",
  "IfStmt", "$@10", "$@11", "$@12", "$@13", "Forstmt", "$@14", "Formid",
  "$@15", "Forclause", "$@16", "$@17", "$@18", "PrintStmt", "$@19", "$@20",
  "IncDecStmt", "Type", "TypeName", "ArrayType", YY_NULLPTR
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
     305,   306
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,   -23,   -66,   -66,   -66,   -66,   -66,   -19,    -5,   -66,
     173,   -66,   -66,   -66,   -66,   -66,   -66,   203,   203,   203,
     173,   173,    44,   143,   -66,    22,    24,    25,   -66,   254,
     -66,    -4,   -66,   -66,   -66,   -66,    26,    28,    46,   -66,
      19,   -66,   -66,     0,   143,   -66,   -66,   335,   -66,   173,
     -66,   -66,   -66,   -21,   267,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,    55,    56,    57,    58,    54,
      60,   173,   -66,   -66,   -66,   173,    62,   143,   173,   173,
      70,    70,    70,    73,   241,    70,   -66,   -66,   -66,     0,
     347,   358,   -11,   -11,   -11,   -11,   -11,   -11,    -8,    -8,
     -66,   -66,   -66,   173,   173,   173,   173,   173,   173,   285,
      53,   173,    71,   303,   319,   -66,   -66,    59,    85,   -66,
     -66,    70,   -66,   335,   335,   335,   335,   335,   335,   -66,
     -66,   335,   -66,   -66,   -66,   143,   -66,    61,   173,   -66,
     110,    70,   -66,   -66,   -66,   -66,    91,   -66,   173,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    91,    92,    94,    93,    14,     0,     0,    11,
       0,    74,    58,    59,    60,    57,    61,     0,     0,     0,
       0,     0,     0,     2,     4,     0,     0,     0,    20,    18,
      33,    48,    54,    52,    56,    53,     0,     0,     0,    19,
       0,    89,    90,     0,     0,    83,    85,    63,    66,     0,
      49,    50,    51,     0,     0,     1,     3,     5,     7,     6,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     8,     0,    13,    15,     0,     0,
       0,     0,     0,     0,    18,     0,    75,    77,    47,     0,
      46,    45,    40,    42,    43,    41,    44,    39,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    67,     0,     0,    79,
      76,     0,    95,    22,    24,    26,    28,    30,    32,    55,
      62,    12,    16,    84,    86,     0,    69,     0,     0,    78,
       0,     0,    72,    80,    65,    70,     0,    81,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -36,   -22,   -66,   -66,   -66,   -66,   -46,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -10,    23,   -66,   -66,
     -66,   -66,   -66,   -47,   -65,   -66,   -28,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -31,   -66,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    44,   122,    27,    28,
      75,    76,    77,    78,    79,    80,    29,    30,    31,    32,
      33,    34,    35,    48,   126,   145,    36,    90,    91,   151,
      92,    37,    49,    96,   131,    97,   148,   156,   158,    38,
      88,    89,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    56,    95,    93,     2,     3,     4,     5,    87,    43,
      53,    54,    86,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   127,   128,    98,    45,
     130,    70,    71,    72,    73,    74,    72,    73,    74,    94,
      50,    51,    52,    46,    55,    57,    81,    58,    59,    82,
      21,    83,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    56,   149,    85,   132,    84,
     113,   119,   114,   117,   115,   120,   116,   121,   123,   124,
     118,   125,     0,   142,   146,    10,   155,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     129,   153,   140,   133,   134,   135,   136,   137,   138,   150,
     147,   141,   159,     1,     2,     3,     4,     5,   157,   152,
       0,     6,   154,     0,     0,     0,     0,     0,    56,     0,
       0,     7,     8,     9,    10,     0,    11,     0,    47,    12,
      13,    14,    15,    16,     0,     0,     1,     2,     3,     4,
       5,     0,    17,    18,     6,     0,     0,    19,    20,     0,
      21,     0,     0,     0,     7,     8,     9,    10,     0,    11,
       0,     0,    12,    13,    14,    15,    16,     2,     3,     4,
       5,     0,     0,     0,     0,    17,    18,     0,     0,     0,
      19,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     2,     3,     4,
       5,     0,     0,     0,     0,    17,    18,     0,     0,     0,
      19,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
      19,     0,   -63,    21,    60,    61,   -21,   -23,   -25,   -27,
     -29,   -31,     0,     0,     0,     0,     0,    60,    61,   -21,
     -23,   -25,   -27,   -29,   -31,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,    99,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,     0,   139,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,   143,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,   144,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      10,    23,    49,    49,     4,     5,     6,     7,    44,    32,
      20,    21,    43,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    91,    92,    49,    48,
      95,    42,    43,    44,    45,    46,    44,    45,    46,    49,
      17,    18,    19,    48,     0,    23,    50,    23,    23,    23,
      50,    23,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    87,   131,    48,    99,    23,
      15,    81,    16,    19,    17,    85,    18,    15,    88,    89,
      20,    11,    -1,    12,    25,    24,   151,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      27,   148,    49,   113,   114,   115,   116,   117,   118,   145,
      25,   121,   158,     3,     4,     5,     6,     7,    27,   147,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    21,    22,    23,    24,    -1,    26,    -1,   148,    29,
      30,    31,    32,    33,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    42,    43,    11,    -1,    -1,    47,    48,    -1,
      50,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    30,    31,    32,    33,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    -1,    11,    50,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    51,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    11,    21,    22,    23,
      24,    26,    29,    30,    31,    32,    33,    42,    43,    47,
      48,    50,    53,    54,    55,    56,    57,    60,    61,    68,
      69,    70,    71,    72,    73,    74,    78,    83,    91,    94,
      95,    96,    97,    32,    58,    48,    48,    68,    75,    84,
      69,    69,    69,    68,    68,     0,    55,    23,    23,    23,
      13,    14,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    62,    63,    64,    65,    66,
      67,    50,    23,    23,    23,    48,    95,    54,    92,    93,
      79,    80,    82,    60,    68,    75,    85,    87,    49,    51,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    15,    16,    17,    18,    19,    20,    68,
      68,    15,    59,    68,    68,    11,    76,    76,    76,    27,
      76,    86,    95,    68,    68,    68,    68,    68,    68,    51,
      49,    68,    12,    49,    49,    77,    25,    25,    88,    76,
      54,    81,    78,    75,    12,    76,    89,    27,    90,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    58,    59,    57,    54,    60,    60,
      60,    62,    61,    63,    61,    64,    61,    65,    61,    66,
      61,    67,    61,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    71,    72,    72,    73,    73,
      73,    73,    74,    75,    77,    76,    79,    78,    80,    81,
      78,    82,    78,    83,    84,    83,    85,    86,    85,    88,
      89,    90,    87,    92,    91,    93,    91,    94,    94,    95,
      95,    96,    96,    96,    96,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     5,     3,     0,     0,     5,     1,     1,     1,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     4,     1,     0,     4,     0,     4,     0,     0,
       7,     0,     6,     0,     0,     3,     2,     0,     3,     0,
       0,     0,     8,     0,     5,     0,     5,     2,     2,     1,
       1,     1,     1,     1,     1,     4
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
        case 2:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
    {;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    {;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    {;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int temp = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
		if(for_flag > 0)//in f_block
		{
			if( (yyvsp[-2].i_val) == 1){ 					
				insert_symbol((yyvsp[-3].s_val), "int32", 1);
				assign_symbol(1, (yyvsp[0].f_val));
				//dump_symbol();
			}
			else if( (yyvsp[-2].i_val) == 2){
				insert_symbol((yyvsp[-3].s_val), "float32", 2); 
				assign_symbol(1, (yyvsp[0].f_val)); 
				//dump_symbol();
			}
		}
		else{
		if(temp == -1){ //new value
			//insert_symbol($2, $3); 
			if( (yyvsp[-2].i_val) == 1){ 					
				insert_symbol((yyvsp[-3].s_val), "int32", 1);
				int index = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
				fprintf(file,"\tistore %d\n\n", index);
				//dump_symbol();
			}
			else if( (yyvsp[-2].i_val) == 2){
				insert_symbol((yyvsp[-3].s_val), "float32", 2); 
				int index = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
				fprintf(file,"\tfstore %d\n\n", index);
				//dump_symbol();
			}
			else if ((yyvsp[-2].i_val) == 3){
					insert_symbol((yyvsp[-3].s_val), "string", (yyvsp[-2].i_val));
					int temp = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
					int index = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
					strcpy(symbol_table[temp].str_value, string_value); 
					//printf("%s\n", symbol_table[temp].str_value );
					fprintf(file,"\tastore %d\n", index);
			}

			else if ((yyvsp[-2].i_val) == 4){
					insert_symbol((yyvsp[-3].s_val), "bool", (yyvsp[-2].i_val)); 	
					int temp = lookup_symbol((yyvsp[-3].s_val), scope_flag, 1);
					strcpy( symbol_table[temp].bool_val, bool_value); 
					symbol_table[temp].int_value = bool_val;
					fprintf(file,"\tistore %d\n\n", temp);
					//printf("%s\n", symbol_table[temp].bool_val );		
			}
/*
			else if( $3 == 1){ 					
				insert_symbol($2, "array", $3);
				assign_symbol(1, $5);
				//dump_symbol();
			}
			else if( $3 == 1){ 					
				insert_symbol($2, "array", $3);
				assign_symbol(1, $5);
				//dump_symbol();
			}
		*/	
		}
		else{
			printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno, (yyvsp[-3].s_val), symbol_table[temp].lineno);
			error_count++;		
		}
		}
	}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    {

				int temp = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1);
				if(temp == -1){
				//error


//no error 
				if( (yyvsp[0].i_val) == 1){ 	//int				
					insert_symbol((yyvsp[-1].s_val), "int32", (yyvsp[0].i_val));
					int a = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1);	
					fprintf(file, "\tldc 0\n"); 
					fprintf(file, "\tistore %d\n\n", a);
				}
				else if( (yyvsp[0].i_val) == 2){ //float
					insert_symbol((yyvsp[-1].s_val), "float32", (yyvsp[0].i_val));
					int a = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1); 
					fprintf(file, "\tldc 0.000000\n");
					fprintf(file, "\tfstore %d\n\n", a);
				}
				else if ((yyvsp[0].i_val) == 3){
					insert_symbol((yyvsp[-1].s_val), "string", (yyvsp[0].i_val));
					int a = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1); 
					fprintf(file, "\tldc \"\"\n");
					fprintf(file, "\tastore %d\n", a);
				}
				else if ((yyvsp[0].i_val) == 4){
					insert_symbol((yyvsp[-1].s_val), "bool", (yyvsp[0].i_val));
				}
				else if( (yyvsp[0].i_val) == 5){
					insert_symbol((yyvsp[-1].s_val), "array", (yyvsp[0].i_val));
					int a = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1);
					/*
					fprintf(file, "\tnewarray int\n");*/
					fprintf(file, "\tastore %d\n\n", a);
				}
				else if( (yyvsp[0].i_val) == 6){
					insert_symbol((yyvsp[-1].s_val), "array", (yyvsp[0].i_val));
					int a = lookup_symbol((yyvsp[-1].s_val), scope_flag, 1);
				//	fprintf(file, "\tnewarray float\n");
					fprintf(file, "\tastore %d\n\n", a); 
				}

				}

				else{ //error

				printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",
				yylineno, (yyvsp[-1].s_val), symbol_table[temp].lineno);
				error_count++;
				}
	}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 279 "compiler_hw3.y" /* yacc.c:1646  */
    {
		scope_flag++ ; 
		//for_flag = 1; 
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 284 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		dump_symbol(); 
		scope_flag-- ; 
		//for_flag = 0; 
		}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 298 "compiler_hw3.y" /* yacc.c:1646  */
    {;}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 299 "compiler_hw3.y" /* yacc.c:1646  */
    {;}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 303 "compiler_hw3.y" /* yacc.c:1646  */
    { 	
				//int x = (int)$1;
				printf("$1: %f\n", (yyvsp[0].f_val));
				if( (yyvsp[0].f_val)<= 4.0) { fprintf(file,"pop\n");  } 
				mid =1;				
			}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "compiler_hw3.y" /* yacc.c:1646  */
    { 	
							//assign_symbol($1,0);
							if((yyvsp[-3].f_val) == 1 ) fprintf(file,"\tistore %d\n\n", pre_id);
							else if((yyvsp[-3].f_val) == 2) fprintf(file,"\tfstore %d\n\n", pre_id);
							else if((yyvsp[-3].f_val) == 3) fprintf(file,"\tastore %d\n\n", now_id);
							else if((yyvsp[-3].f_val) == 4) { fprintf(file,"\tistore %d\n\n", now_id); symbol_table[now_id].int_value = bool_val; }
							else if((yyvsp[-3].f_val) == 5) fprintf(file,"\tiastore\n\n");
							else if((yyvsp[-3].f_val) == 6) fprintf(file,"\tfastore\n\n");
//printf("%d %d\n",$1, $4 );
							if( ((yyvsp[-3].f_val) == 1 && (yyvsp[0].f_val) == 2)||((yyvsp[-3].f_val) == 7 && (yyvsp[0].f_val) == 8 )){ 
								printf("error:%d: invalid operation: ASSIGN (mismatched types int32 and float32)\n", yylineno); 
								error_count++;
							}
							printf("ASSIGN\n"); 
							pre_id = 0;
							mid = 0;
						}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 327 "compiler_hw3.y" /* yacc.c:1646  */
    { mid = 1; }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 328 "compiler_hw3.y" /* yacc.c:1646  */
    { 	
							if((yyvsp[-3].f_val) == 1) 	{ fprintf(file,"\tiadd\n", pre_id); fprintf(file,"\tistore %d\n\n", pre_id);  }
							else if((yyvsp[-3].f_val) == 2) { fprintf(file,"\tfadd\n", pre_id); fprintf(file,"\tfstore %d\n\n", pre_id); }
							//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
							else if((yyvsp[-3].f_val) == 5) { fprintf(file,"\tiadd\n"); fprintf(file,"\tastore\n\n"); }
							else if((yyvsp[-3].f_val) == 6) { fprintf(file,"\tfadd\n"); fprintf(file,"\tastore\n\n"); }
							if((yyvsp[-3].f_val) >6 && (yyvsp[0].f_val) ==1){
								printf("error:%d: cannot assign to int32\n", yylineno);
								error_count++;			
							} 
							printf("ADD_ASSIGN\n");
						 }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "compiler_hw3.y" /* yacc.c:1646  */
    { mid = 1; }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 341 "compiler_hw3.y" /* yacc.c:1646  */
    { 	if((yyvsp[-3].f_val) == 1) 	{ fprintf(file,"isub\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
							else if((yyvsp[-3].f_val) == 2) { fprintf(file,"fsub\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
							//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
							else if((yyvsp[-3].f_val) == 5) { fprintf(file,"isub\n"); fprintf(file,"astore\n"); }
							else if((yyvsp[-3].f_val) == 6) { fprintf(file,"fsub\n"); fprintf(file,"astore\n"); }
							printf("SUB_ASSIGN\n"); 
						}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 348 "compiler_hw3.y" /* yacc.c:1646  */
    { mid = 1; }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 349 "compiler_hw3.y" /* yacc.c:1646  */
    { if((yyvsp[-3].f_val) == 1) 	{ fprintf(file,"imul\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if((yyvsp[-3].f_val) == 2) { fprintf(file,"fmul\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if((yyvsp[-3].f_val) == 5) { fprintf(file,"imul\n"); fprintf(file,"astore\n"); }
						else if((yyvsp[-3].f_val) == 6) { fprintf(file,"fmul\n"); fprintf(file,"astore\n"); }
						printf("MUL_ASSIGN\n"); 
						}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    { mid = 1; }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 357 "compiler_hw3.y" /* yacc.c:1646  */
    { if((yyvsp[-3].f_val) == 1) 	{ fprintf(file,"idiv\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if((yyvsp[-3].f_val) == 2) { fprintf(file,"fdiv\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if((yyvsp[-3].f_val) == 5) { fprintf(file,"idiv\n"); fprintf(file,"astore\n"); }
						else if((yyvsp[-3].f_val) == 6) { fprintf(file,"fdiv\n"); fprintf(file,"astore\n"); }
						printf("QUO_ASSIGN\n"); 
						}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 364 "compiler_hw3.y" /* yacc.c:1646  */
    { mid = 1; }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 365 "compiler_hw3.y" /* yacc.c:1646  */
    { if((yyvsp[-3].f_val) == 1) 	{ fprintf(file,"irem\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if((yyvsp[-3].f_val) == 2) { fprintf(file,"frem\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if((yyvsp[-3].f_val) == 5) { fprintf(file,"irem\n"); fprintf(file,"astore\n"); }
						else if((yyvsp[-3].f_val) == 6) { fprintf(file,"frem\n"); fprintf(file,"astore\n"); }
						printf("REM_ASSIGN\n"); 
						}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					  if( ((yyvsp[-2].f_val) == 1 && (yyvsp[0].f_val) == 2)||((yyvsp[-2].f_val) == 7 && (yyvsp[0].f_val) == 8 )){ 
						printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno); 
						error_count++;
					}
					else if((yyvsp[-2].f_val) ==2 && (yyvsp[0].f_val) == 1){
						printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno); 
						error_count++;					
					}
					if( (yyvsp[-2].f_val) == 1 || (yyvsp[-2].f_val) == 7 || (yyvsp[-2].f_val) == 5){
						fprintf(file,"\tiadd\n");
					}
					if( (yyvsp[-2].f_val) == 2 || (yyvsp[-2].f_val) == 8 || (yyvsp[-2].f_val) == 6){
						fprintf(file,"\tfadd\n");
					}

printf("ADD\n"); 
					(yyval.f_val) = (yyvsp[-2].f_val);
					}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					if((yyvsp[-2].f_val) == 1 && (yyvsp[0].f_val) == 2){ 
						printf("error:%d: invalid operation: SUB (mismatched types int32 and float32)\n", yylineno); 
						error_count++;
					}
					else if((yyvsp[-2].f_val) ==2&&(yyvsp[0].f_val) == 1){
						printf("error:%d: invalid operation: SUB (mismatched types float32 and int32)\n", yylineno); 
						error_count++;
					}
					if( (yyvsp[-2].f_val) == 1 || (yyvsp[-2].f_val) == 7 || (yyvsp[-2].f_val) == 5){
						fprintf(file,"\tisub\n");
					}
					if( (yyvsp[-2].f_val) == 2 || (yyvsp[-2].f_val) == 8 || (yyvsp[-2].f_val) == 6){
						fprintf(file,"\tfsub\n");
					}
					printf("SUB\n");
					(yyval.f_val) = (yyvsp[-2].f_val);
					}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("MUL\n");
					//printf("%f\n", $1);
					//printf("%f\n", $3);
					int a = (int)((yyvsp[-2].f_val)*(yyvsp[0].f_val));
					//printf("%d\n", a);
					a = a%2;
					if( a == 1 ){//int
						fprintf(file,"\timul\n");
						(yyval.f_val) = 1;		
					}
					if( a == 0 ){ //float
						fprintf(file,"\tfmul\n");
						(yyval.f_val) = 2;
					} 

}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					printf("QUO\n"); 
					int a = (int)((yyvsp[-2].f_val)*(yyvsp[0].f_val));
					(yyval.f_val) = (yyvsp[-2].f_val);
					//printf("%d\n", a);
					a = a%2;
					
						if( a == 1 ){
						fprintf(file,"\tidiv\n");
						}
						else if( a == 0){
						fprintf(file,"\tfdiv\n");
						}
					
					}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 443 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					if( ((yyvsp[-2].f_val) == 2 || (yyvsp[0].f_val) == 2)){ 
						printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno); 
						error_count++;
						}
					fprintf(file,"\tirem\n");
					printf("REM\n");  }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					printf("EQL\n"); 
					(yyval.f_val) = 10; 
					print_mode = 10;
					if((yyvsp[-2].f_val)==1|(yyvsp[-2].f_val)==5|(yyvsp[-2].f_val)==7) fprintf(file,"\tisub\n");
					else if((yyvsp[-2].f_val)==2|(yyvsp[-2].f_val)==6|(yyvsp[-2].f_val)==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }

					fprintf(file,"\tifeq Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
					}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 467 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					printf("NEQ\n"); 
					(yyval.f_val) = 10;
					print_mode = 10;
					fprintf(file,"\tisub\n");
					fprintf(file,"\tifne L_cmp_0\n");
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto L_cmp_1\n");
					fprintf(file,"L_cmp_0:\n");
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"L_cmp_1:\n\n");
					}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 479 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GTR\n"); 
					(yyval.f_val) = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if((yyvsp[-2].f_val)==1|(yyvsp[-2].f_val)==5|(yyvsp[-2].f_val)==7) fprintf(file,"\tisub\n");
					else if((yyvsp[-2].f_val)==2|(yyvsp[-2].f_val)==6|(yyvsp[-2].f_val)==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifgt Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					if(fornum) fprintf(file,"\tgoto For_exit%d\n", fornum);
					else fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
				//	}
					}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 496 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LSS\n"); 
					(yyval.f_val) = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if((yyvsp[-2].f_val)==1|(yyvsp[-2].f_val)==5|(yyvsp[-2].f_val)==7) fprintf(file,"\tisub\n");
					else if((yyvsp[-2].f_val)==2|(yyvsp[-2].f_val)==6|(yyvsp[-2].f_val)==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tiflt Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					if( !fornum )fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;	
					}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 511 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LEQ\n"); 
					(yyval.f_val) = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if((yyvsp[-2].f_val)==1|(yyvsp[-2].f_val)==5|(yyvsp[-2].f_val)==7) fprintf(file,"\tisub\n");
					else if((yyvsp[-2].f_val)==2|(yyvsp[-2].f_val)==6|(yyvsp[-2].f_val)==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifle Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					if( !fornum ) fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;	
					}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 526 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GTR\n"); 
					(yyval.f_val) = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if((yyvsp[-2].f_val)==1|(yyvsp[-2].f_val)==5|(yyvsp[-2].f_val)==7) fprintf(file,"\tisub\n");
					else if((yyvsp[-2].f_val)==2|(yyvsp[-2].f_val)==6|(yyvsp[-2].f_val)==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifge Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					if(fornum) fprintf(file,"\tgoto For_exit%d\n", fornum);
					else fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
				//	}
					}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 543 "compiler_hw3.y" /* yacc.c:1646  */
    { if((yyvsp[-2].f_val) == 1 || (yyvsp[0].f_val) == 1 || (yyvsp[-2].f_val) == 7 || (yyvsp[0].f_val) == 7){ 
						printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno); 
						error_count++;
						}
					if((yyvsp[-2].f_val) == 2 || (yyvsp[0].f_val) == 2 || (yyvsp[-2].f_val) == 8 || (yyvsp[0].f_val) == 8){ 
						printf("error:%d: invalid operation: (operator LAND not defined on float32)\n", yylineno); 
						error_count++;				
					}
					//printf("%f  %f\n",$1,$3);
					(yyval.f_val) = 10;					
					print_mode = 10;					
					printf("LAND\n");
					
					fprintf(file, "\tiand\n");
					 }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 558 "compiler_hw3.y" /* yacc.c:1646  */
    { if((yyvsp[-2].f_val) == 1 || (yyvsp[0].f_val) == 1  || (yyvsp[-2].f_val) == 7 || (yyvsp[0].f_val) == 7){ 
						printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno);
						error_count++;
					 }
					if((yyvsp[-2].f_val) == 2 || (yyvsp[0].f_val) == 2  || (yyvsp[-2].f_val) == 8 || (yyvsp[0].f_val) == 8){ 
						printf("error:%d: invalid operation: (operator LOR not defined on float32)\n", yylineno); 
						error_count++;
					}
					//printf("%f  %f\n",$1,$3);
					(yyval.f_val) = 10;					
					print_mode = 10;
					printf("LOR\n"); 
					
					fprintf(file, "\tior\n");
					}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 573 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[-1].f_val);}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 576 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 577 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("POS\n"); (yyval.f_val) = (yyvsp[0].f_val);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 578 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NEG\n"); (yyval.f_val) = (yyvsp[0].f_val); 
			printf("%f\n", (yyvsp[0].f_val)); 
			if((int)(yyvsp[0].f_val) == 1 | (int)(yyvsp[0].f_val) == 7) { fprintf(file, "\tineg\n"); }
			if((int)(yyvsp[0].f_val) == 2 | (int)(yyvsp[0].f_val) == 8 ) { fprintf(file, "\tfneg\n"); }
			}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 583 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NOT\n"); (yyval.f_val) = (yyvsp[0].f_val); 
			 fprintf(file, "\ticonst_1\n");
			fprintf(file, "\tixor\n"); }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 588 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val); }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 592 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[-3].f_val);
		if(mid == 1 ){
			if((yyvsp[-3].f_val) == 5) fprintf(file, "\tiaload\n");
			if((yyvsp[-3].f_val) == 6) fprintf(file, "\tfaload\n"); 
		}
	 }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 600 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = (yyvsp[0].f_val);}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 601 "compiler_hw3.y" /* yacc.c:1646  */
    {//printf("enter ident"); 
				int temp = lookup_symbol((yyvsp[0].s_val), scope_flag, 2);
				now_id = temp;
				if(mid == 0)	pre_id = now_id;			

				if(temp == -1){
					printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].s_val));
					error_count++;				
				}

			else{

				if(symbol_table[temp].type_mode == 1){
					//printf("xcvxcv\n");
					//$$ = symbol_table[temp].int_value;
					(yyval.f_val) = 1;
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					print_mode = 1;
					fprintf(file, "\tiload %d\n", temp);                	  	
				}
				else if(symbol_table[temp].type_mode == 2){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);

					(yyval.f_val) = 2;
					print_mode = 2;
					fprintf(file, "\tfload %d\n", temp);                	  	
				}
				else if(symbol_table[temp].type_mode == 3){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					(yyval.f_val) = 3;
					print_mode = 3;
					fprintf(file, "\taload %d\n", temp);
				}
				else if(symbol_table[temp].type_mode == 4){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					(yyval.f_val) = 4;
					print_mode = 4;
					if(print_flag) { 
						if(symbol_table[temp].int_value == 1) fprintf(file, "\ticonst_1\n");
						else fprintf(file, "\ticonst_0\n");
					}
					else{ fprintf(file, "\tiload %d\n", temp); }
				}
				else if(symbol_table[temp].type_mode == 5){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					(yyval.f_val) = 5;
					print_mode = 5; 
					array_mode = 1; 
					fprintf(file, "\taload %d\n", temp);
					//fprintf(file, "swap\n");
					//fprintf(file, "\tiaload\n");              	  	
				}
				else if(symbol_table[temp].type_mode == 6){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					(yyval.f_val) = 6;
					print_mode = 6;                	  	
					array_mode = 2;	
					fprintf(file, "\taload %d\n", temp);
			
				}
				}

}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 667 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = 7; printf("INT_LIT %d\n", (yyvsp[0].i_val)); 
				print_mode = 1; 
				fprintf(file, "\tldc %d\n", (int)(yyvsp[0].i_val)); }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 671 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = 8; printf("FLOAT_LIT %.6f\n", (yyvsp[0].f_val)); 	
				print_mode = 2; 	
				fprintf(file, "\tldc %f\n", (yyvsp[0].f_val)); }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 674 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = 9; printf("STRING_LIT %s\n", (yyvsp[0].s_val)); 
			string_value = strdup((yyvsp[0].s_val)); 
			print_mode = 3; 
			fprintf(file, "\tldc \"%s\"\n", string_value);
			}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 679 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.f_val) = 10; print_mode = 4; 

//printf("%s\n", $1);
			bool_value = strdup((yyvsp[0].s_val));
			if(strcmp((yyvsp[0].s_val),"true") == 0) { fprintf(file, "\ticonst_1\n"); bool_val =1; }
			else if( strcmp((yyvsp[0].s_val),"false") == 0) { fprintf(file, "\ticonst_0\n"); bool_val = 0; }
			}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 688 "compiler_hw3.y" /* yacc.c:1646  */
    {
	     				 	if((yyvsp[-3].i_val) == 1) {
							if(print_mode == 2){
								printf("F to I\n");
								fprintf(file, "\tf2i\n");
							}
						} 
						else if((yyvsp[-3].i_val) == 2) {
							if(print_mode == 1 ){
								printf("I to F\n"); 
								fprintf(file, "\ti2f\n");
							}
						}
						(yyval.f_val) = (yyvsp[-3].i_val);
					}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 706 "compiler_hw3.y" /* yacc.c:1646  */
    { 
	if((yyvsp[0].f_val) == 1 || (yyvsp[0].f_val) == 7) { printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1); error_count++; }
	if((yyvsp[0].f_val) == 2 || (yyvsp[0].f_val) == 8) { printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);  error_count++;}
}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 713 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		scope_flag++ ; for_flag++;  
		if( ftype == 1) {
			fprintf(file,	"\tifeq FExit_%d%d\n", scope_flag, fexit_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		if( ftype == 2) {
			fprintf(file,	"\tifeq FLable_%d%d\n", for_flag, flabel_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		/*
		if( fornum ) {
			fprintf(file,	"\tifeq For_exit%d\n", fornum);
		}
		*/
			
	}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if( ftype == 1) { 
		fprintf(file,	"FExit_%d%d:\n", for_flag, exit_num[for_flag]);
		}
		if( ftype == 2) {
			//fprintf(file,	"\tifeq FLable_%d%d\n", for_flag, flabel_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		exit_num[for_flag]++;
		dump_symbol(); scope_flag-- ; for_flag--; 
	}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 745 "compiler_hw3.y" /* yacc.c:1646  */
    { ftype = 1; }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 745 "compiler_hw3.y" /* yacc.c:1646  */
    {
		//fprintf(file,	"\tifeq FLabel_%d%d\n", scope_flag, label_num[scope_flag]);
		
		
		printf("%d\n", ftype);	
		//fprintf(file,	"FLabel_%d%d:\n", scope_flag, label_num[scope_flag]);
		

	//	fprintf(file,	"FExit_%d%d:\n", for_flag, exit_num[for_flag]);
	//	exit_num[for_flag]++;
	}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 756 "compiler_hw3.y" /* yacc.c:1646  */
    { ftype = 21; }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 756 "compiler_hw3.y" /* yacc.c:1646  */
    { ftype = 22; }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 756 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%d\n", ftype); }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 757 "compiler_hw3.y" /* yacc.c:1646  */
    { ftype = 3; }
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 757 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%d\n", ftype); }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 762 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("hi\n"); 
	
		fornum++;
		fprintf(file,	"For_begin%d:\n", fornum);
		printf("%d\n", fornum); 
	}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 774 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		fprintf(file,	"\tgoto For_begin%d\n", fornum); 
		fprintf(file,	"For_exit%d:\n", fornum);
		fornum--;
		}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 780 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file, "Fblock_%d:\n", fornum); }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 782 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file,	"\tgoto For_action%d\n", fornum); 
		fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]-1);
		fornum--;
		exit_num[scope_flag]++;
	}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 791 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file, "For_semi%d:\n", fornum); }
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 792 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 793 "compiler_hw3.y" /* yacc.c:1646  */
    {
	fprintf(file, "\tgoto Fblock_%d\n", fornum);
	fprintf(file, "For_action%d:\n", fornum); 
	}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 797 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file, "\tgoto For_semi%d\n", fornum); }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 800 "compiler_hw3.y" /* yacc.c:1646  */
    { print_flag++; mid = 1; }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 801 "compiler_hw3.y" /* yacc.c:1646  */
    {
						 	
					if(print_mode == 1)	{ 
	 						if(array_mode == 2){ printf("PRINT float32\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(F)V\n" );
							}						
							else{
							printf("PRINT int32\n");
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(I)V\n" );	

} 
						}
					else if(print_mode == 2){
							printf("PRINT float32\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(F)V\n" );	
							} 

					else if(print_mode == 3 | print_mode ==9){ printf("PRINT string\n"); }
					else if(print_mode == 4 | print_mode == 10){ 
						printf("PRINT bool\n"); 
						
						fprintf(file,	"\tifne Label_%d%d\n", scope_flag, label_num[scope_flag]);
						fprintf(file,	"\tldc \"false\"\n" );
						fprintf(file,	"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
						
						fprintf(file,	"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
						fprintf(file,	"\tldc \"true\"\n");

						fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]);
						fprintf(file,	"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(file,	"\tswap\n");
						fprintf(file,	"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");									
						
						label_num[scope_flag]++;
						exit_num[scope_flag]++;					
						}
						print_flag--;
						mid = 0; 
					;
			}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 847 "compiler_hw3.y" /* yacc.c:1646  */
    { print_flag++; mid = 1; }
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 847 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("print_mode: %d\n", print_mode);	
						if(print_mode == 1)	{ 
							if(array_mode == 2){ 
								printf("PRINTLN float32\n"); 
								fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
										"\tswap\n"
										"\tinvokevirtual java/io/PrintStream/println(F)V\n\n" );
							}						
							else{ printf("PRINTLN int32\n");
								fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
										"\tswap\n"
										"\tinvokevirtual java/io/PrintStream/println(I)V\n\n" );	
							} 
						}
						else if(print_mode == 2){ 
							printf("PRINTLN float32\n");
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									 "\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(F)V\n\n" );
						 }
						else if(print_mode == 3 | print_mode == 9){ 
							printf("PRINTLN string\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n" );
						}
						else if(print_mode == 4 | print_mode == 10){ printf("PRINTLN bool\n");
							fprintf(file,	"\tifne Label_%d%d\n", scope_flag, label_num[scope_flag]);
							fprintf(file,	"\tldc \"false\"\n" );
							fprintf(file,	"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
						
							fprintf(file,	"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
							fprintf(file,	"\tldc \"true\"\n");
	
							fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]);
							fprintf(file,	"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
							fprintf(file,	"\tswap\n");
							fprintf(file,	"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");									
						
						label_num[scope_flag]++;
						exit_num[scope_flag]++;				
						 }
						print_flag--;
						mid  = 0 ;
					;}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 893 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INC\n");  //has error

if((yyvsp[-1].f_val) == 1 || (yyvsp[-1].f_val) == 7){

fprintf(file, "\tldc 1\n");
				fprintf(file, "\tiadd\n");
				fprintf(file, "\tistore %d\n", now_id);               			
				}
				else if((yyvsp[-1].f_val) == 2 || (yyvsp[-1].f_val) == 8){

fprintf(file, "\tldc 1.000000\n");
				fprintf(file, "\tfadd\n");
				fprintf(file, "\tfstore %d\n", now_id);
				}


}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 910 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("DEC\n"); 
				if((yyvsp[-1].f_val) == 1 || (yyvsp[-1].f_val) == 7){

fprintf(file, "\tldc 1\n");
				fprintf(file, "\tisub\n");
				fprintf(file, "\tistore %d\n", now_id);      
				}
				else if((yyvsp[-1].f_val) == 2 || (yyvsp[-1].f_val) == 8){

fprintf(file, "\tldc 1.000000\n");
				fprintf(file, "\tfsub\n");
				fprintf(file, "\tfstore %d\n", now_id);      
				}		
			}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 925 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 926 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[0].i_val); }
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 930 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 931 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 932 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 3; }
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 933 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 4; }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 936 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					if((yyvsp[0].i_val) == 1) {
					(yyval.i_val) = 5 ;
			 		fprintf(file, "\tnewarray int\n");
					}

					if((yyvsp[0].i_val) == 2) {
					(yyval.i_val) = 6; 
					fprintf(file, "\tnewarray float\n");
					}
}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2692 "y.tab.c" /* yacc.c:1646  */
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
#line 947 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
	yyin = fopen(argv[1], "r");
    } else {
	yyin = stdin;
    }

	file = fopen("hw3.j","w");
	fprintf(file,   
		    ".source hw3.j\n"  
		    ".class public Main\n"
		    ".super java/lang/Object\n"
		    ".method public static main([Ljava/lang/String;)V\n"
		    ".limit stack %d\n"
		    ".limit locals %d\n", 100, 100);


	yylineno = 0;
    	yyparse();

	dump_symbol();
	printf("Total lines: %d\n", yylineno);


	fprintf(file,   "\treturn\n"
			    ".end method\n");
	fclose(file);
    	fclose(yyin);
    	
	if(error_count>0){
		remove("hw3.j");
	}
	return 0;
}
/*
static void create_symbol() {
}
*/
static void assign_symbol(int type, double data)
{/*
    if(type == 1){        

fprintf(file,"\tistore %d\n", id);
    }

else if(type == 2){


fprintf(file,"\tistore %d\n", id);

}
	else if(type == 5){


fprintf(file,"\tiastore %d\n", id);

}
	else if(type == 6){


fprintf(file,"\tfastore %d\n", id);

}
	*/

}
//inset
static void insert_symbol(char* name, char* types, int type_modes) {
	printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope_flag);
	strcpy(symbol_table[var_num].type, types);
	strcpy(symbol_table[var_num].name, name);
	strcpy(symbol_table[var_num].element, "-");
	symbol_table[var_num].address = address_num;
	symbol_table[var_num].lineno = yylineno;

symbol_table[var_num].type_mode = type_modes;

//	symbol_table[var_num].assign_bit = 0;
	symbol_table[var_num].scope = scope_flag;

if(type_modes == 5) { strcpy(symbol_table[var_num].type, "array"); strcpy(symbol_table[var_num].element,"int32");} 

if(type_modes == 6) { strcpy(symbol_table[var_num].type, "array"); strcpy(symbol_table[var_num].element,"float32");}
	//printf("insert completion");
	address_num++;
	var_num++;
	//f_bit = for_flag;
}

//lookup symbol
int lookup_symbol(char* id, int flag, int check) {
	int i;
	int temp = flag;
	
	if(for_flag == 0 ){ 
		if(check == 1){//when declare
			for(i = 0; i < var_num; i++){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope == temp && symbol_table[i].be_dumped == 0){//same scope
			//printf("%d",i);
			return i;
			}
			}
		}
		if(check == 2){ //normal
			for(i = var_num-1 ; i >=0; i--){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope <= temp && symbol_table[i].be_dumped == 0 ){
			//printf("%d",i);
			return i;
			}
			}
		}
		
	}
	else if(for_flag > 0){//fblock
		for(i = var_num-1 ; i >=0; i--){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope <= temp && symbol_table[i].be_dumped == 0 ){
			//printf("%d",i);
			return i;
			}
		}
	}

	return -1;
}

void dump_symbol() {
	int i, index = 0;
    printf("> Dump symbol table (scope level: %d)\n", scope_flag);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
	   "Index", "Name", "Type", "Address", "Lineno", "Element type");
	for(i = 0; i < var_num; i++){
		if(symbol_table[i].scope == scope_flag && symbol_table[i].be_dumped == 0){

printf("%-10d%-10s%-10s%-10d%-10d%s\n",
			index, symbol_table[i].name, symbol_table[i].type, symbol_table[i].address, symbol_table[i].lineno, symbol_table[i].element);
		index++;
		symbol_table[i].be_dumped = 1;		
		}	
	}
}




