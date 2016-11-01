#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>

#include <sys/resource.h>


extern int errno;


static void
regiter_signal(int signo)
{
    printf("catch signal sig number = %d\n", signo);
    
    exit(EXIT_FAILURE);
}


static void
print_resource(long int limit)
{
    if (limit == RLIM_INFINITY)
    {
        printf("(infinite)\n");
    }
    else
    {
        printf("%ld\n", limit);
    }
}


static void
resource_limit(int resource, long int value)
{
    struct rlimit rlim;

    errno = 0;
    if (getrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "line: %d %s\n", __LINE__, strerror(errno));
        return;
    }
    print_resource(rlim.rlim_cur);

    errno = 0;
    rlim.rlim_cur = value;
    if (setrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
}

int
main(int argc, char* argv[])
{
    FILE *pfile = NULL;
    char buf[BUFSIZ] = "";

#ifdef SIGXFSZ
    if (signal(SIGXFSZ, regiter_signal) == SIG_ERR)
    {
        fprintf(stderr, "file size signal regiter failure\n");
        return EXIT_FAILURE;
    }
#endif //SIGXFSZ

    resource_limit(RLIMIT_FSIZE, 100);

    pfile = fopen("filename.test", "w+");
    if (pfile == NULL)
    {
        fprintf(stderr, "file open failure\n");
        return EXIT_FAILURE;
    }

    fwrite(buf, sizeof(char), sizeof(buf), pfile);
    fwrite(buf, sizeof(char), sizeof(buf), pfile);

    fclose(pfile);

    return EXIT_SUCCESS;
}
