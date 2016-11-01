#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define		N				(200000)


typedef struct TEST_t
{
	int			_index;
	int			eventId;
	char*		startTime;
	char*		endTime;
	int			duretime;
	char*		name;
	char*		description;
	char*		extension;
	int			nibbles;
} TEST_t;

const TEST_t test = {1, 100, "2016-04-25", "2016-04-25", 100, "inspur", "company", "reserve", 100};

const char* psqlInsert = 
{
	"INSERT INTO EPG (_index, eventId, startTime, endTime, duration, name, description, extension, nibbles)"	\
	" VALUES (100, 100, \"2016-04-25\", \"2016-04-25\", 100, \"inspur\", \"company\", \"reserve\", 100)"
};

int
main(int argc, char* argv[])
{
	int i = 0;
	int ret = 0;
	sqlite3* phandle = NULL;
	char buffer[BUFSIZ] = {0};
	char* errMsg = NULL;
	
	ret = sqlite3_open("dvb_provider_epg1.db", &phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "open tw.db failure\n");
		return ret;
	}

	printf("%d\n",sqlite3_exec(phandle, "BEGIN TRANSACTION", NULL, NULL, NULL));
	for (i = 0; i < N; i++)
	{
		ret = sqlite3_exec(phandle, psqlInsert, NULL, NULL, &errMsg);
		if (ret != SQLITE_OK)
		{
			fprintf(stderr, "data insert failure, ret = %d, errmsg: %s\n", ret, errMsg);
			sqlite3_free(errMsg);
			return ret;
		}
	}
	printf("line = %d, %d\n", __LINE__, sqlite3_exec(phandle, "COMMIT TRANSACTION", NULL, NULL, NULL));

	printf("%d\n", sqlite3_close(phandle));

	return EXIT_SUCCESS;
}
