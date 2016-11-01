#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	name(haha)				AAAA##haha##BBBB

#define	test(a)									\
	static void print_##a()						\
{												\
	/*test*/										\
	printf("adfasdfasdfa\n");					\
}

test(a);


int
main(int argc, char* argv[])
{
	int name(a) = 3;

	printf("%d\n", name(a));

	print_a();

	return EXIT_SUCCESS;
}
