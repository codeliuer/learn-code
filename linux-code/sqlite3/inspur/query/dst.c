/*
** dst function implementation  
*/

#include <stdio.h>
#include <sqlite3.h>

#include "dst.h"

static struct 
{
	char*		name;
	sqlite3*	handle;
} handle = 
	{
		"memory.db",
#define DST_DB		handle.name
		NULL,
#define phandle		handle.handle
	};


static int 
callback(void* arg, int num, char** values, char** names)
{
	*(int *)arg = 1;
	return 0;
}

void
dst_init(void)
{
	sqlite3_open(DST_DB, &phandle);
}

int 
dst_exec(int tsId, int serviceId)
{
	int num = 0;
	char buffer[BUFSIZ] = "";

	snprintf(buffer, sizeof(buffer), 
			"select tsId from epg where tsId=%d and serviceid=%d",
			tsId, serviceId);
	sqlite3_exec(phandle, buffer, callback, &num, NULL);

	return num;
}

void
dst_uninit(void)
{
	sqlite3_close(phandle);
}
