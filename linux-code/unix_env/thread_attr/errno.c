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
    void *value = NULL;

    pthread_once(&once, create_only_key);
    if ((value = pthread_getspecific(process_key)) == NULL)
    {
    }
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
