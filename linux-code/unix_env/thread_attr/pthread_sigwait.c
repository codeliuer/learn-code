#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>
#include <pthread.h>


static sigset_t set;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int quitflag = 0;


static void *thread_func(void *arg)
{
    int ret = 0;
    int signo = 0;

    for (;;)
    {
        ret = sigwait(&set, &signo);
        if (ret < 0)
        {
            fprintf(stderr, "sigwait failure\n");
            pthread_exit(NULL);
        }

        switch (signo)
        {
        case SIGINT:
            printf("\ninterrupt\n");
            break;

        case SIGQUIT:
            printf("thread_quit\n");
            pthread_mutex_lock(&lock);
            quitflag = 1;
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    sigset_t oset;

    pthread_t thid;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    pthread_sigmask(SIG_BLOCK, &set, &oset);

    pthread_create(&thid, NULL, thread_func, NULL);

    pthread_mutex_lock(&lock);
    while (quitflag == 0)
    {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);

    return EXIT_SUCCESS;
}
