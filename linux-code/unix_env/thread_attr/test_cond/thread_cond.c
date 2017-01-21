#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static void *thread_func(void *arg)
{
    pthread_mutex_lock(&lock);
    while (condition == 0)
    {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_lock
}


int main(int argc, char *argv[])
{


    return EXIT_SUCCESS;
}
