#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define arr_ele_num(arr)        (sizeof(arr)/sizeof(arr[0]))


typedef struct NODE
{
#define     N           (10)
    int array[N];
    char string[N];
    int value;
} NODE;


static void
print_struct(NODE* pnode)
{
    int i = 0;

    for (i = 0; i < arr_ele_num(pnode->array); i++)
    {
        printf("%d  ", pnode->array[i]);
    }
    printf("\n");

    printf("string : %s\n", pnode->string);
    printf("value = %d\n", pnode->value);
}

int
main(int argc, char* argv[])
{
    NODE node = 
        {
            .array = {1, 2, 3, 4, 5, 6, 7,},
            .string = "liuwei",
            .value = 11,
        };

    print_struct(&node);

    return EXIT_SUCCESS;
}
