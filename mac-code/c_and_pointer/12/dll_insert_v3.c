#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct NODE
{
	struct NODE			*prev;
	struct NODE			*next;
	int					value;
} NODE;


static NODE *
dll_get_node(int value)
{
	NODE* node = malloc(sizeof(*node));
	assert(node);

	node->value = value;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

static void
dll_insert(struct NODE** pphead, struct NODE** pptail, int value)
{
	struct NODE* node = NULL;

	while ((*pphead != NULL) && (*pphead)->value < value)
	{
		pphead = &(*pphead)->next;
	}

	node = dll_get_node(value);

	node->next = *pphead;
	*pphead = node;
	if (*pphead == NULL)
	{
		if (*pptail == NULL)
		{
			*pptail = node;
		}
		else
		{
			(*pptail)->prev = node;
		}
	}
	else
	{
		node->prev = (*pphead)->prev;
	}
}


static void
dll_show(struct NODE* head)
{
	while (head)
	{
		printf("%d--", head->value);
		head = head->next;
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	struct NODE* head = NULL;
	struct NODE* tail = NULL;

	dll_insert(&head, &tail, 10);
	dll_insert(&head, &tail, 20);
	dll_insert(&head, &tail, 15);
	dll_insert(&head, &tail, 25);
	dll_insert(&head, &tail, 5);
	dll_insert(&head, &tail, 1);
	dll_insert(&head, &tail, 30);
	dll_show(head);

	return EXIT_SUCCESS;
}
