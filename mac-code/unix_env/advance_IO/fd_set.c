#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/select.h>


int main(int argc, char *argv[])
{
    printf("sizeof(fd_set) = %lu\n", sizeof(fd_set));

    return EXIT_SUCCESS;
}
