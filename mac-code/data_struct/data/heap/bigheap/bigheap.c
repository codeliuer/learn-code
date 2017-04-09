#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOP         /* null operator */

#define SWAP(a, b)      {int t = a; a = b; b = t;}


int arr[21] = {0};
int top = 0;

int push(int value)
{
    int i = 0;
    int j = 0;

    if (top >= 20)
    {
        fprintf(stderr, "capacity is not enough\n");
        return EXIT_FAILURE;
    }

    for (i = ++top, j = i/2; j != 0 && value > arr[j]; i = j, j = i/2)
    {
        arr[i] = arr[j];
    }

    arr[i] = value;

    return EXIT_SUCCESS;
}


int pop(void)
{
    int i = 0;
    int retdata = 0;

    if (top == 0)
    {
        fprintf(stderr, "stack is null\n");
        return EXIT_FAILURE;
    }

    retdata = arr[1];
    arr[1] = arr[top--];

    for (i = 1; 2*i <= top; NOP)
    {
        if (2*i != top)
        {

        }
        else
        {
        }
    }

    return retdata;
}


int main(int argc, char *argv[])
{
    int i = 0;
    int a[] = {3, 16, 18, 11, 18, 17, 5, 10, 3, 20, 12, 1, 7, 18, 10, 5, 20, 10, 19, 1,};

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        push(a[i]);
    }

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%2d--", pop());
    }
    printf("\n");

    return EXIT_SUCCESS;
}
