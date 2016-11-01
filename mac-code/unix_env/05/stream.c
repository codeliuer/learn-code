/*
** pursue flow implementation details
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void pr_stdio(const char* stream_name, FILE* fp);


int
main(int argc, char* argv[])
{
    FILE* fp = NULL;

    fputs("enter any character\n", stdout);
    while (getchar() == EOF)
    {
        fprintf(stderr, "getchar error\n");
    }
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ((fp = fopen("/etc/passwd", "r")) == NULL)
    {
        fprintf(stderr, "fopen error\n");
        exit(EXIT_FAILURE);
    }

    if (getc(fp) == EOF)
    {
        fprintf(stderr, "getc error\n");
    }
    pr_stdio("/etc/passwd", fp);

    return EXIT_SUCCESS;
}


static int is_unbuffered(FILE* fp);
static int is_linebuffer(FILE* fp);
static int buffer_size(FILE* fp);

static void
pr_stdio(const char* stream_name, FILE* fp)
{
    printf("stream = %s\n", stream_name);

    if (is_unbuffered(fp))
    {
        printf("undeffered");
    }
    else if (is_linebuffer(fp))
    {
        printf("line buffered\n");
    }
    else
    {
        printf("fully buffered\n");
    }

    printf(", buffer size = %d\n", buffer_size(fp));
}

#if defined(unix)
static int is_unbuffered(FILE* fp)
{
    return fp->_flags & _IONBF;
}
static int is_linebuffer(FILE* fp)
{
    return fp->_flags & _IOLBF;
}
static int buffer_size(FILE* fp)
{
    return fp->_IO_buf_end - fp->_IO_buf_base;
}
#elif defined(__APPLE__) &&  defined(__MACH__)
static int is_unbuffered(FILE* fp);
static int is_linebuffer(FILE* fp);
static int buffer_size(FILE* fp);
#else
#error "does not support"
#endif //unix __APPLE__ __MACH__
