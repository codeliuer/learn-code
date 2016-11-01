#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <linux/limits.h>


#define print(x)            printf(#x " = %#x\n", x)


static void
file_info(int fd)
{
//#define TEST_FILE_INFO
#if defined(TEST_FILE_INFO)
    struct stat st;

    errno = 0;
    if (fstat(fd, &st) < 0)
    {
        fprintf(stderr, "%d open failure %s\n", fd, strerror(fd));
        return;
    }

    if (S_ISREG(st.st_mode))
    {
        printf("regular file\n");
    }
    else if (S_ISDIR(st.st_mode))
    {
        printf("directory\n");
    }
    else if (S_ISBLK(st.st_mode))
    {
        printf("block special file\n");
    }
    else if (S_ISCHR(st.st_mode))
    {
        printf("character special file\n");
    }
    else if (S_ISLNK(st.st_mode))
    {
        printf("symbolic link\n");
    }
    else if (S_ISFIFO(st.st_mode))
    {
        printf("pipe or FIFO\n");
    }
    else if (S_ISSOCK(st.st_mode))
    {
        printf("socket\n");
    }
    else
    {
        //
    }

    printf("%d\n", st.st_uid);
    printf("%d\n", st.st_gid);
    printf("O_ACCMODE = %d\n", O_ACCMODE);
#endif  //TEST_FILE_INFO
}


static void
test_access(void)
{
//#define TEST_ACCESS
#if defined(TEST_ACCESS)
    if (access("/dev/null", R_OK) == 0)
    {
        printf("able read\n");
    }

    if (access("/.vimrc", W_OK) == 0)
    {
        printf("able write\n");
    }
    else
    {
        printf("not to write\n");
    }
#endif  //TEST_ACCESS
}


static void
test_faccessat(void)
{
//#define FACCESSAT
#if defined(FACCESSAT)
    if (access("./name", W_OK) == 0)
    {
        printf("access check uid and gid\n");
    }
    else
    {
        printf("access not file\n");
    }

    if (faccessat(AT_FDCWD, "./name", W_OK, 0) == 0)
    {
        printf("faccessat check uid and gid\n");
    }
    else
    {
        printf("faccessat not file\n");
    }

    printf("AT_EACCESS = %d\n", AT_EACCESS);
#endif  //FACCESSAT
}


static void
test_mode(void)
{
//#define TEST_UMASK
#if defined(TEST_UMASK)
    print(S_ISUID);
    print(S_ISGID);
    print(S_ISVTX);
    print(S_IRWXU);
    print(S_IRWXG);
    print(S_IRWXO);
    print(S_IRUSR);
    print(S_IWUSR);
    print(S_IXUSR);
    print(S_IRGRP);
    print(S_IWGRP);
    print(S_IXGRP);
    print(S_IROTH);
    print(S_IWOTH);
    print(S_IXOTH);
//    print(AT_SYMLINK_NOFOLLOW);
//    print(AT_SYMLINK_FOLLOW);
//    print(AT_FDCWD);
#endif  //TEST_UMASK
}

static void
test_chown(void)
{
//#define TEST_CHOWN
#if defined(TEST_CHOWN)
    printf("LINK_MAX = %ld\n", pathconf("/", _PC_LINK_MAX));

    print(sysconf(_POSIX_CHOWN_RESTRICTED));
#endif  //TEST_CHOWN
}


static void
test_write_test(void)
{
//#define WRITE_TEST
#if defined(WRITE_TEST)
    unsigned char a = 100;
    unsigned char b = 200;
    unsigned char c = 0;
    unsigned char d = 0;

    c = a + b;
    d = a - b;

    printf("%d %d %d %d\n", c, a+b, d, a-b);
#endif  //WRITE_TEST
}


static void
test_unlink(void)
{
//#define TEST_UNLINK
#if defined(TEST_UNLINK)
    int fd = 0;

    if ((fd = open("tempfile", O_RDWR|O_CREAT, 0666)) < 0)
    {
        printf("tempfile failure\n");
        return;
    }
    ftruncate(fd, 1024*1024*1024);
    if (unlink("tempfile")  < 0)
    {
        printf("unlink failure\n");
        return;
    }

    printf("file unlinked\n");

    write(fd, "123", 3);

    sleep(15);
    printf("done\n");
    return;
#endif  //TEST_UNLINK
}

static void 
test_link(void)
{
//#define TEST_LINK
#if defined(TEST_LINK)
    /* 
     * test if file not exist
     *
     *****************/
    if (symlink("aa", "bb") < 0)
    {
        perror("aa");
    }
    if (link("aa", "cc") < 0)
    {
        perror("aa");
    }
#endif  //TEST_LINK
}

static void
test_mkdir(void)
{
//#define TEST_MKDIR
#if defined(TEST_MKDIR)
    if (mkdir("test_mkdir", 0666) < 0)
    {
        perror("mkdir");
    }

//    sleep(10);

/*    if (rmdir("test_mkdir") < 0)
    {
        perror("rmdir");
    }*/
#endif  //TEST_MKDIR
}

static void
test_readdir(void)
{
//#define TEST_READDIR
#if defined(TEST_READDIR)
    int n = 0;
    char buffer[BUFSIZ] = "";

    int fd = open("..", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    /*
    ** forbidden to read directory
    */
    n = read(fd, buffer, sizeof(buffer));
    printf("n = %d, %s\n", n, buffer);
    perror("read");
#endif  //TEST_READDIR
}

static void 
test_openat(void)
{
//#define TEST_OPENAT
#if defined(TEST_OPENAT)
    int fd = open("..", O_RDONLY);
    if (fd < 0)
    {
        perror("..");
        return;
    }

    int fdat = openat(fd, "test_file", O_CREAT|O_EXCL|O_RDWR, 0666);
    if (fdat < 0)
    {
        perror("test_file");
        return;
    }

    close(fdat);
    perror("close fdat");
    close(fd);
    perror("close fd");
#endif  //TEST_OPENAT
}

static void
test_ln(void)
{
#define TEST_LN
#if defined(TEST_LN)
    struct stat st;

    if (lstat("link", &st) < 0)
    {
        perror("link");
        return;
    }
#endif //TEST_LN
}

int
main(int argc, char* argv[])
{
    file_info(STDIN_FILENO);
    file_info(STDOUT_FILENO);

    test_access();
    test_faccessat();
    test_mode();
    test_chown();
    test_write_test();
    test_unlink();
    test_link();
    test_mkdir();
    test_readdir();
    test_openat();
    test_ln();

    return EXIT_SUCCESS;
}
