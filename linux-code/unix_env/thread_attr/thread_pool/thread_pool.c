#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>

#include "thread_pool.h"


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

int task_insert(struct task *task)
{
    pthread_mutex_lock(&queue_info.m_lock);

    task->next = queue_info.m_head;
    queue_info.m_head = task;

    queue_info.m_count += 1;

    pthread_mutex_unlock(&queue_info.m_lock);

    return EXIT_SUCCESS;
}

int task_append(struct task *task)
{
    struct task **phead = NULL;

    pthread_mutex_lock(&queue_info.m_lock);

    phead = &queue_info.m_head;
    while (*phead != NULL)
    {
        phead = &(*phead)->next;
    }
    *phead = task;

    pthread_mutex_lock(&queue_info.m_lock);

    return EXIT_SUCCESS;
}

struct task *task_remove(void)
{
    struct task *task = NULL;

    pthread_mutex_lock(&queue_info.m_lock);

    if ((task = queue_info.m_head) == NULL)
    {
        fprintf(stderr, "queue is empty\n");
        pthread_mutex_unlock(&queue_info.m_lock);

        return NULL;
    }

    queue_info.m_head = queue_info.m_head->next;
    task->next = NULL;

    pthread_mutex_unlock(&queue_info.m_lock);

    return task;
}
