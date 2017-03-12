#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


struct LIST
{
    int         data;
    struct LIST *next;
};


static struct LIST *reserve(struct LIST *p)
{
    struct LIST *t = NULL;
    struct LIST *h = NULL;

    while (p != NULL)
    {
        t = p;
        p = p->next;

        t->next = h;
        h = t;
    }

    return h;
}

static void show(struct LIST *node)
{
    while (node != NULL)
    {
        printf("%d -- ", node->data);
        node = node->next;
    }

    printf("\n");
}

static void insert(struct LIST **pphead, int value)
{
    struct LIST *node = (struct LIST *)malloc(sizeof(*node));

    assert(node);

    node->data = value;
    node->next = *pphead;

    *pphead = node;
}

int main(int argc, char *argv[])
{
    struct LIST *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    show(head);

    head = reserve(head);

    show(head);

    return EXIT_SUCCESS;
}
