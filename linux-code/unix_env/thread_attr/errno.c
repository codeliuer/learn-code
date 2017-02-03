#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define private_val (*__private_localtion())


static int private_val;

static pthread_key_t thread_key;


static int *__private_localtion(void)
{
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
