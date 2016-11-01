#ifndef		__LIST_H__
#define		__LIST_H__


#include "type.h"


#define	LIST_HEAD_INIT(head)		{&head, &head}
#define	LIST_HEAD(head)				\
	struct list_head head = LIST_HEAD_INIT(head)

static inline void
INIT_LIST_HEAD(struct list_head* this)
{
	this->prev = this;
	this->next = this;
}

static inline void 
__list_add(struct list_head* this, struct list_head* prev, struct list_head* next)
{
	this->next = next;
	prev->next = this;
	this->prev = prev;
	next->prev = this;
}


/*
** 
*/
static inline void
list_add(struct list_head* new, struct list_head* head)
{
	__list_add(new, head, head->next);
}


static inline void
list_add_tail(struct list_head* new, struct list_head* tail)
{
	__list_add(new, tail->prev, tail);
}

static inline void
__list_del(struct list_head* prev, struct list_head* next)
{
	prev->next = next;
	next->prev = prev;
}


static inline void
list_del_current(struct list_head* current)
{
	__list_del(current->prev, current->next);
}

#define	offsetof(type, member)								\
		(unsigned long)&(((type *)0)->member)

#define	container_of(ptr, type, member)						\
		(type *)((char *)ptr - offsetof(type, member))

#define	list_entry(ptr, type, member)						\
		container_of(ptr, type, member)

#define list_for_each(pos, head)							\
	for (pos = (head)->next; pos != (head); pos = pos->next)

#define	list_for_safe_each(pos, n, head)					\
	for (pos = (head)->next, n = pos->next; pos != (head);  \
			pos = pos->next, n = pos->next)	


#endif	//__LIST_H__
