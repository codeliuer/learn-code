
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>
#include <sys/time.h>

#include <unistd.h>


#define	N						10000000
#define	DB_FILENAME				"dvb_provider_epg1.db"


static void
create_db(sqlite3** phandle)
{
	int retCode = 0;
	char* errMsg = NULL;

	retCode = sqlite3_open(DB_FILENAME, phandle);
	printf("open database retCode = %d\n", retCode);

	retCode = sqlite3_exec(*phandle, "CREATE TABLE name (table1 VARCHAR(10), table2 VARCHAR(10), table3 VARCHAR(10))", NULL, NULL, &errMsg);
	if (retCode != SQLITE_OK)
	{
		fprintf(stderr, "line: %d, create table failure retCode = %d, msg: %s\n", __LINE__, retCode, errMsg);
		exit(EXIT_FAILURE);
	}
}

static void
insert_data(sqlite3* phandle)
{
	int i = 0;
	int retCode = 0;
	char* errMsg = NULL;


	for (i = 0; i < N; i++)
	{
		retCode = sqlite3_exec(phandle, "INSERT INTO name VALUES(\"123456789\", \"123456789\", \"123456789\")", NULL, NULL, &errMsg);
		if (retCode != SQLITE_OK)
		{
			fprintf(stderr, "line = %d, insert failure retCode = %d, errMsg: %s\n", __LINE__, retCode, errMsg);
			exit(EXIT_FAILURE);
		}
	}
}

static void
start_transation(sqlite3* phandle)
{
	int retCode = 0;
	char* errMsg = NULL;

	retCode = sqlite3_exec(phandle, "BEGIN TRANSACTION", NULL, NULL, &errMsg);
	if (retCode != SQLITE_OK)
	{
		fprintf(stderr, "line = %d, retCode = %d, errMsg: %s\n", __LINE__, retCode, errMsg);
		sqlite3_free(errMsg);
		exit(EXIT_FAILURE);
	}
}

static void
end_transation(sqlite3* phandle)
{
	int retCode = 0;
	char* errMsg = NULL;

	retCode = sqlite3_exec(phandle, "COMMIT TRANSACTION", NULL, NULL, &errMsg);
	if (retCode != SQLITE_OK)
	{
		fprintf(stderr, "line = %d, retCode = %d, errMsg: %s\n", __LINE__, retCode, errMsg);
		sqlite3_free(errMsg);
		exit(EXIT_FAILURE);
	}
}

int
main(int argc, char* argv[])
{
	clock_t tstart, tend;
	sqlite3* phandle = NULL;

	create_db(&phandle);

	tstart = clock();
	start_transation(phandle);
	insert_data(phandle);
	end_transation(phandle);
	tend = clock();

	printf("transaction %lus\n", (tend-tstart)/CLOCKS_PER_SEC);

	tstart = clock();
//	insert_data(phandle);
	tend = clock();

	printf("insert %lus\n", (tend-tstart)/CLOCKS_PER_SEC);


	return EXIT_SUCCESS;
}
