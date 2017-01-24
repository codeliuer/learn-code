#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


static void thread_pool_init(int max)
{
    int i = 0;
    pthread_t thid;

    for (i = 0; i < max; i++)
    {
        pthread_create();
    }
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
