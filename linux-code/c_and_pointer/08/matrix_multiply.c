/*
** A(i*j) * B(j*k) = C(i*k) matrix multiply
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define element_num(arr)        (sizeof(arr)/sizeof(arr[0]))

static void
matrix_multiply(int* m1, int* m2, int* r, int x, int y, int z)
{
    int i, k, j;

    for (i = 0;  i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                r[i*z+k] += m1[i*y+j] * m2[j*z+k];
            }
        }
    }
}

static void 
matrix_multiply_cp(int* m1, int* m2, int* r, int x, int y, int z)
{
    int i, j, k;
    int* m1p, *m2p;

    for (i = 0; i < x; i++)
    {
        for (k = 0; k < z; k++)
        {
            m1p = m1 + i*y;
            m2p = m2+k;

            for (j = 0; j < y; j++)
            {
                *r += *m1p * *m2p;
                m1p++;
                m2p += z;
            }

            r++;
        }
    }
}

static void
show(int (*p)[4], int num)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < num; i++)
    {
        printf("{");
        for (j = 0; j < 4; j++)
        {
            printf("%d, ", p[i][j]);
        }
        printf("}\n");
    }
}

int
main(int argc, char* argv[])
{
    int arr1[3][2] = 
        {
            {2, -6},
            {3, 5},
            {1, -1},
        };
    int arr2[2][4] = 
        {
            {4, -2, -4, -5},
            {-7, -3, 6, 7},
        };
    int arr3[3][4] = {0};

    matrix_multiply_cp((int *)arr1, (int *)arr2, (int *)arr3, 
            element_num(arr1), element_num(arr1[0]), element_num(arr2[0]));

    show(arr3, element_num(arr3));

    return EXIT_SUCCESS;
}
