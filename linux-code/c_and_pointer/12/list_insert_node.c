#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct NODE
{
	int					value;
	struct NODE*		next;
} NODE;


static NODE *
find_location(NODE* head, int value)
{
	NODE* prev = NULL;

	while ((head!=NULL) && (value>head->value))
	{
		prev = head;
		head = head->next;
	}

	return prev;
}

static NODE*
get_node(size_t size)
{
	NODE* tmp = (NODE *)malloc(size);
	assert(tmp);

	return tmp;
}

static NODE *
node_init(int value)
{
	NODE* node = get_node(sizeof(*node));

	node->value = value;
	node->next = NULL;

	return node;
}

static NODE *
insert(NODE* head, int value)
{
	NODE* prev = NULL;
	NODE* node = NULL;
	NODE* tmp = NULL;

	if ((head == NULL) || ((prev = find_location(head, value)) == NULL))
	{
		node = node_init(value);

		node->next = head;

		return node;
	}
	else
	{
		node = node_init(value);

		tmp = prev->next;
		node->next = tmp;
		prev->next = node;

		return head;
	}
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

	head = insert(head, 5);
	head = insert(head, 10);
	head = insert(head, 1);
	head = insert(head, 12);
	head = insert(head, 6);
	show(head);

	return EXIT_SUCCESS;
}
