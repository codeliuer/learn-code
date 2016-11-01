#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include <unistd.h>
#include <sys/param.h>


#define print(x, format)        printf(#x " = " #format "\n", x)


int
main(int argc, char* argv[])
{
    print(FOPEN_MAX, %d);
    print(NAME_MAX, %d);
    print(PATH_MAX, %d);
    print(TMP_MAX, %d);
    print(FILENAME_MAX, %d);

#define VALUE_LIMITS
#if defined(VALUE_LIMITS)
    //print(LONG_BIT);
    print(SSIZE_MAX, %ld);
#endif  //VALUE_LIMITS
    printf("%ld\n", sysconf(_POSIX_SEM_NSEMS_MAX));
    printf("PATH_MAX = %lu\n", sysconf(_POSIX_PATH_MAX));
    printf("%ld\n", sysconf(_POSIX_NAME_MAX));
    printf("NOFILE = %d\n", NOFILE);

    printf("OPEN_MAX = %ld\n", pathconf("/", _SC_OPEN_MAX));
    printf("MAXPATHLEN = %d\n", MAXPATHLEN);

    printf("version = %ld\n", sysconf(_SC_VERSION));
    printf("host name max len = %ld\n", sysconf(_SC_HOST_NAME_MAX)+1);

    printf("OPEN_MAX = %ld\n", sysconf(_SC_OPEN_MAX));
    printf("_POSIX_OPEN_MAX = %d\n", _POSIX_OPEN_MAX);

    printf("XOPEN_VERSION = %ld\n", sysconf(_SC_XOPEN_VERSION));
    printf("POSIX_C_SOURCE = %ld\n", _POSIX_C_SOURCE);

    printf("clock = %ld\n", sysconf(_SC_CLK_TCK));
    printf("clock = %ld\n", CLOCKS_PER_SEC);

//    printf("_NFILE = %d\n", _NFILE);

//    printf("version = %d\n",, sysconf(_SC_VERSION));

    return EXIT_SUCCESS;
}
