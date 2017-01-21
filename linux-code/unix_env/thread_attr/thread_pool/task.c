/*****************************************************
 *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>

#include "task.h"


struct task
{
    void *task;
    struct task *next;
};

struct task_queue
{
    struct task *m_head;
    int m_count;
    pthread_mutex_t m_lock;
};


static struct task_queue queue_info = 
{
    .m_head  = NULL,
    .m_count = 0,
    .m_lock  = PTHREAD_MUTEX_INITIALIZER,
};

int task_init(void)
{
    return EXIT_SUCCESS;
}

int task_destroy(void)
{
    return EXIT_SUCCESS;
}

int task_insert(void *task)
{
    struct task *node = (struct task *)malloc(sizeof(*node));
    node->task = task;

    pthread_mutex_lock(&queue_info.m_lock);
    printf("get lock success\n");

    node->next = queue_info.m_head;
    queue_info.m_head = node;

    queue_info.m_count += 1;

    pthread_mutex_unlock(&queue_info.m_lock);
    printf("quit lock success\n");

    return EXIT_SUCCESS;
}

int task_append(void *task)
{
    struct task **phead = NULL;

    struct task *node = (struct task *)malloc(sizeof(*node));
    node->task = task;

    pthread_mutex_lock(&queue_info.m_lock);

    phead = &queue_info.m_head;
    while (*phead != NULL)
    {
        phead = &(*phead)->next;
    }
    *phead = node;

    pthread_mutex_lock(&queue_info.m_lock);

    return EXIT_SUCCESS;
}

void *task_remove(void)
{
    void *data = NULL;
    struct task *task = NULL;

    pthread_mutex_lock(&queue_info.m_lock);

    if ((task = queue_info.m_head) == NULL)
    {
        fprintf(stderr, "queue is empty\n");
        pthread_mutex_unlock(&queue_info.m_lock);

        return NULL;
    }

    queue_info.m_head = queue_info.m_head->next;

    data = task->task;

    pthread_mutex_unlock(&queue_info.m_lock);

    free(task);
    task = NULL;

    return task;
}
