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
#include "list.h"
#include "misc.h"
#include "semantic.h"

void yyerror(char const *s);
void replace_name(lexeme_t *lex, const char *str);
extern int yylex(void);
extern int yylineno;
extern void *arvore;
StackNode* global_scope = NULL;
ElementList* var_list = NULL;
ElementList* param_list = NULL;
hash_element* stored_element = NULL;
hash_element* stored_literal = NULL;
hash_element* stored_fun = NULL;


#line 94 "parser.tab.c"

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
#line 28 "parser.y"

    lexeme_t *lex_value;
    node_t *tree_node;
    int type;

#line 199 "parser.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   484

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

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
       0,   166,   166,   168,   169,   171,   172,   173,   181,   185,
     199,   216,   220,   226,   231,   235,   239,   243,   249,   257,
     258,   259,   260,   261,   263,   264,   266,   267,   269,   270,
     271,   272,   280,   283,   299,   300,   302,   303,   305,   311,
     329,   330,   332,   333,   337,   351,   352,   354,   356,   363,
     377,   378,   381,   384,   387,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   416,   418,   419,   420,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   441,   443,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   460,   462,   463,
     467,   471,   472,   473,   475,   477,   478,   480,   482
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
  "\"(\"", "';'", "']'", "'('", "')'", "','", "$accept", "Init", "End",
  "Start", "Program", "ID", "IDArray", "FunID", "Lit", "Int", "TypeBase",
  "TypeStatic", "TypeConst", "TypeStaticConst", "FuncDecl", "FuncHead",
  "ParamsDecl", "ParamDeclList", "ParamDecl", "FuncCall", "ParamsCall",
  "ParamCallList", "GlobalVarDecl", "GlobalVarList", "GlobalVar",
  "LocalVarDecl", "LocalVarList", "LocalVar", "Expr", "UnaryExpr",
  "UnarySet", "CreateScope", "DestroyScope", "Cmd", "CmdBlock", "CmdSeq",
  "Assignment", "ControlFlow", "If", "Else", "For", "While", YY_NULLPTR
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

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,   148,     7,   -90,   -90,   -90,   -90,   -90,   185,   -90,
     -90,   -31,   148,   -32,   -51,   -90,   -90,   -90,   -29,   -20,
     -23,   -90,   -15,   -90,   -90,    13,   -90,   148,    18,   155,
      14,    -5,     3,    14,   307,   332,   185,   279,     5,   -90,
     -90,    11,   -25,     9,   -90,    34,   -90,   -90,    -6,   -90,
      39,   -90,   -90,   -90,   -90,   -90,   -90,    20,   185,   -90,
      37,    19,   -90,    36,   -90,   -90,   332,   332,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   354,   354,   354,
     354,   354,   354,   354,   332,   -90,   -90,   -90,   309,   -90,
     -90,   -90,   185,   -90,    14,   332,    69,    69,   332,   332,
      86,    87,   -90,    48,    13,   -90,   -90,   -90,   -90,   -90,
     -90,   155,   151,   164,     4,     4,    31,     4,    -1,    -1,
      16,   195,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   -90,
      63,    58,   208,   -90,   -90,   -90,   309,    54,   -90,    80,
     307,    34,   -90,   -90,   -32,   112,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   261,   261,   115,   115,   356,   371,
      66,   411,    66,   -11,   -11,    66,   261,   261,   239,   -90,
     402,   332,   -90,   -90,   332,   -90,   -90,   -90,   117,   -32,
     332,   274,   -90,   -32,   -90,   -90,   309,    14,   -90,    67,
     -32,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     5,     0,    19,    20,    21,    22,    23,     0,     3,
      24,     0,     5,     0,     0,     1,    25,     4,     8,    47,
       0,    44,    45,     7,    92,   108,    32,     5,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,     9,     0,     0,    28,     0,   100,    94,     0,    99,
       0,    95,   106,   111,   112,   113,     6,     0,     0,    26,
       0,     0,    35,    36,     8,    46,     0,     0,    96,    12,
      13,    15,    14,    16,    17,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,   103,    55,
      56,    30,     0,    29,     0,     0,     0,     0,     0,    40,
      52,     0,    49,    50,   108,    93,   107,    48,    27,    38,
      33,     0,     0,     0,    87,    91,    88,    89,    85,    86,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,    18,   101,   102,   110,     0,    41,    42,
       0,     0,   109,    37,     0,     0,    80,    84,    81,    82,
      78,    79,    83,    74,    69,    70,    67,    68,    71,    72,
      61,    63,    59,    57,    58,    60,    65,    66,     0,    64,
      62,     0,    10,    39,     0,    53,    54,    51,   115,     0,
       0,     0,    43,     0,   114,   118,    73,     0,   116,     0,
       0,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,    -4,    -8,   -24,   131,   -30,    47,
      17,   -90,   -90,   -90,   -90,   -90,   -90,    38,   -90,   -19,
     -90,   -37,   -90,   126,   -90,   -90,    12,   -90,   -33,   394,
     364,   -90,   -90,   -90,   -13,    71,   -89,   -90,   -90,   -90,
     -90,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    17,     2,     9,    41,    85,    43,    86,   144,
      10,    11,    60,    45,    12,    13,    61,    62,    63,    87,
     147,   148,    14,    21,    22,    47,   102,   103,   149,    89,
      90,    25,   106,    48,    49,    50,    51,    52,    53,   194,
      54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    42,    88,    19,    76,   141,    46,    15,    23,    68,
      75,    96,    97,    18,    24,    27,     3,     4,     5,     6,
       7,    31,    19,    56,    32,    16,    33,    34,    35,    36,
      37,    98,    38,   112,   113,    39,    40,   101,   128,   -11,
     130,    28,    44,   133,    77,    29,    59,    78,   137,    77,
      80,   121,    78,    91,    93,    30,    57,    18,    64,    24,
     104,    77,   142,    66,    78,   146,    79,    80,    81,    82,
     140,    67,    95,    94,    83,   108,    77,    99,   100,    78,
      42,   109,    80,    81,    82,    46,   105,   107,   110,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   111,   143,   199,   139,
     122,   123,   124,   125,   126,   127,    -8,   150,   151,    98,
     186,    44,   181,   183,   189,   137,   185,   193,    59,   128,
     129,   130,   131,   132,   133,   134,   200,   135,   136,   137,
     138,   188,    20,   101,   145,   122,   123,   192,   191,   153,
     184,     3,     4,     5,     6,     7,    65,   196,     3,     4,
       5,     6,     7,   187,   128,     8,   130,   131,   132,   133,
     134,    58,   135,   140,   137,   152,   195,     0,     0,     0,
     198,   122,   123,   124,   125,   126,   127,   201,     3,     4,
       5,     6,     7,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     0,   135,   136,
     137,   138,     0,   128,   129,   130,   131,   132,   133,   134,
     154,   135,   136,   137,   138,   122,   123,   124,   125,   126,
     127,     0,     0,   155,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,   135,   136,   137,   138,     0,   128,   129,   130,
     131,   132,   133,   134,   163,   135,   136,   137,   138,   122,
     123,   124,   125,   126,   127,   182,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     0,   128,   129,
     130,   131,   132,   133,   134,    92,   135,   136,   137,   138,
       0,     0,     0,   190,   122,   123,   124,   125,   126,   127,
     128,     0,   130,   131,   132,   133,     0,     0,     0,     0,
     137,     0,     0,   128,   129,   130,   131,   132,   133,   134,
       0,   135,   136,   137,   138,     0,     0,     0,   197,   122,
     123,   124,   125,   126,   127,    69,    70,    71,    72,    73,
      74,    64,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,   135,   136,   137,   138,
      69,    70,    71,    72,    73,    74,    18,    77,     0,     0,
      78,     0,    79,    80,    81,    82,   122,   123,   124,   125,
      83,   127,    69,    70,    71,    72,    73,    74,    18,     0,
      84,   122,   123,   124,   125,   128,   129,   130,   131,   132,
     133,   134,     0,   135,     0,   137,   138,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,     0,   135,     0,
     137,   138,   122,   123,   124,   125,     0,     0,     0,     0,
       0,   122,   123,   124,   125,     0,     0,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,     0,   135,
     128,   137,   130,   131,   132,   133,   134,     0,   135,     0,
     137,   114,   115,   116,   117,   118,   119,   120,   156,   157,
     158,   159,   160,   161,   162
};

static const yytype_int16 yycheck[] =
{
      13,    25,    35,    11,    34,    94,    25,     0,    12,    33,
      34,    36,    37,    44,    46,    66,     3,     4,     5,     6,
       7,     8,    30,    27,    11,     8,    13,    14,    15,    16,
      17,    56,    19,    66,    67,    22,    23,    45,    49,    68,
      51,    61,    25,    54,    45,    68,    29,    48,    59,    45,
      51,    84,    48,    36,    37,    70,    38,    44,    44,    46,
      66,    45,    95,    68,    48,    98,    50,    51,    52,    53,
      94,    68,    61,    68,    58,    58,    45,    68,    44,    48,
     104,    44,    51,    52,    53,   104,    47,    67,    69,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    70,    38,   197,    92,
      30,    31,    32,    33,    34,    35,    30,    30,    70,    56,
     150,   104,    64,    69,    12,    59,   150,    10,   111,    49,
      50,    51,    52,    53,    54,    55,    69,    57,    58,    59,
      60,   154,    11,   151,    97,    30,    31,   184,   181,   111,
      70,     3,     4,     5,     6,     7,    30,   190,     3,     4,
       5,     6,     7,   151,    49,    17,    51,    52,    53,    54,
      55,    16,    57,   197,    59,   104,   189,    -1,    -1,    -1,
     193,    30,    31,    32,    33,    34,    35,   200,     3,     4,
       5,     6,     7,    -1,    30,    31,    32,    33,    34,    35,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    -1,    49,    50,    51,    52,    53,    54,    55,
      69,    57,    58,    59,    60,    30,    31,    32,    33,    34,
      35,    -1,    -1,    69,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    -1,    49,    50,    51,
      52,    53,    54,    55,    69,    57,    58,    59,    60,    30,
      31,    32,    33,    34,    35,    67,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    49,    50,
      51,    52,    53,    54,    55,    16,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    30,    31,    32,    33,    34,    35,
      49,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    64,    30,
      31,    32,    33,    34,    35,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    30,    31,    32,    33,
      58,    35,    38,    39,    40,    41,    42,    43,    44,    -1,
      68,    30,    31,    32,    33,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      59,    60,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      49,    59,    51,    52,    53,    54,    55,    -1,    57,    -1,
      59,    77,    78,    79,    80,    81,    82,    83,   114,   115,
     116,   117,   118,   119,   120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    74,     3,     4,     5,     6,     7,    17,    75,
      81,    82,    85,    86,    93,     0,    81,    73,    44,    76,
      78,    94,    95,    75,    46,   102,   105,    66,    61,    68,
      70,     8,    11,    13,    14,    15,    16,    17,    19,    22,
      23,    76,    77,    78,    81,    84,    90,    96,   104,   105,
     106,   107,   108,   109,   111,   112,    75,    38,    16,    81,
      83,    87,    88,    89,    44,    94,    68,    68,    77,    38,
      39,    40,    41,    42,    43,    77,    79,    45,    48,    50,
      51,    52,    53,    58,    68,    77,    79,    90,    99,   100,
     101,    81,    16,    81,    68,    61,    36,    37,    56,    68,
      44,    76,    97,    98,    66,    47,   103,    67,    81,    44,
      69,    70,    99,    99,   100,   100,   100,   100,   100,   100,
     100,    99,    30,    31,    32,    33,    34,    35,    49,    50,
      51,    52,    53,    54,    55,    57,    58,    59,    60,    81,
      77,   107,    99,    38,    80,    80,    99,    91,    92,    99,
      30,    70,   106,    88,    69,    69,   101,   101,   101,   101,
     101,   101,   101,    69,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    64,    67,    69,    70,    77,    79,    97,   105,    12,
      64,    99,    92,    10,   110,   105,    99,    64,   105,   107,
      69,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    75,    75,    75,    76,    77,
      77,    78,    79,    79,    79,    79,    79,    79,    80,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    85,    86,    87,    87,    88,    88,    89,    90,
      91,    91,    92,    92,    93,    94,    94,    95,    95,    96,
      97,    97,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   106,   106,
     107,   108,   108,   108,   109,   110,   110,   111,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     3,     0,     3,     2,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       2,     3,     2,     5,     0,     1,     1,     3,     2,     4,
       0,     1,     1,     3,     2,     1,     3,     1,     4,     2,
       1,     3,     1,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     3,     3,     2,     1,     1,     1,     3,     0,     3,
       3,     1,     1,     1,     6,     0,     2,     9,     6
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
#line 166 "parser.y"
             {push(&global_scope, hash_create());}
#line 1700 "parser.tab.c"
    break;

  case 3:
#line 168 "parser.y"
            {hash_print(top(global_scope));}
#line 1706 "parser.tab.c"
    break;

  case 4:
#line 169 "parser.y"
                        { arvore = (yyvsp[-1].tree_node); }
#line 1712 "parser.tab.c"
    break;

  case 5:
#line 171 "parser.y"
                                   { (yyval.tree_node) = NULL;             }
#line 1718 "parser.tab.c"
    break;

  case 6:
#line 172 "parser.y"
                                   { (yyval.tree_node) = (yyvsp[0].tree_node);               }
#line 1724 "parser.tab.c"
    break;

  case 7:
#line 173 "parser.y"
                                   { (yyval.tree_node) = add_node((yyvsp[-1].tree_node), (yyvsp[0].tree_node)); 
}
#line 1731 "parser.tab.c"
    break;

  case 8:
#line 181 "parser.y"
                     { store_identificador(&stored_element, (yyvsp[0].lex_value)); 
                        (yyval.tree_node) = create_node(NAT_VAR,(yyvsp[0].lex_value), 0);
                    }
#line 1739 "parser.tab.c"
    break;

  case 9:
#line 185 "parser.y"
                         { (yyval.tree_node) = (yyvsp[0].tree_node);  
                         store_nature(&stored_element, NAT_VAR);
                            int already_on_table = hash_search(global_scope, stored_element->name);
                            if(already_on_table == 0){
                                print_ERR_UNDECLARED(stored_element);
                            }
                            else{
                                int previous_nature = id_nature(global_scope, stored_element->name);
                                if(previous_nature != 0)
                                {
                                    print_ERR_VARIABLE(stored_element, previous_nature);
                                }
                            }
                        }
#line 1758 "parser.tab.c"
    break;

  case 10:
#line 199 "parser.y"
                         { 
                            replace_name((yyvsp[-2].lex_value), "[]");
                            (yyval.tree_node) = create_node(NAT_VET,(yyvsp[-2].lex_value), 2, (yyvsp[-3].tree_node), (yyvsp[-1].tree_node));
                            store_nature(&stored_element, NAT_VET);
                            int already_on_table = hash_search(global_scope, stored_element->name);
                            if(already_on_table == 0){
                                print_ERR_UNDECLARED(stored_element);
                            }
                            else{
                                int previous_nature = id_nature(global_scope, stored_element->name);
                                if(previous_nature != 1)
                                {
                                    print_ERR_VECTOR(stored_element, previous_nature);
                                }
                            }
                            }
#line 1779 "parser.tab.c"
    break;

  case 11:
#line 216 "parser.y"
                        { store_identificador(&stored_fun, (yyvsp[0].lex_value)); 
                        (yyval.tree_node) = create_node(NAT_VET,(yyvsp[0].lex_value), 0);
                    }
#line 1787 "parser.tab.c"
    break;

  case 12:
#line 220 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_INT,(yyvsp[0].lex_value), 0);
                    store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_INT);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_INT);

                    }
#line 1798 "parser.tab.c"
    break;

  case 13:
#line 226 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_FLOAT,(yyvsp[0].lex_value), 0);
                    store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_FLOAT);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_FLOAT);
}
#line 1808 "parser.tab.c"
    break;

  case 14:
#line 231 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_TRUE,(yyvsp[0].lex_value), 0);
                    store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_TRUE);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_BOOL);}
#line 1817 "parser.tab.c"
    break;

  case 15:
#line 235 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_FALSE,(yyvsp[0].lex_value), 0);
                     store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_FALSE);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_BOOL);}
#line 1826 "parser.tab.c"
    break;

  case 16:
#line 239 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_CHAR,(yyvsp[0].lex_value), 0);
                    store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_CHAR);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_CHAR);}
#line 1835 "parser.tab.c"
    break;

  case 17:
#line 243 "parser.y"
                   { (yyval.tree_node) = create_node(NAT_STR,(yyvsp[0].lex_value), 0);
                    store_literal(&stored_literal, (yyvsp[0].lex_value), NAT_STR);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_CHAR);
                    }
#line 1845 "parser.tab.c"
    break;

  case 18:
#line 249 "parser.y"
                { (yyval.tree_node) = create_node(NAT_INT,(yyvsp[0].lex_value), 0); }
#line 1851 "parser.tab.c"
    break;

  case 19:
#line 257 "parser.y"
                       {(yyval.type) = TK_PR_INT;}
#line 1857 "parser.tab.c"
    break;

  case 20:
#line 258 "parser.y"
                       {(yyval.type) = TK_PR_FLOAT;}
#line 1863 "parser.tab.c"
    break;

  case 21:
#line 259 "parser.y"
                       {(yyval.type) = TK_PR_BOOL;}
#line 1869 "parser.tab.c"
    break;

  case 22:
#line 260 "parser.y"
                       {(yyval.type) = TK_PR_CHAR;}
#line 1875 "parser.tab.c"
    break;

  case 23:
#line 261 "parser.y"
                       {(yyval.type) = TK_PR_STRING;}
#line 1881 "parser.tab.c"
    break;

  case 24:
#line 263 "parser.y"
                                  {}
#line 1887 "parser.tab.c"
    break;

  case 25:
#line 264 "parser.y"
                                  {}
#line 1893 "parser.tab.c"
    break;

  case 26:
#line 266 "parser.y"
                                {}
#line 1899 "parser.tab.c"
    break;

  case 27:
#line 267 "parser.y"
                                {}
#line 1905 "parser.tab.c"
    break;

  case 28:
#line 269 "parser.y"
                                                   {}
#line 1911 "parser.tab.c"
    break;

  case 29:
#line 270 "parser.y"
                                                   {}
#line 1917 "parser.tab.c"
    break;

  case 30:
#line 271 "parser.y"
                                                   {}
#line 1923 "parser.tab.c"
    break;

  case 31:
#line 272 "parser.y"
                                                   {}
#line 1929 "parser.tab.c"
    break;

  case 32:
#line 280 "parser.y"
                            {
                            add_node((yyvsp[-1].tree_node), (yyvsp[0].tree_node));}
#line 1936 "parser.tab.c"
    break;

  case 33:
#line 283 "parser.y"
                                               { 
                                                    store_function_elem(&stored_fun);
                                                    store_param(&stored_fun,param_list);
                                                    HashTable * table = top(global_scope);
                                                    param_list = NULL;  
                                                    int already_on_table = hash_search(global_scope, stored_fun->name);
                                                    if (already_on_table == 0){
                                                    hash_insert(&table, stored_fun, (yyvsp[-4].type));
                                                    }                                            
                                                    else{
                                                    // NÃO COLOCAR NA ÁRVORE CASO TIVER ERRO
                                                    print_ERR_DECLARED(stored_fun ,already_on_table);
                                            }
                                            (yyval.tree_node) = (yyvsp[-3].tree_node);   
}
#line 1956 "parser.tab.c"
    break;

  case 34:
#line 299 "parser.y"
                          {}
#line 1962 "parser.tab.c"
    break;

  case 35:
#line 300 "parser.y"
                          {}
#line 1968 "parser.tab.c"
    break;

  case 36:
#line 302 "parser.y"
                                           {}
#line 1974 "parser.tab.c"
    break;

  case 37:
#line 303 "parser.y"
                                           {}
#line 1980 "parser.tab.c"
    break;

  case 38:
#line 305 "parser.y"
                                      { store_identificador(&stored_element,(yyvsp[0].lex_value));
                    store_nature(&stored_element, NAT_VAR);
                    push_param(&param_list, stored_element, (yyvsp[-1].type));}
#line 1988 "parser.tab.c"
    break;

  case 39:
#line 311 "parser.y"
                                   { 
                                store_nature(&stored_fun, NAT_FUN);
                                int already_on_table = hash_search(global_scope, stored_fun->name);                               
                                if(already_on_table == 0){
                                print_ERR_UNDECLARED(stored_fun);
                                }
                                else{
                                int previous_nature = id_nature(global_scope, stored_fun->name);
                                if(previous_nature != 2)
                                {
                                    print_ERR_FUNCTION(stored_fun, previous_nature);
                                }
                                }
                                check_parameters(global_scope,stored_fun ,(yyvsp[-1].tree_node));
                               
                                ((yyvsp[-3].tree_node))->lex_value->type = TYPE_FUNC_CALL; (yyval.tree_node) = add_node((yyvsp[-3].tree_node), (yyvsp[-1].tree_node)); 
                                }
#line 2010 "parser.tab.c"
    break;

  case 40:
#line 329 "parser.y"
                          { (yyval.tree_node) = NULL; }
#line 2016 "parser.tab.c"
    break;

  case 41:
#line 330 "parser.y"
                          { (yyval.tree_node) = (yyvsp[0].tree_node);   }
#line 2022 "parser.tab.c"
    break;

  case 42:
#line 332 "parser.y"
                                      { (yyval.tree_node) = (yyvsp[0].tree_node);               }
#line 2028 "parser.tab.c"
    break;

  case 43:
#line 333 "parser.y"
                                      { (yyval.tree_node) = add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2034 "parser.tab.c"
    break;

  case 44:
#line 337 "parser.y"
                                        {  HashTable * table = top(global_scope);
                                            while(!isEmpty_stack_list(var_list)){
                                            hash_element* element = pop_element(&var_list);
                                            int already_on_table = hash_search(global_scope, element->name);
                                            if(already_on_table == 0){
                                            hash_insert(&table, element, (yyvsp[-1].type));
                                            }
                                            else{
                                                print_ERR_DECLARED(element ,already_on_table);
                                                }
                                            }
                                            var_list = NULL;
                                        }
#line 2052 "parser.tab.c"
    break;

  case 45:
#line 351 "parser.y"
                                           {}
#line 2058 "parser.tab.c"
    break;

  case 46:
#line 352 "parser.y"
                                           {}
#line 2064 "parser.tab.c"
    break;

  case 47:
#line 354 "parser.y"
                   {store_nature(&stored_element, NAT_VAR);
                    push_element(&var_list, stored_element);}
#line 2071 "parser.tab.c"
    break;

  case 48:
#line 356 "parser.y"
                                 {store_nature(&stored_element, NAT_VET);
         store_vet_size(&stored_element, (yyvsp[-1].lex_value)->val.d); 
         push_element(&var_list, stored_element);}
#line 2079 "parser.tab.c"
    break;

  case 49:
#line 363 "parser.y"
                                          { (yyval.tree_node) = (yyvsp[0].tree_node); 
             HashTable * table = top(global_scope);
                                        while(!isEmpty_stack_list(var_list)){
                                            hash_element* element = pop_element(&var_list);
                                            int already_on_table = hash_search(global_scope, element->name);
                                            if(already_on_table == 0){
                                            hash_insert(&table, element, (yyvsp[-1].type));}
                                            else{
                                                print_ERR_DECLARED(element ,already_on_table);
                                            }
                                        }
                                        var_list = NULL;
             }
#line 2097 "parser.tab.c"
    break;

  case 50:
#line 377 "parser.y"
                                        { (yyval.tree_node) = (yyvsp[0].tree_node);                                     }
#line 2103 "parser.tab.c"
    break;

  case 51:
#line 378 "parser.y"
                                        { (yyval.tree_node) = ((yyvsp[-2].tree_node)) == NULL ? ((yyvsp[0].tree_node)) : add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2109 "parser.tab.c"
    break;

  case 52:
#line 381 "parser.y"
                                              { store_identificador(&stored_element, (yyvsp[0].lex_value)); (yyval.tree_node) = NULL;
                                                store_nature(&stored_element, NAT_VAR);
                                                push_element(&var_list, stored_element);}
#line 2117 "parser.tab.c"
    break;

  case 53:
#line 384 "parser.y"
                              { (yyval.tree_node) = create_node(NAT_VAR,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
#line 2125 "parser.tab.c"
    break;

  case 54:
#line 387 "parser.y"
                              { (yyval.tree_node) = create_node(NAT_VAR,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); 
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
#line 2133 "parser.tab.c"
    break;

  case 55:
#line 396 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                             }
#line 2139 "parser.tab.c"
    break;

  case 56:
#line 397 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                             }
#line 2145 "parser.tab.c"
    break;

  case 57:
#line 398 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2151 "parser.tab.c"
    break;

  case 58:
#line 399 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2157 "parser.tab.c"
    break;

  case 59:
#line 400 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2163 "parser.tab.c"
    break;

  case 60:
#line 401 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2169 "parser.tab.c"
    break;

  case 61:
#line 402 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2175 "parser.tab.c"
    break;

  case 62:
#line 403 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2181 "parser.tab.c"
    break;

  case 63:
#line 404 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2187 "parser.tab.c"
    break;

  case 64:
#line 405 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2193 "parser.tab.c"
    break;

  case 65:
#line 406 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2199 "parser.tab.c"
    break;

  case 66:
#line 407 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2205 "parser.tab.c"
    break;

  case 67:
#line 408 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2211 "parser.tab.c"
    break;

  case 68:
#line 409 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2217 "parser.tab.c"
    break;

  case 69:
#line 410 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2223 "parser.tab.c"
    break;

  case 70:
#line 411 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2229 "parser.tab.c"
    break;

  case 71:
#line 412 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2235 "parser.tab.c"
    break;

  case 72:
#line 413 "parser.y"
                             { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node));     }
#line 2241 "parser.tab.c"
    break;

  case 73:
#line 414 "parser.y"
                             { replace_name((yyvsp[-3].lex_value), "?:");
                               (yyval.tree_node) = create_node(EXP,(yyvsp[-3].lex_value), 3, (yyvsp[-4].tree_node), (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2248 "parser.tab.c"
    break;

  case 74:
#line 416 "parser.y"
                             { (yyval.tree_node) = (yyvsp[-1].tree_node);                             }
#line 2254 "parser.tab.c"
    break;

  case 75:
#line 418 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2260 "parser.tab.c"
    break;

  case 76:
#line 419 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2266 "parser.tab.c"
    break;

  case 77:
#line 420 "parser.y"
                    { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2272 "parser.tab.c"
    break;

  case 78:
#line 422 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2278 "parser.tab.c"
    break;

  case 79:
#line 423 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2284 "parser.tab.c"
    break;

  case 80:
#line 424 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2290 "parser.tab.c"
    break;

  case 81:
#line 425 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2296 "parser.tab.c"
    break;

  case 82:
#line 426 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2302 "parser.tab.c"
    break;

  case 83:
#line 427 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2308 "parser.tab.c"
    break;

  case 84:
#line 428 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-2].lex_value), 1, (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2314 "parser.tab.c"
    break;

  case 85:
#line 429 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2320 "parser.tab.c"
    break;

  case 86:
#line 430 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2326 "parser.tab.c"
    break;

  case 87:
#line 431 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2332 "parser.tab.c"
    break;

  case 88:
#line 432 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2338 "parser.tab.c"
    break;

  case 89:
#line 433 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2344 "parser.tab.c"
    break;

  case 90:
#line 434 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2350 "parser.tab.c"
    break;

  case 91:
#line 435 "parser.y"
                                 { (yyval.tree_node) = create_node(EXP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2356 "parser.tab.c"
    break;

  case 92:
#line 441 "parser.y"
                 { push(&global_scope, hash_create());}
#line 2362 "parser.tab.c"
    break;

  case 93:
#line 443 "parser.y"
                  { hash_print(top(global_scope)); pop(&global_scope);}
#line 2368 "parser.tab.c"
    break;

  case 94:
#line 446 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2374 "parser.tab.c"
    break;

  case 95:
#line 447 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2380 "parser.tab.c"
    break;

  case 96:
#line 448 "parser.y"
                             { (yyval.tree_node) = create_node(INP,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2386 "parser.tab.c"
    break;

  case 97:
#line 449 "parser.y"
                             { (yyval.tree_node) = create_node(OUT,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2392 "parser.tab.c"
    break;

  case 98:
#line 450 "parser.y"
                             { (yyval.tree_node) = create_node(OUT,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2398 "parser.tab.c"
    break;

  case 99:
#line 451 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2404 "parser.tab.c"
    break;

  case 100:
#line 452 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2410 "parser.tab.c"
    break;

  case 101:
#line 453 "parser.y"
                             { (yyval.tree_node) = create_node(SL,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2416 "parser.tab.c"
    break;

  case 102:
#line 454 "parser.y"
                             { (yyval.tree_node) = create_node(SR,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2422 "parser.tab.c"
    break;

  case 103:
#line 455 "parser.y"
                             { (yyval.tree_node) = create_node(RET,(yyvsp[-1].lex_value), 1, (yyvsp[0].tree_node));     }
#line 2428 "parser.tab.c"
    break;

  case 104:
#line 456 "parser.y"
                             { (yyval.tree_node) = create_node(BREAK,(yyvsp[0].lex_value), 0);         }
#line 2434 "parser.tab.c"
    break;

  case 105:
#line 457 "parser.y"
                             { (yyval.tree_node) = create_node(CONT,(yyvsp[0].lex_value), 0);         }
#line 2440 "parser.tab.c"
    break;

  case 106:
#line 458 "parser.y"
                             { (yyval.tree_node) = (yyvsp[0].tree_node);                         }
#line 2446 "parser.tab.c"
    break;

  case 107:
#line 460 "parser.y"
                                          { (yyval.tree_node) = (yyvsp[-1].tree_node);}
#line 2452 "parser.tab.c"
    break;

  case 108:
#line 462 "parser.y"
                        { (yyval.tree_node) = NULL;                                   }
#line 2458 "parser.tab.c"
    break;

  case 109:
#line 463 "parser.y"
                        { (yyval.tree_node) = ((yyvsp[-2].tree_node)) == NULL ? ((yyvsp[0].tree_node)) : add_node((yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2464 "parser.tab.c"
    break;

  case 110:
#line 467 "parser.y"
                             { (yyval.tree_node) = create_node(ASS,(yyvsp[-1].lex_value), 2, (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2470 "parser.tab.c"
    break;

  case 111:
#line 471 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2476 "parser.tab.c"
    break;

  case 112:
#line 472 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2482 "parser.tab.c"
    break;

  case 113:
#line 473 "parser.y"
                     { (yyval.tree_node) = (yyvsp[0].tree_node); }
#line 2488 "parser.tab.c"
    break;

  case 114:
#line 475 "parser.y"
                                        { (yyval.tree_node) = create_node(FLOW,(yyvsp[-5].lex_value), 3, (yyvsp[-3].tree_node), (yyvsp[-1].tree_node), (yyvsp[0].tree_node)); }
#line 2494 "parser.tab.c"
    break;

  case 115:
#line 477 "parser.y"
                          { (yyval.tree_node) = NULL; }
#line 2500 "parser.tab.c"
    break;

  case 116:
#line 478 "parser.y"
                          { (yyval.tree_node) = (yyvsp[0].tree_node);   }
#line 2506 "parser.tab.c"
    break;

  case 117:
#line 480 "parser.y"
                                                                   { (yyval.tree_node) = create_node(FLOW,(yyvsp[-8].lex_value), 4, (yyvsp[-6].tree_node), (yyvsp[-4].tree_node), (yyvsp[-2].tree_node), (yyvsp[0].tree_node)); }
#line 2512 "parser.tab.c"
    break;

  case 118:
#line 482 "parser.y"
                                                  { (yyval.tree_node) = create_node(FLOW,(yyvsp[-5].lex_value), 2, (yyvsp[-3].tree_node), (yyvsp[0].tree_node)); }
#line 2518 "parser.tab.c"
    break;


#line 2522 "parser.tab.c"

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
#line 486 "parser.y"



void replace_name(lexeme_t *lex, const char *str)
{
    free(lex->name);
    lex->name = strdup(str);
}

void yyerror(char const *s)
{
    fprintf(stderr, "At line %d: %s\n", yylineno, s);
}
