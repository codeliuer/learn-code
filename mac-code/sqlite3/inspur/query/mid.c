/*
** mid function implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#include "mid.h"
#include "dst.h"


static struct 
{
	char*		name;
	sqlite3*	handle;
} handle = 
	{
		"program.db",
#define MID_DB		handle.name
		NULL,
#define phandle		handle.handle
	};


static int 
callback(void* arg, int num, char** values, char** names)
{
	*(int *)arg = dst_exec(atoi(values[0]), atoi(values[1]));

	return 0;
}

void 
mid_init(void)
{
	sqlite3_open(MID_DB, &phandle);
}


int
mid_exec(int eventId, int indexProgram)
{
	int retcode = 0;
	char buffer[BUFSIZ] = "";

	snprintf(buffer, sizeof(buffer), 
			"select tsId, serviceId from program where indexProgram=%d", indexProgram);
	sqlite3_exec(phandle, buffer, callback, &retcode, NULL);

	return retcode;
}


void
mid_uninit(void)
{
	sqlite3_close(phandle);
}
