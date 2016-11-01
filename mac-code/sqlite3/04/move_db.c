#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>
#include <unistd.h>


int
main(int argc, char* argvp[])
{
	int retcode = 0;
	sqlite3* phead = NULL;

	retcode = sqlite3_open("testdb", &phead);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "open database failure\n");
		exit(EXIT_FAILURE);
	}
/*
	retcode = sqlite3_exec(phead, "create table test (i1, i2, i3)", NULL, NULL, NULL);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "table create failure\n");
		exit(EXIT_FAILURE);
	}
*/
	while (1)
	{
		retcode = sqlite3_exec(phead, "insert into test (i1, i2, i3) VALUES(1, 2, 3)", NULL, NULL, NULL);
		if (retcode != SQLITE_OK)
		{
			fprintf(stderr, "exec failure\n");
			return EXIT_FAILURE;
		}
		
		sleep(5);
	}

	return EXIT_SUCCESS;
}
