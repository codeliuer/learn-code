#include <stdio.h>


int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int* pa = arr;


void
print_extern(void)
{
    printf("arr = %p, &pa = %p\n", arr, &pa);
}
