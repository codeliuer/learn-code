#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int err;
    struct timespec tout;
    pthread_mutex_t lock;

    pthread_mutex_init(&lock);
    pthread_mutex_lock(&lock);



    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}
