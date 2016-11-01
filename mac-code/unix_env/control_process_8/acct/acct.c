#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define RECORD_FILE		"record.txt"


int
main(int argc, char *argv[])
{
	if (acct(RECORD_FILE) < 0)
	{
		perror(RECORD_FILE);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
