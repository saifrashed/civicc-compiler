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
    THEN = 299                     /* THEN  */
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

#line 195 "parser.tab.c"

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
  YYSYMBOL_THEN = 44,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_decls = 47,                     /* decls  */
  YYSYMBOL_decl = 48,                      /* decl  */
  YYSYMBOL_globdecl = 49,                  /* globdecl  */
  YYSYMBOL_globdef = 50,                   /* globdef  */
  YYSYMBOL_funbody = 51,                   /* funbody  */
  YYSYMBOL_fundef = 52,                    /* fundef  */
  YYSYMBOL_funcall = 53,                   /* funcall  */
  YYSYMBOL_vardecls = 54,                  /* vardecls  */
  YYSYMBOL_vardecl = 55,                   /* vardecl  */
  YYSYMBOL_args = 56,                      /* args  */
  YYSYMBOL_arg = 57,                       /* arg  */
  YYSYMBOL_params = 58,                    /* params  */
  YYSYMBOL_param = 59,                     /* param  */
  YYSYMBOL_exprs_dims = 60,                /* exprs_dims  */
  YYSYMBOL_id_dims = 61,                   /* id_dims  */
  YYSYMBOL_id_dim = 62,                    /* id_dim  */
  YYSYMBOL_expr_dim = 63,                  /* expr_dim  */
  YYSYMBOL_stmts = 64,                     /* stmts  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_ifelse = 66,                    /* ifelse  */
  YYSYMBOL_assign = 67,                    /* assign  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_varlet = 69,                    /* varlet  */
  YYSYMBOL_cast = 70,                      /* cast  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_constant = 72,                  /* constant  */
  YYSYMBOL_floatval = 73,                  /* floatval  */
  YYSYMBOL_intval = 74,                    /* intval  */
  YYSYMBOL_boolval = 75,                   /* boolval  */
  YYSYMBOL_datatype = 76                   /* datatype  */
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
#define YYLAST   501

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    90,    94,   100,   105,   110,   122,   127,
     132,   136,   140,   144,   148,   152,   156,   160,   170,   174,
     178,   194,   198,   202,   206,   210,   214,   218,   222,   226,
     230,   234,   238,   242,   246,   251,   255,   266,   271,   277,
     281,   285,   289,   295,   300,   305,   311,   316,   321,   325,
     331,   336,   341,   346,   351,   356,   365,   369,   374,   378,
     382,   386,   390,   396,   400,   405,   411,   412,   418,   424,
     440,   444,   448,   453,   457,   461,   466,   471,   476,   481,
     486,   491,   496,   501,   506,   511,   516,   521,   526,   531,
     543,   547,   551,   556,   561,   566,   570,   581,   582,   583,
     584
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
  "VOIDTYPE", "NUM", "FLOAT", "ID", "UMINUS", "THEN", "$accept", "program",
  "decls", "decl", "globdecl", "globdef", "funbody", "fundef", "funcall",
  "vardecls", "vardecl", "args", "arg", "params", "param", "exprs_dims",
  "id_dims", "id_dim", "expr_dim", "stmts", "stmt", "ifelse", "assign",
  "block", "varlet", "cast", "expr", "constant", "floatval", "intval",
  "boolval", "datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     237,   139,   139,  -129,  -129,  -129,  -129,    20,  -129,   237,
    -129,  -129,  -129,    28,    29,    30,  -129,  -129,   264,     1,
     264,   134,    -9,     9,   188,   264,  -129,  -129,  -129,  -129,
      83,   264,  -129,    75,    88,  -129,   456,  -129,  -129,  -129,
    -129,    26,  -129,   264,    90,   104,  -129,   264,  -129,   105,
     114,   120,  -129,   297,   128,  -129,   244,  -129,    89,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,    13,   130,   126,    68,   331,    94,    16,
     135,   345,   106,    -9,   140,   145,  -129,   264,  -129,   150,
     163,   456,     4,  -129,   113,   113,  -129,  -129,  -129,   311,
     311,   311,   311,   482,   482,   469,   169,    52,  -129,    17,
     139,    -9,  -129,  -129,    47,    78,  -129,    95,  -129,   185,
    -129,  -129,   187,  -129,  -129,   264,  -129,   264,  -129,   170,
     253,     7,   192,   218,   139,  -129,   218,  -129,  -129,   172,
     359,    80,   127,  -129,  -129,   194,  -129,   264,  -129,   197,
     168,  -129,  -129,  -129,  -129,   373,   264,  -129,   387,  -129,
    -129,  -129,  -129,   264,  -129,   264,    69,  -129,   210,   158,
     401,  -129,  -129,   211,  -129,   317,  -129,   415,   214,  -129,
     264,  -129,  -129,  -129,  -129,   215,  -129,   177,   429,   212,
     203,    72,  -129,  -129,   217,   215,  -129,   264,  -129,  -129,
     443,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   100,    99,    98,    97,     0,     2,     4,
       6,     5,     7,     0,     0,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    94,    93,
      73,     0,    72,     0,    51,    71,    55,    74,    90,    91,
      92,     0,    10,     0,     0,     0,    14,     0,    54,     0,
      53,     0,     8,     0,     0,    89,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,    36,     0,
      44,    45,     0,    50,    76,    75,    77,    78,    79,    81,
      80,    83,    82,    84,    85,    86,    87,     0,    21,     0,
       0,     0,    48,    12,     0,     0,    27,     0,    16,     0,
      52,    33,     0,    69,    35,     0,    11,     0,    22,     0,
       0,    73,     0,    18,    38,    19,    57,    59,    58,     0,
       0,     0,     0,    24,    46,     0,    15,     0,    28,     0,
       0,    30,     9,    34,    43,     0,     0,    61,     0,    23,
      20,    37,    56,     0,    60,     0,     0,    25,     0,     0,
       0,    29,    31,     0,    13,     0,    62,     0,     0,    39,
       0,    26,    49,    17,    32,     0,    65,     0,     0,     0,
      63,     0,    41,    66,     0,     0,    40,     0,    67,    64,
       0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   224,  -129,  -129,  -129,   -83,  -129,  -129,   100,
    -129,   110,  -129,   -42,  -129,   -19,   -10,  -129,  -129,  -128,
    -129,  -129,  -129,    44,  -129,  -129,   -18,  -129,  -129,  -129,
    -129,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,   132,    12,    32,   133,
     134,    89,    90,    74,    75,    33,    49,    50,    34,   135,
     136,   137,   138,   190,   139,    35,   140,    37,    38,    39,
      40,   141
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    44,    36,    80,    41,   160,    53,    55,   162,    85,
      56,    42,    51,    57,   126,    13,    14,    15,   107,    52,
      16,   115,   142,   108,    13,    77,   116,   143,    43,    81,
      73,   127,   149,    48,   -68,    18,    20,    22,    91,    54,
      93,    36,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    24,    76,   146,   128,   168,
      76,   194,     3,     4,     5,     6,    76,   173,   144,   123,
      19,    21,    23,   120,   147,   111,    25,    26,    27,   179,
     129,    24,   196,    58,   148,   130,    56,   165,     3,     4,
       5,     6,    28,    29,   131,    31,   180,    59,    78,   197,
     150,   145,    25,    26,    27,   151,   129,    91,    79,   155,
     112,   130,   158,    82,     3,     4,     5,     6,    28,    29,
     131,    31,   166,    83,    84,    76,    62,    63,    64,   170,
      24,    92,    87,   167,   109,   110,   114,    45,   175,   117,
       3,     4,     5,     6,    46,   177,   178,    36,   119,   122,
     121,    25,    26,    27,   124,   129,     3,     4,     5,     6,
     130,    47,   188,     3,     4,     5,     6,    28,    29,   131,
      31,    24,   125,   156,   172,     3,     4,     5,     6,   200,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    24,    25,    26,    27,   152,   129,   153,   159,   163,
     182,   130,   169,   171,     3,     4,     5,     6,    28,    29,
     131,    31,    25,    26,    27,    24,   181,   184,   193,   191,
     189,    24,   187,   198,     3,     4,     5,     6,    28,    29,
      30,    31,   195,    17,   161,   154,    25,    26,    27,   199,
     129,     0,    25,    26,    27,   130,   129,    24,    88,     0,
       0,   130,    28,    29,   131,    31,    24,     0,    28,    29,
     131,    31,     0,   157,     0,     0,     0,    24,    25,    26,
      27,     1,     2,     3,     4,     5,     6,    25,    26,    27,
       0,     0,     0,     0,    28,    29,    30,    31,    25,    26,
      27,     0,     0,    28,    29,    30,    31,     0,     0,     0,
       0,    86,     0,     0,    28,    29,    30,    31,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   185,    60,    61,    62,    63,    64,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   113,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   118,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   164,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   174,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   176,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   183,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   186,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   192,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   201,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    72,    60,    61,    62,    63,    64,    65,    66,
      67,    68
};

static const yytype_int16 yycheck[] =
{
      18,    20,    20,    45,     3,   133,    24,    25,   136,    51,
       3,    10,     3,    31,    10,     0,     1,     2,     5,    10,
       0,     5,     5,    10,     9,    43,    10,    10,    27,    47,
       4,    27,   115,    42,    27,     7,     7,     7,    56,    24,
      59,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     3,    41,    10,     6,   142,
      45,   189,    36,    37,    38,    39,    51,   150,   110,    87,
      42,    42,    42,    83,    27,     7,    24,    25,    26,    10,
      28,     3,    10,     8,     6,    33,     3,     7,    36,    37,
      38,    39,    40,    41,    42,    43,    27,     9,     8,    27,
       5,   111,    24,    25,    26,    10,    28,   125,     4,   127,
      42,    33,   130,     8,    36,    37,    38,    39,    40,    41,
      42,    43,    42,     9,     4,   110,    13,    14,    15,   147,
       3,    42,     4,     6,     4,     9,    42,     3,   156,     4,
      36,    37,    38,    39,    10,   163,   165,   165,    42,     4,
      10,    24,    25,    26,     4,    28,    36,    37,    38,    39,
      33,    27,   180,    36,    37,    38,    39,    40,    41,    42,
      43,     3,     9,     3,     6,    36,    37,    38,    39,   197,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     3,    24,    25,    26,    10,    28,    10,     6,    27,
      42,    33,     8,     6,    36,    37,    38,    39,    40,    41,
      42,    43,    24,    25,    26,     3,     6,     6,     6,    42,
       5,     3,     8,     6,    36,    37,    38,    39,    40,    41,
      42,    43,    29,     9,   134,   125,    24,    25,    26,   195,
      28,    -1,    24,    25,    26,    33,    28,     3,     4,    -1,
      -1,    33,    40,    41,    42,    43,     3,    -1,    40,    41,
      42,    43,    -1,    10,    -1,    -1,    -1,     3,    24,    25,
      26,    34,    35,    36,    37,    38,    39,    24,    25,    26,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    24,    25,
      26,    -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    40,    41,    42,    43,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     4,    11,    12,    13,    14,    15,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    11,    12,    13,    14,    15,    16,    17,
      18,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    46,    47,    48,
      49,    50,    52,    76,    76,    76,     0,    47,     7,    42,
       7,    42,     7,    42,     3,    24,    25,    26,    40,    41,
      42,    43,    53,    60,    63,    70,    71,    72,    73,    74,
      75,     3,    10,    27,    60,     3,    10,    27,    42,    61,
      62,     3,    10,    71,    76,    71,     3,    71,     8,     9,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    58,    59,    76,    71,     8,     4,
      58,    71,     8,     9,     4,    58,     4,     4,     4,    56,
      57,    71,    42,    60,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,     5,    10,     4,
       9,     7,    42,    10,    42,     5,    10,     4,    10,    42,
      61,    10,     4,    71,     4,     9,    10,    27,     6,    28,
      33,    42,    51,    54,    55,    64,    65,    66,    67,    69,
      71,    76,     5,    10,    58,    61,    10,    27,     6,    51,
       5,    10,    10,    10,    56,    71,     3,    10,    71,     6,
      64,    54,    64,    27,    10,     7,    42,     6,    51,     8,
      71,     6,     6,    51,    10,    71,    10,    71,    60,    10,
      27,     6,    42,    10,     6,     4,    10,     8,    71,     5,
      68,    42,    10,     6,    64,    29,    10,    27,     6,    68,
      71,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    66,    66,    67,    68,    68,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    73,    74,    75,    75,    76,    76,    76,
      76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     7,
       3,     6,     5,     8,     4,     7,     6,     9,     1,     1,
       2,     5,     6,     7,     6,     7,     8,     6,     7,     8,
       7,     8,     9,     6,     7,     4,     3,     2,     1,     3,
       6,     5,     8,     3,     1,     1,     3,     1,     2,     5,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     3,     5,     7,     4,     2,     3,     1,     4,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 79 "parser.y"
         {
           parseresult = (yyvsp[0].node);
         }
#line 1578 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 91 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1586 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 95 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1594 "parser.tab.c"
    break;

  case 5: /* decl: globdef  */
#line 101 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1602 "parser.tab.c"
    break;

  case 6: /* decl: globdecl  */
#line 106 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1610 "parser.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 111 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1618 "parser.tab.c"
    break;

  case 8: /* globdecl: EXTERN datatype ID SEMICOLON  */
#line 123 "parser.y"
       {
         (yyval.node) =  ASTglobdecl(NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id));
       }
#line 1626 "parser.tab.c"
    break;

  case 9: /* globdecl: EXTERN datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 128 "parser.y"
       {
         (yyval.node) =  ASTglobdecl((yyvsp[-3].node), (yyvsp[-5].cdatatype), (yyvsp[-1].id));
       }
#line 1634 "parser.tab.c"
    break;

  case 10: /* globdef: datatype ID SEMICOLON  */
#line 133 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), false);
        }
#line 1642 "parser.tab.c"
    break;

  case 11: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 137 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), false);
        }
#line 1650 "parser.tab.c"
    break;

  case 12: /* globdef: datatype ID LET expr SEMICOLON  */
#line 141 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1658 "parser.tab.c"
    break;

  case 13: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 145 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), false);
        }
#line 1666 "parser.tab.c"
    break;

  case 14: /* globdef: EXPORT datatype ID SEMICOLON  */
#line 149 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), true);
        }
#line 1674 "parser.tab.c"
    break;

  case 15: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 153 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), true);
        }
#line 1682 "parser.tab.c"
    break;

  case 16: /* globdef: EXPORT datatype ID LET expr SEMICOLON  */
#line 157 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1690 "parser.tab.c"
    break;

  case 17: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 161 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), true);
        }
#line 1698 "parser.tab.c"
    break;

  case 18: /* funbody: vardecls  */
#line 171 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[0].node), NULL, NULL);
      }
#line 1706 "parser.tab.c"
    break;

  case 19: /* funbody: stmts  */
#line 175 "parser.y"
      {
        (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[0].node));
      }
#line 1714 "parser.tab.c"
    break;

  case 20: /* funbody: vardecls stmts  */
#line 179 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, (yyvsp[0].node));
      }
#line 1722 "parser.tab.c"
    break;

  case 21: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 195 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1730 "parser.tab.c"
    break;

  case 22: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 199 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1738 "parser.tab.c"
    break;

  case 23: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 203 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1746 "parser.tab.c"
    break;

  case 24: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 207 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1754 "parser.tab.c"
    break;

  case 25: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 211 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1762 "parser.tab.c"
    break;

  case 26: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 215 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), false); 
        }
#line 1770 "parser.tab.c"
    break;

  case 27: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 219 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1778 "parser.tab.c"
    break;

  case 28: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 223 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), true); 
        }
#line 1786 "parser.tab.c"
    break;

  case 29: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 227 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1794 "parser.tab.c"
    break;

  case 30: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 231 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1802 "parser.tab.c"
    break;

  case 31: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 235 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1810 "parser.tab.c"
    break;

  case 32: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 239 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), true); 
        }
#line 1818 "parser.tab.c"
    break;

  case 33: /* fundef: EXTERN datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 243 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false); 
        }
#line 1826 "parser.tab.c"
    break;

  case 34: /* fundef: EXTERN datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 247 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1834 "parser.tab.c"
    break;

  case 35: /* funcall: ID ROUNDBRACKET_L args ROUNDBRACKET_R  */
#line 252 "parser.y"
        {
          (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 1842 "parser.tab.c"
    break;

  case 36: /* funcall: ID ROUNDBRACKET_L ROUNDBRACKET_R  */
#line 256 "parser.y"
        {
          (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
        }
#line 1850 "parser.tab.c"
    break;

  case 37: /* vardecls: vardecl vardecls  */
#line 267 "parser.y"
      {
        VARDECL_NEXT((yyvsp[-1].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
      }
#line 1859 "parser.tab.c"
    break;

  case 38: /* vardecls: vardecl  */
#line 272 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1867 "parser.tab.c"
    break;

  case 39: /* vardecl: datatype ID SEMICOLON  */
#line 278 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].cdatatype));
        }
#line 1875 "parser.tab.c"
    break;

  case 40: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 282 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].id), (yyvsp[-5].cdatatype));
        }
#line 1883 "parser.tab.c"
    break;

  case 41: /* vardecl: datatype ID LET expr SEMICOLON  */
#line 286 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].cdatatype));
        }
#line 1891 "parser.tab.c"
    break;

  case 42: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 290 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-5].node), (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-7].cdatatype));
        }
#line 1899 "parser.tab.c"
    break;

  case 43: /* args: arg COMMA args  */
#line 296 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1908 "parser.tab.c"
    break;

  case 44: /* args: arg  */
#line 301 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1916 "parser.tab.c"
    break;

  case 45: /* arg: expr  */
#line 306 "parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 1924 "parser.tab.c"
    break;

  case 46: /* params: param COMMA params  */
#line 312 "parser.y"
      {
        PARAM_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1933 "parser.tab.c"
    break;

  case 47: /* params: param  */
#line 317 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1941 "parser.tab.c"
    break;

  case 48: /* param: datatype ID  */
#line 322 "parser.y"
      {
        (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].cdatatype));
      }
#line 1949 "parser.tab.c"
    break;

  case 49: /* param: datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID  */
#line 326 "parser.y"
      {
        (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].cdatatype));
      }
#line 1957 "parser.tab.c"
    break;

  case 50: /* exprs_dims: expr_dim COMMA exprs_dims  */
#line 332 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1966 "parser.tab.c"
    break;

  case 51: /* exprs_dims: expr_dim  */
#line 337 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1974 "parser.tab.c"
    break;

  case 52: /* id_dims: id_dim COMMA id_dims  */
#line 342 "parser.y"
      {
        IDS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1983 "parser.tab.c"
    break;

  case 53: /* id_dims: id_dim  */
#line 347 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1991 "parser.tab.c"
    break;

  case 54: /* id_dim: ID  */
#line 352 "parser.y"
      {
        (yyval.node) = ASTids(NULL, (yyvsp[0].id));
      }
#line 1999 "parser.tab.c"
    break;

  case 55: /* expr_dim: expr  */
#line 357 "parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
      }
#line 2007 "parser.tab.c"
    break;

  case 56: /* stmts: stmt stmts  */
#line 366 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 2015 "parser.tab.c"
    break;

  case 57: /* stmts: stmt  */
#line 370 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2023 "parser.tab.c"
    break;

  case 58: /* stmt: assign  */
#line 375 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2031 "parser.tab.c"
    break;

  case 59: /* stmt: ifelse  */
#line 379 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2039 "parser.tab.c"
    break;

  case 60: /* stmt: expr SEMICOLON  */
#line 383 "parser.y"
      {
        (yyval.node) = ASTexprstmt((yyvsp[-1].node));
      }
#line 2047 "parser.tab.c"
    break;

  case 61: /* stmt: RETURN SEMICOLON  */
#line 387 "parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2055 "parser.tab.c"
    break;

  case 62: /* stmt: RETURN expr SEMICOLON  */
#line 391 "parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2063 "parser.tab.c"
    break;

  case 63: /* ifelse: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 397 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 2071 "parser.tab.c"
    break;

  case 64: /* ifelse: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block  */
#line 401 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2079 "parser.tab.c"
    break;

  case 65: /* assign: varlet LET expr SEMICOLON  */
#line 406 "parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2087 "parser.tab.c"
    break;

  case 66: /* block: CURLYBRACKET_L CURLYBRACKET_R  */
#line 411 "parser.y"
                                     {}
#line 2093 "parser.tab.c"
    break;

  case 67: /* block: CURLYBRACKET_L stmts CURLYBRACKET_R  */
#line 413 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2101 "parser.tab.c"
    break;

  case 68: /* varlet: ID  */
#line 419 "parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[0].id));
          AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
        }
#line 2110 "parser.tab.c"
    break;

  case 69: /* cast: ROUNDBRACKET_L datatype ROUNDBRACKET_R expr  */
#line 425 "parser.y"
      {
        (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].cdatatype));
        AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[-3]));
      }
#line 2119 "parser.tab.c"
    break;

  case 70: /* expr: ROUNDBRACKET_L expr ROUNDBRACKET_R  */
#line 441 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2127 "parser.tab.c"
    break;

  case 71: /* expr: cast  */
#line 445 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2135 "parser.tab.c"
    break;

  case 72: /* expr: funcall  */
#line 449 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2144 "parser.tab.c"
    break;

  case 73: /* expr: ID  */
#line 454 "parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 2152 "parser.tab.c"
    break;

  case 74: /* expr: constant  */
#line 458 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2160 "parser.tab.c"
    break;

  case 75: /* expr: expr PLUS expr  */
#line 462 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_add);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2169 "parser.tab.c"
    break;

  case 76: /* expr: expr MINUS expr  */
#line 467 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_sub);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2178 "parser.tab.c"
    break;

  case 77: /* expr: expr STAR expr  */
#line 472 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mul);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2187 "parser.tab.c"
    break;

  case 78: /* expr: expr SLASH expr  */
#line 477 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_div);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2196 "parser.tab.c"
    break;

  case 79: /* expr: expr PERCENT expr  */
#line 482 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mod);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2205 "parser.tab.c"
    break;

  case 80: /* expr: expr LT expr  */
#line 487 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_le);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2214 "parser.tab.c"
    break;

  case 81: /* expr: expr LE expr  */
#line 492 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_lt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2223 "parser.tab.c"
    break;

  case 82: /* expr: expr GT expr  */
#line 497 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_gt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2232 "parser.tab.c"
    break;

  case 83: /* expr: expr GE expr  */
#line 502 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ge);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2241 "parser.tab.c"
    break;

  case 84: /* expr: expr EQ expr  */
#line 507 "parser.y"
      {
          (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_eq);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2250 "parser.tab.c"
    break;

  case 85: /* expr: expr NE expr  */
#line 512 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ne);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2259 "parser.tab.c"
    break;

  case 86: /* expr: expr OR expr  */
#line 517 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_or);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2268 "parser.tab.c"
    break;

  case 87: /* expr: expr AND expr  */
#line 522 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_and);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2277 "parser.tab.c"
    break;

  case 88: /* expr: UMINUS expr  */
#line 527 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2286 "parser.tab.c"
    break;

  case 89: /* expr: NEG expr  */
#line 532 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2295 "parser.tab.c"
    break;

  case 90: /* constant: floatval  */
#line 544 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2303 "parser.tab.c"
    break;

  case 91: /* constant: intval  */
#line 548 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2311 "parser.tab.c"
    break;

  case 92: /* constant: boolval  */
#line 552 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2319 "parser.tab.c"
    break;

  case 93: /* floatval: FLOAT  */
#line 557 "parser.y"
          {
            (yyval.node) = ASTfloat((yyvsp[0].cflt));
          }
#line 2327 "parser.tab.c"
    break;

  case 94: /* intval: NUM  */
#line 562 "parser.y"
        {
          (yyval.node) = ASTnum((yyvsp[0].cint));
        }
#line 2335 "parser.tab.c"
    break;

  case 95: /* boolval: TRUEVAL  */
#line 567 "parser.y"
        {
          (yyval.node) = ASTbool(true);
        }
#line 2343 "parser.tab.c"
    break;

  case 96: /* boolval: FALSEVAL  */
#line 571 "parser.y"
        {
          (yyval.node) = ASTbool(false);
        }
#line 2351 "parser.tab.c"
    break;

  case 97: /* datatype: VOIDTYPE  */
#line 581 "parser.y"
                  {   (yyval.cdatatype) = CT_void; }
#line 2357 "parser.tab.c"
    break;

  case 98: /* datatype: INTTYPE  */
#line 582 "parser.y"
                  {   (yyval.cdatatype) = CT_int;  }
#line 2363 "parser.tab.c"
    break;

  case 99: /* datatype: FLOATTYPE  */
#line 583 "parser.y"
                  {   (yyval.cdatatype) = CT_float; }
#line 2369 "parser.tab.c"
    break;

  case 100: /* datatype: BOOLTYPE  */
#line 584 "parser.y"
                  {   (yyval.cdatatype) = CT_bool;  }
#line 2375 "parser.tab.c"
    break;


#line 2379 "parser.tab.c"

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

#line 587 "parser.y"


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

