#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
    printf("pid = %d\n", getpid());
    printf("ppid = %d\n", getppid());
    printf("uid = %d\n", getuid());
    printf("euid = %d\n", geteuid());
    printf("gid = %d\n", getgid());
    printf("egid = %d\n", getegid());

    return EXIT_SUCCESS;
}
