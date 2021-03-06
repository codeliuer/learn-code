#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


#define QUEUE_MAX           (100)


typedef struct NODE
{
    int             value;
    struct NODE     *left;
    struct NODE     *right;
} NODE;

typedef struct MAXQUE
{
    int             nums;
    int             max;
    NODE            *queue;
} MAXQUE;

static MAXQUE queue = {1, QUEUE_MAX, NULL};

static int push(int value)
{
    int i = 0;

    if (queue.nums < queue.max)
    {
        i = queue.nums++;

        while (i / 2 != 0 && queue.queue[i/2].value < value)
        {
            queue.queue[i].value = queue.queue[i/2].value;
            i /= 2;
        }

        queue.queue[i].value = value;

        return 0;
    }

    return 0;
}

static void show(void)
{
    int i = 0;

    for (i = 1; i < queue.nums; i++)
    {
        printf("%d", queue.queue[i].value);
        if (i + 1 != queue.nums)
        {
            printf("--");
        }
    }

    printf("\n");
}

static int pop(void)
{
    int i = 0;
    int j = 0;
    int index = --queue.nums;
    int retmax = queue.queue[1].value;

    int value = queue.queue[1].value = queue.queue[index].value;

    i = 1;
    while (i < index)
    {
        if (queue.queue[2*i].value > queue.queue[2*i+1].value)
        {
            queue.queue[i].value = queue.queue[2*i].value;
            j = i;
            i *= 2;
        }
        else
        {
            queue.queue[i].value = queue.queue[2*i+1].value;
            j = i;
            i = 2*i+1;
        }
    }

    queue.queue[j].value = value;

    return retmax;
}

static int init_queue(void)
{
    queue.queue = (NODE *)malloc(sizeof(NODE) * (QUEUE_MAX+1));
    if (queue.queue == NULL)
    {
        fprintf(stderr, "%s[%d] malloc failure\n", __func__, __LINE__);
        return -1;
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int i = 0;
    int data = 0;

    setbuf(stdout, NULL);

    init_queue();

    srand(time(NULL));   

    for (i = 0; i < 20; i++)
    {
        data = rand()%100+1;
        push(data);
        printf("%d", data);
        if (i+1 != 20)
        {
            printf("--");
        }
    }

    printf("\n");

    show();

    for (i = 0; i < 20; i++)
    {
        printf("%d", pop());
        if (i+1 != 20)
        {
            printf("--");
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
