#include <stdlib.h>
#include <iostream>


using namespace std;

static void quote_func(int a, int &qa, int b)
{
	printf("quote_func a address: %p\n", &a);
	printf("quote_func b address: %p\n", &b);
}

static void common_func(int c, int d, int e)
{
	printf("common_func c address: %p\n", &c);
	printf("common_func d address: %p\n", &d);
	printf("common_func e address: %p\n", &e);
}

int main(int argc, char *argv[])
{
	int a = 100;
	int &qa = a;
	int b = 200;

	printf("a address: %p\n", &a);
	printf("qa address: %p\n", &qa);
	printf("b address: %p\n", &b);

	quote_func(a, a, b);

	int c = 100;
	int d = 200;
	int e = 300;

	printf("c address: %p\n", &c);
	printf("d address: %p\n", &d);
	printf("e address: %p\n", &e);

	common_func(c, d, e);

	return EXIT_SUCCESS;
}
