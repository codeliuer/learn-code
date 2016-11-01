#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
    printf("original effective user id =  %d\n", geteuid());

    printf(setuid(0) == 0 ? "success\n" : "failure\n");
    printf("effective user id =  %d after setuid equal 0\n", geteuid());

    printf("process user id = %d\n", getuid());
    printf(setuid(getuid()) == 0 ? "success\n" : "failure\n");
    printf("effective user id =  %d after restore user id\n", geteuid());

    return EXIT_SUCCESS;
}
