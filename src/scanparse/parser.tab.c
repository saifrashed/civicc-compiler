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
  YYSYMBOL_funheader = 52,                 /* funheader  */
  YYSYMBOL_funbody = 53,                   /* funbody  */
  YYSYMBOL_fundef = 54,                    /* fundef  */
  YYSYMBOL_funcall = 55,                   /* funcall  */
  YYSYMBOL_vardecls_opt = 56,              /* vardecls_opt  */
  YYSYMBOL_stmts_opt = 57,                 /* stmts_opt  */
  YYSYMBOL_vardecls = 58,                  /* vardecls  */
  YYSYMBOL_vardecl = 59,                   /* vardecl  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg = 61,                       /* arg  */
  YYSYMBOL_params = 62,                    /* params  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_exprs_dims = 64,                /* exprs_dims  */
  YYSYMBOL_id_dims = 65,                   /* id_dims  */
  YYSYMBOL_id_dim = 66,                    /* id_dim  */
  YYSYMBOL_expr_dim = 67,                  /* expr_dim  */
  YYSYMBOL_stmts = 68,                     /* stmts  */
  YYSYMBOL_stmt = 69,                      /* stmt  */
  YYSYMBOL_assign = 70,                    /* assign  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_varlet = 72,                    /* varlet  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_unary_expr = 74,                /* unary_expr  */
  YYSYMBOL_arithmetic_expr = 75,           /* arithmetic_expr  */
  YYSYMBOL_comparison_expr = 76,           /* comparison_expr  */
  YYSYMBOL_logical_expr = 77,              /* logical_expr  */
  YYSYMBOL_array_expr = 78,                /* array_expr  */
  YYSYMBOL_cast = 79,                      /* cast  */
  YYSYMBOL_constant = 80,                  /* constant  */
  YYSYMBOL_datatype = 81                   /* datatype  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       0,    80,    80,    92,    96,   102,   107,   112,   124,   129,
     134,   138,   142,   146,   150,   154,   158,   162,   187,   191,
     196,   210,   214,   219,   226,   230,   236,   241,   254,   259,
     269,   274,   280,   284,   288,   292,   298,   303,   308,   314,
     319,   324,   328,   334,   339,   344,   349,   354,   359,   368,
     372,   378,   382,   386,   390,   394,   398,   402,   406,   410,
     414,   420,   426,   427,   431,   437,   441,   447,   451,   455,
     459,   463,   467,   471,   475,   479,   483,   489,   493,   499,
     503,   507,   511,   515,   521,   525,   529,   533,   537,   541,
     547,   551,   557,   563,   576,   580,   584,   588,   598,   599,
     600,   601
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
  "program", "decls", "decl", "globdecl", "globdef", "funheader",
  "funbody", "fundef", "funcall", "vardecls_opt", "stmts_opt", "vardecls",
  "vardecl", "args", "arg", "params", "param", "exprs_dims", "id_dims",
  "id_dim", "expr_dim", "stmts", "stmt", "assign", "block", "varlet",
  "expr", "unary_expr", "arithmetic_expr", "comparison_expr",
  "logical_expr", "array_expr", "cast", "constant", "datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,   227,   227,  -104,  -104,  -104,  -104,    10,  -104,   189,
    -104,  -104,    11,  -104,     2,    11,    12,     3,    15,  -104,
    -104,   227,  -104,   163,   128,  -104,   163,   130,  -104,   -18,
       8,   111,  -104,   227,    21,    85,   163,   163,  -104,  -104,
    -104,  -104,    17,   163,  -104,    26,    33,   438,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,    22,  -104,   163,    59,  -104,
     163,  -104,    77,    78,  -104,    95,    97,    20,   105,    94,
       5,   102,   107,  -104,   111,  -104,    87,  -104,   163,    56,
     218,   141,   124,  -104,   155,  -104,   104,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,  -104,   150,   154,    75,   327,   123,   341,   125,   -18,
     163,   163,    -1,  -104,   138,   227,  -104,   355,   163,  -104,
    -104,  -104,   163,   164,  -104,   163,  -104,   163,  -104,  -104,
     167,   166,   438,    76,  -104,    80,    80,  -104,  -104,  -104,
     232,   232,   232,   232,   475,   475,   451,   464,  -104,   227,
     -18,  -104,  -104,    79,  -104,   173,  -104,   238,   258,  -104,
     171,   170,   142,  -104,   177,   369,   149,   383,  -104,  -104,
     163,  -104,   163,  -104,   184,  -104,   163,  -104,    20,    20,
    -104,   163,   172,  -104,  -104,    89,  -104,  -104,   397,   151,
     411,   165,  -104,   278,   163,  -104,   163,  -104,  -104,  -104,
      20,   190,   313,   425,  -104,  -104,   163,  -104,   198,    20,
     163,  -104,   298,    20,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   101,   100,    99,    98,     0,     2,     4,
       6,     5,     0,     7,     0,     0,     0,     0,     0,     1,
       3,    27,    22,     0,     0,    23,     0,     0,    21,     0,
       0,    29,    26,    31,     0,     0,     0,     0,    96,    97,
      95,    94,    68,     0,    70,     0,    44,    48,    76,    73,
      74,    75,    72,    69,    71,     0,    10,     0,     0,    14,
       0,    47,     0,    46,     8,     0,     0,     0,     0,     0,
      65,     0,     0,    28,    50,    51,     0,    30,     0,     0,
       0,     0,     0,    78,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,    59,     0,     0,    52,
      20,    49,     0,     0,    32,     0,    67,     0,    92,    25,
       0,    37,    38,     0,    43,    80,    79,    81,    82,    83,
      85,    84,    87,    86,    88,    89,    90,    91,    18,     0,
       0,    41,    12,     0,    16,     0,    45,     0,     0,    62,
       0,     0,     0,    60,     0,     0,     0,     0,    93,    24,
       0,    11,     0,    39,     0,    15,     0,     9,     0,     0,
      63,     0,     0,    66,    61,     0,    34,    36,     0,     0,
       0,    57,    56,     0,     0,    33,     0,    13,    42,    17,
       0,     0,     0,     0,    58,    55,     0,    35,     0,     0,
       0,    53,     0,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,   192,  -104,  -104,  -104,    37,   193,  -104,   -31,
    -104,  -104,   215,  -104,    98,  -104,   118,  -104,   -22,  -103,
    -104,  -104,   -67,   -28,  -104,   -49,  -104,   -20,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    22,    13,    44,
      31,    72,    32,    33,   130,   131,   102,   103,    45,    62,
      63,    46,    73,   113,    75,   114,    76,    47,    48,    49,
      50,    51,    52,    53,    54,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    16,    18,    74,    58,   159,   156,   121,    84,    23,
      19,    55,   118,    28,    82,    80,    21,    83,    64,    26,
      84,    34,    29,    85,    61,   112,   101,    65,    78,    66,
      67,    68,    69,    34,    86,    81,    71,   105,    15,    17,
     107,    70,    87,    71,    24,   160,    74,   174,    65,   117,
      66,    67,    68,    69,    27,   104,   123,    30,     3,     4,
       5,     6,    70,    79,   132,   134,   124,   106,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    71,   150,   125,    74,   108,   171,   109,    35,   175,
     157,   158,    36,    90,    91,    92,   164,    35,   110,   195,
     111,    36,   165,   172,   116,   167,   176,   168,   115,    37,
      38,    39,   119,   120,   122,   162,   196,   151,    37,    38,
      39,     3,     4,     5,     6,    40,    41,    42,    43,   191,
     192,    55,   128,    55,    40,    41,    42,    43,    56,    65,
      59,    66,    67,    68,    69,   127,   133,    71,    71,   104,
     132,   204,   188,    70,   148,    57,   190,    60,    35,   129,
     211,   193,    36,   149,   214,   153,    35,   155,   161,    71,
      36,   169,   166,   181,   202,   170,   203,   180,    71,    37,
      38,    39,    71,   177,   182,   183,   208,    37,    38,    39,
     212,   185,   189,   198,   200,    40,    41,    42,    43,   194,
     205,    20,   209,    40,    41,    42,    43,   210,    25,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   126,     1,     2,     3,     4,     5,     6,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   178,    88,    89,    90,    91,    92,    77,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   179,     3,     4,     5,     6,   173,   187,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   201,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   213,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   206,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   152,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   154,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   163,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   184,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   186,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   197,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   199,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   207,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    88,    89,    90,    91,
      92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      31,     1,     2,    31,    26,     6,   109,    74,     3,     7,
       0,     3,     7,    10,    36,    35,     5,    37,    10,     7,
       3,    21,     7,    43,    42,     5,     4,    28,     7,    30,
      31,    32,    33,    33,     8,    35,    67,    57,     1,     2,
      60,    42,     9,    74,    42,   112,    74,   150,    28,    69,
      30,    31,    32,    33,    42,    55,    78,    42,    36,    37,
      38,    39,    42,    42,    84,    87,    10,     8,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   112,     7,    27,   112,     8,    10,     9,     3,    10,
     110,   111,     7,    13,    14,    15,   118,     3,     3,    10,
       3,     7,   122,    27,    10,   125,    27,   127,     3,    24,
      25,    26,    10,     6,    27,   115,    27,    42,    24,    25,
      26,    36,    37,    38,    39,    40,    41,    42,    43,   178,
     179,     3,     8,     3,    40,    41,    42,    43,    10,    28,
      10,    30,    31,    32,    33,     4,    42,   178,   179,   149,
     170,   200,   172,    42,     4,    27,   176,    27,     3,     4,
     209,   181,     7,     9,   213,    42,     3,    42,    30,   200,
       7,     4,     8,     3,   194,     9,   196,     6,   209,    24,
      25,    26,   213,    10,    42,     8,   206,    24,    25,    26,
     210,    42,     8,    42,    29,    40,    41,    42,    43,    27,
      10,     9,     4,    40,    41,    42,    43,     9,    15,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    34,    35,    36,    37,    38,    39,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    11,    12,    13,    14,    15,    33,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    36,    37,    38,    39,   149,   170,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     9,    -1,    11,    12,    13,    14,    15,    16,
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
       0,    34,    35,    36,    37,    38,    39,    47,    48,    49,
      50,    51,    52,    54,    81,    52,    81,    52,    81,     0,
      48,     5,    53,     7,    42,    53,     7,    42,    10,     7,
      42,    56,    58,    59,    81,     3,     7,    24,    25,    26,
      40,    41,    42,    43,    55,    64,    67,    73,    74,    75,
      76,    77,    78,    79,    80,     3,    10,    27,    64,    10,
      27,    42,    65,    66,    10,    28,    30,    31,    32,    33,
      42,    55,    57,    68,    69,    70,    72,    58,     7,    42,
      73,    81,    64,    73,     3,    73,     8,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     4,    62,    63,    81,    73,     8,    73,     8,     9,
       3,     3,     5,    69,    71,     3,    10,    73,     7,    10,
       6,    68,    27,    64,    10,    27,     4,     4,     8,     4,
      60,    61,    73,    42,    64,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,     4,     9,
       7,    42,    10,    42,    10,    42,    65,    73,    73,     6,
      68,    30,    81,    10,    64,    73,     8,    73,    73,     4,
       9,    10,    27,    62,    65,    10,    27,    10,     4,     4,
       6,     3,    42,     8,    10,    42,    10,    60,    73,     8,
      73,    71,    71,    73,    27,    10,    27,    10,    42,    10,
      29,     4,    73,    73,    71,    10,     9,    10,    73,     4,
       9,    71,    73,     4,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    79,    80,    80,    80,    80,    81,    81,
      81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     7,
       3,     6,     5,     8,     4,     7,     6,     9,     5,     4,
       4,     3,     2,     3,     4,     3,     1,     0,     1,     0,
       2,     1,     3,     6,     5,     8,     3,     1,     1,     3,
       1,     2,     5,     3,     1,     3,     1,     1,     1,     2,
       1,     1,     2,    10,    12,     7,     5,     5,     7,     2,
       3,     4,     2,     3,     1,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 81 "parser.y"
         {
           parseresult = (yyvsp[0].node);
         }
#line 1587 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 93 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1595 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 97 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1603 "parser.tab.c"
    break;

  case 5: /* decl: globdef  */
#line 103 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1611 "parser.tab.c"
    break;

  case 6: /* decl: globdecl  */
#line 108 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1619 "parser.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 113 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1627 "parser.tab.c"
    break;

  case 8: /* globdecl: EXTERN datatype ID SEMICOLON  */
#line 125 "parser.y"
       {
         (yyval.node) =  ASTglobdecl(NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id));
       }
#line 1635 "parser.tab.c"
    break;

  case 9: /* globdecl: EXTERN datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 130 "parser.y"
       {
         (yyval.node) =  ASTglobdecl((yyvsp[-3].node), (yyvsp[-5].cdatatype), (yyvsp[-1].id));
       }
#line 1643 "parser.tab.c"
    break;

  case 10: /* globdef: datatype ID SEMICOLON  */
#line 135 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), false);
        }
#line 1651 "parser.tab.c"
    break;

  case 11: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 139 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), false);
        }
#line 1659 "parser.tab.c"
    break;

  case 12: /* globdef: datatype ID LET expr SEMICOLON  */
#line 143 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1667 "parser.tab.c"
    break;

  case 13: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 147 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), false);
        }
#line 1675 "parser.tab.c"
    break;

  case 14: /* globdef: EXPORT datatype ID SEMICOLON  */
#line 151 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), true);
        }
#line 1683 "parser.tab.c"
    break;

  case 15: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 155 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), true);
        }
#line 1691 "parser.tab.c"
    break;

  case 16: /* globdef: EXPORT datatype ID LET expr SEMICOLON  */
#line 159 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1699 "parser.tab.c"
    break;

  case 17: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 163 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), true);
        }
#line 1707 "parser.tab.c"
    break;

  case 18: /* funheader: datatype ID ROUNDBRACKET_L params ROUNDBRACKET_R  */
#line 188 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false); 
        }
#line 1715 "parser.tab.c"
    break;

  case 19: /* funheader: datatype ID ROUNDBRACKET_L ROUNDBRACKET_R  */
#line 192 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-3].cdatatype), (yyvsp[-2].id), false); 
        }
#line 1723 "parser.tab.c"
    break;

  case 20: /* funbody: CURLYBRACKET_L vardecls_opt stmts_opt CURLYBRACKET_R  */
#line 197 "parser.y"
        {
          (yyval.node) = ASTfunbody((yyvsp[-2].node), NULL, (yyvsp[-1].node)); 
        }
#line 1731 "parser.tab.c"
    break;

  case 21: /* fundef: EXTERN funheader SEMICOLON  */
#line 211 "parser.y"
        { 
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1739 "parser.tab.c"
    break;

  case 22: /* fundef: funheader funbody  */
#line 215 "parser.y"
        { 
          FUNDEF_BODY((yyvsp[-1].node)) = (yyvsp[0].node);
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1748 "parser.tab.c"
    break;

  case 23: /* fundef: EXPORT funheader funbody  */
#line 220 "parser.y"
        { 
          FUNDEF_BODY((yyvsp[-1].node)) = (yyvsp[0].node);
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1757 "parser.tab.c"
    break;

  case 24: /* funcall: ID ROUNDBRACKET_L args ROUNDBRACKET_R  */
#line 227 "parser.y"
        {
          (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 1765 "parser.tab.c"
    break;

  case 25: /* funcall: ID ROUNDBRACKET_L ROUNDBRACKET_R  */
#line 231 "parser.y"
        {
          (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
        }
#line 1773 "parser.tab.c"
    break;

  case 26: /* vardecls_opt: vardecls  */
#line 237 "parser.y"
              {
                (yyval.node) = (yyvsp[0].node);
              }
#line 1781 "parser.tab.c"
    break;

  case 27: /* vardecls_opt: %empty  */
#line 241 "parser.y"
              {
                (yyval.node) = NULL;
              }
#line 1789 "parser.tab.c"
    break;

  case 28: /* stmts_opt: stmts  */
#line 255 "parser.y"
              {
                (yyval.node) = (yyvsp[0].node);
              }
#line 1797 "parser.tab.c"
    break;

  case 29: /* stmts_opt: %empty  */
#line 259 "parser.y"
              {
                (yyval.node) = NULL;
              }
#line 1805 "parser.tab.c"
    break;

  case 30: /* vardecls: vardecl vardecls  */
#line 270 "parser.y"
      {
        VARDECL_NEXT((yyvsp[-1].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
      }
#line 1814 "parser.tab.c"
    break;

  case 31: /* vardecls: vardecl  */
#line 275 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1822 "parser.tab.c"
    break;

  case 32: /* vardecl: datatype ID SEMICOLON  */
#line 281 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].cdatatype));
        }
#line 1830 "parser.tab.c"
    break;

  case 33: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 285 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].id), (yyvsp[-5].cdatatype));
        }
#line 1838 "parser.tab.c"
    break;

  case 34: /* vardecl: datatype ID LET expr SEMICOLON  */
#line 289 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].cdatatype));
        }
#line 1846 "parser.tab.c"
    break;

  case 35: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 293 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-5].node), (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-7].cdatatype));
        }
#line 1854 "parser.tab.c"
    break;

  case 36: /* args: arg COMMA args  */
#line 299 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1863 "parser.tab.c"
    break;

  case 37: /* args: arg  */
#line 304 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1871 "parser.tab.c"
    break;

  case 38: /* arg: expr  */
#line 309 "parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 1879 "parser.tab.c"
    break;

  case 39: /* params: param COMMA params  */
#line 315 "parser.y"
      {
        PARAM_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1888 "parser.tab.c"
    break;

  case 40: /* params: param  */
#line 320 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1896 "parser.tab.c"
    break;

  case 41: /* param: datatype ID  */
#line 325 "parser.y"
      {
        (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].cdatatype));
      }
#line 1904 "parser.tab.c"
    break;

  case 42: /* param: datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID  */
#line 329 "parser.y"
      {
        (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].cdatatype));
      }
#line 1912 "parser.tab.c"
    break;

  case 43: /* exprs_dims: expr_dim COMMA exprs_dims  */
#line 335 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1921 "parser.tab.c"
    break;

  case 44: /* exprs_dims: expr_dim  */
#line 340 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1929 "parser.tab.c"
    break;

  case 45: /* id_dims: id_dim COMMA id_dims  */
#line 345 "parser.y"
      {
        IDS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1938 "parser.tab.c"
    break;

  case 46: /* id_dims: id_dim  */
#line 350 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1946 "parser.tab.c"
    break;

  case 47: /* id_dim: ID  */
#line 355 "parser.y"
      {
        (yyval.node) = ASTids(NULL, (yyvsp[0].id));
      }
#line 1954 "parser.tab.c"
    break;

  case 48: /* expr_dim: expr  */
#line 360 "parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
      }
#line 1962 "parser.tab.c"
    break;

  case 49: /* stmts: stmt stmts  */
#line 369 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1970 "parser.tab.c"
    break;

  case 50: /* stmts: stmt  */
#line 373 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 1978 "parser.tab.c"
    break;

  case 51: /* stmt: assign  */
#line 379 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1986 "parser.tab.c"
    break;

  case 52: /* stmt: funcall SEMICOLON  */
#line 383 "parser.y"
      {
        (yyval.node) = ASTexprstmt((yyvsp[-1].node));
      }
#line 1994 "parser.tab.c"
    break;

  case 53: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr ROUNDBRACKET_R block  */
#line 387 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[0].node), (yyvsp[-6].id));
      }
#line 2002 "parser.tab.c"
    break;

  case 54: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr COMMA expr ROUNDBRACKET_R block  */
#line 391 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-8].id) );
      }
#line 2010 "parser.tab.c"
    break;

  case 55: /* stmt: DO block WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R SEMICOLON  */
#line 395 "parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-5].node));
      }
#line 2018 "parser.tab.c"
    break;

  case 56: /* stmt: WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 399 "parser.y"
      {
        (yyval.node) = ASTwhile((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2026 "parser.tab.c"
    break;

  case 57: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 403 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 2034 "parser.tab.c"
    break;

  case 58: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block  */
#line 407 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2042 "parser.tab.c"
    break;

  case 59: /* stmt: RETURN SEMICOLON  */
#line 411 "parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2050 "parser.tab.c"
    break;

  case 60: /* stmt: RETURN expr SEMICOLON  */
#line 415 "parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2058 "parser.tab.c"
    break;

  case 61: /* assign: varlet LET expr SEMICOLON  */
#line 421 "parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2066 "parser.tab.c"
    break;

  case 63: /* block: CURLYBRACKET_L stmts CURLYBRACKET_R  */
#line 428 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2074 "parser.tab.c"
    break;

  case 64: /* block: stmt  */
#line 432 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2082 "parser.tab.c"
    break;

  case 65: /* varlet: ID  */
#line 438 "parser.y"
        {
          (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
        }
#line 2090 "parser.tab.c"
    break;

  case 66: /* varlet: ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 442 "parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 2098 "parser.tab.c"
    break;

  case 67: /* expr: ROUNDBRACKET_L expr ROUNDBRACKET_R  */
#line 448 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2106 "parser.tab.c"
    break;

  case 68: /* expr: ID  */
#line 452 "parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 2114 "parser.tab.c"
    break;

  case 69: /* expr: cast  */
#line 456 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2122 "parser.tab.c"
    break;

  case 70: /* expr: funcall  */
#line 460 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2130 "parser.tab.c"
    break;

  case 71: /* expr: constant  */
#line 464 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2138 "parser.tab.c"
    break;

  case 72: /* expr: array_expr  */
#line 468 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2146 "parser.tab.c"
    break;

  case 73: /* expr: arithmetic_expr  */
#line 472 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2154 "parser.tab.c"
    break;

  case 74: /* expr: comparison_expr  */
#line 476 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2162 "parser.tab.c"
    break;

  case 75: /* expr: logical_expr  */
#line 480 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2170 "parser.tab.c"
    break;

  case 76: /* expr: unary_expr  */
#line 484 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2178 "parser.tab.c"
    break;

  case 77: /* unary_expr: UMINUS expr  */
#line 490 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
      }
#line 2186 "parser.tab.c"
    break;

  case 78: /* unary_expr: NEG expr  */
#line 494 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
      }
#line 2194 "parser.tab.c"
    break;

  case 79: /* arithmetic_expr: expr PLUS expr  */
#line 500 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_add);
      }
#line 2202 "parser.tab.c"
    break;

  case 80: /* arithmetic_expr: expr MINUS expr  */
#line 504 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_sub);
      }
#line 2210 "parser.tab.c"
    break;

  case 81: /* arithmetic_expr: expr STAR expr  */
#line 508 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mul);
      }
#line 2218 "parser.tab.c"
    break;

  case 82: /* arithmetic_expr: expr SLASH expr  */
#line 512 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_div);
      }
#line 2226 "parser.tab.c"
    break;

  case 83: /* arithmetic_expr: expr PERCENT expr  */
#line 516 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mod);
      }
#line 2234 "parser.tab.c"
    break;

  case 84: /* comparison_expr: expr LT expr  */
#line 522 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_le);
      }
#line 2242 "parser.tab.c"
    break;

  case 85: /* comparison_expr: expr LE expr  */
#line 526 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_lt);
      }
#line 2250 "parser.tab.c"
    break;

  case 86: /* comparison_expr: expr GT expr  */
#line 530 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_gt);
      }
#line 2258 "parser.tab.c"
    break;

  case 87: /* comparison_expr: expr GE expr  */
#line 534 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ge);
      }
#line 2266 "parser.tab.c"
    break;

  case 88: /* comparison_expr: expr EQ expr  */
#line 538 "parser.y"
      {
          (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_eq);
      }
#line 2274 "parser.tab.c"
    break;

  case 89: /* comparison_expr: expr NE expr  */
#line 542 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ne);
      }
#line 2282 "parser.tab.c"
    break;

  case 90: /* logical_expr: expr OR expr  */
#line 548 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_or);
      }
#line 2290 "parser.tab.c"
    break;

  case 91: /* logical_expr: expr AND expr  */
#line 552 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_and);
      }
#line 2298 "parser.tab.c"
    break;

  case 92: /* array_expr: SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 558 "parser.y"
      {
        (yyval.node) = ASTarrexpr((yyvsp[-1].node));
      }
#line 2306 "parser.tab.c"
    break;

  case 93: /* cast: ROUNDBRACKET_L datatype ROUNDBRACKET_R expr  */
#line 564 "parser.y"
    {
      (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].cdatatype));
    }
#line 2314 "parser.tab.c"
    break;

  case 94: /* constant: FLOAT  */
#line 577 "parser.y"
          {
            (yyval.node) = ASTfloat((yyvsp[0].cflt));
          }
#line 2322 "parser.tab.c"
    break;

  case 95: /* constant: NUM  */
#line 581 "parser.y"
          {
            (yyval.node) = ASTnum((yyvsp[0].cint));
          }
#line 2330 "parser.tab.c"
    break;

  case 96: /* constant: TRUEVAL  */
#line 585 "parser.y"
          {
            (yyval.node) = ASTbool(true);
          }
#line 2338 "parser.tab.c"
    break;

  case 97: /* constant: FALSEVAL  */
#line 589 "parser.y"
          {
            (yyval.node) = ASTbool(false);
          }
#line 2346 "parser.tab.c"
    break;

  case 98: /* datatype: VOIDTYPE  */
#line 598 "parser.y"
                  {   (yyval.cdatatype) = CT_void; }
#line 2352 "parser.tab.c"
    break;

  case 99: /* datatype: INTTYPE  */
#line 599 "parser.y"
                  {   (yyval.cdatatype) = CT_int;  }
#line 2358 "parser.tab.c"
    break;

  case 100: /* datatype: FLOATTYPE  */
#line 600 "parser.y"
                  {   (yyval.cdatatype) = CT_float; }
#line 2364 "parser.tab.c"
    break;

  case 101: /* datatype: BOOLTYPE  */
#line 601 "parser.y"
                  {   (yyval.cdatatype) = CT_bool;  }
#line 2370 "parser.tab.c"
    break;


#line 2374 "parser.tab.c"

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

#line 604 "parser.y"


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

