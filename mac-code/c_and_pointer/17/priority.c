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
    if (queue.nums < queue.max)
    {
        queue.queue[queue.nums].value = value;
    }
}

static int pop(void)
{
    int i = 0;
    int j = 0;
    int index = queue.nums--;
    int retmax = queue.queue[1].value;

    int value = queue.queue[1].value = queue.queue[index].value;

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
    

    return EXIT_SUCCESS;
}
