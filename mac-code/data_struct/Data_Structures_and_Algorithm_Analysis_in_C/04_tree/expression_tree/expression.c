/*
** expression tree
*/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "getop.h"


enum e
{
    e_data,
    e_alpha,
    e_operator,
};

typedef struct EBREE
{
    enum e          e;
    int             data;
    struct EBREE    *left;
    struct EBREE    *right;
} EBREE;


static EBREE *
make_tree(enum e e, int data)
{
    EBREE *new = (EBREE *)malloc(sizeof(new));
    
    new->e = e;
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}


void
expression_tree(EBREE **root)
{
    OP_t op;
    int data;
    EBREE *left = NULL;
    EBREE *right = NULL;
    EBREE *new = NULL;

    while ((op = getop(&data)) != OTHER)
    {
        if (op == DATA)
        {
            push(make_tree(e_data, data));
        }
        else if (op == ALPHABET)
        {
            push(make_tree(e_alpha, data));
        }
        else
        {
            right = pop();
            left = pop();

            new = make_tree(e_operator, data);
            new->left = left;
            new->right = right;

            push(new);
        }
    }

    *root = pop();
}


static void
print_data(EBREE * root)
{
    if (root->e == e_data)
    {
        printf("%d ", root->data);
    }
    else if (root->e = e_alpha)
    {
        printf("%c ", root->data);
    }
    else
    {
        printf("%c ", root->data);
    }
}

void
print_tree(EBREE *root)
{
    if (root != NULL)
    {
        print_tree(root->left);
        print_data(root);
        print_tree(root->right);
    }
}
