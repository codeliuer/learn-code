#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT            (8)

#define MAX_RANGE               (10000000)


static pthread_barrier_t barrier;


static void product_data(void)
{
}

int main(int argc, char *argv[])
{
    int count = THREAD_COUNT;

    product_data();

//    pthread_barrier_init(&barrier, NULL, count);

//    pthread_barrier_destroy(&barrier);

    return EXIT_SUCCESS;
}
