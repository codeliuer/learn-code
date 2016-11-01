#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"


typedef struct NODE
{
	char				*name;
	struct list_head	head;
	int					age;
	int					id;
} NODE;


static NODE *
dll_get_node(int id, const char* name, int age)
{
	NODE* node = (NODE *)malloc(sizeof(*node));
	assert(node != NULL);

	node->id = id;
	node->name = strdup(name);
	node->age = age;

	return node;
}


static void
dll_insert(NODE* head, int id, const char* name, int age)
{
	NODE* new = NULL;
	NODE* this = head;
	NODE* cur = NULL;
	struct list_head* prev = NULL;
	struct list_head* next = NULL;

	list_for_safe_each(prev, next, &head->head)
	{
		this = list_entry(prev, NODE, head);
		cur  = list_entry(next, NODE, head);

		if ((this->id < id) && (cur->id > id))
		{
			break;
		}
		else if (this->id > id)
		{
			this = head;
			break;
		}
	}

	new = dll_get_node(id, name, age);

	list_add(&new->head, &this->head);
}

static void
dll_show(NODE* head)
{
	NODE* tmp = NULL;
	struct list_head* pos = NULL;

	list_for_each(pos, &head->head)
	{
		tmp = list_entry(pos, NODE, head);
		printf("id = %d, name: %s, age = %d\n", tmp->id, tmp->name, tmp->age);
	}
	printf("#######################################################\n");
}

int
main(int argc, char* argv[])
{
	NODE node;
	INIT_LIST_HEAD(&node.head);

	dll_insert(&node, 2, "li",     30);
	dll_show(&node);
	dll_insert(&node, 4, "l",      20);
	dll_show(&node);
	dll_insert(&node, 3, "liu",    25);
	dll_show(&node);
	dll_insert(&node, 1, "liuw",   10);
	dll_show(&node);
	dll_insert(&node, 6, "liuwe",  15);
	dll_show(&node);
	dll_insert(&node, 5, "liuwei", 5);
	dll_show(&node);

	return EXIT_SUCCESS;
}
