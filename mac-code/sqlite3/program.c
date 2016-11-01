#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


static int 
func(void *arg, int num, char **values, char **names)
{
	*(int *)arg = atoi(values[0]);
	printf("arg = %d\n", *(int *)arg);

	return 0;
}


int
main(int argc, char * argv[])
{
	int count = 0;
	int retcode = 0;
	sqlite3 *phandle = NULL;

	retcode = sqlite3_open("program.db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", sqlite3_errmsg(phandle));
		return EXIT_FAILURE;
	}

	sqlite3_exec(phandle, "select count(*) from program;", func, &count, NULL);

	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}
