/*
** Judgment identity matrix 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define false               (0)
#define true                (1)

#define element(arr)        (sizeof(arr)/sizeof(arr[0]))


typedef unsigned char       bool;


static bool
identity_matrix(unsigned long (*arr)[5], int num)
{
    int i = 0; 
    int j = 0;
    unsigned long sum = 0;

    if (5 != num)
    {
        return false;
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((i!=j && arr[i][j]!=0) || (i==j && arr[i][j]!=1))
            {
                return false;
            }
        }
    }

    return true;
}

int
main(int argc, char* argv[])
{
    unsigned long arr[5][5] =
        {
            {1,},
            {0, 1,},
            {0, 0, 1,},
            {0, 0, 0, 1,},
            {0, 0, 0, 0, 1,},
        };

    printf("%s\n", identity_matrix(arr, element(arr))?"true":"false");

    return EXIT_SUCCESS;
}
