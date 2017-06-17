#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int token = 0x010203;
    int fd = 0;

    fd = open("./test.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    if (write(fd, (const char *)&token, 3) != 3)
    {
        perror("write failure: ");
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}
