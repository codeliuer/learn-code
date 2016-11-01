#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct DLINK
{
	struct DLINK		*next;
	struct DLINK		*prev;
	int					value;
} DLINK;


static void
dll_insert(DLINK* phead, int value)
{
	DLINK* this = NULL;
	DLINK* next = NULL;
	DLINK* node = NULL;

	for (this = phead; (next = this->next) != NULL; this = next)
	{
		if (next->value > value)
		{
			break;
		}
	}

	node = malloc(sizeof(*node));
	if (node == NULL)
	{
		return;
	}

	node->value = value;

	node->next = next;
	this->next = node;

	/*      __            __
	**	   |  |          |  |
	**     |__|          |__|
	**       |			   |
	**       |			   |
	**      _|_     __    _|_
	**  <--|  |<->|  |<->|  |-->
	**      --     --     --
	*/   
	(this == phead) ? (node->prev = NULL) : (node->prev = this);
	(next == NULL) ? (phead->prev = node) : (next->prev = node);
}

static void
dll_show(DLINK* phead)
{
	DLINK* next = phead->next;

	while ((next != NULL) && (next != phead))
	{
		printf("%d--", next->value);
		next = next->next;
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	struct DLINK head;

	dll_insert(&head, 20);
	dll_insert(&head, 50);
	dll_insert(&head, 30);
	dll_insert(&head, 10);
	dll_insert(&head, 40);
	dll_insert(&head, 5);
	dll_insert(&head, 15);
	dll_insert(&head, 3);
	dll_insert(&head, 100);
	dll_insert(&head, 18);
	dll_insert(&head, 2);
	dll_insert(&head, 1);
	dll_show(&head);

	return EXIT_SUCCESS;
}
