#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "task.h"
#include "task_struct.h"
#include "thread_pool.h"


#define forever_true()      for (;;)


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static void *thread_task(void *arg)
{
    struct task_struct *task = NULL;

    forever_true()
    {
        pthread_mutex_lock(&lock);
        while (task == NULL && (task = (struct task_struct *)task_remove()) == NULL)
        {
            pthread_cond_wait(&cond, &lock);
            printf("========================ressume thread=======================\n");
        }
        pthread_mutex_unlock(&lock);

        task->task(task->arg);
    }

    pthread_exit(NULL);
}


int thread_pool_init(int num)
{
    int i = 0;
    pthread_t thid;

    for (i = 0; i < num; i++)
    {
        pthread_create(&thid, NULL, thread_task, NULL);
    }

    return EXIT_SUCCESS;
}


int thread_pool_destroy(void)
{
    return EXIT_SUCCESS;
}
