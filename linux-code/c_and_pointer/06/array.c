#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
my_func1(int fruit[2][3][5])
{
    printf("111111111111111111111111111\n");
    printf("fruit = %p\n", fruit);
    printf("fruit+1 = %p\n", fruit+1);
}


static void
my_func2(int fruit[][3][5])
{
    printf("22222222222222222222222222222\n");
    printf("fruit = %p\n", fruit);
    printf("fruit+1 = %p\n", fruit+1);
}

static void
my_func3(int (* fruit)[3][5])
{
    printf("33333333333333333333333333333\n");
    printf("fruit = %p\n", fruit);
    printf("fruit+1 = %p\n", fruit+1);
}

static void
test(void)
{
    int apricot[2][3][5];

    my_func1(apricot);
    my_func2(apricot);
    my_func3(apricot);
}

int
main(int argc, char *argv[])
{
/*    int arr[3][10][10] = {0};

    printf("sizeof(arr[0]) = %lu\n", sizeof(arr[0]));
    printf("sizeof(arr[0]) = %lu\n", sizeof(arr[0]+1));

    printf("arr[0] = %p\n", arr[0]);
    printf("arr[0] + 1 = %p\n", arr[0]+1);
    printf("arr[1] = %p\n", arr[1]);
    printf("arr+1 = %p\n", arr+1);
*/
    test();

    return EXIT_SUCCESS;
}
