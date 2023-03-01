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

%type <node> intval floatval boolval constant ids
%type <node>  vardecl vardecls vardecls_opt stmt stmts stmts_opt localfundef localfundefs localfundefs_opt
%type <node> assign varlet program block
%type <node> fundef fundefs fundefs_opt funbody funcall funheader  
%type <node> decl decls globdef globdecl exprs_dims id_dims expr_dim id_dim arg args args_opt param params params_opt
%type <node> expr array_expr logical_expr arithmetic_expr unary_expr comparison_expr cast
%type <cmonop> monop
%type <cbinop> binop
%type <cdatatype> datatype


%right LET

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT

%right NEG CAST

%right UMINUS


%nonassoc ROUNDBRACKET_L CURLYBRACKET_L SQUAREBRACKET_L
%nonassoc ROUNDBRACKET_R CURLYBRACKET_R SQUAREBRACKET_R

%precedence THEN
%precedence ELSE

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
  FUNCTIONS & VARIABEL DECLARATIONS                        
*************************************/

fundefs: fundefs fundef
      {
        $$ = ASTfundefs($1, $2);
      }
      | fundef
      {
        $$ = ASTfundefs($1, NULL);
      }

fundef: EXTERN funheader SEMICOLON // example: 
        { 
          $$ = $2;
        }
        | funheader funbody // example:  
        { 
          FUNDEF_BODY($1) = $2;
          $$ = $1;
        }
        | EXPORT funheader funbody // example:  
        { 
          FUNDEF_EXPORT($2) = true;
          FUNDEF_BODY($2) = $3;
          $$ = $2;
        }

localfundefs: localfundef localfundefs
      {
        $$ = ASTfundefs($1, $2);
      }
      | localfundef
      {
        $$ = ASTfundefs($1, NULL);
      }

localfundef: funheader funbody // example:  int foo();
        { 
          FUNDEF_BODY($1) = $2;
          $$ = $1;
        };


vardecls: vardecls vardecl  // example: int a = 5; int b = 4; int c;
      {
        node_st *current = $1;

        while(VARDECL_NEXT(current) != NULL) {
          current = VARDECL_NEXT(current);
        }

      // reverse a linked list 
      VARDECL_NEXT(current) = $2;

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

funheader: datatype[type] ID ROUNDBRACKET_L params_opt ROUNDBRACKET_R 
        {
          $$ = ASTfundef(NULL, $4, $type, $2, false); 
        };      

funbody: CURLYBRACKET_L vardecls CURLYBRACKET_R
        {
          $$ = ASTfunbody($2, NULL, NULL); 
        }
        | CURLYBRACKET_L localfundefs CURLYBRACKET_R
        {
          $$ = ASTfunbody(NULL, $2, NULL); 
        }
        | CURLYBRACKET_L stmts CURLYBRACKET_R
        {
          $$ = ASTfunbody(NULL, NULL, $2); 
        }
        | CURLYBRACKET_L vardecls stmts CURLYBRACKET_R
        {
          $$ = ASTfunbody($2, NULL, $3); 
        }    
        | CURLYBRACKET_L localfundefs stmts CURLYBRACKET_R
        {
          $$ = ASTfunbody(NULL, $2, $3); 
        }
        | CURLYBRACKET_L vardecls localfundefs CURLYBRACKET_R
        {
          $$ = ASTfunbody($2, $3, NULL); 
        }
         | CURLYBRACKET_L vardecls localfundefs stmts CURLYBRACKET_R
        {
          $$ = ASTfunbody($2, $3, $4); 
        }
        | CURLYBRACKET_L CURLYBRACKET_R
        {
          $$ = ASTfunbody(NULL, NULL, NULL); 
        };                   

funcall: ID ROUNDBRACKET_L args_opt ROUNDBRACKET_R  // example: foo(5, 3);
        {
          $$ = ASTfuncall($3, $1);
        };


/*************************************
  ARGUMENTS, PARAMETERS AND DIMENSIONS                  
*************************************/


args_opt: args // Optional arguments
      {
        $$ = $1;
      }
      | /* empty */
      {
        $$ = NULL;
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


params_opt: params // Optional parameters
      {
        $$ = $1;
      }
      | /* empty */
      {
        $$ = NULL;
      };


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


exprs_dims: expr_dim COMMA exprs_dims // example: 1, 2, 3, 4 - used for arrays
      {
        EXPRS_NEXT($1) = $3;
        $$ = $1;
      }
      | expr_dim
      {
        $$ = $1;
      };

expr_dim: expr
      {
        $$ = ASTexprs($1, NULL);
      };      

id_dims: id_dim COMMA id_dims // example: a, b, c, d - used for arrays
      {
        IDS_NEXT($1) = $3;
        $$ = $1;
      }
      | id_dim
      {
        $$ = $1;
      };

id_dim: ID 
      {
        $$ = ASTids(NULL, $1);
      };           

/*************************************
  STATEMENTS                        
*************************************/

stmts_opt: stmts // Optional statement
              {
                $$ = $1;
              }
              | /* empty */ 
              {
                $$ = NULL;
              }; 


stmts: stmt stmts // One or many statements
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
      }
      | funcall SEMICOLON 
      {
        $$ = ASTexprstmt($1);
      }
      | FOR ROUNDBRACKET_L datatype[type] ID LET expr COMMA expr ROUNDBRACKET_R block // example:  // example:  for(int a = 0, 10) {...}
      {
        $$ = ASTfor($6, $8, NULL, $10, $4);
      }
      | FOR ROUNDBRACKET_L datatype[type] ID LET expr COMMA expr COMMA expr ROUNDBRACKET_R block // example:  for(int a = 0, 10, 1) {...}
      {
        $$ = ASTfor($6, $8, $10, $12, $4 );
      }
      | DO block WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R SEMICOLON // example: do {...} while(true)
      {
        $$ = ASTdowhile($5, $2);
      }
      | WHILE ROUNDBRACKET_L expr ROUNDBRACKET_R block  // example: while(true) {...}
      {
        $$ = ASTwhile($3, $5);
      }
      | IF ROUNDBRACKET_L expr ROUNDBRACKET_R block %prec THEN // example: if(true) {...}
      {
        $$ = ASTifelse($3, $5, NULL);
      }
      | IF ROUNDBRACKET_L expr ROUNDBRACKET_R block ELSE block // example: if(true) {...} else {...}
      {
        $$ = ASTifelse($3, $5, $7);
      }
      | RETURN SEMICOLON // example: return;
      {
        $$ = ASTreturn(NULL);
      }
      | RETURN expr SEMICOLON // example: return 1;
      {
        $$ = ASTreturn($2);
      };   


assign: varlet LET expr SEMICOLON
        {
          $$ = ASTassign($1, $3);
        };


block:  CURLYBRACKET_L stmts_opt CURLYBRACKET_R
      {
        $$ = $2;
      }
      | stmt
      {
        $$ = ASTstmts($1, NULL);
      };


varlet: ID
        {
          $$ = ASTvarlet(NULL, $1);
        }
        | ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R
        {
          $$ = ASTvarlet($3, $1);
        };


expr:  ROUNDBRACKET_L expr ROUNDBRACKET_R
      {
        $$ = $2;
      }
      | constant
      {
        $$ = $1;
      } 
      | ID SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R 
      {
        $$ = ASTvar($3, $1);
      }     
      | ID 
      {
        $$ = ASTvar(NULL, $1);
      }     
      | cast
      {
        $$ = $1;
      }   
      | funcall
      {
        $$ = $1;
      }     
      | array_expr
      {
        $$ = $1;
      }
      | arithmetic_expr
      {
        $$ = $1;
      }
      | comparison_expr
      {
        $$ = $1;
      }
      | logical_expr
      {
        $$ = $1;
      }
      | unary_expr
      {
        $$ = $1;
      };


unary_expr: MINUS expr %prec UMINUS
      {
        $$ = ASTmonop($2, MO_not);
      }
      | NEG expr
      {
        $$ = ASTmonop($2, MO_neg);
      };


arithmetic_expr: expr PLUS expr
      {
        $$ = ASTbinop( $1, $3, BO_add);
      }
      | expr MINUS expr 
      {
        $$ = ASTbinop( $1, $3, BO_sub);
      }
      | expr STAR expr
      {
        $$ = ASTbinop( $1, $3, BO_mul);
      }
      | expr SLASH expr
      {
        $$ = ASTbinop( $1, $3, BO_div);
      }
      | expr PERCENT expr
      {
        $$ = ASTbinop( $1, $3, BO_mod);
      };


comparison_expr: expr LT expr
      {
        $$ = ASTbinop( $1, $3, BO_le);
      }
      | expr LE expr
      {
        $$ = ASTbinop( $1, $3, BO_lt);
      }
      | expr GT expr
      {
        $$ = ASTbinop( $1, $3, BO_gt);
      }
      | expr GE expr
      {
        $$ = ASTbinop( $1, $3, BO_ge);
      }
      | expr EQ expr
      {
          $$ = ASTbinop( $1, $3, BO_eq);
      }
      | expr NE expr
      {
        $$ = ASTbinop( $1, $3, BO_ne);
      };            


logical_expr: expr OR expr
      {
        $$ = ASTbinop( $1, $3, BO_or);
      }
      | expr AND expr
      {
        $$ = ASTbinop( $1, $3, BO_and);
      };          


array_expr: SQUAREBRACKET_L exprs_dims SQUAREBRACKET_R 
      {
        $$ = ASTarrexpr($2);
      };


cast: ROUNDBRACKET_L datatype[type] ROUNDBRACKET_R expr %prec CAST
    {
      $$ = ASTcast($4, $type);
    }; 

/*************************************
  CONSTANTS                        
*************************************/

constant: FLOAT
          {
            $$ = ASTfloat($1);
          }
          | NUM
          {
            $$ = ASTnum($1);
          }
          | TRUEVAL
          {
            $$ = ASTbool(true);
          }
          | FALSEVAL
          {
            $$ = ASTbool(false);
          };

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

