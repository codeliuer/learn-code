#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "index.h"


#define	PUBLIC		//extern interface flag

#define	FALSE			(0)
#define	TRUE			(1)

struct DLL_LIST
{
	char*				string;
	struct DLL_LIST*	next;
};

struct SINGLE_LIST
{
	char				first;
	struct SINGLE_LIST*	next;
	struct DLL_LIST*	pdll;
};


static struct SINGLE_LIST*
get_single_node(char c)
{
	struct SINGLE_LIST* node = malloc(sizeof(*node));
	assert(node != NULL);

	node->first = c;
	node->next = NULL;
	node->pdll = NULL;

	return node;
}

static struct DLL_LIST*
get_dll_node(const char* word)
{
	struct DLL_LIST* node = malloc(sizeof(node));
	assert(node);

	node->string = strdup(word);
	node->next = NULL;

	return node;
}

static struct SINGLE_LIST*
insert_head(struct SINGLE_LIST** list, char c)
{
	struct SINGLE_LIST* node = get_single_node(c);

	node->next = *list;
	*list = node;

	return node;
}

static struct SINGLE_LIST* 
find_or_insert_head(struct SINGLE_LIST** list, char c)
{
	/* find head */
	while ((*list != NULL) && ((*list)->first <= c))
	{
		if ((*list)->first == c)
		{
			return *list;
		}

		list = &(*list)->next;
	}

	return insert_head(list, c);
}

static int 
is_condition_increase(const char* string, const char* word)
{
	return strcmp(string, word) <= 0 ? TRUE : FALSE;
}

static int 
is_condition_equal(const char* string, const char* word)
{
	return strcmp(string, word) == 0 ? TRUE : FALSE;
}

static void
insert_dll_insert(struct DLL_LIST** pphead, const char* word)
{
	struct DLL_LIST* node = NULL;

	while ((*pphead != NULL) && is_condition_increase((*pphead)->string, word))
	{
		if (is_condition_equal((*pphead)->string, word))
		{
			return;
		}

		pphead = &(*pphead)->next;
	}

	node = get_dll_node(word);
	node->next = *pphead;
	*pphead = node;
}

PUBLIC void 
insert_word(struct SINGLE_LIST** list, const char* word)
{
	struct DLL_LIST** pphead = NULL;
	struct SINGLE_LIST* node = NULL;

	node = find_or_insert_head(list, word[0]);
	pphead = &node->pdll;

	insert_dll_insert(pphead, word);
}


static void
print(struct DLL_LIST* head)
{
	while (head != NULL)
	{
		printf("%s\n", head->string);
		head = head->next;
	}
}

PUBLIC void
show(struct SINGLE_LIST* list)
{
	struct DLL_LIST* pdll = NULL;

	while (list != NULL)
	{
		print(list->pdll);
		list = list->next;
	}
}
