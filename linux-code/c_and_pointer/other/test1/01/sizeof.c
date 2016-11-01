#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static size_t 
func(int size)
{
    char arr[size];

    return sizeof arr+1;
}


//static int arr = 1, 0, 2;


int
main(int argc, char * argv[])
{
    int arr[2][3][4];
    int (*parr)[2][3][4] = &arr;

//    printf("%lu\n", func(10));
    printf("%lu\n", sizeof(*parr+1));

    return EXIT_SUCCESS;
}
