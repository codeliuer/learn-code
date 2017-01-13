#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>


int main(int argc, char *argv)
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutex_attr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&mutex, &attr);

    return EXIT_SUCCESS;
}
