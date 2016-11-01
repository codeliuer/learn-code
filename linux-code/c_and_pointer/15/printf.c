#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	int d = 0;
	int n = 0;

	//scanf("%d %n", &d, &n);
	//printf("n = %d\n", n);
	//printf("%d, %n\n", 33, &n);
	//printf("n = %d\n", n);
	//printf("% d\n", 3);
	//printf("test %.0d\n", 0);

	printf("%#o\n", 3);
	printf("%#X\n", 188);
	printf("%#e\n", (double)3);
	printf("%#g\n", 3.0);

	return EXIT_SUCCESS;
}
