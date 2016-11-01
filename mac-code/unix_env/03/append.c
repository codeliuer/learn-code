#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


#define TEST_FILE               "log"
#define FILE_STATUS             (O_CREAT|O_RDWR|O_APPEND)
#define FILE_MODE               (0666)


#define THREAD1_STRING          "3333333333333333333333"
#define THREAD2_STRING          "4444444444444444444444"


#define forever_true()          (1)


static void *
thread1(void* arg)
{
    const int fd = *(const int *)arg;

    lseek(fd, 0, SEEK_END);
    sleep(1);

    write(fd, THREAD1_STRING, strlen(THREAD1_STRING));
}

static void *
thread2(void* arg)
{
    const int fd = *(const int *)arg;

    lseek(fd, 0, SEEK_END);
    sleep(1);

    write(fd, THREAD2_STRING, strlen(THREAD2_STRING));
}

static void 
write_double_thread(const int* pfd)
{
    pthread_t pthid;

    pthread_create(&pthid, NULL, thread1, pfd);
    pthread_create(&pthid, NULL, thread2, pfd);
}


int
main(int argc, char* argv[])
{
    int fd = open(TEST_FILE, FILE_STATUS, FILE_MODE);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failure\n", TEST_FILE);
        return EXIT_FAILURE;
    }

    write_double_thread(&fd);

    sleep(3);

    close(fd);

    return EXIT_SUCCESS;
}
