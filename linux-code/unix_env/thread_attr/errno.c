#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define private_val (*__private_localtion())


static int private_val;

static pthread_key_t process_key;
static pthread_once_t once = PTHREAD_ONCE_INIT;


static void create_only_key(void)
{
    pthread_key_create(&process_key, free);
}

static int *__private_localtion(void)
{
    int *value = NULL;

    pthread_once(&once, create_only_key);
    if ((value = (int *)pthread_getspecific(process_key)) == NULL)
    {
        value = (int *)malloc(sizeof(int));
        pthread_setspecific(process_key, value);
    }

    return value;
}

static void *thread_func(void *arg)
{
    private_val = 0;
    printf("thread id %ld, private_val = %d\n", pthread_self(), private_val);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;

    pthread_create(&thid, NULL, thread_func, NULL);
    sleep(1);

    return EXIT_SUCCESS;
}
