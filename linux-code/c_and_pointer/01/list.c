#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define RAND_RANGE_MAX          (100+1)


struct LIST
{
    void *data;
    struct LIST *next;
};


static struct LIST *listhead = NULL;


void add_list(struct LIST *list)
{
    struct LIST *tmp = NULL;

    if (listhead == NULL)
    {
        listhead = list;
        return ;
    }

    for (tmp = listhead; tmp->next != NULL; tmp = tmp->next)
    {
        ;
    }

    tmp->next = list;
}

static void *create_data(void)
{
    static int rand_seed = 0;

    if (rand_seed == 0)
    {
        srand(time(NULL));
        rand_seed = !rand_seed;
    }

    return (void *)(long int)(rand() % RAND_RANGE_MAX);
}

static struct LIST *make_node(void)
{
    struct LIST *list = (struct LIST *)malloc(sizeof(*list));
    if (list == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        return NULL;
    }

    list->data = create_data();
    list->next = NULL;

    return list;
}


static void show_list(void)
{
    struct LIST *tmp = NULL;

    for (tmp = listhead; tmp != NULL; tmp = tmp->next)
    {
        printf(" -- %d", *(int *)&tmp->data);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    add_list(make_node());
    show_list();

    return EXIT_SUCCESS;
}
