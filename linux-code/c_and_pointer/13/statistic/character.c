#include <stdio.h>
#include <stdlib.h>

#include "common.h"


#define	CHAR_FILE			"log.txt"


int
main(int argc, char* argv[])
{
	rand_character(CHAR_FILE);

	statistics_character(CHAR_FILE);

	return EXIT_SUCCESS;
}
