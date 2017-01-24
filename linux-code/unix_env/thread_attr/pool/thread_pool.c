#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


#define TRUE                        (1)

#define THREAD_MAX_NUMBER           (10)


typedef struct task
{
    void *(* func)(void *);
    void *arg;
    struct task *next;
} task_t;

typedef struct task_cnt
{
    pthread_cond_t cond;
    pthread_mutex_t lock;
    task_t task;
    int count;
} task_cnt_t;


static task_cnt_t task_cnt = 
{
    .cond  = PTHREAD_COND_INITIALIZER,
    .lock  = PTHREAD_MUTEX_INITIALIZER,
    .task  = {NULL, NULL, NULL}
    .count = 0,
};

static void thread_pool(void *arg)
{
    while (TRUE)
    {
        pthread_mutex_lock(&task_cnt.lock);
        while (task_cnt.count == 0)
        {
        }
        pthread_mutex_unlock(&task_cnt.lock);
    }

    pthread_exit(NULL);
}


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
