#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>

#include "task_queue.h"


typedef struct task_queue
{
    task_t *task;
    int count;
    pthread_mutex_t lock;
} task_queue_t;


static pthread_mutex_t global = PTHREAD_MUTEX_INITIALIZER;

static task_queue_t *queue = NULL;

int task_init(void)
{
    pthread_mutex_lock(&global);

    if (queue != NULL)
    {
        fprintf(stderr, "task queue inited\n");
        pthread_mutex_unlock(&global);   

        return TASK_ERRCODE_INITED;
    }

    queue = (task_queue_t *)malloc(sizeof(*queue));
    if (queue == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        pthread_mutex_unlock(&global);

        return TASK_ERRCODE_ALLOC;
    }


    if (pthread_mutex_init(&queue->lock, NULL))
    {
        fprintf(stderr, "mutex init failure\n");
        free(queue), queue = NULL;
        pthread_mutex_unlock(&global);

        return TASK_ERRCODE_FAIL;
    }

    pthread_mutex_unlock(&global);

    queue->task = NULL;
    queue->count = 0;

    return TASK_ERRCODE_SUCCESS;
}


int task_destroy(void)
{
}
