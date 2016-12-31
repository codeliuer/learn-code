#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static pthread_barrier_t barrier;


int main(int argc, char *argv[])
{
    pthread_barrier_init(&barrier, NULL);

    return EXIT_SUCCESS;
}
