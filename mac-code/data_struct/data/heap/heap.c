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
        printf("%2d-- ", i);
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
    int i = 0;
    void *retdata = NULL;

    if (top == 0)
    {
        fprintf(stderr, "heap is null\n");
        return NULL;
    }

    retdata = pp[1];

    for (i = 1; i < top; NOP)
    {
        if (cmp(pp[2*i], pp[2*i+1]) < 0)
        {
            if (cmp(pp[2*i], pp[top]) < 0)
            {
                pp[i] = pp[2*i];
                i *= 2;
            }
            else
            {
                pp[i] = pp[top];
                break;
            }
        }
        else
        {
            if (cmp(pp[2*i+1], pp[top]) < 0)
            {
                pp[i] = pp[2*i+1];
                i = 2*i + 1;
            }
            else
            {
                pp[i] = pp[top];
                break;
            }
        }
    }

    top--;

    return retdata;
}
