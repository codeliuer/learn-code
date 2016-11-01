#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char * argv[])
{
    int fd = 0;
    char buffer[] = "test write";

    fd = open("test", O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    write(fd, buffer, strlen(buffer));

    close(fd);

    return EXIT_SUCCESS;
}
