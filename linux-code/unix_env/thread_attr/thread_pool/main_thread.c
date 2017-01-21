#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "task_struct.h"
#include "thread_pool.h"


static void *func(void *arg)
{
    int data = *(int *)arg;

    printf("data = %d\n", data);
}

int main(int argc, char *argv[])
{
    struct task_struct task;

    thread_pool_init(10);

    thread_pool_destroy();

    return EXIT_SUCCESS;
}
