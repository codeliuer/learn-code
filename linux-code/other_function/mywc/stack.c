#include <stdlib.h>

#include "stack.h"
#include "memory.h"


typedef struct queue_t
{
    const char*         q_name;
    struct queue_t*     q_next;
} queue_t;


static queue_t* head;

PUBLIC void
push(const char* name)
{
    queue_t* tmp = New(queue_t);

    tmp->q_name = name;
    tmp->q_next = head;
    head = tmp;
}


PUBLIC const char* 
pop(void)
{
    const char* name = NULL;
    queue_t* tmp = NULL;

    if (head != NULL)
    {
        tmp = head;
        head = head->q_next;
        name = tmp->q_name;

        Delete(tmp);
        tmp = NULL;
    }

    return name;
}
