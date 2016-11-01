#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define NUL             ('\0')


typedef struct LL
{
    char        c;
    struct LL   *next;
} LL;


static LL *
insert(LL *head, char c)
{
    LL **tmpp = &head;

    LL *node = malloc(sizeof(*node));
    assert(node);

    node->c = c;
    node->next = NULL;

    while (*tmpp != NULL)
    {
        tmpp = &(*tmpp)->next;
    }

    *tmpp = node;

    return head;
}


static void
reserve_list(LL **ppl, LL *head)
{
    LL *node = NULL;

    while (head != NULL)
    {
        node = head;
        head = head->next;

        node->next = *ppl;
        *ppl = node;
    }
}


static void
reserve(LL **ppl, const char *string)
{
    LL *head = NULL;

    while (*string != NUL)
    {
        head = insert(head, *string);
        string++;
    }

    reserve_list(ppl, head);
}

static void
show_list(LL *head)
{
    while (head != NULL)
    {
        printf("%c", head->c);
        head = head->next;
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
    LL *head = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out string");
        return EXIT_FAILURE;
    }

    reserve(&head, argv[1]);
    show_list(head);

    return EXIT_SUCCESS;
}
