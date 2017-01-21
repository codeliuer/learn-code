#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "task_struct.h"
#include "thread_pool.h"


#define MAX             (100)


static void *func(void *arg)
{
    int data = *(int *)arg;

    printf("data = %d\n", data);
}

int main(int argc, char *argv[])
{
    int i = 0;
    struct task_struct *task = (struct task_struct *)malloc(sizeof(*task));

    thread_pool_init(10);

    for (i = 0; i < MAX; i++)
    {
        task->task = func;
        task->arg = (void *)(long)i;

        task_insert(&task);

        pthread_cond_signal(&cond);
    }

    sleep (10);

    thread_pool_destroy();

    return EXIT_SUCCESS;
}
