#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>


#define print_num(x)        printf(#x " = %d\n", x)


int
main(int argc, char* argv[])
{
    int ch;
    int cntrl = 0;
    int space = 0;
    int digit = 0;
    int lower = 0;
    int upper = 0;
    int punct = 0;
    int nprint = 0;

    while ((ch = getchar()) != EOF)
    {
        if (iscntrl(ch))
        {
            cntrl++;
        }
        else if (isspace(ch))
        {
            space++;
        }
        else if (isdigit(ch))
        {
            digit++;
        }
        else if (islower(ch))
        {
            lower++;
        }
        else if (isupper(ch))
        {
            upper++;
        }
        else if (ispunct(ch))
        {
            punct++;
        }
        else if (!isprint(ch))
        {
            nprint++;
        }
    }

    print_num(cntrl), print_num(space), print_num(digit), print_num(lower),
    print_num(upper), print_num(punct), print_num(nprint);

    return EXIT_SUCCESS;
}
