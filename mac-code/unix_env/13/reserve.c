#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

NODE *insert(NODE *p, int value)
{
    NODE ** pphead = &p;

    while (*pphead != NULL)
    {
        pphead = &(*pphead)->next;
    }

    *pphead = (NODE *)malloc(sizeof(*p));
    assert(*pphead);

    (*pphead)->value = value;
    (*pphead)->next = NULL;

    return p;
}

NODE *server(NODE *pheader)
{
    NODE *p = NULL;
    NODE *tmp = NULL;

    while (pheader != NULL)
    {
        tmp = pheader;
        pheader = pheader->next;

        tmp->next = p;
        p = tmp;
    }

    return p;
}

void show(NODE *p)
{
    while (p != NULL)
    {
        printf("%d-- ", p->value);
        p = p->next;
    }
}

int main(int argc, char *argv[])
{
    NODE *p = NULL;

    p = insert(p, 1);
    p = insert(p, 2);
    p = insert(p, 3);
    p = insert(p, 4);
    p = insert(p, 5);
    show(p);

    printf("\n");

    p = server(p);
    show(p);

    return EXIT_SUCCESS;
}
