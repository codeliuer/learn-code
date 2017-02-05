#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <unistd.h>


#define TMP_FILE        "test.xxxx"


extern int errno;

int main(int argc, char *argv[])
{
    int fd = 0;
    pid_t pid = 0;

    fd = open(TMP_FILE, O_RDWR|O_CREAT, 0666);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failure\n", TMP_FILE);
        return EXIT_FAILURE;
    }

    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        printf("child process\n");

        sleep(1);

        errno = 0;
        if (write(fd, "test", 4) != 4)
        {
            fprintf(stderr, "write failure: msg %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        close(fd);

        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("parent process\n");

        close(fd);
    }

//    unlink(TMP_FILE);

    return EXIT_SUCCESS;
}
