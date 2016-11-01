/*
** test expression tree
*/

#include <stdio.h>
#include <stdlib.h>

#include "expression.h"


int
main(int argc, char *argv[])
{
    EBREE *root = NULL;

    expression_tree(&root);
    print_tree(root);
    printf("\n");

    return EXIT_SUCCESS;
}
