#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


static pthread_key_t  thread_key;
static pthread_once_t once = PTHREAD_ONCE_INIT;


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
