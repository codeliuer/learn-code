#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	LIST_HEAD_INIT(list)			{&list; &list}
#define	LIST_HEAD(head)					(struct list_head head = LIST_HEAD_INIT(head))

#define	offsetof(type, member)			(unsigned int)&(((type *)0)->member)
#define	container_of(ptr, type, member) (type *)((char *)ptr - offsetof(type, member))



struct list_head
{
	struct list_head	*next;
	struct list_head	*prev;
};


typedef struct NODE
{
	char				*name;
	int					age;
	struct list_head	list;
} NODE;


static void
__list_add(struct list_head* this, struct list_head* prev, struct list_head* next)
{
	this->next = next;
	prev->next = this;
	this->prev = prev;
	next->prev = this;
}

struct void
list_add(struct list_head* new, struct list_head* head)
{
	__list_add(new, head->prev, head);
}


int
main(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}
