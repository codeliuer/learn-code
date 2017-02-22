#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/select.h>


int main(int argc, char *argv[])
{
    printf("sizeof(fd_set) = %ld\n", sizeof(fd_set));
    printf("FD_SETSIZE = %d\n", FD_SETSIZE);

    return EXIT_SUCCESS;
}
