#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define pthread_private_val (*__pthread_private_val())

static int *__pthread_private_val(void);

static pthread_once_t initflag = PTHREAD_ONCE_INIT;


static pthread_key_t key;

static void only_once(void)
{
    int *val = (int *)malloc(sizeof(*val));

    printf("here\n");

    pthread_key_create(&key, free);

    pthread_setspecific(key, val);
}


static int *__pthread_private_val(void)
{
    int *val = NULL;

    pthread_once(&initflag, only_once);

    val = (int *)pthread_getspecific(key);
    printf("thread id = %ld, val = %p\n", pthread_self(), val);

    return val;
}

static void *thread_func(void *arg)
{
    pthread_private_val = 10;

    printf("pthread_private_val = %d\n", pthread_private_val);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    
    pthread_private_val = 3;
    printf("line: %d pthread_private_val = %d\n", __LINE__, pthread_private_val);

    printf("main thread id = %ld\n", pthread_self());
    sleep(1);

    pthread_create(&thid, NULL, thread_func, NULL);

    pthread_exit(NULL);
//    return EXIT_SUCCESS;
}
