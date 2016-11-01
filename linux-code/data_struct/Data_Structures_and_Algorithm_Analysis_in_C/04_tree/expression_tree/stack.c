/*
** the implementation of the general stack interface 
*/

#include <stdlib.h>

#include "stack.h"


typedef struct STACK
{
    void            *data;
    struct STACK    *next;
} STACK;


static STACK *head = NULL;


static STACK *
make_node(void *data)
{
    STACK *tmp = (STACK *)malloc(sizeof(*tmp));

    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

void 
push(void *data)
{
    STACK *new = make_node(data);

    new->next = head;
    head = new;
}


void *
pop(void)
{
    void *data = NULL;
    STACK *tmp = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    tmp = head;
    head = head->next;

    data = tmp->data;
    
    free(tmp), tmp = NULL;

    return data;
}
