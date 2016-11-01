#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE
{
	int				value;
	struct NODE		*next;
};


static struct NODE *
sll_reserve(struct NODE* first)
{
	struct NODE* this = NULL;
	struct NODE* head = NULL;

	if (first == NULL)
	{
		return NULL;
	}

	for (; (this = first) != NULL; )
	{
		first = first->next;
		this->next = head;
		head = this;
	}

	return head;
}

static struct NODE *
insert(struct NODE* head, int value)
{
	struct NODE* prev = NULL;
	struct NODE* next = NULL;
	struct NODE* this = NULL;

	this = malloc(sizeof(*this));
	this->value = value;
	this->next = NULL;

	if (head == NULL || head->value > value)
	{
		this->next = head;
		head = this;
	}
	else
	{
		for (prev = head; (next=prev->next) != NULL && next->value < value; prev = prev->next)
		{
		}

		this->next = next;
		prev->next = this;
	}

	return head;
}

static void 
show(struct NODE* head)
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

	head = insert(head, 10);
	show(head);
	head = insert(head, 15);
	show(head);
	head = insert(head, 15);
	show(head);
	head = insert(head, 13);
	show(head);
	head = insert(head, 8);
	show(head);
	head = insert(head, 9);
	show(head);
	head = insert(head, 20);
	show(head);
	head = insert(head, 1);
	show(head);
	head = sll_reserve(head);
	show(head);

	return EXIT_SUCCESS;
}
