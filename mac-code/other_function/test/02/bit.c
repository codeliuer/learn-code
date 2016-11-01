#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct
{
	signed int a0:1;
	signed int a1:1;
	signed int a2:1;
	signed int a3:1;
	signed int a4:1;
	signed int a5:1;
	signed int a6:1;
	signed int a7:1;
} bit;


int
main(int argc, char *argv[])
{
	printf("%lu\n", sizeof(bit));

	return EXIT_SUCCESS;
}
