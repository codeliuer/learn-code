#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT            (8)

#define MAX_RANGE               (10000000)


static pthread_barrier_t barrier;


static int cmp(const void *data1, const void *data2)
{
    return *(const int *)data1 - *(const int *)data2;
}

static void product_data(void)
{
    int i = 0;
    int data[MAX_RANGE] = {0};

    for (i = 0; i < MAX_RANGE; i++)
    {
        data[i] = rand() % MAX_RANGE+1;
    }

    qsort(data, MAX_RANGE, sizeof(int), cmp);
}

int main(int argc, char *argv[])
{
    int count = THREAD_COUNT;

    product_data();

//    pthread_barrier_init(&barrier, NULL, count);

//    pthread_barrier_destroy(&barrier);

    return EXIT_SUCCESS;
}
