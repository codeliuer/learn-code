#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define pthread_private_val (*(unsigned int *)__pthread_private_val())


int pthread_private_val;


int main(int argc, char *argv[])
{


    return EXIT_SUCCESS;
}
