#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define pthread_private_val (*(unsigned int *)__pthread_private_val())


int pthread_private_val;
static pthread_once_t initflag = PTHREAD_ONCE_INIT;


static void only_once(void)
{
    int val = 0;
    pthread_key_t key;

    pthread_key_create(&key, free);

    pthread_setspecific(key, &val);
}


static void *pthread_private_val(void)
{
    void *val = NULL;

    pthread_once(&initflag, only_once);

    pthread_getspecific(key);
}


int main(int argc, char *argv[])
{


    return EXIT_SUCCESS;
}
