%{


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


%}

%union {
 char               *id;
 int                 cint;
 float               cflt;
 enum MonOpEnum     cmonop;
 enum BinOpEnum     cbinop;
 enum Type          cdatatype;
 node_st             *node;
}

%locations

%token ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R SQUAREBRACKET_L SQUAREBRACKET_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND NEG
%token TRUEVAL FALSEVAL LET
%token IF ELSE 
%token WHILE DO FOR 
%token RETURN
%token EXPORT EXTERN
%token BOOLTYPE FLOATTYPE INTTYPE VOIDTYPE

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> intval floatval boolval constant exprs expr cast ids
%type <node> stmts stmt assign varlet program
%type <node> decl decls globdef globdecl fundef fundefs funbody funcall vardecl vardecls args arg exprs_dims id_dims dim param params
%type <cmonop> monop
%type <cbinop> binop
%type <cdatatype> datatype

%left PLUS MINUS
%left STAR SLASH PERCENT
%nonassoc LE LT GE GT
%nonassoc EQ NE
%left AND
%left OR

%nonassoc ROUNDBRACKET_L CURLYBRACKET_L SQUAREBRACKET_L
%nonassoc ROUNDBRACKET_R CURLYBRACKET_R SQUAREBRACKET_R

%nonassoc UMINUS
%nonassoc ELSE

%start program

%%

program: decls
         {
           parseresult = $1;
         }
         ;


/*************************************
  TOP LEVEL DECLARATIONS & DEFINITIONS                        
*************************************/        


decls: decl decls
        {
          $$ = ASTdecls($1, $2);
        }
      | decl
        {
          $$ = ASTdecls($1, NULL);
        }
  

decl: globdef 
       {
         $$ = $1;
       }
      |
      globdecl 
       {
         $$ = $1;
       }
      |
      fundef 
       {
         $$ = $1;
       }   
       ;


/*************************************
  GLOBAL DECLARATIONS & DEFINITIONS                        
*************************************/

globdecl: 
     EXTERN datatype[type] ID SEMICOLON // example: extern int id;
       {
         $$ =  ASTglobdecl(NULL, $type, $3);
       } 
    |
      EXTERN datatype[type] SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID SEMICOLON // example: extern int[a, b] id;
       {
         $$ =  ASTglobdecl($4, $type, $6);
       };
  
globdef: datatype[type] ID SEMICOLON // example: int id;
        {
          $$ =  ASTglobdef(NULL, NULL, $type, $2, false);
        }
        | datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON // example: int[1, 2] id;
        {
          $$ =  ASTglobdef($3, NULL, $type, $5, false);
        }      
        | datatype[type] ID LET expr SEMICOLON // example: int id = 123;
        {
          $$ =  ASTglobdef(NULL, $4, $type, $2, false);
        }  
        | datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON // example: int[1, 2] id = 123;
        {
          $$ =  ASTglobdef($3, $7, $type, $5, false);
        }       
        | EXPORT datatype[type] ID SEMICOLON // example: export int id;
        {
          $$ =  ASTglobdef(NULL, NULL, $type, $3, true);
        }
        | EXPORT datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON // example: export int[1, 2] id;
        {
          $$ =  ASTglobdef($4, NULL, $type, $6, true);
        }
        | EXPORT datatype[type] ID LET expr SEMICOLON // example: export int id = 123;
        {
          $$ =  ASTglobdef(NULL, $5, $type, $3, true);
        }
        | EXPORT datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON // example: export int[1, 2] id = 123;
        {
          $$ =  ASTglobdef($4, $8, $type, $6, true);
        };

/*************************************
  FUNCTIONS                        
*************************************/


funbody: vardecls 
      {
        $$ = ASTfunbody($1, NULL, NULL);
      }
      | stmts
      {
        $$ = ASTfunbody(NULL, NULL, $1);
      }
      | vardecls stmts 
      {
        $$ = ASTfunbody($1, NULL, $2);
      };


fundefs: fundef fundefs
      {
        FUNDEFS_NEXT($1) = $2;
        $$ = $1;
      }
      | fundef
      {
        $$ = $1;
      };

fundef: datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON // example:  int foo();
        { 
          $$ = ASTfundef(NULL, NULL, $type, $2, false);
        }
        | datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R // example: int foo() {};
        { 
          $$ = ASTfundef(NULL, NULL, $type, $2, false); 
        }
        | datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R // example: int foo() {...};
        { 
          $$ = ASTfundef($6, NULL, $type, $2, false); 
        }
        | datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  // example:  int foo(int a, int b);
        { 
          $$ = ASTfundef(NULL, $4, $type, $2, false);
        }
        | datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R // example: int foo(int a, int b) {};
        { 
          $$ = ASTfundef(NULL, $4, $type, $2, false); 
        }
        | datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R // example: int foo(int a, int b) {...};
        { 
          $$ = ASTfundef($7, $4, $type, $2, false); 
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON // example: export int foo();
        { 
          $$ = ASTfundef(NULL, NULL, $type, $3, true);
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R // example: export int foo() {};
        { 
          $$ = ASTfundef(NULL, NULL, $type, $3, true); 
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R // example: export int foo() {...};
        { 
          $$ = ASTfundef($7, NULL, $type, $3, true); 
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON  // example: export int foo(int a, int b);
        { 
          $$ = ASTfundef(NULL, $5, $type, $3, false);
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L CURLYBRACKET_R // example: export int foo(int a, int b) {};
        { 
          $$ = ASTfundef(NULL, $5, $type, $3, true); 
        }
        | EXPORT datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R CURLYBRACKET_L funbody CURLYBRACKET_R // example: export int foo(int a, int b) {...};
        { 
          $$ = ASTfundef($8, $5, $type, $3, true); 
        }
        | EXTERN datatype[type] ID ROUNDBRACKET_L ROUNDBRACKET_R SEMICOLON // example: extern int foo();
        {
          $$ = ASTfundef(NULL, NULL, $type, $3, false); 
        }
        | EXTERN datatype[type] ID ROUNDBRACKET_L params ROUNDBRACKET_R SEMICOLON // example: extern int foo(int a, int b);
        { 
          $$ = ASTfundef(NULL, $5, $type, $3, false); 
        };

funcall: ID ROUNDBRACKET_L args ROUNDBRACKET_R  // example: foo(5, 3);
        {
          $$ = ASTfuncall($3, $1);
        }
        | ID ROUNDBRACKET_L ROUNDBRACKET_R // example: foo();
        {
          $$ = ASTfuncall(NULL, $1);
        };


/*************************************
  VAR DECLARATIONS, ARGUMENTS, PARAMETERS AND DIMENSIONS                  
*************************************/


vardecls: vardecl vardecls // example: int a = 5; int b = 4; int c;
      {
        VARDECL_NEXT($1) = $2;
        $$ = $1;
      }
      | vardecl
      {
        $$ = $1;
      };


vardecl: datatype[type] ID SEMICOLON  // example: int a;
        {
          $$ = ASTvardecl(NULL, NULL, NULL, $2, $type);
        }
        | datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID SEMICOLON  // example: int a;
        {
          $$ = ASTvardecl($3, NULL, NULL, $5, $type);
        }
        | datatype[type] ID LET expr SEMICOLON  // example: int a = 5;
        {
          $$ = ASTvardecl(NULL, $4, NULL, $2, $type);
        }
        | datatype[type] SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R ID LET expr SEMICOLON  // example: int a = 5;
        {
          $$ = ASTvardecl($3, $7, NULL, $5, $type);
        };


args: arg COMMA args // example: a,b,c,d
      {
        EXPRS_NEXT($1) = $3;
        $$ = $1;
      }
      | arg
      {
        $$ = $1;
      };

arg: expr // example: a
        {
          $$ = ASTexprs($1, NULL);
        } ;          


params: param COMMA params // example: int a, int[a,b] b, float[a] b
      {
        PARAM_NEXT($1) = $3;
        $$ = $1;
      }
      | param
      {
        $$ = $1;
      };

param: datatype[type] ID  // example: int a
      {
        $$ = ASTparam(NULL, NULL, $2, $type);
      }
      | datatype[type] SQUAREBRACKET_L id_dims SQUAREBRACKET_R ID // example: int[a,b] a
      {
        $$ = ASTparam($3, NULL, $5, $type);
      };          


exprs_dims: dim COMMA exprs_dims // example: 1, 2, 3, 4 - used for arrays
      {
        EXPRS_NEXT($1) = $3;
        $$ = $1;
      }
      | dim
      {
        $$ = $1;
      };

id_dims: dim COMMA id_dims // example: a, b, c, d - used for arrays
      {
        IDS_NEXT($1) = $3;
        $$ = $1;
      }
      | dim
      {
        $$ = $1;
      };

dim:  ID 
      {
        $$ = ASTids(NULL, $1);
      }
      | expr
      {
        $$ = ASTexprs($1, NULL);
      };      

/*************************************
  STATEMENTS                        
*************************************/

stmts: stmt stmts
      {
        $$ = ASTstmts($1, $2);
      }
      | stmt
      {
        $$ = ASTstmts($1, NULL);
      };

stmt: assign
      {
        $$ = $1;
      };

assign: varlet LET expr SEMICOLON
        {
          $$ = ASTassign($1, $3);
        };

varlet: ID
        {
          $$ = ASTvarlet($1);
          AddLocToNode($$, &@1, &@1);
        };


cast: ROUNDBRACKET_L datatype[type] ROUNDBRACKET_R expr
      {
        $$ = ASTcast($4, $type);
        AddLocToNode($$, &@1, &@1);
      };



exprs: expr exprs
      {
        $$ = ASTexprs($1, $2);
      }
      | expr
      {
        $$ = ASTexprs($1, NULL);
      }
      ;

expr: ROUNDBRACKET_L expr ROUNDBRACKET_R
      {
        $$ = $2;
      }
      | expr[left] binop[type] expr[right] // CONFLICTS
      {
        $$ = ASTbinop( $left, $right, $type);
        AddLocToNode($$, &@left, &@right);
      }
      | monop[type] expr[right] // CONFLICTS
      {
        $$ = ASTmonop($right, $type);
        AddLocToNode($$, &@right, &@right);
      }
      | cast
      {
        $$ = $1;
      }   
      | funcall
      {
        $$ = $1;
        AddLocToNode($$, &@1, &@1);
      }     
      | ID
      {
        $$ = ASTvar($1);
      }     
      | constant
      {
        $$ = $1;
      };

/*************************************
  CONSTANTS                        
*************************************/


constant: floatval
          {
            $$ = $1;
          }
          | intval
          {
            $$ = $1;
          }
          | boolval
          {
            $$ = $1;
          };

floatval: FLOAT
          {
            $$ = ASTfloat($1);
          };

intval: NUM
        {
          $$ = ASTnum($1);
        };

boolval: TRUEVAL
        {
          $$ = ASTbool(true);
        }
        | FALSEVAL
        {
          $$ = ASTbool(false);
        };

/*************************************
  BINARY OPERATORS                        
*************************************/

binop: PLUS      { $$ = BO_add; }
     | MINUS     { $$ = BO_sub; }
     | STAR      { $$ = BO_mul; }
     | SLASH     { $$ = BO_div; }
     | PERCENT   { $$ = BO_mod; }
     | LE        { $$ = BO_le; }
     | LT        { $$ = BO_lt; }
     | GE        { $$ = BO_ge; }
     | GT        { $$ = BO_gt; }
     | EQ        { $$ = BO_eq; }
     | OR        { $$ = BO_or; }
     | AND       { $$ = BO_and; }
     | NE        { $$ = BO_ne; }
     ;

/*************************************
  MONO OPERATORS                        
*************************************/

monop: MINUS      { $$ = MO_not; }
     | NEG        { $$ = MO_neg; }
     ;


/*************************************
  TYPES                       
*************************************/

datatype:
        VOIDTYPE  {   $$ = CT_void; }
      | INTTYPE   {   $$ = CT_int;  }
      | FLOATTYPE {   $$ = CT_float; }
      | BOOLTYPE  {   $$ = CT_bool;  } 
      ;

%%

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
