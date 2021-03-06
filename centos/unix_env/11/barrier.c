#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT            (8)

#define MAX_RANGE               (80000000)


static pthread_barrier_t barrier;


static int cmp(const void *data1, const void *data2)
{
    return *(const int *)data1 - *(const int *)data2;
}

static void product_data(void)
{
    int i = 0;
    int *data = malloc(sizeof(int) * MAX_RANGE);

    for (i = 0; i < MAX_RANGE; i++)
    {
        data[i] = rand() % MAX_RANGE+1;
    }

    qsort(data, MAX_RANGE, sizeof(int), cmp);
}

static void *thread(void *arg)
{
    qsort(arg, MAX_RANGE/THREAD_COUNT, sizeof(int), cmp);
    pthread_barrier_wait(&barrier);

    printf("thread id = %d\n", pthread_self());

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int i = 0;
    int count = THREAD_COUNT;
    pthread_t thid[THREAD_COUNT];
    int *data = malloc(sizeof(int) * MAX_RANGE);

//    product_data();

    pthread_barrier_init(&barrier, NULL, count+1);

    for (i = 0; i < count; i++)
    {
        pthread_create(&thid[i], NULL, thread, data+i*(MAX_RANGE/count));
    }

    pthread_barrier_wait(&barrier);

    pthread_barrier_destroy(&barrier);

    return EXIT_SUCCESS;
}
