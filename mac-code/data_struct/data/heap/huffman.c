#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "heap.h"


#define heap_push(node)         push(node, type_cmp)
#define heap_pop()              pop(type_cmp)


typedef struct huffmantree_t
{
    struct huffmantree_t        *left;
    struct huffmantree_t        *right;
    struct huffmantree_t        *parent;
    int                         weight;
} huffmantree_t;


int type_cmp(const void *n1, const void *n2)
{
    const huffmantree_t *tree1 = *(huffmantree_t * const *)&n1;
    const huffmantree_t *tree2 = *(huffmantree_t * const *)&n2;

    return (tree1->weight - tree2->weight);
}

#define MAXSIZE         (20)


static huffmantree_t htree[MAXSIZE];

static void htree_init(void)
{
    int i = 0;

    srand(time(NULL));
    for (i = 0; i < MAXSIZE; i++)
    {
        htree[i].left = NULL;
        htree[i].right = NULL;
        htree[i].weight = rand()%MAXSIZE+1;
        htree[i].parent = NULL;
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    huffmantree_t *huff = NULL;

    htree_init();

    for (i = 0;  i < MAXSIZE; i++)
    {
        heap_push(&htree[i]);
    }

    printf("================================\n");

    for (i = 0; i < MAXSIZE; i++)
    {
        huff = heap_pop();

        printf("%d--", huff->weight);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
