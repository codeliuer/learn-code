#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "task.h"
#include "task_struct.h"


int main(int argc, char *argv[])
{
    thread_pool_init();

    return EXIT_SUCCESS;
}