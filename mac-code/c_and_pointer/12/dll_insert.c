#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct NODE
{
    int             values;
    struct NODE     *prev;
    struct NODE     *next;
} NODE;


static void insert_null(NODE* pHead, int value);


static void
insert_node(NODE* pNode, int value)
{
    NODE* tmp = malloc(sizeof(*tmp));
    assert(tmp);

    tmp->values = value;
    tmp->next = NULL;
    tmp->prev = NULL;

    tmp->next = pNode->next;
    tmp->prev = pNode;
    pNode->next->prev = tmp;
    pNode->next = tmp;
}

static void
insert_base(NODE* pHead, int value)
{
    while ((pHead->next != NULL) && (pHead->next->values < value))
    {
        pHead = pHead->next;
    }

    if (pHead->next != NULL)
    {
        insert_node(pHead, value);
    }
    else
    {
        insert_null(pHead, value);
    }
}

static void
insert_null(NODE* pHead, int value)
{
    NODE* node = malloc(sizeof(*node));
    assert(node);

    node->values = value;
    node->prev = NULL;
    node->next = NULL;

    node->prev = pHead;
    pHead->next = node;
}

static void
dll_insert(NODE* pHead, int value)
{
    if (pHead->next != NULL)
    {
        insert_base(pHead, value);
    }
    else
    {
        /* The current node is the tail */
        insert_null(pHead, value);
    }

    pHead->values++;
}

static void
dll_show(NODE* pHead)
{
    printf("total = %d\n", pHead->values);
    while (pHead->next != NULL)
    {
        printf("%d--", pHead->next->values);
        pHead = pHead->next;
    }
    printf("\n");
}

int
main(int argc, char* argv[])
{
    NODE head = {0, NULL, NULL};

    dll_insert(&head, 2);
    dll_insert(&head, 10);
    dll_insert(&head, 20);
    dll_insert(&head, 5);
	dll_insert(&head, 0);
    dll_insert(&head, 1);
    dll_show(&head);
    
    return EXIT_SUCCESS;
}
