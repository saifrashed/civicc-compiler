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
%type <node> decl decls globdef globdecl fundef fundefs funcall
%type <cmonop> monop
%type <cbinop> binop
%type <cdatatype> datatype

%left COMMA
%right LET
%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT

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
  DECLARATIONS & DEFINITIONS                        
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
       ;



globdecl: 
     EXTERN datatype[type] ID SEMICOLON
       {
         $$ =  ASTglobdecl(NULL, $type, $3);
       } 
       ;
  

globdef: 
     datatype[type] ID SEMICOLON
       {
         $$ =  ASTglobdef(NULL, NULL, $1, $2, false);
       }
    |
     datatype[type] ID LET expr SEMICOLON
       {
         $$ =  ASTglobdef(NULL, $4, $1, $2, false);
       }   
    |
      EXPORT datatype[type] ID SEMICOLON
       {
         $$ =  ASTglobdef(NULL, NULL, $2, $3, true);
       }
    |
      EXPORT datatype[type] ID LET expr SEMICOLON
       {
         $$ =  ASTglobdef(NULL, $5, $2, $3, true);
       }
       ;
      
/*************************************
  FUNCTIONS                        
*************************************/


funcall: ID ROUNDBRACKET_L exprs ROUNDBRACKET_R
              {
                $$ = ASTfuncall($3, $1);
              }
             | ID ROUNDBRACKET_L ROUNDBRACKET_R
              {
                $$ = ASTfuncall(NULL, $1);
              }
             ;


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
        }
        ;

stmt: assign
       {
         $$ = $1;
       }
       ;

assign: varlet LET expr SEMICOLON
        {
          $$ = ASTassign($1, $3);
        }
        ;

varlet: ID
        {
          $$ = ASTvarlet($1);
          AddLocToNode($$, &@1, &@1);
        }
        ;

ids: ID ids
        {
          $$ = ASTids($1, $2);
        }
      | ID
        {
          $$ = ASTids($1, NULL);
        }
        ;

exprs: expr exprs
        {
          $$ = ASTexprs($1, $2);
        }
      | expr
        {
          $$ = ASTexprs($1, NULL);
        }
       |  expr COMMA exprs 
        {
          $$ = ASTexprs($1, $3);
        }
        ;

expr: ROUNDBRACKET_L expr ROUNDBRACKET_R
      {
        $$ = $2;
      }
    | expr[left] binop[type] expr[right]
      {
        $$ = ASTbinop( $left, $right, $type);
        AddLocToNode($$, &@left, &@right);
      }
    | monop[type] expr[right]
      {
        $$ = ASTmonop($right, $type);
        AddLocToNode($$, &@right, &@right);
      }
    | ROUNDBRACKET_L datatype[type] ROUNDBRACKET_R expr
      {
        $$ = ASTcast($4, $type);
        AddLocToNode($$, &@4, &@4);
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
      }
    ;


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
          }
        ;

floatval: FLOAT
           {
             $$ = ASTfloat($1);
           }
         ;

intval: NUM
        {
          $$ = ASTnum($1);
        }
      ;

boolval: TRUEVAL
         {
           $$ = ASTbool(true);
         }
       | FALSEVAL
         {
           $$ = ASTbool(false);
         }
       ;

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
