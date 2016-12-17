#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    int a = 10;
    const int array[] = {0, 1, 2, 3,};
    int b = 20;

    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "array = " << array << endl;

    return EXIT_SUCCESS;
}
