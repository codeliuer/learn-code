#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>


#define K               (1024)
#define M               (K * K)


#define TEST_LEN        (8 * M)


#define TEST_FILE       "test.hole"


int
main(int argc, char* argv[])
{
    struct stat st;

    int fd = open(TEST_FILE, O_CREAT|O_RDWR, 0666);
    if (fd < 0)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    lseek(fd, TEST_LEN, SEEK_SET);

    write(fd, "1234567890", strlen("1234567890"));

    close(fd);

    stat(TEST_FILE, &st);

    printf("%ld\n", st.st_blksize);

    return EXIT_SUCCESS;
}
