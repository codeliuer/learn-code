#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "common.h"


#define	NOP

static void
deal_with_character(FILE* pfile)
{
	int ch;
	int num = 0;
	int cntl = 0;
	int space = 0;
	int digit = 0;
	int little = 0;
	int big = 0;
	int mark = 0;
	int print = 0;
	size_t size = 0;
	char buffer[BUFSIZ] = "";

	while ((size = fread(buffer, 1, sizeof(buffer), pfile)) > 0)
	{
		while (size--)
		{
			if (iscntrl(buffer[size]))	cntl++;
			else if (isspace(buffer[size]))		space++;
			else if (isdigit(buffer[size]))		digit++;
			else if (islower(buffer[size]))		little++;
			else if (isupper(buffer[size]))		big++;
			else if (ispunct(buffer[size]))		mark++;
			else if (!isprint(buffer[size]))	print++;
			else				NOP;

			num++;
		}
	}

	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "num", "cntl",
			"space", "digit", "little", "big", "mark", "print");
	printf("%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d\n", num, cntl,
			space, digit, little, big, mark, print);
}


static void
init_flag(char* buffer, size_t size)
{
	int i = 0;

	/* 
	** cntrl:  0x01
	** space:  0x02
	** digit:  0x04
	** little: 0x08
	** big:    0x10
	** mark:   0x20
	** print:  0x40
	*/
	for (i = 0; i < size; i++)
	{
		if (iscntrl(i))			buffer[i] = 0;
		else if (isspace(i))	buffer[i] = 1;
		else if (isdigit(i))	buffer[i] = 2;
		else if (islower(i))	buffer[i] = 3;
		else if (isupper(i))	buffer[i] = 4;
		else if (ispunct(i))	buffer[i] = 5;
		else if (!isprint(i))	buffer[i] = 6;
		else					buffer[i] = 7;
	}
}

static void
alg_character(FILE* pfile)
{
	int ch;
	int num[9] = {0};
	size_t size = 0;
	char flag[CHAR_MAX] = {0};
	char buffer[BUFSIZ] = {0};

	init_flag(flag, sizeof(flag));

	while ((size = fread(buffer, 1, sizeof(buffer), pfile)) > 0)
	{
		while (size--)
		{
			num[flag[buffer[size]]]++;
			num[8]++;
		}
	}

	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "num", "cntl",
			"space", "digit", "little", "big", "mark", "print");
	printf("%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d\n", num[0], num[1], 
			num[2], num[3], num[4], num[5], num[6], num[7]);
}

PUBLIC void
statistics_character(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "open %s failure\n", filename);
		return;
	}

	deal_with_character(fp);
	//alg_character(fp);

	fclose(fp);
}
