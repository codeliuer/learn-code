#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("thread quit max number = %d\n", sysconf(_SC_THREAD_DESTRUCTOR_ITERATIONS));
    printf("");

    return EXIT_SUCCESS;
}
