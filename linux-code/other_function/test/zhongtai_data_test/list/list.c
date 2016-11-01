/*
** list install delete enter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


typedef struct PERSON
{
    char           *name;
    int             age;
    struct PERSON  *next;
} PERSON;


static PERSON *
make_node(char *name, int age)
{
    PERSON *tmp = malloc(sizeof(*tmp));
    if (tmp == NULL)
    {
        printf("%s[%d]  memory failure\n", __func__, __LINE__);
        return NULL;
    }

    tmp->name = name;
    tmp->age = age;
    tmp->next = NULL;

    return tmp;
}


int
insert_info(PERSON **pphead, char *name, int age)
{
    int cmp = 0;
    PERSON *new = NULL;

    if (pphead == NULL || name == NULL)
    {
        return LIST_DATA_PARAM;
    }

    while ((*pphead != NULL) && (cmp = strcmp((*pphead)->name, name)) < 0)
    {
        pphead = &(*pphead)->next;
    }

    if (*pphead == NULL || cmp != 0)
    {
        new = make_node(name, age);

        new->next = *pphead;
        *pphead = new;

        return LIST_DATA_SUCCESS;
    }
    else
    {
        return LIST_DATA_EXIST;
    }
}


static int 
cmp(PERSON *person, void *data, int type)
{
    if (type == NAME_F)
    {
        return strcmp(person->name, *(char **)&data);
    }
    else if (type == AGE_F)
    {
        return person->age - *(int *)&data;
    }
}


int 
delete_info(PERSON **pphead, void *data, int type)
{
    PERSON *tmp = NULL;

    if (pphead == NULL || data == NULL || ((type < 0) && (type >= MAX_F)))
    {
        return LIST_DATA_PARAM;
    }

    while (*pphead != NULL && cmp(*pphead, data, type) != 0)
    {
        pphead = &(*pphead)->next;
    }

    if (*pphead == NULL)
    {
        return LIST_DATA_NO_EXIST;
    }
    else
    {
        tmp = *pphead;
        *pphead = tmp->next;

        free(tmp), tmp = NULL;

        return LIST_DATA_SUCCESS;
    }
}


int
print_info(PERSON *phead)
{
    if (phead == NULL)
    {
        return LIST_DATA_PARAM;
    }

    while (phead != NULL)
    {
        printf("name: %-12s arg = %-4d\n", phead->name, phead->age);
        phead = phead->next;
    }
}
