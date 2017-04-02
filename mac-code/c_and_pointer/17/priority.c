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

static void push(int value)
{
}

static int pop(void)
{
    int i = 0;
    int index = queue.nums--;
    int value = queue.queue[1].value;

    int value = queue.queue[1].value = queue.queue[index].value;
    
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
