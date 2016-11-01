/*
** process control environment
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <unistd.h>


#define REGISTER_MAX            ((1000000)+1)


static void
func1(void)
{
    printf("func1\n");
}

static void
func2(void)
{
    printf("func2\n");
}

static int i = 3;
static int ii = 3;

int
main(int argc, char* argv[])
{
    int i = 0;
    int stack = 0;

    atexit(func1);
    atexit(func2);

    printf("stack = %p\n", &stack);

    printf("%p\n", &argc);
    printf("%p\n", argv);

    printf("base %p\n", argv[0]);

//    printf("ATEXIT_MAX = %d\n", ATEXIT_MAX);
    printf("sysconf(_SC_ATEXIT_MAX) = %ld\n", sysconf(_SC_ATEXIT_MAX));

    return EXIT_SUCCESS;
}
