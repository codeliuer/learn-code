#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>
#include <pthread.h>


int
main(int argc, char *argv[])
{
    printf("%d\n", pthread_kill(pthread_self(), 0));
    printf("%d\n", pthread_kill(pthread_self()-1, 0));
    printf("EINVAL = %d\n", EINVAL);
    printf("ESRCH = %d\n", ESRCH);

    return EXIT_SUCCESS;
}
