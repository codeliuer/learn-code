#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define USER_ID         (1)


int
main(int argc, char *argv[])
{
    if (setuid(USER_ID) == 0)
    {
        printf("success\n");
    }
    else
    {
        printf("failure\n");
    }

    printf("%d\n", getuid());

    return EXIT_SUCCESS;
}
