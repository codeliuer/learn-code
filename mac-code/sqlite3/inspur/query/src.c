/*
** src function implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#include "src.h"
#include "mid.h"


#define INVALID			(0)
#define VALID			(1)


static struct
{
	char*		name;
	sqlite3*	handle;
} handle = 
	{
		"dvb_provider_epg1.db", 
#define SRC_DB	handle.name
		NULL,
#define phandle	handle.handle
	};

static int total = 0;

static int 
callback(void* arg, int num, char** values, char** names)
{
	int retcode = 0;

    retcode	= mid_exec(atoi(values[1]), atoi(values[14]));
	if (retcode == INVALID)
	{
		total++;
	//	printf("_index = %d, eventId = %d, startTime: %s, endTime: %s, duration = %d, name: %s, description: %s, extension: %s, nibbeles: %s, serviceIndex = %d\n", atoi(values[0]), atoi(values[1]), values[2], values[3], atoi(values[4]), values[5], values[6], values[7], values[8], atoi(values[14]));
		printf("serviceIndex = %d\n", atoi(values[14]));
	}

	return 0;
}

void
src_init(void)
{
	sqlite3_open(SRC_DB, &phandle);
}


void
src_exec(void)
{
	sqlite3_exec(phandle, "select * from epg", callback, NULL, NULL);
	printf("total = %d\n", total);
}


void
src_uninit(void)
{
	sqlite3_close(phandle);
}
