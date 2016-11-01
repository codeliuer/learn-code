#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma pack(4)

struct NODE
{
	char a[3];
	int b;
	short c[5];
	struct _NODE* d[2];
};

#pragma pack()


int
main(int argc, char* argv[])
{
	printf("%lu\n", (unsigned long)&((struct NODE *)0)->d[1]);

	return EXIT_SUCCESS;
}
