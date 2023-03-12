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

// Generate a unique signature for a given function definition node
char *STgeneratesignature(node_st *function_definition)
{
    // Copy the function name to a new string in memory
    char *signature = STRcpy(FUNDEF_NAME(function_definition));

    // Initialize a counter variable for the number of parameters
    int parameter_count = 0;

    // Check if there are any parameters in the function definition
    if (FUNDEF_PARAMS(function_definition) != NULL)
    {

        // Count the number of parameters
        node_st *parameter = FUNDEF_PARAMS(function_definition);
        while (parameter != NULL)
        {
            parameter_count++;
            parameter = PARAM_NEXT(parameter);
        }
    }

    // Append the parameter count to the signature string
    char parameter_count_string[10];
    snprintf(parameter_count_string, 10, "_%d", parameter_count);
    signature = STRcat(signature, parameter_count_string);

    return signature;
}

// Look up an identifier in a given symbol table
node_st *STlookup(node_st *symbol_table, char *identifier)
{
    // Check if the symbol table or identifier are NULL
    if (symbol_table == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Check if the identifier exists in the symbol table
    node_st *entry = SYMTBL_HEAD(symbol_table);
    while (entry != NULL)
    {
        if (STReq(STE_NAME(entry), identifier) == true)
        {
            // Identifier found in the symbol table
            return entry;
        }
        entry = STE_NEXT(entry);
    }

    // Identifier not found in the symbol table
    return NULL;
}

// Store an identifier and its associated data in a given symbol table
node_st *STstore(node_st *symbol_table, char *identifier, enum Type type, node_st *link)
{
    // Check for null pointers
    if (!symbol_table || !identifier || !link)
    {
        return NULL;
    }

    // Find the tail of the symbol table
    node_st *tail = SYMTBL_HEAD(symbol_table);
    if (tail)
    {
        while (STE_NEXT(tail))
        {
            tail = STE_NEXT(tail);
        }
    }
    else
    { // Set the head of the symbol table if it's empty
        SYMTBL_HEAD(symbol_table) = ASTste(NULL, identifier, type, link);
        return symbol_table;
    }

    // Add a new entry to the tail of the symbol table
    STE_NEXT(tail) = ASTste(NULL, identifier, type, link);
    return symbol_table;
}

/**
 * @fn STprogram
 */
node_st *STprogram(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    data->current_scope = node;

    PROGRAM_SYMTBL(node) = ASTsymtbl(NULL, NULL); // Create a blank symbol table with a init fundef for global scope.

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
        char *signature = STgeneratesignature(node);
        node_st *entry = STlookup(PROGRAM_SYMTBL(outer), signature);
        if (entry == NULL)
        {
            STstore(PROGRAM_SYMTBL(outer), signature, FUNDEF_TYPE(node), node);
        }
        else
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                FUNDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }
    else if (outer_type == NT_FUNDEF)
    {
        FUNDEF_SYMTBL(node) = ASTsymtbl(FUNDEF_SYMTBL(outer), NULL);
        char *signature = STgeneratesignature(node);
        node_st *entry = STlookup(FUNDEF_SYMTBL(outer), signature);
        if (entry == NULL)
        {
            STstore(FUNDEF_SYMTBL(outer), signature, FUNDEF_TYPE(node), node);
        }
        else
        {
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                FUNDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }

    // Set this node as the current scope
    data->current_scope = node;

    // Traverse the node and its body
    TRAVparams(node);
    TRAVbody(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn STglobdecl
 */
node_st *STglobdecl(node_st *node)
{
    // Get the data and the current scope
    struct data_st *data = DATA_ST_GET();
    node_st *outer = data->current_scope;

    // Look up the node in the symbol table
    node_st *entry = STlookup(PROGRAM_SYMTBL(outer), GLOBDECL_NAME(node));

    // Store the node in the symbol table if it doesn't exist
    if (entry == NULL)
    {
        STstore(PROGRAM_SYMTBL(outer), GLOBDECL_NAME(node), GLOBDECL_TYPE(node), node);
    }
    else
    { // Otherwise, report an error
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            GLOBDECL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Set this node as the current scope and traverse its children
    TRAVchildren(node);

    return node;
}

/**
 * @fn STglobdef
 */
node_st *STglobdef(node_st *node)
{
    // Get the data and the current scope
    struct data_st *data = DATA_ST_GET();
    node_st *outer = data->current_scope;

    // Look up the node in the symbol table
    node_st *entry = STlookup(PROGRAM_SYMTBL(outer), GLOBDEF_NAME(node));

    // Store the node in the symbol table if it doesn't exist
    if (entry == NULL)
    {
        STstore(PROGRAM_SYMTBL(outer), GLOBDEF_NAME(node), GLOBDEF_TYPE(node), node);
    }
    else
    { // Otherwise, report an error
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            GLOBDEF_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);

    return node;
}

/**
 * @fn STvardecl
 */
node_st *STvardecl(node_st *node)
{
    // Get the data and the current scope
    struct data_st *data = DATA_ST_GET();
    node_st *outer = data->current_scope;

    // Look up the node in the symbol table
    node_st *entry = STlookup(FUNDEF_SYMTBL(outer), VARDECL_NAME(node));

    // Store the node in the symbol table if it doesn't exist
    if (entry == NULL)
    {
        STstore(FUNDEF_SYMTBL(outer), VARDECL_NAME(node), VARDECL_TYPE(node), node);
    }
    else
    { // Otherwise, report an error
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            VARDECL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);

    return node;
}

/**
 * @fn STparam
 */
node_st *STparam(node_st *node)
{
    // Get the data and the current scope
    struct data_st *data = DATA_ST_GET();
    node_st *outer = data->current_scope;

    // Traverse the dimensions of the node
    TRAVdims(node);

    // Look up the node in the symbol table
    node_st *entry = STlookup(FUNDEF_SYMTBL(outer), PARAM_NAME(node));

    // Store the node in the symbol table if it doesn't exist
    if (entry == NULL)
    {
        STstore(FUNDEF_SYMTBL(outer), PARAM_NAME(node), PARAM_TYPE(node), node);
    }
    else
    { // Otherwise, report an error
        CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
            PARAM_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the next node and return the current node
    TRAVnext(node);

    return node;
}

/**
 * @fn STids
 */
node_st *STids(node_st *node)
{
    // Get the data and the current scope
    struct data_st *data = DATA_ST_GET();
    node_st *outer = data->current_scope;
    enum ccn_nodetype outer_type = NODE_TYPE(outer);

    // Create a new symbol table for the node if the outer node is a program or a function definition
    if (outer_type == NT_PROGRAM)
    {
        node_st *entry = STlookup(PROGRAM_SYMTBL(outer), IDS_NAME(node));

        if (entry == NULL)
        {
            STstore(PROGRAM_SYMTBL(outer), IDS_NAME(node), CT_int, node);
        }
        else
        { // Otherwise, report an error
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
        else
        { // Otherwise, report an error
            CTI(CTI_ERROR, true, "\n Duplicate definition: '%s' is already defined. see: line: %d col: %d-%d. \n",
                IDS_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
        }
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);

    return node;
}
