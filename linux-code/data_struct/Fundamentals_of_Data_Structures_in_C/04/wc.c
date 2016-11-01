#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define IN          (1)
#define OUT         (2)


int
main(int argc, char *argv[])
{
    int c;
    int num = 0;
    int flag = OUT;

    while ((c = getchar()) != EOF)
    {
        if ((flag == OUT) && isalpha(c))
        {
            num++;
            flag = IN;
        }
        else if ((flag == IN) && !isalpha(c))
        {
            flag = OUT;
        }
    }

    printf("\nnum = %d\n", num);

    return EXIT_SUCCESS;
}
