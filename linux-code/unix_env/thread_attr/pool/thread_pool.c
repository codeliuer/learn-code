#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


static void thread_pool_init(int max)
{
    int i = 0;
    int num = 0;
    pthread_t thid;

    for (i = 0; i < max; i++)
    {
        if (pthread_create(&thid, NULL, thread_pool, NULL) != 0)
        {
        }
    }
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
