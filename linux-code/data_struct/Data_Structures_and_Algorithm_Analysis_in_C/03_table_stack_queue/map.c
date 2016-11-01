#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAP_SUCCESS             (0)
#define MAP_RANGE               (1)
#define MAP_OVER                (2)

/* set flag */
#define F_EMPTY                 (0)
#define F_FULL                  (1)

#define OUT                     (0)
#define IN                      (1)


typedef struct LIST
{
    int             start;
    int             end;
    struct LIST     *prev;
    struct LIST     *next;
} LIST;

typedef struct NODE
{
    char            *arr;
    int             n;
    int             nodes;
    LIST            *head;
    int (* PF_alloc)(char **, int);
    int (* PF_insert)(char *, int, int, int);
    int (* PF_check)(char *, int, int *);
    int (* PF_show)(char *, int);
    int (* PF_to_list)(LIST **, char *, int);
    int (* PF_to_show)(LIST *);
} NODE;


static int 
alloc(char **pp, int n)
{
    *pp = (char *)malloc(n);
    assert(*pp != NULL);

    return MAP_SUCCESS;
}


static int 
insert(char *arr, int n, int start, int end)
{
    int i = 0;

    if (start > n || end > n)
    {
        return MAP_RANGE;
    }

    for (i = start; i <= end; i++)
    {
        arr[i-1] = F_FULL;
    }

    return MAP_SUCCESS;
}


static int 
check(char *arr, int n, int *pnode)
{
    int i = 0;
    int flag = OUT;

    *pnode = 0;
    for (i = 0; i < n; i++)
    {
        if (flag == OUT && arr[i] == F_FULL)
        {
            *pnode += 1;
            flag = IN;
        }
        else if (flag == IN && arr[i] != F_FULL)
        {
            flag = OUT;
        }
    }

    return MAP_SUCCESS;
}


static int 
show(char *arr, int n)
{
    int i = 0;
    int start = 0;
    int end = 0;

    for (i = 0; i < n; i++)
    {
        if (start == 0 && arr[i] == F_FULL)
        {
            start = i+1;
        }
        else if (start != 0 && arr[i] != F_FULL)
        {
            end = i;
            printf("[%d----%d]  ", start, end);
            start = 0, end = 0;
        }
    }

    if (start != 0)
    {
        end = n;
        printf("[%d----%d]  ", start, end);
    }
    printf("\n");

    return MAP_SUCCESS;
}


static int 
get_range(char *arr, int n, int *start, int *end)
{
    return MAP_SUCCESS;
}

static int 
to_list(LIST **pphead, char *arr, int n)
{
    int ret = 0;
    int start = 0;
    int end = 0;

    while (*pphead != NULL && (ret = get_range(arr, n, &start, &end)) != MAP_OVER)
    {
    }

    return MAP_SUCCESS;
}


static int 
to_show(LIST *phead)
{
    int flag = 0;

    while (phead != NULL)
    {
        flag++;
        printf("[%d----%d]  ", phead->start, phead->end);
        phead = phead->next;
    }

    if (flag)
    {
        printf("\r\n");
    }

    return MAP_SUCCESS;
}


static NODE node = 
        {
            NULL, 100, 0, NULL, 
            alloc,          /* memory */ 
            insert,         /* array insert */
            check,          /* check number */
            show,           /* array show */
            to_list,        /* transition to list */
            to_show,        /* list show */
        };


int
main(int argc, char * argv[])
{
    node.PF_alloc(&node.arr, node.n);
    node.PF_insert(node.arr, node.n, 1, 10);
    node.PF_insert(node.arr, node.n, 1, 2);
    node.PF_insert(node.arr, node.n, 11, 12);
    node.PF_insert(node.arr, node.n, 20, 29);
    node.PF_insert(node.arr, node.n, 40, 50);
    node.PF_insert(node.arr, node.n, 31, 39);
    node.PF_check(node.arr, node.n, &node.nodes);
    node.PF_show(node.arr, node.n);
    node.PF_to_show(node.head);

    return EXIT_SUCCESS;
}
