#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    char ch = 0;

    fd = open("./test.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    while (read(fd, (void *)&ch, 1) > 0)
    {
        printf("ch = %d\n", ch);
    }

    return EXIT_SUCCESS;
}
