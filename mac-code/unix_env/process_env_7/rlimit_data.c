#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/resource.h>


extern int errno;


static void
resource_limit(int resource, long int lim)
{
    struct rlimit rlim;

    errno = 0;
    if (getrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }

    errno = 0;
    rlim.rlim_cur = lim;
    if (setrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }

    errno = 0;
    if (getrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    printf("%ld\n", rlim.rlim_cur);
}


static int data[BUFSIZ] = {0};
static int data1[BUFSIZ] = {0};
static int data2[BUFSIZ] = {0};


int
main(int argc, char* argv[])
{
#ifdef RLIMIT_DATA
    resource_limit(RLIMIT_DATA, 1);
    printf("rlimit_data = %d\n", RLIMIT_DATA);
#endif //RLIMIT_DATA
    int i = 0;

    for (i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        data[i] = i;
        data1[i] = i;
        data2[i] = i;

//        printf("data[%d] = %d, data1[%d] = %d, data2[%d] = %d\n", i, data[i], i, data1[i], i, data2[i]);
    }

    return EXIT_SUCCESS;
}
