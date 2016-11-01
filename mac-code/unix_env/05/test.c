/*
** fwide(FILE* fp, int mode)
** when mode is zero, the fwide() function determines the currents orientation
** of stream, It returns a positive value if stream is wide-character oriented.
** that is, if wide-character I/O is permitted but char I/O is disallowed. It 
** returns a negative value if stream is byte oriented, i.e., if char I/O is 
** permitted but wide-character I/O is disallowed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <wchar.h>


extern int errno;


void
test_fwide(void)
{
//#define TEST_FWIDE
#if defined(TEST_FWIDE)
    int retcode = 0;

//    printf("%s\n", "head comma");
//    errno = 0;
    retcode = fwide(stdout, -1);
//    if (errno != 0)
//    {
//        perror("fwide");
        //return EXIT_FAILURE;
//    }

    wprintf("adfadsfasdfadfasd");

#endif //TEST_FWIDE
}


static void
test_freopen(void)
{
//#define TEST_FREOPEN
#if defined(TEST_FREOPEN)
    FILE* pf = NULL;
    char buffer[BUFSIZ] = "";

    pf = freopen("test.c", "r", stdin);
    fread(buffer, sizeof(char), sizeof(buffer), pf);
    printf("%s\n", buffer);
#endif  //TEST_FREOPEN
}

static void
test_filerw(void)
{
//#define TEST_FILERW
#if defined(TEST_FILERW)
    FILE* fp = NULL;
    char buffer[BUFSIZ] = "";

    fp = fopen("rwfile", "r+");
    if (fp == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    fwrite("123456", sizeof(char), strlen("123456"), fp);
    //rewind(fp);
    printf("%ld\n", fread(buffer, sizeof(char), sizeof(buffer), fp));
    printf("%s\n", buffer);

    fclose(fp);
#endif//TEST_FILERW
}

static void
test_gets(void)
{
//#define TEST_GETS
#if defined(TEST_GETS)
    char buffer[BUFSIZ] = "";

    while (gets(buffer) != NULL)
    {
        printf("%s", buffer);
    }
#endif  //TEST_GETS
}

static void
test_printf(void)
{
#define TEST_PRINTF
#if defined(TEST_PRINTF)
//    int num = 0;
    int n = 0;
    char buf[BUFSIZ] = "";

    printf("%d%n\n", 123, &n);
    printf("n = %d\n", n);

//    scanf("%d", &n);
//    printf("n = %d\n", n);
//    scanf("%*[^\n]");
//    scanf("%*c");
//    scanf("%d", &n);
//    printf("n = %d\n", n);
    
    printf("enter: n = ");
    scanf("%3s%d", buf, &n);
    printf("buflen = %ld, buf: %s\n", strlen(buf), buf);
    printf("n = %d\n", n);

//    scanf("%[s", buf);
//    scanf("%s%n", buf, &n);
//    printf("n = %d\n", n);
#endif //TEST_PRINTF
}

int
main(int argc, char* argv[])
{
    test_fwide();
    test_freopen();
    test_filerw();
    test_gets();
    test_printf();

    return EXIT_SUCCESS;
}
