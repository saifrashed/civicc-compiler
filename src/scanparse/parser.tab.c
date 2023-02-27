/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

static node_st *parseresult = NULL;
extern int yylex();
static int yyerror( char *errname);
extern FILE *yyin;
void AddLocToNode(node_st *node, void *begin_loc, void *end_loc);



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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ROUNDBRACKET_L = 258,          /* ROUNDBRACKET_L  */
    ROUNDBRACKET_R = 259,          /* ROUNDBRACKET_R  */
    CURLYBRACKET_L = 260,          /* CURLYBRACKET_L  */
    CURLYBRACKET_R = 261,          /* CURLYBRACKET_R  */
    SQUAREBRACKET_L = 262,         /* SQUAREBRACKET_L  */
    SQUAREBRACKET_R = 263,         /* SQUAREBRACKET_R  */
    COMMA = 264,                   /* COMMA  */
    SEMICOLON = 265,               /* SEMICOLON  */
    MINUS = 266,                   /* MINUS  */
    PLUS = 267,                    /* PLUS  */
    STAR = 268,                    /* STAR  */
    SLASH = 269,                   /* SLASH  */
    PERCENT = 270,                 /* PERCENT  */
    LE = 271,                      /* LE  */
    LT = 272,                      /* LT  */
    GE = 273,                      /* GE  */
    GT = 274,                      /* GT  */
    EQ = 275,                      /* EQ  */
    NE = 276,                      /* NE  */
    OR = 277,                      /* OR  */
    AND = 278,                     /* AND  */
    NEG = 279,                     /* NEG  */
    TRUEVAL = 280,                 /* TRUEVAL  */
    FALSEVAL = 281,                /* FALSEVAL  */
    LET = 282,                     /* LET  */
    IF = 283,                      /* IF  */
    ELSE = 284,                    /* ELSE  */
    WHILE = 285,                   /* WHILE  */
    DO = 286,                      /* DO  */
    FOR = 287,                     /* FOR  */
    RETURN = 288,                  /* RETURN  */
    EXPORT = 289,                  /* EXPORT  */
    EXTERN = 290,                  /* EXTERN  */
    BOOLTYPE = 291,                /* BOOLTYPE  */
    FLOATTYPE = 292,               /* FLOATTYPE  */
    INTTYPE = 293,                 /* INTTYPE  */
    VOIDTYPE = 294,                /* VOIDTYPE  */
    NUM = 295,                     /* NUM  */
    FLOAT = 296,                   /* FLOAT  */
    ID = 297,                      /* ID  */
    UMINUS = 298,                  /* UMINUS  */
    CAST = 299,                    /* CAST  */
    THEN = 300                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

 char               *id;
 int                 cint;
 float               cflt;
 enum MonOpEnum     cmonop;
 enum BinOpEnum     cbinop;
 enum Type          cdatatype;
 node_st             *node;

#line 196 "parser.tab.c"

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



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ROUNDBRACKET_L = 3,             /* ROUNDBRACKET_L  */
  YYSYMBOL_ROUNDBRACKET_R = 4,             /* ROUNDBRACKET_R  */
  YYSYMBOL_CURLYBRACKET_L = 5,             /* CURLYBRACKET_L  */
  YYSYMBOL_CURLYBRACKET_R = 6,             /* CURLYBRACKET_R  */
  YYSYMBOL_SQUAREBRACKET_L = 7,            /* SQUAREBRACKET_L  */
  YYSYMBOL_SQUAREBRACKET_R = 8,            /* SQUAREBRACKET_R  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_STAR = 13,                      /* STAR  */
  YYSYMBOL_SLASH = 14,                     /* SLASH  */
  YYSYMBOL_PERCENT = 15,                   /* PERCENT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_NEG = 24,                       /* NEG  */
  YYSYMBOL_TRUEVAL = 25,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 26,                  /* FALSEVAL  */
  YYSYMBOL_LET = 27,                       /* LET  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_DO = 31,                        /* DO  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_EXPORT = 34,                    /* EXPORT  */
  YYSYMBOL_EXTERN = 35,                    /* EXTERN  */
  YYSYMBOL_BOOLTYPE = 36,                  /* BOOLTYPE  */
  YYSYMBOL_FLOATTYPE = 37,                 /* FLOATTYPE  */
  YYSYMBOL_INTTYPE = 38,                   /* INTTYPE  */
  YYSYMBOL_VOIDTYPE = 39,                  /* VOIDTYPE  */
  YYSYMBOL_NUM = 40,                       /* NUM  */
  YYSYMBOL_FLOAT = 41,                     /* FLOAT  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_UMINUS = 43,                    /* UMINUS  */
  YYSYMBOL_CAST = 44,                      /* CAST  */
  YYSYMBOL_THEN = 45,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_decls = 48,                     /* decls  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_globdecl = 50,                  /* globdecl  */
  YYSYMBOL_globdef = 51,                   /* globdef  */
  YYSYMBOL_funbody = 52,                   /* funbody  */
  YYSYMBOL_fundefs = 53,                   /* fundefs  */
  YYSYMBOL_fundef = 54,                    /* fundef  */
  YYSYMBOL_funcall = 55,                   /* funcall  */
  YYSYMBOL_vardecls = 56,                  /* vardecls  */
  YYSYMBOL_vardecl = 57,                   /* vardecl  */
  YYSYMBOL_args = 58,                      /* args  */
  YYSYMBOL_arg = 59,                       /* arg  */
  YYSYMBOL_params = 60,                    /* params  */
  YYSYMBOL_param = 61,                     /* param  */
  YYSYMBOL_exprs_dims = 62,                /* exprs_dims  */
  YYSYMBOL_id_dims = 63,                   /* id_dims  */
  YYSYMBOL_id_dim = 64,                    /* id_dim  */
  YYSYMBOL_expr_dim = 65,                  /* expr_dim  */
  YYSYMBOL_stmts = 66,                     /* stmts  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_assign = 68,                    /* assign  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_varlet = 70,                    /* varlet  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_unary_expr = 72,                /* unary_expr  */
  YYSYMBOL_arithmetic_expr = 73,           /* arithmetic_expr  */
  YYSYMBOL_comparison_expr = 74,           /* comparison_expr  */
  YYSYMBOL_logical_expr = 75,              /* logical_expr  */
  YYSYMBOL_array_expr = 76,                /* array_expr  */
  YYSYMBOL_cast = 77,                      /* cast  */
  YYSYMBOL_constant = 78,                  /* constant  */
  YYSYMBOL_datatype = 79                   /* datatype  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   675

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    91,    95,   101,   106,   111,   123,   128,
     133,   137,   141,   145,   149,   153,   157,   161,   171,   175,
     179,   183,   189,   193,   198,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   246,   250,   255,   259,
     270,   275,   281,   285,   289,   293,   299,   304,   309,   315,
     320,   325,   329,   335,   340,   345,   350,   355,   360,   369,
     373,   379,   383,   387,   391,   395,   399,   403,   407,   411,
     415,   421,   427,   428,   434,   438,   444,   448,   452,   456,
     460,   464,   468,   472,   476,   480,   486,   490,   496,   500,
     504,   508,   512,   518,   522,   526,   530,   534,   538,   544,
     548,   554,   560,   573,   577,   581,   585,   595,   596,   597,
     598
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ROUNDBRACKET_L",
  "ROUNDBRACKET_R", "CURLYBRACKET_L", "CURLYBRACKET_R", "SQUAREBRACKET_L",
  "SQUAREBRACKET_R", "COMMA", "SEMICOLON", "MINUS", "PLUS", "STAR",
  "SLASH", "PERCENT", "LE", "LT", "GE", "GT", "EQ", "NE", "OR", "AND",
  "NEG", "TRUEVAL", "FALSEVAL", "LET", "IF", "ELSE", "WHILE", "DO", "FOR",
  "RETURN", "EXPORT", "EXTERN", "BOOLTYPE", "FLOATTYPE", "INTTYPE",
  "VOIDTYPE", "NUM", "FLOAT", "ID", "UMINUS", "CAST", "THEN", "$accept",
  "program", "decls", "decl", "globdecl", "globdef", "funbody", "fundefs",
  "fundef", "funcall", "vardecls", "vardecl", "args", "arg", "params",
  "param", "exprs_dims", "id_dims", "id_dim", "expr_dim", "stmts", "stmt",
  "assign", "block", "varlet", "expr", "unary_expr", "arithmetic_expr",
  "comparison_expr", "logical_expr", "array_expr", "cast", "constant",
  "datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,   185,   185,  -108,  -108,  -108,  -108,    13,  -108,   177,
    -108,  -108,  -108,    23,    24,    30,  -108,  -108,   379,   103,
     379,   143,   -27,   112,   335,   379,   379,  -108,  -108,  -108,
    -108,    20,   379,  -108,    21,    29,   639,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,    -3,  -108,   379,    53,    39,  -108,
     379,  -108,    63,    71,    80,  -108,   434,    97,    94,  -108,
     359,  -108,    69,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   162,   117,    96,
      32,   282,    81,   179,   133,   528,   106,   -27,   128,   141,
    -108,   379,  -108,  -108,   150,   156,   639,    -6,  -108,   326,
     326,  -108,  -108,  -108,   401,   401,   401,   401,   376,   376,
     652,   337,    57,  -108,   193,   185,   -27,  -108,  -108,    -5,
     202,  -108,   194,  -108,   153,  -108,  -108,   163,  -108,  -108,
     379,  -108,   379,  -108,   171,   178,   183,   187,   154,   185,
     185,   144,   176,  -108,   372,   304,   185,  -108,   304,  -108,
     164,   542,    37,   243,  -108,  -108,   184,  -108,   379,  -108,
     196,   284,  -108,  -108,  -108,  -108,   556,   379,   379,   101,
     170,   185,  -108,   570,   189,   205,   379,  -108,  -108,   206,
    -108,  -108,    61,  -108,   379,  -108,   379,   149,  -108,   200,
     210,   584,  -108,  -108,   212,  -108,   454,   474,  -108,   213,
     226,   224,  -108,   267,   269,   280,   286,     0,   598,   298,
    -108,   379,  -108,  -108,  -108,  -108,   183,   183,  -108,   379,
     306,  -108,  -108,   271,   612,   302,  -108,   494,   379,    59,
    -108,   183,   333,   242,  -108,   379,  -108,  -108,   379,   626,
     414,  -108,   183,   379,  -108,   514,   183,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   110,   109,   108,   107,     0,     2,     4,
       6,     5,     7,     0,     0,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   104,
     103,    77,     0,    79,     0,    54,    58,    85,    82,    83,
      84,    81,    78,    80,     0,    10,     0,     0,     0,    14,
       0,    57,     0,    56,     0,     8,     0,     0,     0,    87,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,   101,    39,     0,    47,    48,     0,    53,    89,
      88,    90,    91,    92,    94,    93,    96,    95,    97,    98,
      99,   100,     0,    24,     0,     0,     0,    51,    12,     0,
       0,    30,     0,    16,     0,    55,    36,     0,   102,    38,
       0,    11,     0,    25,     0,     0,     0,     0,     0,     0,
       0,    77,     0,    20,    23,    18,    41,    19,    60,    61,
       0,     0,     0,     0,    27,    49,     0,    15,     0,    31,
       0,     0,    33,     9,    37,    46,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,    26,    22,     0,
      21,    40,     0,    59,     0,    62,     0,     0,    28,     0,
       0,     0,    32,    34,     0,    13,     0,     0,    72,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    29,    52,    17,    35,     0,     0,    73,     0,
       0,    75,    71,     0,     0,    67,    66,     0,     0,     0,
      44,     0,     0,     0,    43,     0,    68,    65,     0,     0,
       0,    45,     0,     0,    63,     0,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   355,  -108,  -108,  -108,   -94,   221,    11,  -108,
     222,  -108,   237,  -108,   -45,  -108,    -1,   -75,  -108,  -108,
      38,  -108,  -108,  -107,  -108,   -18,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,   142,   143,   144,    33,
     145,   146,    94,    95,    78,    79,    34,    52,    53,    35,
     147,   148,   149,   170,   150,   151,    37,    38,    39,    40,
      41,    42,    43,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    77,    36,    84,   131,   157,    56,    36,    59,    89,
     210,    12,   125,    16,    61,    51,    13,    14,    15,    47,
      12,   132,   158,    60,    58,    13,   160,   211,    81,    62,
      18,    20,    85,     3,     4,     5,     6,    22,    63,   116,
      57,   156,    96,    83,   186,    36,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   189,
      24,    82,    98,   133,    25,    19,    21,   194,   186,   234,
     155,    86,    23,   128,   117,     3,     4,     5,     6,   187,
      87,    26,    27,    28,    88,   134,   235,   135,   136,   137,
     138,   139,   140,     3,     4,     5,     6,    29,    30,   141,
      32,    91,    92,   207,    24,   115,    44,   198,    25,   225,
     226,    97,    96,    45,   166,    54,     3,     4,     5,     6,
     173,   114,    55,   119,   236,    26,    27,    28,   152,   134,
      46,   135,   136,   137,   138,   244,   152,   122,   126,   247,
     191,    29,    30,   141,    32,   127,    48,    60,   124,   196,
     197,   176,    44,    49,   129,   174,   175,    24,    36,   210,
     179,    25,   182,   163,   172,   130,   208,   112,    36,   152,
      50,   -74,   113,   164,   167,   205,   211,   152,    26,    27,
      28,   168,   177,   180,   120,   209,   183,   201,   169,   121,
     171,   184,   190,   224,    29,    30,    31,    32,   153,   161,
     200,   227,   192,   154,   162,    24,   212,   199,   159,    25,
     233,     1,     2,     3,     4,     5,     6,   239,   215,   218,
     240,     3,     4,     5,     6,   245,    26,    27,    28,   219,
     134,   203,   135,   136,   137,   138,   139,   140,     3,     4,
       5,     6,    29,    30,   141,    32,    24,   204,   206,   188,
      25,   238,   213,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   220,    26,    27,    28,
      48,   134,    54,   135,   136,   137,   138,   139,   140,     3,
       4,     5,     6,    29,    30,   141,    32,    24,   221,    44,
     193,    25,   118,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   223,    24,    26,    27,
      28,    25,   134,   229,   135,   136,   137,   138,   139,   140,
       3,     4,     5,     6,    29,    30,   141,    32,    26,    27,
      28,   231,   134,   228,   135,   136,   137,   138,    24,    66,
      67,    68,    25,   237,    29,    30,   141,    32,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    26,
      27,    28,    24,    93,    17,   178,    25,   165,   181,     0,
       0,     3,     4,     5,     6,    29,    30,    31,    32,     0,
       0,     0,    24,    26,    27,    28,    25,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,     0,    29,
      30,    31,    32,    26,    27,    28,   139,   140,     3,     4,
       5,     6,    64,    65,    66,    67,    68,     0,   242,    29,
      30,    31,    32,   243,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    90,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   216,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   217,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   232,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   246,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   123,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   185,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   195,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     202,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,   214,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   222,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   230,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   241,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    76
};

static const yytype_int16 yycheck[] =
{
      18,     4,    20,    48,    10,    10,    24,    25,    26,    54,
      10,     0,    87,     0,    32,    42,     0,     1,     2,    20,
       9,    27,    27,     3,    25,     9,   120,    27,    46,     8,
       7,     7,    50,    36,    37,    38,    39,     7,     9,     7,
      24,   116,    60,     4,     7,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   153,
       3,     8,    63,     6,     7,    42,    42,   161,     7,    10,
     115,     8,    42,    91,    42,    36,    37,    38,    39,    42,
       9,    24,    25,    26,     4,    28,    27,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,     8,    42,     3,     9,     3,     6,     7,   216,
     217,    42,   130,    10,   132,     3,    36,    37,    38,    39,
     138,     4,    10,    42,   231,    24,    25,    26,   112,    28,
      27,    30,    31,    32,    33,   242,   120,     4,    10,   246,
     158,    40,    41,    42,    43,     4,     3,     3,    42,   167,
     168,     7,     3,    10,     4,   139,   140,     3,   176,    10,
     144,     7,   146,    10,    10,     9,   184,     5,   186,   153,
      27,    27,    10,    10,     3,   176,    27,   161,    24,    25,
      26,     3,     6,   145,     5,   186,   148,   171,     5,    10,
       3,    27,     8,   211,    40,    41,    42,    43,     5,     5,
      30,   219,     6,    10,    10,     3,     6,   169,     6,     7,
     228,    34,    35,    36,    37,    38,    39,   235,     6,     6,
     238,    36,    37,    38,    39,   243,    24,    25,    26,     3,
      28,    42,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     3,    42,    42,     6,
       7,     9,    42,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    42,    24,    25,    26,
       3,    28,     3,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     3,     8,     3,
       6,     7,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     8,     3,    24,    25,
      26,     7,    28,    42,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    24,    25,
      26,    29,    28,    27,    30,    31,    32,    33,     3,    13,
      14,    15,     7,    10,    40,    41,    42,    43,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    24,
      25,    26,     3,     4,     9,   144,     7,   130,   146,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,     3,    24,    25,    26,     7,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    40,
      41,    42,    43,    24,    25,    26,    34,    35,    36,    37,
      38,    39,    11,    12,    13,    14,    15,    -1,     4,    40,
      41,    42,    43,     9,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    47,    48,    49,
      50,    51,    54,    79,    79,    79,     0,    48,     7,    42,
       7,    42,     7,    42,     3,     7,    24,    25,    26,    40,
      41,    42,    43,    55,    62,    65,    71,    72,    73,    74,
      75,    76,    77,    78,     3,    10,    27,    62,     3,    10,
      27,    42,    63,    64,     3,    10,    71,    79,    62,    71,
       3,    71,     8,     9,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    60,    61,
      79,    71,     8,     4,    60,    71,     8,     9,     4,    60,
       4,     4,     8,     4,    58,    59,    71,    42,    62,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,     5,    10,     4,     9,     7,    42,    10,    42,
       5,    10,     4,    10,    42,    63,    10,     4,    71,     4,
       9,    10,    27,     6,    28,    30,    31,    32,    33,    34,
      35,    42,    52,    53,    54,    56,    57,    66,    67,    68,
      70,    71,    79,     5,    10,    60,    63,    10,    27,     6,
      52,     5,    10,    10,    10,    58,    71,     3,     3,     5,
      69,     3,    10,    71,    79,    79,     7,     6,    53,    79,
      66,    56,    79,    66,    27,    10,     7,    42,     6,    52,
       8,    71,     6,     6,    52,    10,    71,    71,     6,    66,
      30,    79,    10,    42,    42,    62,    42,    42,    71,    62,
      10,    27,     6,    42,    10,     6,     4,     4,     6,     3,
      42,     8,    10,     8,    71,    69,    69,    71,    27,    42,
      10,    29,     4,    71,    10,    27,    69,    10,     9,    71,
      71,    10,     4,     9,    69,    71,     4,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    77,    78,    78,    78,    78,    79,    79,    79,
      79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     7,
       3,     6,     5,     8,     4,     7,     6,     9,     1,     1,
       1,     2,     2,     1,     5,     6,     7,     6,     7,     8,
       6,     7,     8,     7,     8,     9,     6,     7,     4,     3,
       2,     1,     3,     6,     5,     8,     3,     1,     1,     3,
       1,     2,     5,     3,     1,     3,     1,     1,     1,     2,
       1,     1,     2,    10,    12,     7,     5,     5,     7,     2,
       3,     4,     2,     3,     1,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  case 2: /* program: decls  */
#line 80 "parser.y"
         {
           parseresult = (yyvsp[0].node);
         }
#line 1633 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 92 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1641 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 96 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1649 "parser.tab.c"
    break;

  case 5: /* decl: globdef  */
#line 102 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1657 "parser.tab.c"
    break;

  case 6: /* decl: globdecl  */
#line 107 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1665 "parser.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 112 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1673 "parser.tab.c"
    break;

  case 8: /* globdecl: EXTERN datatype ID SEMICOLON  */
#line 124 "parser.y"
       {
         (yyval.node) =  ASTglobdecl(NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id));
       }
#line 1681 "parser.tab.c"
    break;

  case 9: /* globdecl: EXTERN datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 129 "parser.y"
       {
         (yyval.node) =  ASTglobdecl((yyvsp[-3].node), (yyvsp[-5].cdatatype), (yyvsp[-1].id));
       }
#line 1689 "parser.tab.c"
    break;

  case 10: /* globdef: datatype ID SEMICOLON  */
#line 134 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), false);
        }
#line 1697 "parser.tab.c"
    break;

  case 11: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 138 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), false);
        }
#line 1705 "parser.tab.c"
    break;

  case 12: /* globdef: datatype ID LET expr SEMICOLON  */
#line 142 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1713 "parser.tab.c"
    break;

  case 13: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 146 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), false);
        }
#line 1721 "parser.tab.c"
    break;

  case 14: /* globdef: EXPORT datatype ID SEMICOLON  */
#line 150 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), true);
        }
#line 1729 "parser.tab.c"
    break;

  case 15: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 154 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), true);
        }
#line 1737 "parser.tab.c"
    break;

  case 16: /* globdef: EXPORT datatype ID LET expr SEMICOLON  */
#line 158 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1745 "parser.tab.c"
    break;

  case 17: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 162 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), true);
        }
#line 1753 "parser.tab.c"
    break;

  case 18: /* funbody: vardecls  */
#line 172 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[0].node), NULL, NULL);
      }
#line 1761 "parser.tab.c"
    break;

  case 19: /* funbody: stmts  */
#line 176 "parser.y"
      {
        (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[0].node));
      }
#line 1769 "parser.tab.c"
    break;

  case 20: /* funbody: fundefs  */
#line 180 "parser.y"
      {
        (yyval.node) = ASTfunbody(NULL, (yyvsp[0].node), NULL);
      }
#line 1777 "parser.tab.c"
    break;

  case 21: /* funbody: vardecls stmts  */
#line 184 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, (yyvsp[0].node));
      }
#line 1785 "parser.tab.c"
    break;

  case 22: /* fundefs: fundef fundefs  */
#line 190 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1793 "parser.tab.c"
    break;

  case 23: /* fundefs: fundef  */
#line 194 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[0].node), NULL);
      }
#line 1801 "parser.tab.c"
    break;

  case 24: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 199 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1809 "parser.tab.c"
    break;

  case 25: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 203 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1817 "parser.tab.c"
    break;

  case 26: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 207 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1825 "parser.tab.c"
    break;

  case 27: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 211 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1833 "parser.tab.c"
    break;

  case 28: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 215 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1841 "parser.tab.c"
    break;

  case 29: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 219 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), false); 
        }
#line 1849 "parser.tab.c"
    break;

  case 30: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 223 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1857 "parser.tab.c"
    break;

  case 31: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 227 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), true); 
        }
#line 1865 "parser.tab.c"
    break;

  case 32: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 231 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1873 "parser.tab.c"
    break;

  case 33: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 235 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1881 "parser.tab.c"
    break;

  case 34: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 239 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1889 "parser.tab.c"
    break;

  case 35: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 243 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), true); 
        }
#line 1897 "parser.tab.c"
    break;

  case 36: /* fundef: EXTERN datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 247 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false); 
        }
#line 1905 "parser.tab.c"
    break;

  case 37: /* fundef: EXTERN datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 251 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1913 "parser.tab.c"
    break;

  case 38: /* funcall: ID ROUNDBRACKET_L args ROUNDBRACKET_R  */
#line 256 "parser.y"
        {
          (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 1921 "parser.tab.c"
    break;

  case 39: /* funcall: ID ROUNDBRACKET_L ROUNDBRACKET_R  */
#line 260 "parser.y"
        {
          (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
        }
#line 1929 "parser.tab.c"
    break;

  case 40: /* vardecls: vardecl vardecls  */
#line 271 "parser.y"
      {
        VARDECL_NEXT((yyvsp[-1].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
      }
#line 1938 "parser.tab.c"
    break;

  case 41: /* vardecls: vardecl  */
#line 276 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1946 "parser.tab.c"
    break;

  case 42: /* vardecl: datatype ID SEMICOLON  */
#line 282 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].cdatatype));
        }
#line 1954 "parser.tab.c"
    break;

  case 43: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 286 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].id), (yyvsp[-5].cdatatype));
        }
#line 1962 "parser.tab.c"
    break;

  case 44: /* vardecl: datatype ID LET expr SEMICOLON  */
#line 290 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].cdatatype));
        }
#line 1970 "parser.tab.c"
    break;

  case 45: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 294 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-5].node), (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-7].cdatatype));
        }
#line 1978 "parser.tab.c"
    break;

  case 46: /* args: arg COMMA args  */
#line 300 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1987 "parser.tab.c"
    break;

  case 47: /* args: arg  */
#line 305 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1995 "parser.tab.c"
    break;

  case 48: /* arg: expr  */
#line 310 "parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 2003 "parser.tab.c"
    break;

  case 49: /* params: param COMMA params  */
#line 316 "parser.y"
      {
        PARAM_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2012 "parser.tab.c"
    break;

  case 50: /* params: param  */
#line 321 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2020 "parser.tab.c"
    break;

  case 51: /* param: datatype ID  */
#line 326 "parser.y"
      {
        (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].cdatatype));
      }
#line 2028 "parser.tab.c"
    break;

  case 52: /* param: datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID  */
#line 330 "parser.y"
      {
        (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].cdatatype));
      }
#line 2036 "parser.tab.c"
    break;

  case 53: /* exprs_dims: expr_dim COMMA exprs_dims  */
#line 336 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2045 "parser.tab.c"
    break;

  case 54: /* exprs_dims: expr_dim  */
#line 341 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2053 "parser.tab.c"
    break;

  case 55: /* id_dims: id_dim COMMA id_dims  */
#line 346 "parser.y"
      {
        IDS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2062 "parser.tab.c"
    break;

  case 56: /* id_dims: id_dim  */
#line 351 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2070 "parser.tab.c"
    break;

  case 57: /* id_dim: ID  */
#line 356 "parser.y"
      {
        (yyval.node) = ASTids(NULL, (yyvsp[0].id));
      }
#line 2078 "parser.tab.c"
    break;

  case 58: /* expr_dim: expr  */
#line 361 "parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
      }
#line 2086 "parser.tab.c"
    break;

  case 59: /* stmts: stmt stmts  */
#line 370 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 2094 "parser.tab.c"
    break;

  case 60: /* stmts: stmt  */
#line 374 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2102 "parser.tab.c"
    break;

  case 61: /* stmt: assign  */
#line 380 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2110 "parser.tab.c"
    break;

  case 62: /* stmt: expr SEMICOLON  */
#line 384 "parser.y"
      {
        (yyval.node) = ASTexprstmt((yyvsp[-1].node));
      }
#line 2118 "parser.tab.c"
    break;

  case 63: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr ROUNDBRACKET_R block  */
#line 388 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[0].node), (yyvsp[-6].id));
      }
#line 2126 "parser.tab.c"
    break;

  case 64: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr COMMA expr ROUNDBRACKET_R block  */
#line 392 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-8].id) );
      }
#line 2134 "parser.tab.c"
    break;

  case 65: /* stmt: DO block WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R SEMICOLON  */
#line 396 "parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-5].node));
      }
#line 2142 "parser.tab.c"
    break;

  case 66: /* stmt: WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 400 "parser.y"
      {
        (yyval.node) = ASTwhile((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2150 "parser.tab.c"
    break;

  case 67: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 404 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 2158 "parser.tab.c"
    break;

  case 68: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block  */
#line 408 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2166 "parser.tab.c"
    break;

  case 69: /* stmt: RETURN SEMICOLON  */
#line 412 "parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2174 "parser.tab.c"
    break;

  case 70: /* stmt: RETURN expr SEMICOLON  */
#line 416 "parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2182 "parser.tab.c"
    break;

  case 71: /* assign: varlet LET expr SEMICOLON  */
#line 422 "parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2190 "parser.tab.c"
    break;

  case 73: /* block: CURLYBRACKET_L stmts CURLYBRACKET_R  */
#line 429 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2198 "parser.tab.c"
    break;

  case 74: /* varlet: ID  */
#line 435 "parser.y"
        {
          (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
        }
#line 2206 "parser.tab.c"
    break;

  case 75: /* varlet: ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 439 "parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 2214 "parser.tab.c"
    break;

  case 76: /* expr: ROUNDBRACKET_L expr ROUNDBRACKET_R  */
#line 445 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2222 "parser.tab.c"
    break;

  case 77: /* expr: ID  */
#line 449 "parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 2230 "parser.tab.c"
    break;

  case 78: /* expr: cast  */
#line 453 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2238 "parser.tab.c"
    break;

  case 79: /* expr: funcall  */
#line 457 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2246 "parser.tab.c"
    break;

  case 80: /* expr: constant  */
#line 461 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2254 "parser.tab.c"
    break;

  case 81: /* expr: array_expr  */
#line 465 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2262 "parser.tab.c"
    break;

  case 82: /* expr: arithmetic_expr  */
#line 469 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2270 "parser.tab.c"
    break;

  case 83: /* expr: comparison_expr  */
#line 473 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2278 "parser.tab.c"
    break;

  case 84: /* expr: logical_expr  */
#line 477 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2286 "parser.tab.c"
    break;

  case 85: /* expr: unary_expr  */
#line 481 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2294 "parser.tab.c"
    break;

  case 86: /* unary_expr: UMINUS expr  */
#line 487 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
      }
#line 2302 "parser.tab.c"
    break;

  case 87: /* unary_expr: NEG expr  */
#line 491 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
      }
#line 2310 "parser.tab.c"
    break;

  case 88: /* arithmetic_expr: expr PLUS expr  */
#line 497 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_add);
      }
#line 2318 "parser.tab.c"
    break;

  case 89: /* arithmetic_expr: expr MINUS expr  */
#line 501 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_sub);
      }
#line 2326 "parser.tab.c"
    break;

  case 90: /* arithmetic_expr: expr STAR expr  */
#line 505 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mul);
      }
#line 2334 "parser.tab.c"
    break;

  case 91: /* arithmetic_expr: expr SLASH expr  */
#line 509 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_div);
      }
#line 2342 "parser.tab.c"
    break;

  case 92: /* arithmetic_expr: expr PERCENT expr  */
#line 513 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mod);
      }
#line 2350 "parser.tab.c"
    break;

  case 93: /* comparison_expr: expr LT expr  */
#line 519 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_le);
      }
#line 2358 "parser.tab.c"
    break;

  case 94: /* comparison_expr: expr LE expr  */
#line 523 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_lt);
      }
#line 2366 "parser.tab.c"
    break;

  case 95: /* comparison_expr: expr GT expr  */
#line 527 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_gt);
      }
#line 2374 "parser.tab.c"
    break;

  case 96: /* comparison_expr: expr GE expr  */
#line 531 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ge);
      }
#line 2382 "parser.tab.c"
    break;

  case 97: /* comparison_expr: expr EQ expr  */
#line 535 "parser.y"
      {
          (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_eq);
      }
#line 2390 "parser.tab.c"
    break;

  case 98: /* comparison_expr: expr NE expr  */
#line 539 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ne);
      }
#line 2398 "parser.tab.c"
    break;

  case 99: /* logical_expr: expr OR expr  */
#line 545 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_or);
      }
#line 2406 "parser.tab.c"
    break;

  case 100: /* logical_expr: expr AND expr  */
#line 549 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_and);
      }
#line 2414 "parser.tab.c"
    break;

  case 101: /* array_expr: SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 555 "parser.y"
      {
        (yyval.node) = ASTarrexpr((yyvsp[-1].node));
      }
#line 2422 "parser.tab.c"
    break;

  case 102: /* cast: ROUNDBRACKET_L datatype ROUNDBRACKET_R expr  */
#line 561 "parser.y"
    {
      (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].cdatatype));
    }
#line 2430 "parser.tab.c"
    break;

  case 103: /* constant: FLOAT  */
#line 574 "parser.y"
          {
            (yyval.node) = ASTfloat((yyvsp[0].cflt));
          }
#line 2438 "parser.tab.c"
    break;

  case 104: /* constant: NUM  */
#line 578 "parser.y"
          {
            (yyval.node) = ASTnum((yyvsp[0].cint));
          }
#line 2446 "parser.tab.c"
    break;

  case 105: /* constant: TRUEVAL  */
#line 582 "parser.y"
          {
            (yyval.node) = ASTbool(true);
          }
#line 2454 "parser.tab.c"
    break;

  case 106: /* constant: FALSEVAL  */
#line 586 "parser.y"
          {
            (yyval.node) = ASTbool(false);
          }
#line 2462 "parser.tab.c"
    break;

  case 107: /* datatype: VOIDTYPE  */
#line 595 "parser.y"
                  {   (yyval.cdatatype) = CT_void; }
#line 2468 "parser.tab.c"
    break;

  case 108: /* datatype: INTTYPE  */
#line 596 "parser.y"
                  {   (yyval.cdatatype) = CT_int;  }
#line 2474 "parser.tab.c"
    break;

  case 109: /* datatype: FLOATTYPE  */
#line 597 "parser.y"
                  {   (yyval.cdatatype) = CT_float; }
#line 2480 "parser.tab.c"
    break;

  case 110: /* datatype: BOOLTYPE  */
#line 598 "parser.y"
                  {   (yyval.cdatatype) = CT_bool;  }
#line 2486 "parser.tab.c"
    break;


#line 2490 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 601 "parser.y"


void AddLocToNode(node_st *node, void *begin_loc, void *end_loc)
{
    // Needed because YYLTYPE unpacks later than top-level decl.
    YYLTYPE *loc_b = (YYLTYPE*)begin_loc;
    YYLTYPE *loc_e = (YYLTYPE*)end_loc;
    NODE_BLINE(node) = loc_b->first_line;
    NODE_BCOL(node) = loc_b->first_column;
    NODE_ELINE(node) = loc_e->last_line;
    NODE_ECOL(node) = loc_e->last_column;
}

static int yyerror( char *error)
{
  CTI(CTI_ERROR, true, "line %d, col %d\nError parsing source code: %s\n",
            global.line, global.col, error);
  CTIabortOnError();
  return( 0);
}

node_st *SPdoScanParse(node_st *root)
{
    DBUG_ASSERT(root == NULL, "Started parsing with existing syntax tree.");
    yyin = fopen(global.input_file, "r");
    if (yyin == NULL) {
        CTI(CTI_ERROR, true, "Cannot open file '%s'.", global.input_file);
        CTIabortOnError();
    }
    yyparse();
    return parseresult;
}

