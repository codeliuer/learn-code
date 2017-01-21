#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "task_struct.h"
#include "thread_pool.h"


int main(int argc, char *argv[])
{
    thread_pool_init(10);

    thread_pool_destroy();

    return EXIT_SUCCESS;
}
