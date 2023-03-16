/**
 * @file
 *
 * This file contains the code for the Print traversal.
 * The traversal has the uid: PRT
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"

int indent = 0;

char *getTabs()
{
  // Allocate a string with enough space for n spaces and a null terminator
  char *spaces = (char *)malloc((indent + 1) * sizeof(char));

  // Fill the string with n spaces
  memset(spaces, '\t', indent);

  // Add a null terminator at the end of the string
  spaces[indent] = '\0';

  return spaces;
}

/**
 * @fn PRTprogram
 */
node_st *PRTprogram(node_st *node)
{

  TRAVdo(PROGRAM_SYMTBL(node)); // Taverse symbol table for programs

  TRAVnext(node);

  return node;
}

/**
 * @fn PRTstmts
 */
node_st *PRTstmts(node_st *node)
{
  TRAVstmt(node);
  TRAVnext(node);

  return node;
}

/**
 * @fn PRTassign
 */
node_st *PRTassign(node_st *node)
{

  printf("\n%s", getTabs());
  if (ASSIGN_LET(node) != NULL)
  {
    TRAVlet(node);
    printf(" = ");
  }

  TRAVexpr(node);
  printf("\n");

  return node;
}

/**
 * @fn PRTbinop
 */
node_st *PRTbinop(node_st *node)
{
  char *tmp = NULL;
  printf("(");

  // TRAVleft(node);

  TRAVleft(node);

  switch (BINOP_OP(node))
  {
  case BO_add:
    tmp = "+";
    break;
  case BO_sub:
    tmp = "-";
    break;
  case BO_mul:
    tmp = "*";
    break;
  case BO_div:
    tmp = "/";
    break;
  case BO_mod:
    tmp = "%";
    break;
  case BO_lt:
    tmp = "<";
    break;
  case BO_le:
    tmp = "<=";
    break;
  case BO_gt:
    tmp = ">";
    break;
  case BO_ge:
    tmp = ">=";
    break;
  case BO_eq:
    tmp = "==";
    break;
  case BO_ne:
    tmp = "!=";
    break;
  case BO_or:
    tmp = "||";
    break;
  case BO_and:
    tmp = "&&";
    break;
  case BO_NULL:
    DBUG_ASSERT(false, "unknown binop detected!");
  }

  printf(" %s ", tmp);

  TRAVright(node);

  printf(")");

  return node;
}

/**
 * @fn PRTvarlet
 */
node_st *PRTvarlet(node_st *node)
{
  printf("%s", VARLET_NAME(node), NODE_BLINE(node), NODE_BCOL(node));

  if (VAR_INDICES(node) != NULL)
  {
    printf("[");
    TRAVindices(node);
    printf("]");
  }

  return node;
}

/**
 * @fn PRTvar
 */
node_st *PRTvar(node_st *node)
{
  printf("%s", VAR_NAME(node));

  if (VAR_INDICES(node) != NULL)
  {
    printf("[");
    TRAVindices(node);
    printf("]");
  }
  return node;
}

/**
 * @fn PRTnum
 */
node_st *PRTnum(node_st *node)
{
  printf("%d", NUM_VAL(node));
  return node;
}

/**
 * @fn PRTfloat
 */
node_st *PRTfloat(node_st *node)
{
  printf("%f", FLOAT_VAL(node));
  return node;
}

/**
 * @fn PRTbool
 */
node_st *PRTbool(node_st *node)
{
  char *bool_str = BOOL_VAL(node) ? "true" : "false";
  printf("%s", bool_str);
  return node;
}

/**
 * @fn PRTdecls
 */
node_st *PRTdecls(node_st *node)
{
  TRAVdecl(node);
  printf("\n");

  TRAVnext(node);

  return node;
}

/**
 * @fn PRTexprs
 */
node_st *PRTexprs(node_st *node)
{

  TRAVexpr(node);

  if (EXPRS_NEXT(node) != NULL)
  {
    printf(",");
  }

  TRAVnext(node);

  return node;
}

/**
 * @fn PRTarrexpr
 */
node_st *PRTarrexpr(node_st *node)
{

  printf("[");

  TRAVchildren(node);

  printf("]");

  return node;
}

/**
 * @fn PRTids
 */
node_st *PRTids(node_st *node)
{

  if (IDS_NEXT(node) != NULL)
  {
    printf("%s, ", IDS_NAME(node));
  }
  else
  {
    printf("%s", IDS_NAME(node));
  }

  TRAVnext(node);
  return node;
}

/**
 * @fn PRTexprstmt
 */
node_st *PRTexprstmt(node_st *node)
{

  TRAVchildren(node);

  return node;
}

/**
 * @fn PRTreturn
 */
node_st *PRTreturn(node_st *node)
{

  printf("\n%sreturn", getTabs());

  if (RETURN_EXPR(node) != NULL)
  {
    printf(" ");
    TRAVexpr(node);
  }

  printf(";\n");

  return node;
}

/**
 * @fn PRTfuncall
 */
node_st *PRTfuncall(node_st *node)
{

  printf("\n%s%s(", getTabs(), FUNCALL_NAME(node));

  TRAVchildren(node);

  printf(");");

  return node;
}

/**
 * @fn PRTcast
 */
node_st *PRTcast(node_st *node)
{

  char *tmp = NULL;

  switch (CAST_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown cast detected!");
  }

  printf("(%s) ", tmp);

  TRAVchildren(node);

  return node;
}

/**
 * @fn PRTfundefs
 */
node_st *PRTfundefs(node_st *node)
{
  TRAVfundef(node);
  TRAVnext(node);
  return node;
}

/**
 * @fn PRTfundef
 */
node_st *PRTfundef(node_st *node)
{
  if (FUNDEF_BODY(node) != NULL)
  {
    printf("\n");
  }

  char *tmp = NULL;

  switch (FUNDEF_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  if (FUNDEF_BODY(node) == NULL)
  {
    printf("\nextern ");
  }
  else
  {
    printf("\n");
  }

  if (FUNDEF_EXPORT(node) == true)
  {
    printf("export ");
  }

  printf("%s%s %s", getTabs(), tmp, FUNDEF_NAME(node));

  printf("(");

  if (FUNDEF_PARAMS(node) != NULL)
  {
    TRAVparams(node);
  }

  printf(")");

  if (FUNDEF_BODY(node) != NULL)
  {
    TRAVbody(node);
  }
  else
  {
    printf(";");
  }

  if (FUNDEF_SYMTBL(node) != NULL)
    TRAVdo(FUNDEF_SYMTBL(node)); // Taverse symbol table for fundefs

  return node;
}

/**
 * @fn PRTfunbody
 */
node_st *PRTfunbody(node_st *node)
{

  printf("\n%s{", getTabs());

  indent++;

  TRAVdecls(node);
  TRAVlocal_fundefs(node);
  TRAVstmts(node);

  indent--;

  printf("\n%s}", getTabs());

  return node;
}

/**
 * @fn PRTifelse
 */
node_st *PRTifelse(node_st *node)
{

  printf("\n%sif(", getTabs());
  TRAVcond(node);

  printf(") { ");
  indent++;
  TRAVthen(node);
  indent--;
  printf("\n%s}", getTabs());

  if (IFELSE_ELSE_BLOCK(node) != NULL)
  {
    printf(" else { ");
    indent++;
    TRAVelse_block(node);
    indent--;
    printf("\n%s}", getTabs());
  }
  return node;
}

/**
 * @fn PRTternary
 */
node_st *PRTternary(node_st *node)
{

  return node;
}

/**
 * @fn PRTwhile
 */
node_st *PRTwhile(node_st *node)
{

  printf("\n%swhile(", getTabs());
  TRAVcond(node);

  printf(") { ");
  indent++;
  TRAVblock(node);
  indent--;
  printf("\n%s}", getTabs());

  return node;
}

/**
 * @fn PRTdowhile
 */
node_st *PRTdowhile(node_st *node)
{

  printf("\n%sdo { ", getTabs());
  indent++;
  TRAVblock(node);
  indent--;
  printf("\n%s} while (", getTabs());
  TRAVcond(node);
  printf("\n)");

  return node;
}

/**
 * @fn PRTfor
 */
node_st *PRTfor(node_st *node)
{

  printf("\n%sfor(", getTabs());

  TRAVstop(node);

  if (FOR_STEP(node) != NULL)
  {
    printf(", ");
    TRAVstep(node);
  }

  printf(") { ");

  indent++;

  TRAVblock(node);

  indent--;

  printf("\n%s}", getTabs());

  return node;
}

/**
 * @fn PRTglobdecl
 */
node_st *PRTglobdecl(node_st *node)
{

  char *tmp = NULL;

  switch (GLOBDECL_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  printf("extern %s", tmp);

  if (GLOBDECL_DIMS(node) != NULL)
  {
    printf("[");
    TRAVdims(node);
    printf("]");
  }

  printf(" %s", GLOBDECL_NAME(node));

  printf("\n");
  return node;
}

/**
 * @fn PRTglobdef
 */
node_st *PRTglobdef(node_st *node)
{
  char *tmp = NULL;

  switch (GLOBDEF_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  if (GLOBDEF_EXPORT(node) == true)
  {
    printf("export ");
  }

  printf("%s", tmp);

  if (GLOBDEF_DIMS(node) != NULL)
  {
    printf("[");
    TRAVdims(node);
    printf("]");
  }

  printf(" %s", GLOBDEF_NAME(node));

  if (GLOBDEF_INIT(node) != NULL)
  {
    printf(" = ");
    TRAVinit(node);
  }

  printf(";\n");

  return node;
}

/**
 * @fn PRTparam
 */
node_st *PRTparam(node_st *node)
{

  char *tmp = NULL;

  switch (PARAM_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  printf("%s", tmp);

  if (PARAM_DIMS(node) != NULL)
  {
    printf("[");
    TRAVdims(node);
    printf("]");
  }

  printf(" %s", PARAM_NAME(node));

  if (PARAM_NEXT(node) != NULL)
  {
    printf(",");
  }

  TRAVnext(node);

  return node;
}

/**
 * @fn PRTvardecl
 */
node_st *PRTvardecl(node_st *node)
{

  char *tmp = NULL;

  switch (VARDECL_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  printf("\n%s%s", getTabs(), tmp);

  if (VARDECL_DIMS(node) != NULL)
  {
    printf("[");
    TRAVdims(node);
    printf("]");
  }

  printf(" %s", VARDECL_NAME(node));

  if (VARDECL_INIT(node) != NULL)
  {
    printf(" = ");
    TRAVinit(node);
  }

  printf(";");

  TRAVnext(node);

  return node;
}

/**
 * @fn PRTmonop
 */
node_st *PRTmonop(node_st *node)
{
  char *tmp = NULL;

  switch (MONOP_OP(node))
  {
  case MO_not:
    tmp = "-";
    break;
  case MO_neg:
    tmp = "!";
    break;
  case MO_NULL:
    DBUG_ASSERT(false, "unknown unary detected!");
  }

  printf("%s", tmp);

  TRAVoperand(node);

  return node;
}

/**
 * @fn PRTsymtbl
 */
node_st *PRTsymtbl(node_st *node)
{

  if (SYMTBL_OUTER(node) == NULL)
  {
    printf("\n%s****************************** GLOBAL SYMBOL TABLE ******************************", getTabs());
  }
  else
  {
    printf("\n%s****************************** START SYMBOL TABLE ******************************", getTabs());
  }

  if (SYMTBL_HEAD(node) != NULL)
  {
    TRAVdo(SYMTBL_HEAD(node)); // Taverse symbol table for programs
  }

  printf("\n%s****************************** END SYMBOL TABLE ******************************** \n\n", getTabs());

  return node;
}

/**
 * @fn PRTste
 */
node_st *PRTste(node_st *node)
{

  char *tmp = NULL;

  switch (STE_TYPE(node))
  {
  case CT_bool:
    tmp = "bool";
    break;
  case CT_float:
    tmp = "float";
    break;
  case CT_int:
    tmp = "int";
    break;
  case CT_void:
    tmp = "void";
    break;
  case CT_NULL:
    DBUG_ASSERT(false, "unknown type detected!");
  }

  printf("\n%s%s (%s)", getTabs(), STE_NAME(node), tmp);

  if (NODE_TYPE(STE_DECL(node)) == NT_FUNDEF)
  {
    printf(" (");

    node_st *tmp = FUNDEF_PARAMS(STE_DECL(node));

    while (tmp != NULL && PARAM_NEXT(tmp) != NULL)
    {
      switch (PARAM_TYPE(tmp))
      {
      case CT_bool:
        printf("bool ");
        break;
      case CT_float:
        printf("float ");
        break;
      case CT_int:
        printf("int ");
        break;
      case CT_void:
        printf("void ");
        break;
      case CT_NULL:
        DBUG_ASSERT(false, "unknown unary detected!");
      }

      tmp = PARAM_NEXT(tmp);
    }

    printf(")");
  }

  TRAVnext(node);

  return node;
}
