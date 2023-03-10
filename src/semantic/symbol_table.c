/**
 * @file
 *
 * This file contains the code for the SymbolTable traversal.
 * The traversal has the uid: ST
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccn/ccn_types.h"
#include "ccngen/enum.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "palm/ctinfo.h"

void STinit() { return; }
void STfini() { return; }

/**
 * This function searches the specified SYMTBL for an identifier.
 * Returns STE if found.
 **/
node_st *STlookup(node_st *symtbl, char *identifier)
{
    if (symtbl == NULL || identifier == NULL)
        return NULL;

    // Check if the identifier exists in the current symbol table
    node_st *entry = SYMTBL_HEAD(symtbl);
    while (entry != NULL)
    {
        if (STReq(STE_NAME(entry), identifier) == true)
        {
            return entry;
        }
        entry = STE_NEXT(entry);
    }

    // Identifier not found in the current symbol table
    return NULL;
}

/**
 * This function takes a declaration and traverses it's STE nodes and attaches the new node to the tail.
 * This function returns the node if storing has succeeded and returns NULL if this has failed.
 **/
node_st *STstore(node_st *symtbl, char *identifier, enum Type type, node_st *link)
{
    if (!symtbl || !identifier || !link)
    { // check for null pointers
        return NULL;
    }

    node_st *tail = SYMTBL_HEAD(symtbl);
    if (tail)
    { // if the symbol table already has entries, find the tail
        while (STE_NEXT(tail))
        {
            tail = STE_NEXT(tail);
        }
    }
    else
    { // otherwise, set the head
        SYMTBL_HEAD(symtbl) = ASTste(NULL, identifier, type, link);
        return symtbl;
    }

    STE_NEXT(tail) = ASTste(NULL, identifier, type, link); // add new entry to the tail
    return symtbl;
}

/**
 * @fn STprogram
 */
node_st *STprogram(node_st *node)
{
    printf("STprogram \n");

    struct data_st *data = DATA_ST_GET();

    data->current_scope = node;

    PROGRAM_SYMTBL(node) = ASTsymtbl(NULL, NULL); // Create a blank symbol table for global scope.

    TRAVchildren(node);

    CTIabortOnError(); // This Initialises the error messages.

    return node;
}

/**
 * @fn STfundef
 */
node_st *STfundef(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope;
    enum ccn_nodetype outer_type = NODE_TYPE(outer);

    // Create a new symbol table for the node
    if (outer_type == NT_PROGRAM)
    {

        FUNDEF_SYMTBL(node) = ASTsymtbl(PROGRAM_SYMTBL(outer), NULL);

        node_st *entry = STlookup(PROGRAM_SYMTBL(outer), FUNDEF_NAME(node));

        if (entry == NULL)
        {
            STstore(PROGRAM_SYMTBL(outer), FUNDEF_NAME(node), FUNDEF_TYPE(node), node);
        }

        if (entry != NULL)
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                FUNDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }
    else if (outer_type == NT_FUNDEF)
    {
        FUNDEF_SYMTBL(node) = ASTsymtbl(FUNDEF_SYMTBL(outer), NULL);

        node_st *entry = STlookup(FUNDEF_SYMTBL(outer), FUNDEF_NAME(node));

        if (entry == NULL)
        {
            STstore(FUNDEF_SYMTBL(outer), FUNDEF_NAME(node), FUNDEF_TYPE(node), node);
        }

        if (entry != NULL)
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                FUNDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }

    // Set this node as the current scope
    data->current_scope = node;

    TRAVparams(node);
    TRAVbody(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * THESE NODES MUST HAVE
 * AN UNIQUE DECLARATION SO NO DECLARATION CAN PRECEDE IT IN THE SAME SCOPE
 */

/**
 * @fn STglobdecl
 */
node_st *STglobdecl(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope; // we get the current scope.

    node_st *entry = STlookup(PROGRAM_SYMTBL(outer), GLOBDECL_NAME(node));

    if (entry == NULL)
    {
        STstore(PROGRAM_SYMTBL(outer), GLOBDECL_NAME(node), GLOBDECL_TYPE(node), node);
    }

    if (entry != NULL)
    {
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            GLOBDECL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    printf("STglobdef \n");

    // Set this node as the current scope
    TRAVchildren(node);

    return node;
}

/**
 * @fn STglobdef
 */
node_st *STglobdef(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope; // we get the current scope.

    node_st *entry = STlookup(PROGRAM_SYMTBL(outer), GLOBDEF_NAME(node));

    if (entry == NULL)
    {
        STstore(PROGRAM_SYMTBL(outer), GLOBDEF_NAME(node), GLOBDEF_TYPE(node), node);
    }

    if (entry != NULL)
    {
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            GLOBDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVchildren(node);

    return node;
}

/**
 * @fn STvardecl
 */
node_st *STvardecl(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope; // we get the current scope.

    node_st *entry = STlookup(FUNDEF_SYMTBL(outer), VARDECL_NAME(node));

    if (entry == NULL)
    {
        STstore(FUNDEF_SYMTBL(outer), VARDECL_NAME(node), VARDECL_TYPE(node), node);
    }

    if (entry != NULL)
    {
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            VARDECL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVchildren(node);

    return node;
}

/**
 * @fn STparam
 */
node_st *STparam(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope; // we get the current scope.

    node_st *entry = STlookup(FUNDEF_SYMTBL(outer), PARAM_NAME(node));

    TRAVdims(node); // We first traverse possible dimensions

    if (entry == NULL)
    {
        STstore(FUNDEF_SYMTBL(outer), PARAM_NAME(node), PARAM_TYPE(node), node);
    }

    if (entry != NULL)
    {
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            PARAM_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVnext(node);

    return node;
}

/**
 * @fn STids
 */
node_st *STids(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope; // we get the current scope.
    enum ccn_nodetype outer_type = NODE_TYPE(outer);

    // Create a new symbol table for the node
    if (outer_type == NT_PROGRAM)
    {
        node_st *entry = STlookup(PROGRAM_SYMTBL(outer), IDS_NAME(node));

        if (entry == NULL)
        {
            STstore(PROGRAM_SYMTBL(outer), IDS_NAME(node), CT_int, node);
        }

        if (entry != NULL)
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                IDS_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }
    else if (outer_type == NT_FUNDEF)
    {
        node_st *entry = STlookup(FUNDEF_SYMTBL(outer), IDS_NAME(node));

        if (entry == NULL)
        {
            STstore(FUNDEF_SYMTBL(outer), IDS_NAME(node), CT_int, node);
        }

        if (entry != NULL)
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                IDS_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }

    TRAVchildren(node);

    return node;
}