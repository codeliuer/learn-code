/*
 *  heap view:
 *                    O
 *                   / \
 *                  O   O
 *                 / \ / \
 *                 O O O O
 *                /|/|/|/|
 *                OOOOOOOO 
 * heap storage:
 *            _____________________________
 *     arr -->|NULL| | | | | | | | | | | | |
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"


typedef int (*CMP_t)(const void *, const void *);

typedef struct heap_t
{
    void        **plist;
    int         top;
} heap_t;

__thread heap_t heap = {NULL, 0};

#define pp      heap.plist
#define top     heap.top


int push(void *node, CMP_t cmp)
{
    int i = 0;
    int j = 0;

    if (pp != NULL)
    {
        if (top >= HEAP_VOLUME)
        {
            fprintf(stderr, "capacity is not enough\n");
            return HEAP_FAIL;
        }

        i = ++top;
        j = i/2;

        while (i != 0 && cmp(pp[j], node) < 0)
        {
            pp[i] = pp[j];
            i = j;
            j = i/2;
        }

        pp[i] = node;
    }
    else
    {
        pp = (void **)malloc(sizeof(*pp) * (HEAP_VOLUME+1));
        if (pp == NULL)
        {
            fprintf(stderr, "malloc failure\n");
            return HEAP_FAIL;
        }

        pp[++top] = node;
    }

    return HEAP_SUCC;
}


huffmantree *pop(CMP_t cmp)
{
    int i = 0;

    i = top--;

    return NULL;
}
