
/**
 * @file
 *
 * This file contains the code for the ParameterPassing traversal.
 * The traversal has the uid: PP
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void PPinit() { return; }
void PPfini() { return; }

node_st *PPlookup(node_st *symtbl, char *identifier)
{
    // Check if the symbol table and identifier are not null
    if (symtbl == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Traverse the symbol table hierarchy
    node_st *temp = symtbl;
    while (temp != NULL)
    {
        // Check if the identifier exists in the current symbol table
        node_st *entry = SYMTBL_HEAD(temp);
        while (entry != NULL)
        {
            if (STReq(STE_NAME(entry), identifier) == true)
            {
                return entry;
            }
            entry = STE_NEXT(entry);
        }

        // Move to the outer symbol table
        node_st *outer = SYMTBL_OUTER(temp);
        if (outer != NULL)
        {
            temp = outer;
            continue;
        }

        // No more outer symbol tables, exit the loop
        break;
    }

    // If the identifier is not found, return null
    return NULL;
}

node_st *PPadd_before_param(node_st *fundef, char *search, char *identifier)
{

    node_st *temp = FUNDEF_PARAMS(fundef);

    node_st *previous = NULL;
    node_st *current = NULL;
    node_st *new = ASTparam(NULL, NULL, identifier, CT_int);

    if (temp == NULL)
    {
        return NULL; // Empty parameter list, nothing to do
    }

    while (temp != NULL)
    {

        if (STReq(PARAM_NAME(temp), search))
        {
            // Found the desired parameter
            current = temp;
            break; // Exit the loop
        }

        previous = temp; // Update the previous node
        temp = PARAM_NEXT(temp);
    }

    if (previous == NULL)
    {
        // The first parameter is the one we're searching for
        // We need to add the new parameter as the first one
        PARAM_NEXT(new) = current;
        FUNDEF_PARAMS(fundef) = new;

        return FUNDEF_PARAMS(fundef);
    }
    else
    {
        // Add the new parameter between the previous and current nodes
        PARAM_NEXT(new) = current;
        PARAM_NEXT(previous) = new;

        return PARAM_NEXT(previous);
    }
}

node_st *PPadd_id_before_arg(node_st *funcall, char *search, char *identifier)
{
    node_st *temp = FUNCALL_ARGS(funcall);

    node_st *previous = NULL;
    node_st *current = NULL;
    node_st *new = ASTexprs(ASTvar(NULL, identifier), NULL);

    if (temp == NULL)
    {
        return NULL; // Empty argument list, nothing to do
    }

    while (temp != NULL)
    {
        if (NODE_TYPE(EXPRS_EXPR(temp)) == NT_VAR && STReq(VAR_NAME(EXPRS_EXPR(temp)), search))
        {
            // Found the desired parameter
            current = temp;
            break; // Exit the loop
        }

        previous = temp; // Update the previous node
        temp = EXPRS_NEXT(temp);
    }

    if (previous == NULL)
    {
        // The first parameter is the one we're searching for
        // We need to add the new parameter as the first one
        EXPRS_NEXT(new) = current;
        FUNCALL_ARGS(funcall) = CCNcopy(new);

        return FUNCALL_ARGS(funcall);
    }
    else
    {
        // Add the new parameter between the previous and current nodes
        EXPRS_NEXT(new) = current;
        EXPRS_NEXT(previous) = CCNcopy(new);

        return EXPRS_NEXT(previous);
    }
}

node_st *PPadd_expr_before_arg(node_st *funcall, char *search, node_st *expression)
{
    node_st *temp = FUNCALL_ARGS(funcall);

    node_st *previous = NULL;
    node_st *current = NULL;
    node_st *new = ASTexprs(CCNcopy(expression), NULL);

    if (temp == NULL)
    {
        return NULL; // Empty argument list, nothing to do
    }

    while (temp != NULL)
    {
        if (NODE_TYPE(EXPRS_EXPR(temp)) == NT_VAR && STReq(VAR_NAME(EXPRS_EXPR(temp)), search))
        {
            // Found the desired parameter
            current = temp;
            break; // Exit the loop
        }

        previous = temp; // Update the previous node
        temp = EXPRS_NEXT(temp);
    }

    if (previous == NULL)
    {
        // The first parameter is the one we're searching for
        // We need to add the new parameter as the first one
        EXPRS_NEXT(new) = current;
        FUNCALL_ARGS(funcall) = CCNcopy(new);

        return FUNCALL_ARGS(funcall);
    }
    else
    {
        // Add the new parameter between the previous and current nodes
        EXPRS_NEXT(new) = current;
        EXPRS_NEXT(previous) = CCNcopy(new);

        return EXPRS_NEXT(previous);
    }
}

/**
 * @fn PPprogram
 */
node_st *PPprogram(node_st *node)
{
    struct data_pp *data = DATA_PP_GET();

    data->current_scope = node;

    TRAVchildren(node);

    return node;
}

/**
 * @fn PPfundef
 */
node_st *PPfundef(node_st *node)
{

    struct data_pp *data = DATA_PP_GET();
    node_st *outer = data->current_scope;

    if (FUNDEF_BODY(node) == NULL)
    {
        return node;
    }

    node_st *temp_param = FUNDEF_PARAMS(node);

    while (temp_param != NULL)
    {

        if (PARAM_DIMS(temp_param) != NULL)
        { // This parameter has dimensions
            node_st *temp_dim = PARAM_DIMS(temp_param);

            while (temp_dim != NULL)
            {
                node_st *ste = PPlookup(FUNDEF_SYMTBL(node), IDS_NAME(temp_dim));

                node_st *param = PPadd_before_param(node, STRcpy(PARAM_NAME(temp_param)), STRcpy(IDS_NAME(temp_dim)));

                // We link the ste with the actual parameter
                STE_DECL(ste) = param;

                temp_dim = IDS_NEXT(temp_dim);
            }
        }

        temp_param = PARAM_NEXT(temp_param);
    }

    data->current_scope = node;

    TRAVchildren(node);

    data->current_scope = outer;

    return node;
}

/**
 * @fn PPbool
 */
node_st *PPfuncall(node_st *node)
{

    struct data_pp *data = DATA_PP_GET();
    node_st *outer = data->current_scope;
    node_st *temp_arg = FUNCALL_ARGS(node);

    while (temp_arg != NULL)
    {

        if (NODE_TYPE(EXPRS_EXPR(temp_arg)) == NT_VAR)
        {
            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), VAR_NAME(EXPRS_EXPR(temp_arg)));

            node_st *decl = STE_DECL(ste);

            if (NODE_TYPE(decl) == NT_PARAM)
            {
                // We add ids in funcall and link with STE
                if (PARAM_DIMS(decl) != NULL)
                {
                    printf("NT_PARAM\n");

                    node_st *dim = PARAM_DIMS(decl);

                    while (dim != NULL) // loop through all dimensions
                    {
                        node_st *arg = PPadd_id_before_arg(node, VAR_NAME(EXPRS_EXPR(temp_arg)), IDS_NAME(dim));

                        if (NODE_TYPE(arg) == NT_VAR) // Link new arg with STE
                        {
                            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), IDS_NAME(dim));
                            VAR_ENTRY(EXPRS_EXPR(arg)) = ste;
                        }

                        dim = IDS_NEXT(dim);
                    }
                }
            }

            if (NODE_TYPE(decl) == NT_GLOBDECL)
            {
                // We add ids in funcall and link with STE
                if (GLOBDECL_DIMS(decl) != NULL)
                {
                    printf("NT_GLOBDECL\n");

                    node_st *dim = GLOBDECL_DIMS(decl);

                    while (dim != NULL) // loop through all dimensions
                    {
                        node_st *arg = PPadd_id_before_arg(node, VAR_NAME(EXPRS_EXPR(temp_arg)), IDS_NAME(dim));

                        if (NODE_TYPE(arg) == NT_VAR) // Link new arg with STE
                        {
                            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), IDS_NAME(dim));
                            VAR_ENTRY(EXPRS_EXPR(arg)) = ste;
                        }

                        dim = IDS_NEXT(dim);
                    }
                }
            }

            if (NODE_TYPE(decl) == NT_VARDECL)
            {
                // We add exprs in funcall and link with STE if VAR
                if (VARDECL_DIMS(decl) != NULL)
                {
                    printf("NT_VARDECL\n");

                    node_st *dim = VARDECL_DIMS(decl);

                    while (dim != NULL) // loop through all dimensions
                    {
                        node_st *arg = PPadd_expr_before_arg(node, VAR_NAME(EXPRS_EXPR(temp_arg)), EXPRS_EXPR(dim));

                        if (NODE_TYPE(arg) == NT_VAR) // Link new arg with STE
                        {
                            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), VAR_NAME(EXPRS_EXPR(temp_arg)));
                            VAR_ENTRY(EXPRS_EXPR(arg)) = ste;
                        }

                        dim = EXPRS_NEXT(dim);
                    }
                }
            }

            if (NODE_TYPE(decl) == NT_GLOBDEF)
            {

                // We add exprs in funcall and link with STE if VAR
                if (GLOBDEF_DIMS(decl) != NULL)
                {
                    printf("NT_GLOBDEF\n");

                    node_st *dim = GLOBDEF_DIMS(decl);

                    while (dim != NULL) // loop through all dimensions
                    {
                        node_st *arg = PPadd_expr_before_arg(node, VAR_NAME(EXPRS_EXPR(temp_arg)), EXPRS_EXPR(dim));

                        if (NODE_TYPE(arg) == NT_VAR) // Link new arg with STE
                        {
                            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), VAR_NAME(EXPRS_EXPR(temp_arg)));
                            VAR_ENTRY(EXPRS_EXPR(arg)) = ste;
                        }

                        dim = EXPRS_NEXT(dim);
                    }
                }
            }
        }

        temp_arg = EXPRS_NEXT(temp_arg);
    }

    TRAVchildren(node);

    return node;
}
