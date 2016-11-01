#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


#define RECORD_FILE			"recort.file"


int
main(int argc, char *argv[])
{
	if (acct(RECORD_FILE) < 0)
	{
		perror("recort.file: ");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
