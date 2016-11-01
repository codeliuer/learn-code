#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include <unistd.h>


#define	DB_NAME			"drop"


#define	SQLITE_RETCODE_CHECK(code)							\
	do{														\
		if (code != SQLITE_OK)								\
		{													\
			fprintf(stderr, "line = %d, sqlite return code"	\
				" = %d\n", __LINE__, code);					\
			unlink(DB_NAME);								\
			return EXIT_FAILURE;							\
		}													\
	} while (0)

int
main(int argc, char* argv[])
{
	int retCode;
	sqlite3* phandle = NULL;

	retCode = sqlite3_open(DB_NAME, &phandle);
	SQLITE_RETCODE_CHECK(retCode);

	retCode = sqlite3_exec(phandle, "CREATE TABLE PERSONS (firstName INT PRIMARY KEY(firstName), lastName INT)", NULL, NULL, NULL);
	SQLITE_RETCODE_CHECK(retCode);

	retCode = sqlite3_exec(phandle, "CREATE TABLE PERSONS_NEW AS SELECT firstName, lastName FROM PERSONS", NULL, NULL, NULL);
	SQLITE_RETCODE_CHECK(retCode);

	retCode = sqlite3_exec(phandle, "DROP TABLE PERSONS", NULL, NULL, NULL);
	SQLITE_RETCODE_CHECK(retCode);

	retCode = sqlite3_close(phandle);
	SQLITE_RETCODE_CHECK(retCode);

	return EXIT_SUCCESS;
}
