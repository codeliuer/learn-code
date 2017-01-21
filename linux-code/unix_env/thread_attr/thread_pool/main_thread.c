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
    struct task_struct task;

    thread_pool_init(10);

    for (i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&lock);
        pthread_mutex_unlock(&lock);
    }

    thread_pool_destroy();

    return EXIT_SUCCESS;
}
