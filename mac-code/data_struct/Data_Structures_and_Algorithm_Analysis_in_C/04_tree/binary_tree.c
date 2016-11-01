/*
** binary tree operation interface implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TREE_DEBUG          //


typedef struct BTREE
{
    const void      *pdata;
    struct BTREE    *lchild;
    struct BTREE    *rchild;
} BTREE;


typedef int (* BCMP_t)(const void *, const void *);


static BTREE *
make_node(size_t size)
{
    BTREE *tmp = malloc(size);
    assert(tmp);

    return tmp;
}


static BTREE *
init_node(const void *pdata)
{
    BTREE *tmp = make_node(sizeof(*tmp));

    tmp->pdata = pdata;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    return tmp;
}


int 
insert_data(BTREE **root, const void *data, BCMP_t cmp)
{
    while (*root != NULL)
    {
        if (cmp((*root)->pdata, data) > 0)
        {
            root = &(*root)->lchild;
        }
        else
        {
            root = &(*root)->rchild;
        }
    }

    *root = init_node(data);

    return 0;
}


void 
show_data(BTREE *root)
{
    if (root != NULL)
    {
        show_data(root->lchild);
        printf("%d  ", *(const int *)&root->pdata);
        show_data(root->rchild);
    }
}


#if defined(TREE_DEBUG)
static int 
cmp(const void *data1, const void *data2)
{
    const int d1 = *(const int *)&data1;  
    const int d2 = *(const int *)&data2;  

    return (d1 > d2) ? 1 : 0;
}


int
main(int argc, char *argv[])
{
    BTREE *root = NULL;

    setvbuf(stdout, NULL, _IONBF, 0);

    insert_data(&root, (const void *)10, cmp);
    insert_data(&root, (const void *)20, cmp);
    insert_data(&root, (const void *)15, cmp);
    insert_data(&root, (const void *)2, cmp);
    insert_data(&root, (const void *)30, cmp);
    insert_data(&root, (const void *)11, cmp);

    show_data(root);
    printf("\n");

    return EXIT_SUCCESS;
}
#endif  //TREE_DEBUG
