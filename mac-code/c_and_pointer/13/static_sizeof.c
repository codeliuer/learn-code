#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int
main(int argc, char* argv[])
{
	int array[argc];
	int aa = 0;
	static int num = sizeof(aa);

	printf("%d\n", num);

	return EXIT_SUCCESS;
}
