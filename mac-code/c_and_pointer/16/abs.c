#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	unsigned int value = abs(0x7FFFFFFF);
	div_t d = {0, 0};

	d = div(-16, -6);
	//printf("%d, %d\n", *(int *)&d, *((int *)&d+1));
	printf("d.quot = %d, d.rem = %d\n", d.quot, d.rem);

	return EXIT_SUCCESS;
}
