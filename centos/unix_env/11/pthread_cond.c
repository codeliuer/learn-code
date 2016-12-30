#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct work
{
    struct work         *next;
    void *(* action)(void *);
    void                *arg;
} work_t;


static work_t *work = NULL;

void process_msg(void)
{
    void *arg = NULL;
    void *(* action)(void *) = NULL;

    pthread_mutex_lock(&lock);

    while (work == NULL)
    {
        pthread_cond_wait(&cond, &lock);

        action = work->action;
        arg = work->arg;

        work = work->next;

        action(arg);
    }

    pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
