#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product_data.h"


#define	INTFILE			"int.log"
#define	STRFILE			"str.log"


int
main(int argc, char* argv[])
{
	const char* intfile = INTFILE;
	const char* strfile = STRFILE;

	product_data(intfile, strfile);

	sort_data(intfile, strfile);

	return EXIT_SUCCESS;
}
