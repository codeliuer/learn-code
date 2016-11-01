#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#define FILE_NODE           O_CREAT|O_RDWR|O_TRUNC


char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";


static void
test_stat(const char* filename)
{
    struct stat st;

    if (stat(filename, &st) < 0)
    {
        perror("stat");
        return;
    }

#if defined(__APPLE__) && defined(__MACH__)
    printf("file size = %lld\n", st.st_size);
#elif defined(unix)
    printf("file size = %ld\n", st.st_size);
#endif	//platform
}


int
main(int argc, char* argv[])
{
    int fd;

    errno = 0;
    if ((fd = open("file.hole", FILE_NODE, 0666)) < 0)
    {
        perror(strerror(errno));
        return EXIT_FAILURE;
    }

    if (write(fd, buf1, 10) != 10)
    {
        perror(strerror(errno));
        return EXIT_FAILURE;
    }

    if (lseek(fd, 1024*1024*1024, SEEK_SET) == -1)
    {
        perror("lseek");
        return EXIT_FAILURE;
    }

    if (write(fd, buf2, 10) != 10)
    {
        perror("write");
        return EXIT_FAILURE;
    }

    close(fd);

    test_stat("file.hole");

    return EXIT_SUCCESS;
}
