#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define	PROGRAM2				program	
#define	PROGRAM					PROGRAM2

#define	STRING2(PROGRAM)			"create table " #PROGRAM
#define	STRING(PROGRAM)				STRING2(PROGRAM)

int
main(int argc, char* argv[])
{
	printf("%s\n", STRING(PROGRAM));

	return EXIT_SUCCESS;
}
