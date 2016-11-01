#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>
#include <sys/utsname.h>


int
main(int argc, char* argv[])
{
    struct utsname name;
    char hostname[HOST_NAME_MAX] = "";

    uname(&name);

    printf("sysname: %s\n", name.sysname);
    printf("nodename: %s\n", name.nodename);
    printf("release: %s\n", name.release);
    printf("version: %s\n", name.version);
    printf("machine: %s\n", name.machine);

    gethostname(hostname, sizeof(hostname));
    printf("hostname: %s\n", hostname);
    printf("HOST_NAME_MAX = %d\n", HOST_NAME_MAX);

    return EXIT_SUCCESS;
}
