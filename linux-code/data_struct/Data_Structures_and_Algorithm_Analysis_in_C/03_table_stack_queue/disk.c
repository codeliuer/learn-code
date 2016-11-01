#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define DISK_SUCCESS                (0)
#define DISK_MEMORY                 (1)


typedef struct NODE
{
    int         start;
    int         end;
    struct NODE *prev;
    struct NODE *next;
} NODE;


static NODE *
make_node(int start, int end)
{
    NODE *new = (NODE *)malloc(sizeof(*new));
    assert(new != NULL);

    new->start = start;
    new->end = end;
    new->prev = NULL;
    new->next = NULL;

    return new;
}

static void
insert(NODE *prev, NODE *new, NODE *next)
{
    new->prev = prev;
    new->next = next;
    prev->next = new;
    if (next != NULL)
    {
        prev->next->prev = new;
    }
}


static int
insert_section(NODE **pphead, int start, int end)
{
    NODE *prev = NULL;
    NODE *next = NULL;
    NODE *new = NULL;

    for (prev = *pphead; prev != NULL && (next = prev->next) != NULL; prev = next)
    {
        if (prev->end+1 < start && end+1 < next->start) /* insert new node */
        {
            new = make_node(start, end);
            insert(prev, new, next);
        }
        else if ()
        {
        }
        else
        {
        }
    }

    return DISK_SUCCESS;
}

static void
show_section(NODE *head)
{
    while (head != NULL)
    {
        printf("[%d--%d]  ", head->start, head->end);
        head = head->next;
    }
    printf("\n");
}


int
main(int argc, char * argv[])
{
    NODE *head = NULL;

    insert_section(&head, 1, 2);
    insert_section(&head, 2, 3);
    show_section(head);

    return EXIT_SUCCESS;
}
