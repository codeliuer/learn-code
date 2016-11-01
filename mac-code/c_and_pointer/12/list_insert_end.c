#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct NODE
{
	int				value;
	struct NODE*	next;
} NODE;


static NODE *
get_node(int value)
{
	NODE* pNode = malloc(sizeof(*pNode));
	if (pNode == NULL)
	{
		fprintf(stderr, "memory alloc failure\n");
		return NULL;
	}

	pNode->value = value;
	pNode->next = NULL;

	return pNode;
}

static void 
insert(NODE** ppNode, int value)
{
	NODE* pNode = NULL;

	while (*ppNode != NULL && value < ((*ppNode)->value))
	{
		ppNode = &(*ppNode)->next;
	}

	pNode = get_node(value);
	pNode->next = *ppNode;
	*ppNode = pNode;
}

static void
show(NODE* head)
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
	NODE* head = NULL;

	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 1);
	insert(&head, 15);
	insert(&head, 30);
	insert(&head, 11);
	show(head);

	return EXIT_SUCCESS;
}
