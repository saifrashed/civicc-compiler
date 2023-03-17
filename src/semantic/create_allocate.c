
/**
 * @file
 *
 * This file contains the code for the CreateInit traversal.
 * The traversal has the uid: CA
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

/**
 * @fn CAprogram
 */
node_st *CAprogram(node_st *node)
{
    // Initialize a function declaration node with the name "__init" and void return type
    char *init_function_name = "__allocate";
    node_st *init_function_declaration = ASTdecls(
        ASTfundef(ASTfunbody(NULL, NULL, NULL), NULL, CT_int, init_function_name, false),
        NULL);

    // Add the "__init" declaration to the end of the declaration list
    node_st *declaration_tail = PROGRAM_NEXT(node);
    while (DECLS_NEXT(declaration_tail) != NULL)
    {
        declaration_tail = DECLS_NEXT(declaration_tail);
    }
    DECLS_NEXT(declaration_tail) = CCNcopy(init_function_declaration);

    // Set the symbol table of the "__init" declaration to be a copy of the program's symbol table
    FUNDEF_SYMTBL(DECLS_DECL(DECLS_NEXT(declaration_tail))) = ASTsymtbl(PROGRAM_SYMTBL(node), NULL);

    // Copy the program's symbol table
    node_st *symbol_table_head = CCNcopy(SYMTBL_HEAD(PROGRAM_SYMTBL(node)));

    // Create a new symbol table with the "__init" declaration as its first declaration
    node_st *new_symbol_table_head = ASTste(
        symbol_table_head,
        FUNDEF_NAME(DECLS_DECL(DECLS_NEXT(declaration_tail))),
        CT_void,
        DECLS_DECL(DECLS_NEXT(declaration_tail)));

    // Set the new symbol table head as the program's symbol table head
    SYMTBL_HEAD(PROGRAM_SYMTBL(node)) = CCNcopy(new_symbol_table_head);

    // Return the current node
    return node;
}
