#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include "common.h"


#define	RANGE				(CHAR_MAX)
#define	THRESHOLD			(100000000)


static void
write_data(FILE* fp)
{
	int i = 0;
	int data = 0;

	srand(time(NULL));

	for (i = 0; i < THRESHOLD; i++)
	{
		data = rand() % RANGE;
		fwrite(&data, sizeof(data), 1, fp);
	}
}

PUBLIC void
rand_character(const char* filename)
{
	FILE* fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		fprintf(stderr, "open %s failure\n", filename);
		return;
	}

	write_data(fp);

	fclose(fp);
}
