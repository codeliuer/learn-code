#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <aio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    long aio_listio_max = sysconf(_SC_LISTIO_MAX);

    printf("%ld\n", aio_listio_max);

    printf("AIO_LISTIO_MAX = %d\n", AIO_LISTIO_MAX);

    return EXIT_SUCCESS;
}
