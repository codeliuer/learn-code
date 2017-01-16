#include <iostream>


using namespace std;


int main(int argc, char *argv[])
{
    long int value = 0;
    long int &qvalue = value;
    long int var = 0;

    printf("&value = %p\n", &value);
    printf("&var = %p\n", &var);

    long int *ptr = &value-1;
    printf("%0#lx\n", *ptr);

    return EXIT_SUCCESS;
}
