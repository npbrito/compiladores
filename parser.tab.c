/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "parser.y"


#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "hash.h"
#include "stack.h"

void yyerror(char const *s);
void replace_name(lexeme_t *lex, const char *str);
extern int yylex(void);
extern int yylineno;
extern void *arvore;
StackNode* global_scope = NULL;
hash_element* stored_element = NULL;
extern HashTable * table;


#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_PR_END = 283,
    TK_PR_DEFAULT = 284,
    TK_OC_LE = 285,
    TK_OC_GE = 286,
    TK_OC_EQ = 287,
    TK_OC_NE = 288,
    TK_OC_AND = 289,
    TK_OC_OR = 290,
    TK_OC_SL = 291,
    TK_OC_SR = 292,
    TK_LIT_INT = 293,
    TK_LIT_FLOAT = 294,
    TK_LIT_FALSE = 295,
    TK_LIT_TRUE = 296,
    TK_LIT_CHAR = 297,
    TK_LIT_STRING = 298,
    TK_IDENTIFICADOR = 299,
    TOKEN_ERRO = 300,
    TYPE_FUNC_CALL = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    lexeme_t *lex_value;
    node_t *tree_node;
    int type;

#line 194 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    48,     2,    49,    50,     2,
      68,    69,    51,    52,    70,    53,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    66,
      55,    56,    57,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    67,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    60,    47,     2,     2,     2,     2,
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
      62,    63,    65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   161,   163,   164,   165,   172,   176,   177,
     180,   181,   182,   183,   184,   185,   187,   195,   196,   197,
     198,   199,   201,   202,   204,   205,   207,   208,   209,   210,
     218,   220,   221,   223,   224,   226,   230,   232,   233,   235,
     236,   240,   244,   245,   247,   248,   253,   258,   259,   262,
     263,   264,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   291,   293,   294,   295,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   316,
     318,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   335,   337,   338,   342,   346,   347,
     348,   350,   352,   353,   355,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_PR_END", "TK_PR_DEFAULT", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_SL", "TK_OC_SR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "'!'", "'{'", "'}'",
  "'#'", "'%'", "'&'", "'*'", "'+'", "'-'", "'/'", "'<'", "'='", "'>'",
  "'?'", "'^'", "'|'", "'['", "TOKEN_ERRO", "TYPE_FUNC_CALL", "':'",
  "\"(\"", "';'", "']'", "'('", "')'", "','", "$accept", "Init", "Start",
  "Program", "ID", "IDArray", "Lit", "Int", "TypeBase", "TypeStatic",
  "TypeConst", "TypeStaticConst", "FuncDecl", "ParamsDecl",
  "ParamDeclList", "ParamDecl", "FuncCall", "ParamsCall", "ParamCallList",
  "GlobalVarDecl", "GlobalVarList", "GlobalVar", "LocalVarDecl",
  "LocalVarList", "LocalVar", "Expr", "UnaryExpr", "UnarySet",
  "CreateScope", "DestroyScope", "Cmd", "CmdBlock", "CmdSeq", "Assignment",
  "ControlFlow", "If", "Else", "For", "While", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    33,   123,   125,    35,    37,
      38,    42,    43,    45,    47,    60,    61,    62,    63,    94,
     124,    91,   300,   301,    58,   302,    59,    93,    40,    41,
      44
};
# endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -88,    23,    19,   -88,   -88,   -88,   -88,   -88,    56,   -88,
     -88,   -24,    23,   -43,   -88,   -88,   -88,   -46,   -88,   -49,
     -88,    23,    -6,   136,   -24,   -88,   -34,    56,   -88,   -24,
     -35,   -88,   -20,     3,   -88,   -88,   -88,   -88,    31,   136,
     -88,   113,   -88,   -88,    15,    40,   -24,   133,   347,    56,
     175,    42,   -88,   -88,    20,   -25,   -88,    43,   -88,   -88,
      18,   -88,    65,   -88,   -88,   -88,   -88,   -88,   347,   347,
      52,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     133,   133,   133,   133,   133,   133,   133,   347,   -88,   -88,
     -88,   324,   -88,   -88,   -88,    56,   -88,   -24,   347,   347,
      77,    77,   347,    92,    95,   -88,    61,   113,   -88,   -88,
     166,   179,    -3,    -3,    -4,    -3,    34,    34,   430,   210,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   -88,    78,    69,
     223,    75,   -88,   135,   -88,   -88,   -88,   324,   133,    43,
     -88,    31,   134,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   242,   242,   402,   402,   371,   386,    86,    21,    86,
     -45,   -45,    86,   242,   242,   254,   -88,   417,   347,   -88,
     -88,   347,   -88,   -88,   -88,   138,    31,   347,   289,   -88,
      31,   -88,   -88,   324,   -24,   -88,    81,    31,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     0,    17,    18,    19,    20,    21,     0,     3,
      22,     0,     4,     0,     1,    23,     7,    44,    41,    42,
       6,     4,     0,    31,     0,     5,     0,     0,    24,     0,
       0,    32,    33,    44,    43,    45,    25,    35,     0,     0,
      89,   105,    30,    34,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,     8,     0,    26,     0,    97,    91,
       0,    96,     0,    92,   103,   108,   109,   110,     0,     0,
       8,    93,    10,    11,    13,    12,    14,    15,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,   100,    52,    53,    28,     0,    27,     0,     0,    37,
       0,     0,     0,    49,     0,    46,    47,   105,    90,   104,
       0,     0,    84,    88,    85,    86,    82,    83,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,    38,    39,    16,    98,    99,   107,     0,     0,
     106,     0,     0,    77,    81,    78,    79,    75,    76,    80,
      71,    66,    67,    64,    65,    68,    69,    58,    60,    56,
      54,    55,    57,    62,    63,     0,    61,    59,     0,     9,
      36,     0,    50,    51,    48,   112,     0,     0,     0,    40,
       0,   111,   115,    70,     0,   113,     0,     0,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,     4,   -11,   -39,   -42,    50,    16,   -88,
     -88,   -88,   -88,   -88,   115,   -88,   -38,   -88,   -23,   -88,
     137,   -88,   -88,    13,   -88,   -31,   245,   248,   -88,   -88,
     -88,   -37,    57,   -87,   -88,   -88,   -88,   -88,   -88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    54,    88,    89,   145,    10,    11,
      29,    57,    12,    30,    31,    32,    90,   141,   142,    13,
      18,    19,    59,   105,   106,   143,    92,    93,    41,   109,
      60,    61,    62,    63,    64,    65,   191,    66,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    42,    55,    58,   126,    79,   128,    71,    78,   131,
     139,   100,   101,    33,   135,    22,    20,    91,    37,    14,
      16,    24,    23,    21,    15,    25,     3,     4,     5,     6,
       7,   102,    26,    35,    38,    70,    70,   110,   111,    28,
       8,    80,    80,    36,    81,    81,   104,    83,    84,    85,
      39,   120,   121,   122,   123,    28,   119,    56,   138,     3,
       4,     5,     6,     7,    22,    94,    96,   140,    55,    58,
     126,   147,   128,   129,   130,   131,   132,    40,   133,    80,
     135,    98,    81,    68,   107,    83,    70,   103,    99,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   183,   196,    69,   182,
      97,   137,   108,    98,   185,   144,     3,     4,     5,     6,
       7,    44,    -7,    56,    45,   148,    46,    47,    48,    49,
      50,   149,    51,   178,   102,    52,    53,    70,   104,     3,
       4,     5,     6,     7,   180,   135,   186,   188,   190,   192,
     197,   146,    27,   195,    43,   138,   193,    16,   189,    40,
     198,    34,   184,     0,   150,   120,   121,   122,   123,   124,
     125,    72,    73,    74,    75,    76,    77,    16,     3,     4,
       5,     6,     7,    70,   126,   127,   128,   129,   130,   131,
     132,    95,   133,   134,   135,   136,   120,   121,   122,   123,
     124,   125,     0,     0,     0,   181,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   133,   134,   135,   136,     0,   126,   127,
     128,   129,   130,   131,   132,   151,   133,   134,   135,   136,
     120,   121,   122,   123,   124,   125,     0,     0,   152,     0,
       0,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,   133,   134,   135,
     136,     0,   126,   127,   128,   129,   130,   131,   132,   160,
     133,   134,   135,   136,   120,   121,   122,   123,   124,   125,
     179,   126,     0,   128,   129,   130,   131,     0,     0,     0,
       0,   135,     0,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   134,   135,   136,     0,     0,     0,   187,   120,
     121,   122,   123,   124,   125,   112,   113,   114,   115,   116,
     117,   118,     0,     0,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   134,   135,   136,
       0,     0,     0,   194,   120,   121,   122,   123,   124,   125,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
       0,     0,     0,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   134,   135,   136,    72,    73,    74,    75,    76,
      77,    16,    80,     0,     0,    81,     0,    82,    83,    84,
      85,   120,   121,   122,   123,    86,   125,     0,     0,     0,
       0,     0,     0,     0,     0,    87,   120,   121,   122,   123,
     126,   127,   128,   129,   130,   131,   132,     0,   133,     0,
     135,   136,   120,   121,     0,   126,   127,   128,   129,   130,
     131,   132,     0,   133,     0,   135,   136,   120,   121,   122,
     123,   126,     0,   128,   129,   130,   131,   132,     0,   133,
       0,   135,     0,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,     0,   133,    80,   135,     0,    81,     0,
      82,    83,    84,    85,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
      11,    38,    41,    41,    49,    47,    51,    46,    47,    54,
      97,    36,    37,    24,    59,    61,    12,    48,    29,     0,
      44,    70,    68,    66,     8,    21,     3,     4,     5,     6,
       7,    56,    38,    67,    69,    46,    47,    68,    69,    23,
      17,    45,    45,    27,    48,    48,    57,    51,    52,    53,
      70,    30,    31,    32,    33,    39,    87,    41,    97,     3,
       4,     5,     6,     7,    61,    49,    50,    98,   107,   107,
      49,   102,    51,    52,    53,    54,    55,    46,    57,    45,
      59,    61,    48,    68,    66,    51,    97,    44,    68,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   148,   194,    68,   148,
      68,    95,    47,    61,   151,    38,     3,     4,     5,     6,
       7,     8,    30,   107,    11,    30,    13,    14,    15,    16,
      17,    70,    19,    64,    56,    22,    23,   148,   149,     3,
       4,     5,     6,     7,    69,    59,    12,   178,    10,   186,
      69,   101,    16,   190,    39,   194,   187,    44,   181,    46,
     197,    24,   149,    -1,   107,    30,    31,    32,    33,    34,
      35,    38,    39,    40,    41,    42,    43,    44,     3,     4,
       5,     6,     7,   194,    49,    50,    51,    52,    53,    54,
      55,    16,    57,    58,    59,    60,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    70,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    -1,    49,    50,
      51,    52,    53,    54,    55,    69,    57,    58,    59,    60,
      30,    31,    32,    33,    34,    35,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    -1,    49,    50,    51,    52,    53,    54,    55,    69,
      57,    58,    59,    60,    30,    31,    32,    33,    34,    35,
      67,    49,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    -1,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    64,    30,
      31,    32,    33,    34,    35,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    30,    31,    32,    33,    34,    35,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    30,    31,    32,    33,    58,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    30,    31,    32,    33,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      59,    60,    30,    31,    -1,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    30,    31,    32,
      33,    49,    -1,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    45,    59,    -1,    48,    -1,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    73,     3,     4,     5,     6,     7,    17,    74,
      79,    80,    83,    90,     0,    79,    44,    75,    91,    92,
      74,    66,    61,    68,    70,    74,    38,    16,    79,    81,
      84,    85,    86,    75,    91,    67,    79,    75,    69,    70,
      46,    99,   102,    85,     8,    11,    13,    14,    15,    16,
      17,    19,    22,    23,    75,    76,    79,    82,    87,    93,
     101,   102,   103,   104,   105,   106,   108,   109,    68,    68,
      75,    76,    38,    39,    40,    41,    42,    43,    76,    77,
      45,    48,    50,    51,    52,    53,    58,    68,    76,    77,
      87,    96,    97,    98,    79,    16,    79,    68,    61,    68,
      36,    37,    56,    44,    75,    94,    95,    66,    47,   100,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    96,
      30,    31,    32,    33,    34,    35,    49,    50,    51,    52,
      53,    54,    55,    57,    58,    59,    60,    79,    76,   104,
      96,    88,    89,    96,    38,    78,    78,    96,    30,    70,
     103,    69,    69,    98,    98,    98,    98,    98,    98,    98,
      69,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    64,    67,
      69,    70,    76,    77,    94,   102,    12,    64,    96,    89,
      10,   107,   102,    96,    64,   102,   104,    69,   102
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    74,    74,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    78,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      83,    84,    84,    85,    85,    86,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    93,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   103,   103,   104,   105,   105,
     105,   106,   107,   107,   108,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     3,     2,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     2,     3,
       6,     0,     1,     1,     3,     2,     4,     0,     1,     1,
       3,     2,     1,     3,     1,     4,     2,     1,     3,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     2,     1,     1,     3,     3,
       2,     1,     1,     1,     3,     0,     3,     3,     1,     1,
       1,     6,     0,     2,     9,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 158 "parser.y"
             {push(&global_scope, hash_create());}
#line 1690 "parser.tab.c"
    break;

  case 3:
#line 161 "parser.y"
                    { arvore = (yyvsp[0].tree_node); }
#line 1696 "parser.tab.c"
    break;

  case 4:
#line 163 "parser.y"
                                   { (yyval.tree_node) = NULL;             }
#line 1702 "parser.tab.c"
    break;

  case 5:
#line 164 "parser.y"
                                   { (yyval.tree_node) = (yyvsp[0].tree_node);               }
#line 1708 "parser.tab.c"
    break;

  case 6:
#line 165 "parser.y"
                                   { (yyval.tree_node) = add_node((yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 1714 "parser.tab.c"
    break;

  case 7:
#line 172 "parser.y"
                     { stored_element = store_identificador((yyvsp[0].lex_value)); 
                        (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);
                    }
#line 1722 "parser.tab.c"
    break;

  case 8:
#line 176 "parser.y"
                         { (yyval.tree_node) = (yyvsp[0].tree_node);                             }
#line 1728 "parser.tab.c"
    break;

  case 9:
#line 177 "parser.y"
                         { replace_name((yyvsp[-2].lex_value), "[]");
                           (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 2, (yyvsp[-3].tree_node), (yyvsp[-1].tree_node));}
#line 1735 "parser.tab.c"
    break;

  case 10:
#line 180 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1741 "parser.tab.c"
    break;

  case 11:
#line 181 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1747 "parser.tab.c"
    break;

  case 12:
#line 182 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1753 "parser.tab.c"
    break;

  case 13:
#line 183 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1759 "parser.tab.c"
    break;

  case 14:
#line 184 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1765 "parser.tab.c"
    break;

  case 15:
#line 185 "parser.y"
                   { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);}
#line 1771 "parser.tab.c"
    break;

  case 16:
#line 187 "parser.y"
                { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0); }
#line 1777 "parser.tab.c"
    break;

  case 17:
#line 195 "parser.y"
                       {(yyval.type) = TK_PR_INT;}
#line 1783 "parser.tab.c"
    break;

  case 18:
#line 196 "parser.y"
                       {(yyval.type) = TK_PR_FLOAT;}
#line 1789 "parser.tab.c"
    break;

  case 19:
#line 197 "parser.y"
                       {(yyval.type) = TK_PR_BOOL;}
#line 1795 "parser.tab.c"
    break;

  case 20:
#line 198 "parser.y"
                       {(yyval.type) = TK_PR_CHAR;}
#line 1801 "parser.tab.c"
    break;

  case 21:
#line 199 "parser.y"
                       {(yyval.type) = TK_PR_STRING;}
#line 1807 "parser.tab.c"
    break;

  case 22:
#line 201 "parser.y"
                                  {}
#line 1813 "parser.tab.c"
    break;

  case 23:
#line 202 "parser.y"
                                  {}
#line 1819 "parser.tab.c"
    break;

  case 24:
#line 204 "parser.y"
                                {}
#line 1825 "parser.tab.c"
    break;

  case 25:
#line 205 "parser.y"
                                {}
#line 1831 "parser.tab.c"
    break;

  case 26:
#line 207 "parser.y"
                                                   {}
#line 1837 "parser.tab.c"
    break;

  case 27:
#line 208 "parser.y"
                                                   {}
#line 1843 "parser.tab.c"
    break;

  case 28:
#line 209 "parser.y"
                                                   {}
#line 1849 "parser.tab.c"
    break;

  case 29:
#line 210 "parser.y"
                                                   {}
#line 1855 "parser.tab.c"
    break;

  case 30:
#line 218 "parser.y"
                                                    { (yyval.tree_node) = add_node((yyvsp[-4].tree_node), (yyvsp[0].tree_node)); }
#line 1861 "parser.tab.c"
    break;

  case 31:
#line 220 "parser.y"
                          {}
#line 1867 "parser.tab.c"
    break;

  case 32:
#line 221 "parser.y"
                          {}
#line 1873 "parser.tab.c"
    break;

  case 33:
#line 223 "parser.y"
                                           {}
#line 1879 "parser.tab.c"
    break;

  case 34:
#line 224 "parser.y"
                                           {}
#line 1885 "parser.tab.c"
    break;

  case 35:
#line 226 "parser.y"
                        { destroy_node((yyvsp[0].tree_node)); }
#line 1891 "parser.tab.c"
    break;

  case 36:
#line 230 "parser.y"
                                { ((yyvsp[-3].tree_node))->lex_value->type = TYPE_FUNC_CALL; (yyval.tree_node) = add_node((yyvsp[-3].tree_node), (yyvsp[-1].tree_node)); }
#line 1897 "parser.tab.c"
    break;

  case 37:
#line 232 "parser.y"
                          { (yyval.tree_node) = NULL; }
#line 1903 "parser.tab.c"
    break;

  case 38:
#line 233 "parser.y"
                          { (yyval.tree_node) = (yyvsp[0].tree_node);   }
#line 1909 "parser.tab.c"
    break;

  case 39:
#line 235 "parser.y"
                                      { (yyval.tree_node) = (yyvsp[0].tree_node);               }
#line 1915 "parser.tab.c"
    break;

  case 40:
#line 236 "parser.y"
                                      { (yyval.tree_node) = add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 1921 "parser.tab.c"
    break;

  case 41:
#line 240 "parser.y"
                                        { HashTable *table = top(global_scope);
                                        hash_insert(&table, stored_element, (yyvsp[-1].type));
                                        }
#line 1929 "parser.tab.c"
    break;

  case 42:
#line 244 "parser.y"
                                           {}
#line 1935 "parser.tab.c"
    break;

  case 43:
#line 245 "parser.y"
                                           {}
#line 1941 "parser.tab.c"
    break;

  case 44:
#line 247 "parser.y"
                   {store_nature(&stored_element, 0);}
#line 1947 "parser.tab.c"
    break;

  case 45:
#line 248 "parser.y"
                                 {store_nature(&stored_element, 1); }
#line 1953 "parser.tab.c"
    break;

  case 46:
#line 253 "parser.y"
                                          { (yyval.tree_node) = (yyvsp[0].tree_node); 
                                        HashTable *table = top(global_scope);
                                        hash_insert(&table, stored_element, (yyvsp[-1].type));
                                        }
#line 1962 "parser.tab.c"
    break;

  case 47:
#line 258 "parser.y"
                                        { (yyval.tree_node) = (yyvsp[0].tree_node);                                     }
#line 1968 "parser.tab.c"
    break;

  case 48:
#line 259 "parser.y"
                                        { (yyval.tree_node) = ((yyvsp[-2].tree_node)) == NULL ? ((yyvsp[0].tree_node)) : add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 1974 "parser.tab.c"
    break;

  case 49:
#line 262 "parser.y"
                                              { stored_element = store_identificador((yyvsp[0].lex_value)); (yyval.tree_node) = NULL;}
#line 1980 "parser.tab.c"
    break;

  case 50:
#line 263 "parser.y"
                              { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 1986 "parser.tab.c"
    break;

  case 51:
#line 264 "parser.y"
                              { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 1992 "parser.tab.c"
    break;

  case 52:
#line 271 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                             }
#line 1998 "parser.tab.c"
    break;

  case 53:
#line 272 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                             }
#line 2004 "parser.tab.c"
    break;

  case 54:
#line 273 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2010 "parser.tab.c"
    break;

  case 55:
#line 274 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2016 "parser.tab.c"
    break;

  case 56:
#line 275 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2022 "parser.tab.c"
    break;

  case 57:
#line 276 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2028 "parser.tab.c"
    break;

  case 58:
#line 277 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2034 "parser.tab.c"
    break;

  case 59:
#line 278 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2040 "parser.tab.c"
    break;

  case 60:
#line 279 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2046 "parser.tab.c"
    break;

  case 61:
#line 280 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2052 "parser.tab.c"
    break;

  case 62:
#line 281 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2058 "parser.tab.c"
    break;

  case 63:
#line 282 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2064 "parser.tab.c"
    break;

  case 64:
#line 283 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2070 "parser.tab.c"
    break;

  case 65:
#line 284 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2076 "parser.tab.c"
    break;

  case 66:
#line 285 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2082 "parser.tab.c"
    break;

  case 67:
#line 286 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2088 "parser.tab.c"
    break;

  case 68:
#line 287 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2094 "parser.tab.c"
    break;

  case 69:
#line 288 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2100 "parser.tab.c"
    break;

  case 70:
#line 289 "parser.y"
                             { replace_name((yyvsp[-3].lex_value), "?:");
                               (yyval.tree_node) = create_node((yyvsp[-3].lex_value), 3, (yyvsp[-4].tree_node), (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2107 "parser.tab.c"
    break;

  case 71:
#line 291 "parser.y"
                             { (yyval.tree_node) = (yyvsp[-1].tree_node);                             }
#line 2113 "parser.tab.c"
    break;

  case 72:
#line 293 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2119 "parser.tab.c"
    break;

  case 73:
#line 294 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2125 "parser.tab.c"
    break;

  case 74:
#line 295 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2131 "parser.tab.c"
    break;

  case 75:
#line 297 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2137 "parser.tab.c"
    break;

  case 76:
#line 298 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2143 "parser.tab.c"
    break;

  case 77:
#line 299 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2149 "parser.tab.c"
    break;

  case 78:
#line 300 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2155 "parser.tab.c"
    break;

  case 79:
#line 301 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2161 "parser.tab.c"
    break;

  case 80:
#line 302 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2167 "parser.tab.c"
    break;

  case 81:
#line 303 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2173 "parser.tab.c"
    break;

  case 82:
#line 304 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2179 "parser.tab.c"
    break;

  case 83:
#line 305 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2185 "parser.tab.c"
    break;

  case 84:
#line 306 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2191 "parser.tab.c"
    break;

  case 85:
#line 307 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2197 "parser.tab.c"
    break;

  case 86:
#line 308 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2203 "parser.tab.c"
    break;

  case 87:
#line 309 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2209 "parser.tab.c"
    break;

  case 88:
#line 310 "parser.y"
                                 { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2215 "parser.tab.c"
    break;

  case 89:
#line 316 "parser.y"
                 { push(&global_scope, hash_create());}
#line 2221 "parser.tab.c"
    break;

  case 90:
#line 318 "parser.y"
                  { hash_print(top(global_scope)); pop(&global_scope); hash_print(top(global_scope));}
#line 2227 "parser.tab.c"
    break;

  case 91:
#line 321 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2233 "parser.tab.c"
    break;

  case 92:
#line 322 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2239 "parser.tab.c"
    break;

  case 93:
#line 323 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2245 "parser.tab.c"
    break;

  case 94:
#line 324 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2251 "parser.tab.c"
    break;

  case 95:
#line 325 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2257 "parser.tab.c"
    break;

  case 96:
#line 326 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2263 "parser.tab.c"
    break;

  case 97:
#line 327 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2269 "parser.tab.c"
    break;

  case 98:
#line 328 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2275 "parser.tab.c"
    break;

  case 99:
#line 329 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2281 "parser.tab.c"
    break;

  case 100:
#line 330 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2287 "parser.tab.c"
    break;

  case 101:
#line 331 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);         }
#line 2293 "parser.tab.c"
    break;

  case 102:
#line 332 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[0].lex_value), 0);         }
#line 2299 "parser.tab.c"
    break;

  case 103:
#line 333 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2305 "parser.tab.c"
    break;

  case 104:
#line 335 "parser.y"
                                          { (yyval.tree_node) = (yyvsp[-1].tree_node);}
#line 2311 "parser.tab.c"
    break;

  case 105:
#line 337 "parser.y"
                        { (yyval.tree_node) = NULL;                                   }
#line 2317 "parser.tab.c"
    break;

  case 106:
#line 338 "parser.y"
                        { (yyval.tree_node) = ((yyvsp[-2].tree_node)) == NULL ? ((yyvsp[0].tree_node)) : add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2323 "parser.tab.c"
    break;

  case 107:
#line 342 "parser.y"
                             { (yyval.tree_node) = create_node((yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2329 "parser.tab.c"
    break;

  case 108:
#line 346 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2335 "parser.tab.c"
    break;

  case 109:
#line 347 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2341 "parser.tab.c"
    break;

  case 110:
#line 348 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2347 "parser.tab.c"
    break;

  case 111:
#line 350 "parser.y"
                                        { (yyval.tree_node) = create_node((yyvsp[-5].lex_value), 3, (yyvsp[-3].tree_node), (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2353 "parser.tab.c"
    break;

  case 112:
#line 352 "parser.y"
                          { (yyval.tree_node) = NULL; }
#line 2359 "parser.tab.c"
    break;

  case 113:
#line 353 "parser.y"
                          { (yyval.tree_node) = (yyvsp[0].tree_node);   }
#line 2365 "parser.tab.c"
    break;

  case 114:
#line 355 "parser.y"
                                                                   { (yyval.tree_node) = create_node((yyvsp[-8].lex_value), 4, (yyvsp[-6].tree_node), (yyvsp[-4].tree_node), (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2371 "parser.tab.c"
    break;

  case 115:
#line 357 "parser.y"
                                                  { (yyval.tree_node) = create_node((yyvsp[-5].lex_value), 2, (yyvsp[-3].tree_node), (yyvsp[0].tree_node)); }
#line 2377 "parser.tab.c"
    break;


#line 2381 "parser.tab.c"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 361 "parser.y"



void replace_name(lexeme_t *lex, const char *str)
{
    free(lex->name);
    lex->name = strdup(str);
}

void yyerror(char const *s)
{
    fprintf(stderr, "At line %d: %s\n", yylineno, s);
}
