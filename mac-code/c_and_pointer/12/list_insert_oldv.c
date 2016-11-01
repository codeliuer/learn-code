#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct SINGLE_LIST
{
	int					value;
	struct SINGLE_LIST	*pNext;
} SINGLE_LIST;


static SINGLE_LIST *
getNode(int value)
{
	SINGLE_LIST * list = malloc(sizeof(*list));
	assert(list);

	list->value = value;
	list->pNext = NULL;

	return list;
}
 
static SINGLE_LIST *
order_insert(SINGLE_LIST *list, int value)
{
	SINGLE_LIST *head = list;
	SINGLE_LIST *node = NULL;
	SINGLE_LIST *tmp = NULL;

	if (list == NULL)
	{
		return getNode(value);
	}

	while (list != NULL)
	{
		tmp = list;

		if (list->value > value)
		{
			node = getNode(value);
			node->pNext = list;
			head = node;

			break;
		}
		else if ((list->pNext == NULL ) || ((list->pNext!=NULL) && (list->pNext->value > value)))
		{
			node = getNode(value);
			node->pNext = tmp->pNext;
			tmp->pNext = node;

			break;
		}
		else
		{
			list = list->pNext;
		}
	}

	return head;
}

static void
show_list(SINGLE_LIST *list)
{
	while (list != NULL)
	{
		printf("%d  ", list->value);
		list = list->pNext;
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	SINGLE_LIST *list = NULL;

	list = order_insert(list, 5);
	list = order_insert(list, 1);
	list = order_insert(list, 10);
	list = order_insert(list, 15);
	list = order_insert(list, 12);
	list = order_insert(list, 20);
	list = order_insert(list, 0);
	show_list(list);

	return EXIT_SUCCESS;
}
