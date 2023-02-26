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
  YYSYMBOL_fundefs = 52,                   /* fundefs  */
  YYSYMBOL_fundef = 53,                    /* fundef  */
  YYSYMBOL_funcall = 54,                   /* funcall  */
  YYSYMBOL_vardecls = 55,                  /* vardecls  */
  YYSYMBOL_vardecl = 56,                   /* vardecl  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_arg = 58,                       /* arg  */
  YYSYMBOL_params = 59,                    /* params  */
  YYSYMBOL_param = 60,                     /* param  */
  YYSYMBOL_exprs_dims = 61,                /* exprs_dims  */
  YYSYMBOL_id_dims = 62,                   /* id_dims  */
  YYSYMBOL_id_dim = 63,                    /* id_dim  */
  YYSYMBOL_expr_dim = 64,                  /* expr_dim  */
  YYSYMBOL_stmts = 65,                     /* stmts  */
  YYSYMBOL_stmt = 66,                      /* stmt  */
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
#define YYLAST   574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

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
     178,   182,   188,   192,   197,   201,   205,   209,   213,   217,
     221,   225,   229,   233,   237,   241,   245,   249,   254,   258,
     269,   274,   280,   284,   288,   292,   298,   303,   308,   314,
     319,   324,   328,   334,   339,   344,   349,   354,   359,   368,
     372,   377,   381,   385,   389,   393,   397,   401,   405,   411,
     417,   418,   424,   430,   446,   450,   454,   459,   463,   467,
     472,   477,   482,   487,   492,   497,   502,   507,   512,   517,
     522,   527,   532,   537,   549,   553,   557,   562,   567,   572,
     576,   587,   588,   589,   590
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
  "decls", "decl", "globdecl", "globdef", "funbody", "fundefs", "fundef",
  "funcall", "vardecls", "vardecl", "args", "arg", "params", "param",
  "exprs_dims", "id_dims", "id_dim", "expr_dim", "stmts", "stmt", "assign",
  "block", "varlet", "cast", "expr", "constant", "floatval", "intval",
  "boolval", "datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,   302,   302,  -193,  -193,  -193,  -193,    18,  -193,   150,
    -193,  -193,  -193,    15,    21,    68,  -193,  -193,   293,     9,
     293,    98,    -8,    13,   128,   293,  -193,  -193,  -193,  -193,
     103,   293,  -193,   122,    89,  -193,   518,  -193,  -193,  -193,
    -193,    23,  -193,   293,   125,    29,  -193,   293,  -193,   137,
     138,    35,  -193,   333,   153,  -193,   289,  -193,   119,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,    25,   158,   141,    74,   209,   130,    95,
     169,   407,   133,    -8,   168,   186,  -193,   293,  -193,   188,
     184,   518,    -6,  -193,   167,   167,  -193,  -193,  -193,   245,
     245,   245,   245,   555,   555,   531,   544,    52,  -193,   107,
     302,    -8,  -193,  -193,    10,   171,  -193,   146,  -193,   206,
    -193,  -193,   207,  -193,  -193,   293,  -193,   293,  -193,   191,
     195,   228,   284,   302,   302,    76,   229,  -193,   268,   258,
     302,  -193,   258,  -193,   240,   421,    77,   212,  -193,  -193,
     226,  -193,   293,  -193,   233,   238,  -193,  -193,  -193,  -193,
     435,   293,   293,    96,   235,  -193,   449,   243,   248,  -193,
    -193,   253,  -193,  -193,    90,  -193,   293,  -193,   293,   101,
    -193,   264,   255,   463,  -193,  -193,   305,  -193,   353,   373,
    -193,   306,   313,  -193,   317,   318,   319,    86,   477,   315,
    -193,   293,  -193,  -193,  -193,  -193,   228,   228,  -193,   293,
    -193,   286,   491,   314,  -193,   393,   108,  -193,   228,   332,
    -193,   293,  -193,  -193,   505,  -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   104,   103,   102,   101,     0,     2,     4,
       6,     5,     7,     0,     0,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,    98,    97,
      77,     0,    76,     0,    54,    75,    58,    78,    94,    95,
      96,     0,    10,     0,     0,     0,    14,     0,    57,     0,
      56,     0,     8,     0,     0,    93,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,    39,     0,
      47,    48,     0,    53,    80,    79,    81,    82,    83,    85,
      84,    87,    86,    88,    89,    90,    91,     0,    24,     0,
       0,     0,    51,    12,     0,     0,    30,     0,    16,     0,
      55,    36,     0,    73,    38,     0,    11,     0,    25,     0,
       0,     0,     0,     0,     0,    77,     0,    20,    23,    18,
      41,    19,    60,    61,     0,     0,     0,     0,    27,    49,
       0,    15,     0,    31,     0,     0,    33,     9,    37,    46,
       0,     0,     0,     0,     0,    67,     0,     0,     0,    26,
      22,     0,    21,    40,     0,    59,     0,    62,     0,     0,
      28,     0,     0,     0,    32,    34,     0,    13,     0,     0,
      70,     0,     0,    68,     0,     0,     0,     0,     0,     0,
      42,     0,    29,    52,    17,    35,     0,     0,    71,     0,
      69,     0,     0,    65,    64,     0,     0,    44,     0,     0,
      43,     0,    66,    63,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,   349,  -193,  -193,  -193,   -91,   221,   140,  -193,
     220,  -193,   236,  -193,   -40,  -193,   -19,   -80,  -193,  -193,
      37,  -193,  -193,  -192,  -193,  -193,   -18,  -193,  -193,  -193,
    -193,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,   136,   137,   138,    32,
     139,   140,    89,    90,    74,    75,    33,    49,    50,    34,
     141,   142,   143,   164,   144,    35,   145,    37,    38,    39,
      40,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    44,    36,   120,   126,    80,    53,    55,    13,    14,
      15,    85,    41,    57,   213,   214,    51,    13,    16,    42,
     151,   127,    18,    52,   154,    77,   222,    73,    20,    81,
     107,   150,    54,    79,    48,   108,    43,   152,    91,    84,
      93,    36,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    24,   181,    19,   128,     3,
       4,     5,     6,    21,   186,     3,     4,     5,     6,   123,
     149,     3,     4,     5,     6,    22,    25,    26,    27,    56,
     129,   111,   130,   131,   178,   132,   133,   134,     3,     4,
       5,     6,    28,    29,   135,    31,   200,   178,    59,    24,
     115,    45,   190,   -72,    41,   116,    56,    91,    46,   160,
      23,   200,   147,   201,   166,   146,   112,   148,   220,   179,
      25,    26,    27,   146,   129,    47,   130,   131,   201,   132,
      58,    24,   197,    78,   183,   221,    28,    29,   135,    31,
      12,   167,   168,   188,   189,    82,   171,    83,   174,    12,
     110,   155,    25,    26,    27,   146,   156,    87,   198,   199,
      36,    92,   109,   146,     3,     4,     5,     6,    28,    29,
      30,    31,   114,   117,    24,   119,   172,   153,   121,   175,
      62,    63,    64,   212,     1,     2,     3,     4,     5,     6,
     122,   215,   124,   125,   161,    25,    26,    27,   162,   129,
     191,   130,   131,   224,   132,   133,   134,     3,     4,     5,
       6,    28,    29,   135,    31,    24,   157,   158,   180,   113,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   163,   182,   169,    25,    26,    27,   184,
     129,    24,   130,   131,   185,   132,   133,   134,     3,     4,
       5,     6,    28,    29,   135,    31,    60,    61,    62,    63,
      64,    24,    25,    26,    27,   192,   129,   176,   130,   131,
     202,   132,   133,   134,     3,     4,     5,     6,    28,    29,
     135,    31,    25,    26,    27,   194,   129,    24,   130,   131,
     195,   132,    24,    88,   165,   196,    24,   203,    28,    29,
     135,    31,   133,   134,     3,     4,     5,     6,    25,    26,
      27,   205,   208,    25,    26,    27,   209,    25,    26,    27,
      45,    51,    41,   211,    28,    29,    30,    31,   216,    28,
      29,    30,    31,    28,    29,    30,    31,    86,     3,     4,
       5,     6,   223,   218,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   206,    17,   170,
     173,   159,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   207,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   219,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   118,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   177,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   187,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   193,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   204,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   210,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   217,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   225,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    72,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    62,    63,
      64,    65,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      18,    20,    20,    83,    10,    45,    24,    25,     0,     1,
       2,    51,     3,    31,   206,   207,     3,     9,     0,    10,
      10,    27,     7,    10,   115,    43,   218,     4,     7,    47,
       5,   111,    24,     4,    42,    10,    27,    27,    56,     4,
      59,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     3,   147,    42,     6,    36,
      37,    38,    39,    42,   155,    36,    37,    38,    39,    87,
     110,    36,    37,    38,    39,     7,    24,    25,    26,     3,
      28,     7,    30,    31,     7,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    10,     7,     9,     3,
       5,     3,     6,    27,     3,    10,     3,   125,    10,   127,
      42,    10,     5,    27,   132,   107,    42,    10,    10,    42,
      24,    25,    26,   115,    28,    27,    30,    31,    27,    33,
       8,     3,    42,     8,   152,    27,    40,    41,    42,    43,
       0,   133,   134,   161,   162,     8,   138,     9,   140,     9,
       9,     5,    24,    25,    26,   147,    10,     4,   176,   178,
     178,    42,     4,   155,    36,    37,    38,    39,    40,    41,
      42,    43,    42,     4,     3,    42,   139,     6,    10,   142,
      13,    14,    15,   201,    34,    35,    36,    37,    38,    39,
       4,   209,     4,     9,     3,    24,    25,    26,     3,    28,
     163,    30,    31,   221,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     3,    10,    10,     6,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     5,     8,     6,    24,    25,    26,     6,
      28,     3,    30,    31,     6,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    11,    12,    13,    14,
      15,     3,    24,    25,    26,    30,    28,    27,    30,    31,
       6,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    24,    25,    26,    42,    28,     3,    30,    31,
      42,    33,     3,     4,    10,    42,     3,    42,    40,    41,
      42,    43,    34,    35,    36,    37,    38,    39,    24,    25,
      26,     6,     6,    24,    25,    26,     3,    24,    25,    26,
       3,     3,     3,     8,    40,    41,    42,    43,    42,    40,
      41,    42,    43,    40,    41,    42,    43,     4,    36,    37,
      38,    39,    10,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     4,     9,   138,
     140,   125,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    10,    11,    12,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    11,    12,    13,    14,
      15,    16,    17,    18,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    46,    47,    48,
      49,    50,    53,    76,    76,    76,     0,    47,     7,    42,
       7,    42,     7,    42,     3,    24,    25,    26,    40,    41,
      42,    43,    54,    61,    64,    70,    71,    72,    73,    74,
      75,     3,    10,    27,    61,     3,    10,    27,    42,    62,
      63,     3,    10,    71,    76,    71,     3,    71,     8,     9,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    59,    60,    76,    71,     8,     4,
      59,    71,     8,     9,     4,    59,     4,     4,     4,    57,
      58,    71,    42,    61,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,     5,    10,     4,
       9,     7,    42,    10,    42,     5,    10,     4,    10,    42,
      62,    10,     4,    71,     4,     9,    10,    27,     6,    28,
      30,    31,    33,    34,    35,    42,    51,    52,    53,    55,
      56,    65,    66,    67,    69,    71,    76,     5,    10,    59,
      62,    10,    27,     6,    51,     5,    10,    10,    10,    57,
      71,     3,     3,     5,    68,    10,    71,    76,    76,     6,
      52,    76,    65,    55,    76,    65,    27,    10,     7,    42,
       6,    51,     8,    71,     6,     6,    51,    10,    71,    71,
       6,    65,    30,    10,    42,    42,    42,    42,    71,    61,
      10,    27,     6,    42,    10,     6,     4,     4,     6,     3,
      10,     8,    71,    68,    68,    71,    42,    10,    29,     4,
      10,    27,    68,    10,    71,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    73,    74,    75,
      75,    76,    76,    76,    76
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
       1,     1,     2,     7,     5,     5,     7,     2,     3,     4,
       2,     3,     1,     4,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 1598 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 91 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1606 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 95 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1614 "parser.tab.c"
    break;

  case 5: /* decl: globdef  */
#line 101 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1622 "parser.tab.c"
    break;

  case 6: /* decl: globdecl  */
#line 106 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1630 "parser.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 111 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1638 "parser.tab.c"
    break;

  case 8: /* globdecl: EXTERN datatype ID SEMICOLON  */
#line 123 "parser.y"
       {
         (yyval.node) =  ASTglobdecl(NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id));
       }
#line 1646 "parser.tab.c"
    break;

  case 9: /* globdecl: EXTERN datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 128 "parser.y"
       {
         (yyval.node) =  ASTglobdecl((yyvsp[-3].node), (yyvsp[-5].cdatatype), (yyvsp[-1].id));
       }
#line 1654 "parser.tab.c"
    break;

  case 10: /* globdef: datatype ID SEMICOLON  */
#line 133 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), false);
        }
#line 1662 "parser.tab.c"
    break;

  case 11: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 137 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), false);
        }
#line 1670 "parser.tab.c"
    break;

  case 12: /* globdef: datatype ID LET expr SEMICOLON  */
#line 141 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1678 "parser.tab.c"
    break;

  case 13: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 145 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), false);
        }
#line 1686 "parser.tab.c"
    break;

  case 14: /* globdef: EXPORT datatype ID SEMICOLON  */
#line 149 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), true);
        }
#line 1694 "parser.tab.c"
    break;

  case 15: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 153 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), true);
        }
#line 1702 "parser.tab.c"
    break;

  case 16: /* globdef: EXPORT datatype ID LET expr SEMICOLON  */
#line 157 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1710 "parser.tab.c"
    break;

  case 17: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 161 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), true);
        }
#line 1718 "parser.tab.c"
    break;

  case 18: /* funbody: vardecls  */
#line 171 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[0].node), NULL, NULL);
      }
#line 1726 "parser.tab.c"
    break;

  case 19: /* funbody: stmts  */
#line 175 "parser.y"
      {
        (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[0].node));
      }
#line 1734 "parser.tab.c"
    break;

  case 20: /* funbody: fundefs  */
#line 179 "parser.y"
      {
        (yyval.node) = ASTfunbody(NULL, (yyvsp[0].node), NULL);
      }
#line 1742 "parser.tab.c"
    break;

  case 21: /* funbody: vardecls stmts  */
#line 183 "parser.y"
      {
        (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, (yyvsp[0].node));
      }
#line 1750 "parser.tab.c"
    break;

  case 22: /* fundefs: fundef fundefs  */
#line 189 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1758 "parser.tab.c"
    break;

  case 23: /* fundefs: fundef  */
#line 193 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[0].node), NULL);
      }
#line 1766 "parser.tab.c"
    break;

  case 24: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 198 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1774 "parser.tab.c"
    break;

  case 25: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 202 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1782 "parser.tab.c"
    break;

  case 26: /* fundef: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 206 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1790 "parser.tab.c"
    break;

  case 27: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 210 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1798 "parser.tab.c"
    break;

  case 28: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 214 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), false); 
        }
#line 1806 "parser.tab.c"
    break;

  case 29: /* fundef: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 218 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), false); 
        }
#line 1814 "parser.tab.c"
    break;

  case 30: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 222 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1822 "parser.tab.c"
    break;

  case 31: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 226 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-5].cdatatype), (yyvsp[-4].id), true); 
        }
#line 1830 "parser.tab.c"
    break;

  case 32: /* fundef: EXPORT datatype ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 230 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1838 "parser.tab.c"
    break;

  case 33: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 234 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false);
        }
#line 1846 "parser.tab.c"
    break;

  case 34: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R  */
#line 238 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-3].node), (yyvsp[-6].cdatatype), (yyvsp[-5].id), true); 
        }
#line 1854 "parser.tab.c"
    break;

  case 35: /* fundef: EXPORT datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R  */
#line 242 "parser.y"
        { 
          (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].cdatatype), (yyvsp[-6].id), true); 
        }
#line 1862 "parser.tab.c"
    break;

  case 36: /* fundef: EXTERN datatype ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON  */
#line 246 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].cdatatype), (yyvsp[-3].id), false); 
        }
#line 1870 "parser.tab.c"
    break;

  case 37: /* fundef: EXTERN datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  */
#line 250 "parser.y"
        { 
          (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].cdatatype), (yyvsp[-4].id), false); 
        }
#line 1878 "parser.tab.c"
    break;

  case 38: /* funcall: ID ROUNDBRACKET_L args ROUNDBRACKET_R  */
#line 255 "parser.y"
        {
          (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 1886 "parser.tab.c"
    break;

  case 39: /* funcall: ID ROUNDBRACKET_L ROUNDBRACKET_R  */
#line 259 "parser.y"
        {
          (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
        }
#line 1894 "parser.tab.c"
    break;

  case 40: /* vardecls: vardecl vardecls  */
#line 270 "parser.y"
      {
        VARDECL_NEXT((yyvsp[-1].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
      }
#line 1903 "parser.tab.c"
    break;

  case 41: /* vardecls: vardecl  */
#line 275 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1911 "parser.tab.c"
    break;

  case 42: /* vardecl: datatype ID SEMICOLON  */
#line 281 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].cdatatype));
        }
#line 1919 "parser.tab.c"
    break;

  case 43: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 285 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].id), (yyvsp[-5].cdatatype));
        }
#line 1927 "parser.tab.c"
    break;

  case 44: /* vardecl: datatype ID LET expr SEMICOLON  */
#line 289 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].cdatatype));
        }
#line 1935 "parser.tab.c"
    break;

  case 45: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 293 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-5].node), (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-7].cdatatype));
        }
#line 1943 "parser.tab.c"
    break;

  case 46: /* args: arg COMMA args  */
#line 299 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1952 "parser.tab.c"
    break;

  case 47: /* args: arg  */
#line 304 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1960 "parser.tab.c"
    break;

  case 48: /* arg: expr  */
#line 309 "parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 1968 "parser.tab.c"
    break;

  case 49: /* params: param COMMA params  */
#line 315 "parser.y"
      {
        PARAM_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1977 "parser.tab.c"
    break;

  case 50: /* params: param  */
#line 320 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1985 "parser.tab.c"
    break;

  case 51: /* param: datatype ID  */
#line 325 "parser.y"
      {
        (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].cdatatype));
      }
#line 1993 "parser.tab.c"
    break;

  case 52: /* param: datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID  */
#line 329 "parser.y"
      {
        (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].cdatatype));
      }
#line 2001 "parser.tab.c"
    break;

  case 53: /* exprs_dims: expr_dim COMMA exprs_dims  */
#line 335 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2010 "parser.tab.c"
    break;

  case 54: /* exprs_dims: expr_dim  */
#line 340 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2018 "parser.tab.c"
    break;

  case 55: /* id_dims: id_dim COMMA id_dims  */
#line 345 "parser.y"
      {
        IDS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2027 "parser.tab.c"
    break;

  case 56: /* id_dims: id_dim  */
#line 350 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2035 "parser.tab.c"
    break;

  case 57: /* id_dim: ID  */
#line 355 "parser.y"
      {
        (yyval.node) = ASTids(NULL, (yyvsp[0].id));
      }
#line 2043 "parser.tab.c"
    break;

  case 58: /* expr_dim: expr  */
#line 360 "parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
      }
#line 2051 "parser.tab.c"
    break;

  case 59: /* stmts: stmt stmts  */
#line 369 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 2059 "parser.tab.c"
    break;

  case 60: /* stmts: stmt  */
#line 373 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2067 "parser.tab.c"
    break;

  case 61: /* stmt: assign  */
#line 378 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2075 "parser.tab.c"
    break;

  case 62: /* stmt: expr SEMICOLON  */
#line 382 "parser.y"
      {
        (yyval.node) = ASTexprstmt((yyvsp[-1].node));
      }
#line 2083 "parser.tab.c"
    break;

  case 63: /* stmt: DO block WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R SEMICOLON  */
#line 386 "parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-5].node));
      }
#line 2091 "parser.tab.c"
    break;

  case 64: /* stmt: WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 390 "parser.y"
      {
        (yyval.node) = ASTwhile((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2099 "parser.tab.c"
    break;

  case 65: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 394 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 2107 "parser.tab.c"
    break;

  case 66: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block  */
#line 398 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2115 "parser.tab.c"
    break;

  case 67: /* stmt: RETURN SEMICOLON  */
#line 402 "parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2123 "parser.tab.c"
    break;

  case 68: /* stmt: RETURN expr SEMICOLON  */
#line 406 "parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2131 "parser.tab.c"
    break;

  case 69: /* assign: varlet LET expr SEMICOLON  */
#line 412 "parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2139 "parser.tab.c"
    break;

  case 70: /* block: CURLYBRACKET_L CURLYBRACKET_R  */
#line 417 "parser.y"
                                     {}
#line 2145 "parser.tab.c"
    break;

  case 71: /* block: CURLYBRACKET_L stmts CURLYBRACKET_R  */
#line 419 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2153 "parser.tab.c"
    break;

  case 72: /* varlet: ID  */
#line 425 "parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[0].id));
          AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
        }
#line 2162 "parser.tab.c"
    break;

  case 73: /* cast: ROUNDBRACKET_L datatype ROUNDBRACKET_R expr  */
#line 431 "parser.y"
      {
        (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].cdatatype));
        AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[-3]));
      }
#line 2171 "parser.tab.c"
    break;

  case 74: /* expr: ROUNDBRACKET_L expr ROUNDBRACKET_R  */
#line 447 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2179 "parser.tab.c"
    break;

  case 75: /* expr: cast  */
#line 451 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2187 "parser.tab.c"
    break;

  case 76: /* expr: funcall  */
#line 455 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2196 "parser.tab.c"
    break;

  case 77: /* expr: ID  */
#line 460 "parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 2204 "parser.tab.c"
    break;

  case 78: /* expr: constant  */
#line 464 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2212 "parser.tab.c"
    break;

  case 79: /* expr: expr PLUS expr  */
#line 468 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_add);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2221 "parser.tab.c"
    break;

  case 80: /* expr: expr MINUS expr  */
#line 473 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_sub);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2230 "parser.tab.c"
    break;

  case 81: /* expr: expr STAR expr  */
#line 478 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mul);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2239 "parser.tab.c"
    break;

  case 82: /* expr: expr SLASH expr  */
#line 483 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_div);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2248 "parser.tab.c"
    break;

  case 83: /* expr: expr PERCENT expr  */
#line 488 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mod);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2257 "parser.tab.c"
    break;

  case 84: /* expr: expr LT expr  */
#line 493 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_le);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2266 "parser.tab.c"
    break;

  case 85: /* expr: expr LE expr  */
#line 498 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_lt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2275 "parser.tab.c"
    break;

  case 86: /* expr: expr GT expr  */
#line 503 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_gt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2284 "parser.tab.c"
    break;

  case 87: /* expr: expr GE expr  */
#line 508 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ge);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2293 "parser.tab.c"
    break;

  case 88: /* expr: expr EQ expr  */
#line 513 "parser.y"
      {
          (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_eq);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2302 "parser.tab.c"
    break;

  case 89: /* expr: expr NE expr  */
#line 518 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ne);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2311 "parser.tab.c"
    break;

  case 90: /* expr: expr OR expr  */
#line 523 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_or);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2320 "parser.tab.c"
    break;

  case 91: /* expr: expr AND expr  */
#line 528 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_and);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2329 "parser.tab.c"
    break;

  case 92: /* expr: UMINUS expr  */
#line 533 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2338 "parser.tab.c"
    break;

  case 93: /* expr: NEG expr  */
#line 538 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
        AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
      }
#line 2347 "parser.tab.c"
    break;

  case 94: /* constant: floatval  */
#line 550 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2355 "parser.tab.c"
    break;

  case 95: /* constant: intval  */
#line 554 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2363 "parser.tab.c"
    break;

  case 96: /* constant: boolval  */
#line 558 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2371 "parser.tab.c"
    break;

  case 97: /* floatval: FLOAT  */
#line 563 "parser.y"
          {
            (yyval.node) = ASTfloat((yyvsp[0].cflt));
          }
#line 2379 "parser.tab.c"
    break;

  case 98: /* intval: NUM  */
#line 568 "parser.y"
        {
          (yyval.node) = ASTnum((yyvsp[0].cint));
        }
#line 2387 "parser.tab.c"
    break;

  case 99: /* boolval: TRUEVAL  */
#line 573 "parser.y"
        {
          (yyval.node) = ASTbool(true);
        }
#line 2395 "parser.tab.c"
    break;

  case 100: /* boolval: FALSEVAL  */
#line 577 "parser.y"
        {
          (yyval.node) = ASTbool(false);
        }
#line 2403 "parser.tab.c"
    break;

  case 101: /* datatype: VOIDTYPE  */
#line 587 "parser.y"
                  {   (yyval.cdatatype) = CT_void; }
#line 2409 "parser.tab.c"
    break;

  case 102: /* datatype: INTTYPE  */
#line 588 "parser.y"
                  {   (yyval.cdatatype) = CT_int;  }
#line 2415 "parser.tab.c"
    break;

  case 103: /* datatype: FLOATTYPE  */
#line 589 "parser.y"
                  {   (yyval.cdatatype) = CT_float; }
#line 2421 "parser.tab.c"
    break;

  case 104: /* datatype: BOOLTYPE  */
#line 590 "parser.y"
                  {   (yyval.cdatatype) = CT_bool;  }
#line 2427 "parser.tab.c"
    break;


#line 2431 "parser.tab.c"

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

#line 593 "parser.y"


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

