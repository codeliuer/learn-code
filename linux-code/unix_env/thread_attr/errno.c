#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define private_val (*__private_localtion())


static int private_val;

static pthread_key_t process_key;
static pthread_once_t once = PTHREAD_ONCE_INIT;


static void my_free(void *arg)
{
    printf("arg = %p\n", arg);

    free(arg);
}

static void create_only_key(void)
{
    pthread_key_create(&process_key, my_free);
}

static int *__private_localtion(void)
{
    int *value = NULL;

    pthread_once(&once, create_only_key);
    if ((value = (int *)pthread_getspecific(process_key)) == NULL)
    {
        value = (int *)malloc(sizeof(int));
        printf("value = %p\n", value);
        pthread_setspecific(process_key, value);
    }

    return value;
}

static void *thread_func(void *arg)
{
    private_val = 0;
    printf("thread id %ld, private_val = %d\n", pthread_self(), private_val);

    private_val = 10;
    printf("thread id %ld, private_val = %d\n", pthread_self(), private_val);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;

    pthread_create(&thid, NULL, thread_func, NULL);
    private_val = 11;
    printf("thread id %ld, private_val = %d\n", pthread_self(), private_val);

    pthread_exit(NULL);
}
