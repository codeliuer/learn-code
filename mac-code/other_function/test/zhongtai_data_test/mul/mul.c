/*
** interface
*/

#include <stdio.h>
#include <stdlib.h>

#include "mul.h"


void
mul(int max)
{
    int i = 1; 
    int j = 1;

    for (i = 1; i <= max; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d * %d = %-2d  ", i, j, i*j);
        }
        printf("\n");
    }
}
