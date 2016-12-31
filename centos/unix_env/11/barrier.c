#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT            (8)


static pthread_barrier_t barrier;


int main(int argc, char *argv[])
{
    int count = THREAD_COUNT;

    pthread_barrier_init(&barrier, NULL, count);
    pthread_barrier_

    return EXIT_SUCCESS;
}
