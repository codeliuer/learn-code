#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	FAILURE				(-1)
#define	SUCCESS				(0)
#define	EXIST				(1)


typedef struct NODE
{
	int				value;
	struct NODE		*next;
	struct NODE		*prev;
} NODE;


static int
dll_insert(NODE* pHead, int value)
{
	NODE* this = NULL;
	NODE* next = NULL;
	NODE* newnode = NULL;

	for (this = pHead; (next=this->next) != NULL; this = next)
	{
		if (next->value == value)
		{
			return EXIST;
		}

		if (next->value > value)
		{
			break;
		}
	}

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
	{
		return FAILURE;
	}

	newnode->value = value;
	newnode->prev  = NULL;
	newnode->next  = NULL;

	newnode->next = next;
	this->next = newnode;
	newnode->prev = this;
	if (next == NULL)
	{
		pHead->prev = newnode;
	}
	else
	{
		next->prev = newnode;
	}

	return SUCCESS;
}

static void
show(NODE* pHead)
{
	while (pHead->next != NULL)
	{
		printf("%d--", pHead->next->value);
		pHead = pHead->next;
	}
	printf("\n");
}


int
main(int argc, char* argv[])
{
	NODE head;

	dll_insert(&head, 10);
	dll_insert(&head, 20);
	dll_insert(&head, 15);
	dll_insert(&head, 30);
	dll_insert(&head, 5);
	dll_insert(&head, 1);
	show(&head);

	return EXIT_SUCCESS;
}
