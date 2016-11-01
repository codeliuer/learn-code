#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int
main(int argc, char* argv[])
{
    clock_t	ct = clock();

	sleep(1);

    clock_t	ct1 = clock();

	printf("%lu\n", ct1 - ct);
	printf("%d\n", CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}
