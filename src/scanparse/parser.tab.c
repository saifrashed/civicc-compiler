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
    CAST = 298,                    /* CAST  */
    UMINUS = 299,                  /* UMINUS  */
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
  YYSYMBOL_CAST = 43,                      /* CAST  */
  YYSYMBOL_UMINUS = 44,                    /* UMINUS  */
  YYSYMBOL_THEN = 45,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_decls = 48,                     /* decls  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_globdecl = 50,                  /* globdecl  */
  YYSYMBOL_globdef = 51,                   /* globdef  */
  YYSYMBOL_fundef = 52,                    /* fundef  */
  YYSYMBOL_localfundefs = 53,              /* localfundefs  */
  YYSYMBOL_localfundef = 54,               /* localfundef  */
  YYSYMBOL_vardecls = 55,                  /* vardecls  */
  YYSYMBOL_vardecl = 56,                   /* vardecl  */
  YYSYMBOL_funheader = 57,                 /* funheader  */
  YYSYMBOL_funbody = 58,                   /* funbody  */
  YYSYMBOL_funcall = 59,                   /* funcall  */
  YYSYMBOL_args_opt = 60,                  /* args_opt  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_arg = 62,                       /* arg  */
  YYSYMBOL_params_opt = 63,                /* params_opt  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_exprs_dims = 66,                /* exprs_dims  */
  YYSYMBOL_expr_dim = 67,                  /* expr_dim  */
  YYSYMBOL_id_dims = 68,                   /* id_dims  */
  YYSYMBOL_id_dim = 69,                    /* id_dim  */
  YYSYMBOL_stmts_opt = 70,                 /* stmts_opt  */
  YYSYMBOL_stmts = 71,                     /* stmts  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_assign = 73,                    /* assign  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_varlet = 75,                    /* varlet  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_unary_expr = 77,                /* unary_expr  */
  YYSYMBOL_arithmetic_expr = 78,           /* arithmetic_expr  */
  YYSYMBOL_comparison_expr = 79,           /* comparison_expr  */
  YYSYMBOL_logical_expr = 80,              /* logical_expr  */
  YYSYMBOL_array_expr = 81,                /* array_expr  */
  YYSYMBOL_cast = 82,                      /* cast  */
  YYSYMBOL_constant = 83,                  /* constant  */
  YYSYMBOL_datatype = 84                   /* datatype  */
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
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

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
       0,    84,    84,    96,   100,   106,   111,   116,   128,   133,
     138,   142,   146,   150,   154,   158,   162,   166,   184,   188,
     193,   199,   203,   208,   215,   220,   225,   229,   233,   237,
     242,   247,   251,   255,   259,   263,   267,   271,   275,   280,
     291,   296,   301,   306,   311,   317,   322,   327,   332,   337,
     341,   347,   352,   357,   362,   367,   372,   381,   386,   391,
     395,   401,   405,   409,   413,   417,   421,   425,   429,   433,
     437,   443,   449,   453,   459,   463,   469,   473,   477,   481,
     485,   489,   493,   497,   501,   505,   509,   515,   519,   525,
     529,   533,   537,   541,   547,   551,   555,   559,   563,   567,
     573,   577,   583,   589,   598,   602,   606,   610,   620,   621,
     622,   623
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
  "VOIDTYPE", "NUM", "FLOAT", "ID", "CAST", "UMINUS", "THEN", "$accept",
  "program", "decls", "decl", "globdecl", "globdef", "fundef",
  "localfundefs", "localfundef", "vardecls", "vardecl", "funheader",
  "funbody", "funcall", "args_opt", "args", "arg", "params_opt", "params",
  "param", "exprs_dims", "expr_dim", "id_dims", "id_dim", "stmts_opt",
  "stmts", "stmt", "assign", "block", "varlet", "expr", "unary_expr",
  "arithmetic_expr", "comparison_expr", "logical_expr", "array_expr",
  "cast", "constant", "datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     251,   122,   122,  -153,  -153,  -153,  -153,    23,  -153,   251,
    -153,  -153,  -153,     7,    -2,     7,     1,    18,     4,  -153,
    -153,   186,  -153,   164,    56,  -153,   164,    84,  -153,    -1,
      15,  -153,    45,    46,   124,    53,    27,    88,   220,   122,
     203,  -153,     7,    62,    75,    92,  -153,    55,     8,   106,
     164,   164,   164,  -153,  -153,  -153,  -153,   107,  -153,    76,
      81,   500,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   122,
    -153,   164,    85,  -153,   164,  -153,   108,   112,  -153,   164,
     164,    92,  -153,   103,   122,  -153,   389,   164,   164,  -153,
     131,  -153,    73,  -153,   226,  -153,   133,  -153,  -153,  -153,
    -153,   164,   164,   109,   280,   114,   141,  -153,  -153,   164,
      99,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   149,  -153,   155,    35,   403,
     123,   417,   127,    -1,   300,   320,   162,  -153,   169,   132,
    -153,   175,  -153,   174,   500,   176,  -153,   182,  -153,   181,
    -153,   431,   188,  -153,   164,  -153,   164,  -153,   189,    12,
    -153,   163,   163,  -153,  -153,  -153,   294,   294,   294,   294,
     537,   537,   513,   526,  -153,   122,    -1,  -153,  -153,    51,
    -153,   184,  -153,   124,   124,  -153,   164,   171,  -153,   164,
    -153,  -153,  -153,   158,   445,  -153,  -153,  -153,   164,  -153,
     193,  -153,   164,  -153,   183,  -153,   340,   164,  -153,    65,
    -153,   459,   161,   473,   124,   200,   375,  -153,   164,  -153,
    -153,  -153,  -153,  -153,   164,   487,   260,  -153,   124,   164,
    -153,   360,   124,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   111,   110,   109,   108,     0,     2,     4,
       6,     5,     7,     0,     0,     0,     0,     0,     0,     1,
       3,     0,    19,     0,     0,    20,     0,     0,    18,     0,
       0,    38,     0,     0,     0,     0,     0,    74,     0,    22,
       0,    25,     0,     0,     0,    60,    61,     0,     0,     0,
       0,     0,     0,   106,   107,   105,   104,    79,    81,     0,
      52,    53,    86,    83,    84,    85,    82,    80,    77,    46,
      10,     0,     0,    14,     0,    56,     0,    55,     8,     0,
       0,    58,    73,     0,     0,    69,     0,    41,     0,    32,
       0,    21,     0,    31,     0,    24,     0,    23,    62,    33,
      59,     0,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
      70,     0,    40,    43,    44,     0,    35,     0,    36,     0,
      34,     0,     0,    26,     0,    76,     0,   102,     0,     0,
      51,    90,    89,    91,    92,    93,    95,    94,    97,    96,
      98,    99,   100,   101,    30,     0,     0,    49,    12,     0,
      16,     0,    54,     0,     0,    72,     0,     0,    39,     0,
      75,    37,    71,     0,     0,   103,    78,    11,     0,    47,
       0,    15,     0,     9,    67,    66,     0,     0,    42,     0,
      28,     0,     0,     0,     0,     0,     0,    27,     0,    13,
      50,    17,    68,    65,     0,     0,     0,    29,     0,     0,
      63,     0,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   206,  -153,  -153,  -153,  -153,   -30,  -153,  -153,
     180,   126,   -13,   -21,  -153,    32,  -153,  -153,    52,  -153,
     -23,  -153,  -129,  -153,  -153,   -24,   -33,  -153,  -152,  -153,
     -16,  -153,  -153,  -153,  -153,  -153,  -153,  -153,     5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    38,    39,    40,
      41,    42,    22,    58,   141,   142,   143,   125,   126,   127,
      59,    60,    76,    77,   136,    44,    45,    46,    83,    47,
      61,    62,    63,    64,    65,    66,    67,    68,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    82,    25,    72,   182,    23,    16,    18,    26,    91,
      94,    29,    21,    43,    90,   102,    96,    43,    69,    43,
      86,   100,   197,    19,    43,    78,    48,   106,    28,    97,
      49,   204,   205,   104,    50,   107,   108,    85,    51,   198,
      24,    75,   176,    27,    92,    48,    30,   200,    79,    80,
     103,    52,    53,    54,   105,   129,    84,   137,   131,    69,
      43,   201,   222,   134,   135,   145,    70,    55,    56,    57,
     149,   144,    98,    43,   128,   217,   230,   177,   202,   152,
     233,    99,   101,    71,   110,   151,   158,    69,   160,   139,
     111,    87,   218,   130,    73,    88,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    49,
      87,    74,    69,    50,   109,   147,   132,    51,   156,   153,
      32,   133,    33,    34,    35,    36,    13,    15,    17,    81,
      52,    53,    54,   138,    37,    13,   154,   146,   194,   150,
     195,   159,     3,     4,     5,     6,    55,    56,    57,   157,
      82,    82,    32,   174,    33,    34,    35,    36,     3,     4,
       5,     6,    43,    43,   175,   179,    37,    49,   185,   181,
     206,    50,   186,   144,   187,    51,   114,   115,   116,   188,
     128,    82,   211,   189,   190,    69,   213,   191,    52,    53,
      54,   216,    31,    43,   203,    82,   193,   196,   207,    82,
     209,   212,   225,   220,    55,    56,    57,    43,   226,    93,
     223,    43,   214,   231,    32,    20,    33,    34,    35,    36,
      95,   208,     3,     4,     5,     6,    89,   199,    37,     0,
       0,    32,   148,    33,    34,    35,    36,     0,     0,     3,
       4,     5,     6,     0,     0,    37,     0,     0,    32,     0,
      33,    34,    35,    36,    32,     0,    33,    34,    35,    36,
       0,     0,    37,     0,   228,     0,     0,     0,    37,   229,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   155,     1,     2,     3,     4,     5,
       6,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   183,   112,   113,   114,   115,   116,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   184,     0,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   215,     0,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   232,     0,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   224,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   140,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   178,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   180,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   192,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   210,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   219,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   221,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   227,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   124,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   112,   113,
     114,   115,   116,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      21,    34,    15,    26,   133,     7,     1,     2,     7,    39,
      40,     7,     5,    34,    38,     7,    40,    38,     3,    40,
      36,    45,    10,     0,    45,    10,    21,    50,    10,    42,
       3,   183,   184,    49,     7,    51,    52,    10,    11,    27,
      42,    42,     7,    42,    39,    40,    42,   176,     3,     3,
      42,    24,    25,    26,    49,    71,     3,    81,    74,     3,
      81,    10,   214,    79,    80,    88,    10,    40,    41,    42,
      94,    87,    10,    94,    69,    10,   228,    42,    27,   102,
     232,     6,    27,    27,     8,   101,   109,     3,   111,    84,
       9,     3,    27,     8,    10,     7,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     3,
       3,    27,     3,     7,     7,    42,     8,    11,     4,    10,
      28,     9,    30,    31,    32,    33,     0,     1,     2,     5,
      24,    25,    26,    30,    42,     9,    27,     6,   154,     6,
     156,    42,    36,    37,    38,    39,    40,    41,    42,     8,
     183,   184,    28,     4,    30,    31,    32,    33,    36,    37,
      38,    39,   183,   184,     9,    42,    42,     3,     6,    42,
     186,     7,     3,   189,    42,    11,    13,    14,    15,     4,
     175,   214,   198,     9,     8,     3,   202,     6,    24,    25,
      26,   207,     6,   214,    10,   228,     8,     8,    27,   232,
      42,     8,   218,    42,    40,    41,    42,   228,   224,     6,
      10,   232,    29,   229,    28,     9,    30,    31,    32,    33,
      40,   189,    36,    37,    38,    39,     6,   175,    42,    -1,
      -1,    28,     6,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    28,    -1,    30,    31,    32,    33,
      -1,    -1,    42,    -1,     4,    -1,    -1,    -1,    42,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    34,    35,    36,    37,    38,
      39,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    11,    12,    13,    14,    15,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     9,    -1,    11,    12,    13,    14,
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
      17,    18,    19,    20,    21,    22,    23,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    47,    48,    49,
      50,    51,    52,    57,    84,    57,    84,    57,    84,     0,
      48,     5,    58,     7,    42,    58,     7,    42,    10,     7,
      42,     6,    28,    30,    31,    32,    33,    42,    53,    54,
      55,    56,    57,    59,    71,    72,    73,    75,    84,     3,
       7,    11,    24,    25,    26,    40,    41,    42,    59,    66,
      67,    76,    77,    78,    79,    80,    81,    82,    83,     3,
      10,    27,    66,    10,    27,    42,    68,    69,    10,     3,
       3,     5,    72,    74,     3,    10,    76,     3,     7,     6,
      71,    53,    84,     6,    53,    56,    71,    58,    10,     6,
      71,    27,     7,    42,    76,    84,    66,    76,    76,     7,
       8,     9,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    63,    64,    65,    84,    76,
       8,    76,     8,     9,    76,    76,    70,    71,    30,    84,
      10,    60,    61,    62,    76,    66,     6,    42,     6,    71,
       6,    76,    66,    10,    27,     4,     4,     8,    66,    42,
      66,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,     4,     9,     7,    42,    10,    42,
      10,    42,    68,     4,     4,     6,     3,    42,     4,     9,
       8,     6,    10,     8,    76,    76,     8,    10,    27,    64,
      68,    10,    27,    10,    74,    74,    76,    27,    61,    42,
      10,    76,     8,    76,    29,     4,    76,    10,    27,    10,
      42,    10,    74,    10,     9,    76,    76,    10,     4,     9,
      74,    76,     4,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    82,    83,    83,    83,    83,    84,    84,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     7,
       3,     6,     5,     8,     4,     7,     6,     9,     3,     2,
       3,     2,     1,     2,     2,     1,     3,     6,     5,     8,
       5,     3,     3,     3,     4,     4,     4,     5,     2,     4,
       1,     0,     3,     1,     1,     1,     0,     3,     1,     2,
       5,     3,     1,     1,     3,     1,     1,     1,     0,     2,
       1,     1,     2,    10,    12,     7,     5,     5,     7,     2,
       3,     4,     3,     1,     1,     4,     3,     1,     4,     1,
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
#line 85 "parser.y"
         {
           parseresult = (yyvsp[0].node);
         }
#line 1612 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 97 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1620 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 101 "parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1628 "parser.tab.c"
    break;

  case 5: /* decl: globdef  */
#line 107 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1636 "parser.tab.c"
    break;

  case 6: /* decl: globdecl  */
#line 112 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1644 "parser.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 117 "parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1652 "parser.tab.c"
    break;

  case 8: /* globdecl: EXTERN datatype ID SEMICOLON  */
#line 129 "parser.y"
       {
         (yyval.node) =  ASTglobdecl(NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id));
       }
#line 1660 "parser.tab.c"
    break;

  case 9: /* globdecl: EXTERN datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 134 "parser.y"
       {
         (yyval.node) =  ASTglobdecl((yyvsp[-3].node), (yyvsp[-5].cdatatype), (yyvsp[-1].id));
       }
#line 1668 "parser.tab.c"
    break;

  case 10: /* globdef: datatype ID SEMICOLON  */
#line 139 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), false);
        }
#line 1676 "parser.tab.c"
    break;

  case 11: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 143 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), false);
        }
#line 1684 "parser.tab.c"
    break;

  case 12: /* globdef: datatype ID LET expr SEMICOLON  */
#line 147 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false);
        }
#line 1692 "parser.tab.c"
    break;

  case 13: /* globdef: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 151 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), false);
        }
#line 1700 "parser.tab.c"
    break;

  case 14: /* globdef: EXPORT datatype ID SEMICOLON  */
#line 155 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, NULL, (yyvsp[-2].cdatatype), (yyvsp[-1].id), true);
        }
#line 1708 "parser.tab.c"
    break;

  case 15: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 159 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-3].node), NULL, (yyvsp[-5].cdatatype), (yyvsp[-1].id), true);
        }
#line 1716 "parser.tab.c"
    break;

  case 16: /* globdef: EXPORT datatype ID LET expr SEMICOLON  */
#line 163 "parser.y"
        {
          (yyval.node) =  ASTglobdef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), true);
        }
#line 1724 "parser.tab.c"
    break;

  case 17: /* globdef: EXPORT datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 167 "parser.y"
        {
          (yyval.node) =  ASTglobdef((yyvsp[-5].node), (yyvsp[-1].node), (yyvsp[-7].cdatatype), (yyvsp[-3].id), true);
        }
#line 1732 "parser.tab.c"
    break;

  case 18: /* fundef: EXTERN funheader SEMICOLON  */
#line 185 "parser.y"
        { 
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1740 "parser.tab.c"
    break;

  case 19: /* fundef: funheader funbody  */
#line 189 "parser.y"
        { 
          FUNDEF_BODY((yyvsp[-1].node)) = (yyvsp[0].node);
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1749 "parser.tab.c"
    break;

  case 20: /* fundef: EXPORT funheader funbody  */
#line 194 "parser.y"
        { 
          FUNDEF_BODY((yyvsp[-1].node)) = (yyvsp[0].node);
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1758 "parser.tab.c"
    break;

  case 21: /* localfundefs: localfundef localfundefs  */
#line 200 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1766 "parser.tab.c"
    break;

  case 22: /* localfundefs: localfundef  */
#line 204 "parser.y"
      {
        (yyval.node) = ASTfundefs((yyvsp[0].node), NULL);
      }
#line 1774 "parser.tab.c"
    break;

  case 23: /* localfundef: funheader funbody  */
#line 209 "parser.y"
        { 
          FUNDEF_BODY((yyvsp[-1].node)) = (yyvsp[0].node);
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1783 "parser.tab.c"
    break;

  case 24: /* vardecls: vardecls vardecl  */
#line 216 "parser.y"
      {
        VARDECL_NEXT((yyvsp[0].node)) = (yyvsp[-1].node);
        (yyval.node) = (yyvsp[0].node);
      }
#line 1792 "parser.tab.c"
    break;

  case 25: /* vardecls: vardecl  */
#line 221 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1800 "parser.tab.c"
    break;

  case 26: /* vardecl: datatype ID SEMICOLON  */
#line 226 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].cdatatype));
        }
#line 1808 "parser.tab.c"
    break;

  case 27: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  */
#line 230 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].id), (yyvsp[-5].cdatatype));
        }
#line 1816 "parser.tab.c"
    break;

  case 28: /* vardecl: datatype ID LET expr SEMICOLON  */
#line 234 "parser.y"
        {
          (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].cdatatype));
        }
#line 1824 "parser.tab.c"
    break;

  case 29: /* vardecl: datatype SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  */
#line 238 "parser.y"
        {
          (yyval.node) = ASTvardecl((yyvsp[-5].node), (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-7].cdatatype));
        }
#line 1832 "parser.tab.c"
    break;

  case 30: /* funheader: datatype ID ROUNDBRACKET_L params_opt ROUNDBRACKET_R  */
#line 243 "parser.y"
        {
          (yyval.node) = ASTfundef(NULL, (yyvsp[-1].node), (yyvsp[-4].cdatatype), (yyvsp[-3].id), false); 
        }
#line 1840 "parser.tab.c"
    break;

  case 31: /* funbody: CURLYBRACKET_L vardecls CURLYBRACKET_R  */
#line 248 "parser.y"
        {
          (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, NULL); 
        }
#line 1848 "parser.tab.c"
    break;

  case 32: /* funbody: CURLYBRACKET_L localfundefs CURLYBRACKET_R  */
#line 252 "parser.y"
        {
          (yyval.node) = ASTfunbody(NULL, (yyvsp[-1].node), NULL); 
        }
#line 1856 "parser.tab.c"
    break;

  case 33: /* funbody: CURLYBRACKET_L stmts CURLYBRACKET_R  */
#line 256 "parser.y"
        {
          (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[-1].node)); 
        }
#line 1864 "parser.tab.c"
    break;

  case 34: /* funbody: CURLYBRACKET_L vardecls stmts CURLYBRACKET_R  */
#line 260 "parser.y"
        {
          (yyval.node) = ASTfunbody((yyvsp[-2].node), NULL, (yyvsp[-1].node)); 
        }
#line 1872 "parser.tab.c"
    break;

  case 35: /* funbody: CURLYBRACKET_L localfundefs stmts CURLYBRACKET_R  */
#line 264 "parser.y"
        {
          (yyval.node) = ASTfunbody(NULL, (yyvsp[-2].node), (yyvsp[-1].node)); 
        }
#line 1880 "parser.tab.c"
    break;

  case 36: /* funbody: CURLYBRACKET_L vardecls localfundefs CURLYBRACKET_R  */
#line 268 "parser.y"
        {
          (yyval.node) = ASTfunbody((yyvsp[-2].node), (yyvsp[-1].node), NULL); 
        }
#line 1888 "parser.tab.c"
    break;

  case 37: /* funbody: CURLYBRACKET_L vardecls localfundefs stmts CURLYBRACKET_R  */
#line 272 "parser.y"
        {
          (yyval.node) = ASTfunbody((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); 
        }
#line 1896 "parser.tab.c"
    break;

  case 38: /* funbody: CURLYBRACKET_L CURLYBRACKET_R  */
#line 276 "parser.y"
        {
          (yyval.node) = ASTfunbody(NULL, NULL, NULL); 
        }
#line 1904 "parser.tab.c"
    break;

  case 39: /* funcall: ID ROUNDBRACKET_L args_opt ROUNDBRACKET_R  */
#line 281 "parser.y"
        {
          (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 1912 "parser.tab.c"
    break;

  case 40: /* args_opt: args  */
#line 292 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1920 "parser.tab.c"
    break;

  case 41: /* args_opt: %empty  */
#line 296 "parser.y"
      {
        (yyval.node) = NULL;
      }
#line 1928 "parser.tab.c"
    break;

  case 42: /* args: arg COMMA args  */
#line 302 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1937 "parser.tab.c"
    break;

  case 43: /* args: arg  */
#line 307 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1945 "parser.tab.c"
    break;

  case 44: /* arg: expr  */
#line 312 "parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 1953 "parser.tab.c"
    break;

  case 45: /* params_opt: params  */
#line 318 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1961 "parser.tab.c"
    break;

  case 46: /* params_opt: %empty  */
#line 322 "parser.y"
      {
        (yyval.node) = NULL;
      }
#line 1969 "parser.tab.c"
    break;

  case 47: /* params: param COMMA params  */
#line 328 "parser.y"
      {
        PARAM_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 1978 "parser.tab.c"
    break;

  case 48: /* params: param  */
#line 333 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1986 "parser.tab.c"
    break;

  case 49: /* param: datatype ID  */
#line 338 "parser.y"
      {
        (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].cdatatype));
      }
#line 1994 "parser.tab.c"
    break;

  case 50: /* param: datatype SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID  */
#line 342 "parser.y"
      {
        (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].cdatatype));
      }
#line 2002 "parser.tab.c"
    break;

  case 51: /* exprs_dims: expr_dim COMMA exprs_dims  */
#line 348 "parser.y"
      {
        EXPRS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2011 "parser.tab.c"
    break;

  case 52: /* exprs_dims: expr_dim  */
#line 353 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2019 "parser.tab.c"
    break;

  case 53: /* expr_dim: expr  */
#line 358 "parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
      }
#line 2027 "parser.tab.c"
    break;

  case 54: /* id_dims: id_dim COMMA id_dims  */
#line 363 "parser.y"
      {
        IDS_NEXT((yyvsp[-2].node)) = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
      }
#line 2036 "parser.tab.c"
    break;

  case 55: /* id_dims: id_dim  */
#line 368 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2044 "parser.tab.c"
    break;

  case 56: /* id_dim: ID  */
#line 373 "parser.y"
      {
        (yyval.node) = ASTids(NULL, (yyvsp[0].id));
      }
#line 2052 "parser.tab.c"
    break;

  case 57: /* stmts_opt: stmts  */
#line 382 "parser.y"
              {
                (yyval.node) = (yyvsp[0].node);
              }
#line 2060 "parser.tab.c"
    break;

  case 58: /* stmts_opt: %empty  */
#line 386 "parser.y"
              {
                (yyval.node) = NULL;
              }
#line 2068 "parser.tab.c"
    break;

  case 59: /* stmts: stmt stmts  */
#line 392 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 2076 "parser.tab.c"
    break;

  case 60: /* stmts: stmt  */
#line 396 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2084 "parser.tab.c"
    break;

  case 61: /* stmt: assign  */
#line 402 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2092 "parser.tab.c"
    break;

  case 62: /* stmt: funcall SEMICOLON  */
#line 406 "parser.y"
      {
        (yyval.node) = ASTexprstmt((yyvsp[-1].node));
      }
#line 2100 "parser.tab.c"
    break;

  case 63: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr ROUNDBRACKET_R block  */
#line 410 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[0].node), (yyvsp[-6].id));
      }
#line 2108 "parser.tab.c"
    break;

  case 64: /* stmt: FOR ROUNDBRACKET_L datatype ID LET expr COMMA expr COMMA expr ROUNDBRACKET_R block  */
#line 414 "parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-8].id) );
      }
#line 2116 "parser.tab.c"
    break;

  case 65: /* stmt: DO block WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R SEMICOLON  */
#line 418 "parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-5].node));
      }
#line 2124 "parser.tab.c"
    break;

  case 66: /* stmt: WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 422 "parser.y"
      {
        (yyval.node) = ASTwhile((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2132 "parser.tab.c"
    break;

  case 67: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block  */
#line 426 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 2140 "parser.tab.c"
    break;

  case 68: /* stmt: IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block  */
#line 430 "parser.y"
      {
        (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2148 "parser.tab.c"
    break;

  case 69: /* stmt: RETURN SEMICOLON  */
#line 434 "parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2156 "parser.tab.c"
    break;

  case 70: /* stmt: RETURN expr SEMICOLON  */
#line 438 "parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2164 "parser.tab.c"
    break;

  case 71: /* assign: varlet LET expr SEMICOLON  */
#line 444 "parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2172 "parser.tab.c"
    break;

  case 72: /* block: CURLYBRACKET_L stmts_opt CURLYBRACKET_R  */
#line 450 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2180 "parser.tab.c"
    break;

  case 73: /* block: stmt  */
#line 454 "parser.y"
      {
        (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
      }
#line 2188 "parser.tab.c"
    break;

  case 74: /* varlet: ID  */
#line 460 "parser.y"
        {
          (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
        }
#line 2196 "parser.tab.c"
    break;

  case 75: /* varlet: ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 464 "parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[-1].node), (yyvsp[-3].id));
        }
#line 2204 "parser.tab.c"
    break;

  case 76: /* expr: ROUNDBRACKET_L expr ROUNDBRACKET_R  */
#line 470 "parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2212 "parser.tab.c"
    break;

  case 77: /* expr: constant  */
#line 474 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2220 "parser.tab.c"
    break;

  case 78: /* expr: ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 478 "parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[-1].node), (yyvsp[-3].id));
      }
#line 2228 "parser.tab.c"
    break;

  case 79: /* expr: ID  */
#line 482 "parser.y"
      {
        (yyval.node) = ASTvar(NULL, (yyvsp[0].id));
      }
#line 2236 "parser.tab.c"
    break;

  case 80: /* expr: cast  */
#line 486 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2244 "parser.tab.c"
    break;

  case 81: /* expr: funcall  */
#line 490 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2252 "parser.tab.c"
    break;

  case 82: /* expr: array_expr  */
#line 494 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2260 "parser.tab.c"
    break;

  case 83: /* expr: arithmetic_expr  */
#line 498 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2268 "parser.tab.c"
    break;

  case 84: /* expr: comparison_expr  */
#line 502 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2276 "parser.tab.c"
    break;

  case 85: /* expr: logical_expr  */
#line 506 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2284 "parser.tab.c"
    break;

  case 86: /* expr: unary_expr  */
#line 510 "parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2292 "parser.tab.c"
    break;

  case 87: /* unary_expr: MINUS expr  */
#line 516 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
      }
#line 2300 "parser.tab.c"
    break;

  case 88: /* unary_expr: NEG expr  */
#line 520 "parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
      }
#line 2308 "parser.tab.c"
    break;

  case 89: /* arithmetic_expr: expr PLUS expr  */
#line 526 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_add);
      }
#line 2316 "parser.tab.c"
    break;

  case 90: /* arithmetic_expr: expr MINUS expr  */
#line 530 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_sub);
      }
#line 2324 "parser.tab.c"
    break;

  case 91: /* arithmetic_expr: expr STAR expr  */
#line 534 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mul);
      }
#line 2332 "parser.tab.c"
    break;

  case 92: /* arithmetic_expr: expr SLASH expr  */
#line 538 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_div);
      }
#line 2340 "parser.tab.c"
    break;

  case 93: /* arithmetic_expr: expr PERCENT expr  */
#line 542 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_mod);
      }
#line 2348 "parser.tab.c"
    break;

  case 94: /* comparison_expr: expr LT expr  */
#line 548 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_le);
      }
#line 2356 "parser.tab.c"
    break;

  case 95: /* comparison_expr: expr LE expr  */
#line 552 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_lt);
      }
#line 2364 "parser.tab.c"
    break;

  case 96: /* comparison_expr: expr GT expr  */
#line 556 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_gt);
      }
#line 2372 "parser.tab.c"
    break;

  case 97: /* comparison_expr: expr GE expr  */
#line 560 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ge);
      }
#line 2380 "parser.tab.c"
    break;

  case 98: /* comparison_expr: expr EQ expr  */
#line 564 "parser.y"
      {
          (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_eq);
      }
#line 2388 "parser.tab.c"
    break;

  case 99: /* comparison_expr: expr NE expr  */
#line 568 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_ne);
      }
#line 2396 "parser.tab.c"
    break;

  case 100: /* logical_expr: expr OR expr  */
#line 574 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_or);
      }
#line 2404 "parser.tab.c"
    break;

  case 101: /* logical_expr: expr AND expr  */
#line 578 "parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), BO_and);
      }
#line 2412 "parser.tab.c"
    break;

  case 102: /* array_expr: SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R  */
#line 584 "parser.y"
      {
        (yyval.node) = ASTarrexpr((yyvsp[-1].node));
      }
#line 2420 "parser.tab.c"
    break;

  case 103: /* cast: ROUNDBRACKET_L datatype ROUNDBRACKET_R expr  */
#line 590 "parser.y"
    {
      (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].cdatatype));
    }
#line 2428 "parser.tab.c"
    break;

  case 104: /* constant: FLOAT  */
#line 599 "parser.y"
          {
            (yyval.node) = ASTfloat((yyvsp[0].cflt));
          }
#line 2436 "parser.tab.c"
    break;

  case 105: /* constant: NUM  */
#line 603 "parser.y"
          {
            (yyval.node) = ASTnum((yyvsp[0].cint));
          }
#line 2444 "parser.tab.c"
    break;

  case 106: /* constant: TRUEVAL  */
#line 607 "parser.y"
          {
            (yyval.node) = ASTbool(true);
          }
#line 2452 "parser.tab.c"
    break;

  case 107: /* constant: FALSEVAL  */
#line 611 "parser.y"
          {
            (yyval.node) = ASTbool(false);
          }
#line 2460 "parser.tab.c"
    break;

  case 108: /* datatype: VOIDTYPE  */
#line 620 "parser.y"
                  {   (yyval.cdatatype) = CT_void; }
#line 2466 "parser.tab.c"
    break;

  case 109: /* datatype: INTTYPE  */
#line 621 "parser.y"
                  {   (yyval.cdatatype) = CT_int;  }
#line 2472 "parser.tab.c"
    break;

  case 110: /* datatype: FLOATTYPE  */
#line 622 "parser.y"
                  {   (yyval.cdatatype) = CT_float; }
#line 2478 "parser.tab.c"
    break;

  case 111: /* datatype: BOOLTYPE  */
#line 623 "parser.y"
                  {   (yyval.cdatatype) = CT_bool;  }
#line 2484 "parser.tab.c"
    break;


#line 2488 "parser.tab.c"

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

#line 626 "parser.y"


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

