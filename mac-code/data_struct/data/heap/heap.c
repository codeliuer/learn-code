/*
 *  heap view:
 *                    O
 *                   / \
 *                  O   O
 *                 / \ / \
 *                O  OO   O
 * heap storage:
 *            _____________________________
 *     arr -->|NULL| | | | | | | | | | | | |
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"


#define NOP


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

        for (i = ++top, j = i/2; j != 0 && cmp(pp[j], node) > 0; i = j, j = i/2)
        {
            pp[i] = pp[j];
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


void *pop(CMP_t cmp)
{
    int parent = 0;
    int child = 0;
    void *retdata = NULL;

    if (top == 0)
    {
        fprintf(stderr, "stack is null\n");
        return NULL;
    }

    retdata = pp[1];

    for (parent = 1; 2*parent <= top; NOP)
    {
        child = 2*parent;
        if (child != top)
        {
            if (cmp(pp[child], pp[child+1]) < 0)
            {
                if (cmp(pp[parent], pp[child]) < 0)
                {
                    break;
                }
                else
                {
                }
            }
            else
            {
            }
        }
        else
        {
        }
    }

    top--;

    return retdata;
}
