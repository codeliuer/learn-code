/*
** add or fix envrion solution
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
test_add_short(void)
{
    char* ptr = "JOB=SHORT";

    printf("%p\n", getenv("JOB"));
    putenv(ptr);
    printf("ptr = %p\n", ptr);
    printf("%p\n", getenv("JOB"));
    printf("%s\n", getenv("JOB"));
}

static void
test_add_long(void)
{
    char *ptr = "SHLVL=123";

    printf("%p\n", ptr);
    putenv(ptr);
    printf("ptr = %p\n", ptr);
    printf("%p\n", getenv("SHLVL"));
    printf("%s\n", getenv("SHLVL"));
}

static void
test_add_first(void)
{
    char name[] = "name=name";

    printf("name = %p\n", name);
    /* segmentation fault */
//    putenv(name);
    printf("%p\n", getenv("name"));
}

static void
test_add_other(void)
{
    putenv("other=other");
}

static void
test_add_solution(void)
{
    test_add_short();
    test_add_long();
    test_add_first();
    test_add_other();
}


int
main(int argc, char* argv[])
{
    test_add_solution();

    return EXIT_SUCCESS;
}
