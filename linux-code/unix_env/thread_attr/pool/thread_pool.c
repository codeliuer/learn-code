#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


#define THREAD_MAX_NUMBER           (10)


typedef struct task
{
} task_t;

typedef struct task_cnt
{
} task_cnt_t;


static void thread_pool_init(int max)
{
    int i = 0;
    int suc_num = 0;
    int fal_num = 0;
    pthread_t thid;

    for (i = 0; i < max; i++)
    {
        if (pthread_create(&thid, NULL, thread_pool, NULL) != 0)
        {
            fal_num += 1;
            fprintf(stderr, "thread init failure, number = %d\n", fal_num);
            continue;
        }

        suc_num += 1;
    }
    printf("success thread number = %d\n", suc_num);
}


int main(int argc, char *argv[])
{
    thread_pool_init(THREAD_MAX_NUMBER);

    return EXIT_SUCCESS;
}
