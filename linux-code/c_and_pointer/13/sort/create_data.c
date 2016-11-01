#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "common_macro.h"


#define	COE				(10)
#define	NUMMAX			(10000000)
#define	RANGEMAX		(COE*NUMMAX)

extern int errno;

static void
write_data(FILE* pfile)
{
	int i = 0;
	int data = 0;

	srand(time(NULL));

	for (i = 0; i < NUMMAX; i++)
	{
		data = rand() % RANGEMAX;

		fwrite(&data, sizeof(data), 1, pfile);
	}
}

static void
product_integer(const char* filename)
{
	FILE* fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		fprintf(stderr, "failure open file\n");
		return;
	}

	write_data(fp);

	fclose(fp);
}

static void
product_string(const char* filename)
{
}

PUBLIC
void product_data(const char* intfile, const char* strfile)
{
	if (intfile != NULL)
	{
		product_integer(intfile);
	}

	if (strfile != NULL)
	{
		product_string(strfile);
	}
}
