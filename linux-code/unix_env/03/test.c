#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>


//#define STRING_TEST
#if defined(STRING_TEST)
const char str1[BUFSIZ] = "test";
#endif  //STRING_TEST


#define BIG_NUM         (0xFFFFFFFFL)


static void
test_sched(void)
{
#define TEST_SCHED
#if defined(TEST_SCHED)
    pthread_attr_t attr;
    struct sched_param param;

    printf("min = %d\n", sched_get_priority_min(SCHED_OTHER));
    printf("max = %d\n", sched_get_priority_max(SCHED_OTHER));

    printf("min = %d\n", sched_get_priority_min(SCHED_FIFO));
    printf("max = %d\n", sched_get_priority_max(SCHED_FIFO));

    printf("min = %d\n", sched_get_priority_min(SCHED_RR));
    printf("max = %d\n", sched_get_priority_max(SCHED_RR));

    pthread_attr_init(&attr);
    pthread_attr_getschedparam(&attr, &param);
    printf("default priority = %d\n", param.sched_priority);
#endif  //TEST_SCHED
}


static void
test_fcntl_fd(void)
{
//#define TEST_FCNTL_FD
#if defined(TEST_FCNTL_FD)
    int fd;
    int retfd;
    int fdfd;

    fd = open("log", O_RDWR|O_CLOEXEC);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return;
    }

    printf("fd = %d\n", fd);

    retfd = fcntl(fd, F_DUPFD, 10);
    printf("retfd = %d\n", retfd);
    printf("FD_CLOEXEC = %d\n", FD_CLOEXEC);
    printf("%d\n", fcntl(retfd, F_GETFD, 0));

    fdfd = fcntl(fd, F_DUPFD_CLOEXEC, 20);
    printf("fdfd = %d\n", fdfd);
    printf("%d\n", fcntl(fdfd, F_GETFD, 0));
#endif  //TEST_fcnTL_FD
}


static void
test_dir(void)
{
//#define TEST_DIR
#if defined(TEST_DIR)
    int fd;
    struct stat st;

    errno = 0;
    fd = open("../../unix_env", O_RDONLY);
    if (fd < 0)
    {
        perror("../01");
        return;
    }

    fstat(fd, &st);
    printf("%ld\n", st.st_size);
#endif  //TEST_DIR
}


static void 
test_ftruncate(void)
{
//#define TEST_FTRUNCATE
#if defined(TEST_FTRUNCATE)

#define TEST_FILE           "log"
    int fd = 0;
    struct stat st;

    fd = open(TEST_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return;
    }

    fstat(fd, &st);
    printf("blocks = %ld\n", st.st_blocks);

    ftruncate(fd, 1024*1024);
    fstat(fd, &st);
    printf("blocks = %ld\n", st.st_blocks);

    write(fd, "aaaaaaaaaa", 10);
    fstat(fd, &st);
    printf("blocks = %ld\n", st.st_blocks);

#endif  //TEST_FTRUNCATE
}


static void 
test_dup(void)
{
//#define TEST_DUP
#if defined(TEST_DUP)
#define TEST_LOG        "log"
    int fd = open(TEST_LOG, O_RDWR);
    
    int oldfd = dup(fd);
    int newfd = dup(fd);

    write(fd, "aaaaaaaa", 8);
    write(oldfd, "bbbbbbbb", 8);
    write(newfd, "ccccccccc", 8);
#endif  //TEST_DUP
}


static void 
test_pread_write(void)
{
//#define TEST_READ_WRITE
#if defined(TEST_READ_WRITE)

#define TEST_FILE           "log"
#define FILE_STATUS         (O_CREAT|O_RDWR)
#define FILE_MODE           (0666)
    int fd;
    char buf[BUFSIZ] = "";

    fd = open(TEST_FILE, FILE_STATUS, FILE_MODE);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return;
    }

    pread(fd, buf, 10, 20);
    printf("buf: %s\n", buf);
    pread(fd, buf, 10, 20);
    printf("buf: %s\n", buf);

    close(fd);
#endif  //TEST_READ_WRITE
}


static void 
test_big_num(void)
{
//#define TEST_BIG_NUM
#if defined(TEST_BIG_NUM)
    int a = BIG_NUM;
#endif  //TEST_BIG_NUM
}


static void
test_sem(void)
{
//#define TEST_SEM
#if defined(TEST_SEM)
    sem_t sem;
    printf("TEST_SEM\n");
    if (sem_init(&sem, 0, 1) < 0)
    {
        printf("sem\n");
    }

    printf("%d\n", sem_wait(&sem));
    printf("%d\n", sem_trywait(&sem));

#endif	//TEST_SEM
}

static void
test_copy(void)
{
//#define TEST_COPY
#if defined(TEST_COPY)
    int n = 0;
    char buffer[BUFSIZ] = "";

    while ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    {
        if (write(STDOUT_FILENO, buffer, n) != n)
        {
            perror("write");
            return;
        }
    }
#endif  //TEST_COPY
}


static void
true_env(void)
{
//#define TRUE_ENV
#if defined(TRUE_ENV)
    printf("_POSIX_V7_ILP32_OFF32 = %ld\n", sysconf(_SC_V7_ILP32_OFF32));
    printf("_POSIX_V7_ILP32_OFFBIG = %ld\n", sysconf(_SC_V7_ILP32_OFFBIG));
    printf("_POSIX_V7_LP64_OFF64 = %ld\n", sysconf(_SC_V7_LP64_OFF64));

    printf("_POSIX_V6_ILP32_OFF32 = %ld\n", sysconf(_SC_V6_ILP32_OFF32));
    printf("_POSIX_V6_ILP32_OFFBIG = %ld\n", sysconf(_SC_V6_ILP32_OFFBIG));
    printf("_POSIX_V6_LP64_OFF64 = %ld\n", sysconf(_SC_V6_LP64_OFF64));
//    printf("_POSIX_V6_LP64_OFFBIG = %ld\n", sysconf(_SC_V6_LP64_OFFBIG));

//    printf("_FILE_OFFSET_BITS = %d\n", _FILE_OFFSET_BITS);
//    printf("_POSIX_V7_LP64_OFFBIG = %ld\n", sysconf(_SC_V7_LP64_OFFBIG));
#endif  //TRUE_ENV
}

static void
test_basemacro(void)
{
//#define BASEMACRO
#if defined(BASEMACRO)
    printf("sizeof(SSIZE_MAX) = %ld, SSIZE_MAX = %ld\n", sizeof(SSIZE_MAX), SSIZE_MAX);
    printf("%lu\n", 0xFFFFFFFFFFFFFFFF);
#endif  //BASEMACRO
}

int
main(int argc, char* argv[])
{
//#define _TEST_STDOUT
#if defined(_TEST_STDOUT)
    int fd = 0;

    close(STDOUT_FILENO);

    errno = 0;
    fd = open("test", O_CREAT|O_RDWR|O_TRUNC|O_EXCL, 0666);
    if (fd < 0)
    {
        fprintf(stderr, "file: %s, line = %d, test: %s\n", __func__, __LINE__, strerror(errno));
        return EXIT_FAILURE;
    }

    errno = 0;
    write(fd, "nimeide\n", strlen("nimeide\n"));
    printf("test111111111111111");
    printf("test111111111111111");
    printf("test111111111111111");
    close(fd);
#endif  //_TEST_STDOUT

//#define TRUNC_FILE_NAME
#if defined(TRUNC_FILE_NAME)
    printf("NAME_MAX = %d, NAME_MAX = %ld\n", NAME_MAX, pathconf("/", _PC_NAME_MAX));
    printf("PATH_MAX = %d, PATH_MAX = %ld\n", PATH_MAX, pathconf("/", _PC_PATH_MAX));
    printf("_POSIX_NO_TRUNC = %d\n", _POSIX_NO_TRUNC);
#endif  //TRUNC_FILE_NAME

#if defined(STRING_TEST)
    static int num = 0;
    static char string[BUFSIZ] = "aaaa";

    printf("&num = %p, string: %p\n", &num, string);
    printf("str1 = %p\n", str1);
#endif  //STRING_TEST

    true_env();
    test_basemacro();
    test_copy();
    test_sem();
    test_big_num();
    test_pread_write();
    test_dup();
    test_ftruncate();
    test_dir();
    test_fcntl_fd();
    test_sched();

    return EXIT_SUCCESS;
}
