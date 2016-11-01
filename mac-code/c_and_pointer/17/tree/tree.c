#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


struct TREE
{
    TREE_ELE*           value;
    struct TREE         *left;
    struct TREE         *right;
};


struct TREE_t
{
    struct TREE         *ptree;
    int (*FP_insert)(TREE**, TREE_ELE*, FP_cmp_t);
    int (*FP_search)(TREE*, TREE_ELE*, FP_cmp_t);
    int (*FP_delete)(TREE**, TREE_ELE*, FP_cmp_t);
};


struct TREE_t tree = {NULL, insert_node, search_node, del_node};


static TREE *
make_node(TREE_ELE* pvalue)
{
    TREE* ptree = malloc(sizeof(*ptree));
    if (ptree == NULL)
    {
        return NULL;
    }

    ptree->value = pvalue;
    ptree->left = NULL;
    ptree->right = NULL;

    return ptree;
}

static TREE **
find_node(
    TREE** pproot,
    TREE_ELE* pvalue,
    FP_cmp_t cmp
)
{
    int cmpValue = 0;

    while (*pproot != NULL)
    {
        if ((cmpValue = cmp((*pproot)->value, pvalue)) == 0)
        {
            return (struct TREE **)NULL;
        }
        else if (cmpValue > 0)
        {
            pproot = &(*pproot)->left;
        }
        else
        {
            pproot = &(*pproot)->right;
        }
    }

    return pproot;
}

TREE_API int
insert_tree(
    TREE** pproot, 
    TREE_ELE* pValue,
    FP_cmp_t cmp
)
{
    TREE* newnode = NULL;

    pproot = find_node(pproot, pValue, cmp);
    if (pproot == NULL)
    {
        return TREE_FAILURE;
    }

    newnode = make_node(pValue);
    if (newnode == NULL)
    {
        return TREE_MEMORY;
    }

    *pproot = newnode;

    return TREE_SUCCESS;
}


TREE_API int
search_tree(TREE** pproot, TREE_ELE* pValue, FP_cmp_t cmp)
{
    pproot = find_node(pproot, pValue, cmp);

    return (pproot == NULL) ? TREE_FAILURE : TREE_SUCCESS;
}


TREE_API int
del_node(TREE** pproot, TREE_ELE* pValue, FP_cmp_t cmp)
{
    int retcode = 0;
    TREE* tmp = NULL;
    TREE* left = NULL;

    pproot = find_node(pproot, pValue, cmp);
    if (pproot == NULL)
    {
        return TREE_NOT_EXIST;
    }

    left = (*pproot)->left;
    tmp = *pproot;

    *pproot = (*pproot)->right;
    retcode = insert_node(pproot, left->value, cmp);

    free(tmp->value);
    free(tmp);
    tmp = NULL;

    return retcode;
}
