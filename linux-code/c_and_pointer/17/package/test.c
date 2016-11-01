#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	v(m)			~(((unsigned int)~0 >> (m)) << (m))


int
main(int argc, char* argv[])
{
	printf("%d\n", v(3));
	printf("%d\n", (unsigned)~0 << 31);

	return EXIT_SUCCESS;
}
