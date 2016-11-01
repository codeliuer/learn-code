#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	STRING(a)			#a

int
main(int argc, char* argv[])
{
	printf("%s\n", STRING(* * *));

	return EXIT_SUCCESS;
}
