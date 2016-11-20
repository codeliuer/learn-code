#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;


class A
{
public:
    virtual void func(void)
    {
    }
};


int
main(int argc, char* argv[])
{
    int n = atoi(argv[1]);

    int arr[n];

    arr[0] = 1;

    printf("sizeof(arr) = %d\n", sizeof(arr[0]+1));
    printf("arr[0] = %d\n", arr[0]);

    printf("sizeof(void) = %d\n", sizeof(void));

    cout << "sizeof(class A) = " << sizeof(class A) << endl;

    return EXIT_SUCCESS;
}
