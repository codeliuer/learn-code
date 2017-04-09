#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOP         /* null operator */

#define SWAP(a, b)      {int t = a; a = b; b = t;}


__thread int arr[21] = {0};
__thread int top = 0;

int push(int value)
{
    int i = 0;
    int j = 0;

    if (top >= sizeof(arr)/sizeof(arr[0])-1)
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
    int value = 0;
    int retdata = 0;

    if (top == 0)
    {
        fprintf(stderr, "stack is null\n");
        return EXIT_FAILURE;
    }

    retdata = arr[1];
    value = arr[top--];

    for (i = 1; 2*i <= top; NOP)
    {
        if (2*i != top)
        {
            if (arr[2*i] > arr[2*i+1])
            {
                if (arr[2*i] > value)
                {
                    arr[i] = arr[2*i];
                    i *= 2;
                }
                else
                {
                    arr[i] = value;
                    break;
                }
            }
            else
            {
                if (arr[2*i+1] > value)
                {
                    arr[i] = arr[2*i+1];
                    i = 2*i + 1;
                }
                else
                {
                    arr[i] = value;
                    break;
                }
            }
        }
        else
        {
            if (arr[2*i] > value)
            {
                arr[i] = arr[2*i];
                arr[2*i] = value;
            }
            else
            {
                arr[i] = value;
            }

            break;
        }
    }

    printf("retdata = %d --", retdata);
    for (i = 1; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

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

    for (i = 1; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d--", arr[i]);
    }
    printf("\n");

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        pop();
        //printf("%2d--", pop());
    }
//    printf("\n");

    return EXIT_SUCCESS;
}
