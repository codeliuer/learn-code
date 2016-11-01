/*
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define forever_true()      for(;;)


extern char **environ;


static void
test_env(void)
{
    char buf[] = "name=name";

    putenv(buf);
}

static void
test_default(void)
{
    int over = 0;
    char *ptr = NULL;

    printf("over = %d\n", over);

    /*
    ** produced a segmentation fault in this case
    */
    ptr = getenv("name");
    printf("%s\n", ptr);
}

static void
test_not_static_string(void)
{
    test_env();
    test_default();
}

static void
show_env(void)
{
    while (*environ != NULL)
    {
        printf("%s\n", *environ);
        environ++;
    }
}

static void 
test_putenv(void)
{
    printf("environ =  %p\n", environ);
    printf("environ =  %p\n", environ[0]);

    putenv("LS_COLORS=name");

//    printf("environ =  %p\n", environ);
//    printf("environ =  %p\n", environ[0]);
    show_env();
}

int
main(int argc, char* argv[])
{
//    test_not_static_string();

    test_putenv();

//    forever_true();

    return EXIT_SUCCESS;
}
