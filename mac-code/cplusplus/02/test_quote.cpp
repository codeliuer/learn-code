#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

static void quote_func(int a, int &qa, int b)
{
	printf("quote_func a address: %p\n", &a);

	//printf("quote_func qa address: %p\n", &qa);
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
//	int *aa = &a;
//	int *&pa = aa;
//	int &&qqa = a;

#if defined(__APPLE__)
	int *p1 = &a;
	int *p2 = p1-1;
	printf("sizeof(long) = %lu\n", sizeof(long));

	printf("a = %d\n", *p1);
	printf("next a = %d\n", *p2);
	printf("main a address = %#x%x\n", *(p2-1), *(p2-2));
	printf("main a address = %#lx\n", *(long *)(p2-2));
#endif //__APPLE__

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
