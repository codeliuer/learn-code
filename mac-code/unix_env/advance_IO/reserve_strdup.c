#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char *func(char *p)
{
    int i = 0;
    int len = 0;
    int tmp = 0;
    char *newp = NULL;

    if (p == NULL)
    {
        return NULL;
    }

    tmp = len = strlen(p);
    newp = malloc(len+1);
    if (newp == NULL)
    {
        return NULL;
    }

    for (i = 0; i < len; i++)
    {
        newp[i] = p[--tmp];
    }
    newp[i] = 0;

    return newp;
}


int main(int argc, char *argv[])
{
    char *p = "liuwei";

    printf("%s\n", p);
    printf("%s\n", func(p));

    return EXIT_SUCCESS;
}
