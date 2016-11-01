#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char* argv[])
{
    char buffer[BUFSIZ] = "";

    int fd = open("test", O_CREAT|O_EXCL|O_RDWR, 0666);
    if (fd < 0)
    {
        dprintf(STDERR_FILENO, "open test failure\n");
        return EXIT_FAILURE;
    }
    unlink("test");

    dprintf(fd, "test infomation\n");
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, sizeof(buffer));
    dprintf(STDOUT_FILENO, "%s", buffer);

    dprintf(STDOUT_FILENO, "%-10.8s\n", "1234567890abcdefghijk");
    dprintf(STDOUT_FILENO, "%-10.8lf\n", 123456789012345.123456789235424);
    dprintf(STDOUT_FILENO, "% 10.8ld\n", 12345678901234123);
    dprintf(STDOUT_FILENO, "% 10.8ld\n", -12345678901234123);
    dprintf(STDOUT_FILENO, "%'d\n", 12345678);

    return EXIT_SUCCESS;
}
