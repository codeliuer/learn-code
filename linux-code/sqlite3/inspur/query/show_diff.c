#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


int
main(int argc, char* argv[])
{
	init();

	exec();

	uninit();

	return EXIT_SUCCESS;
}
