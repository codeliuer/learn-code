/*
** the implementation of get operator data interface
*/

#include <stdio.h>
#include <ctype.h>

#include "getop.h"


OP_t 
getop(int *pdata)
{
    int c;

    do
    {
        c = getchar();
    } while (isspace(c));

    if (isdigit(c))
    {
        *pdata = c-'0';
        while (isdigit(c = getchar()))
        {
            *pdata = 10 * *pdata + c-'0';
        }
        ungetc(c, stdin);

        return DATA;
    }

    if (isalpha(c))
    {
        *pdata = c;

        return ALPHABET;
    }

    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        *pdata = c;

        return OPERATOR;
    }

    return OTHER;
}


//#define DEBUG
#if defined(DEBUG)

#include <stdlib.h>


int
main(int argc, char * argv[])
{
    OP_t op;
    int data;

    while ((op = getop(&data)) != OTHER)
    {
        if (op == DATA)
        {
            printf("data = %d\n", data);
        }
        else if (op == OPERATOR)
        {
            printf("operator = %c\n", data);
        }
    }

    return EXIT_SUCCESS;
}
#endif //DEBUG
