#include <stdio.h>
#include <stdlib.h>


static void static_var(void)
{
    static int var = 1000;

    printf("static_var %d\n", var++);
}

int main(int argc, char *argv[])
{
    static int var = 100;

    static_var();

    printf("main %d\n", var++);

    static_var();

    printf("main %d\n", var);

    return EXIT_SUCCESS;
}
