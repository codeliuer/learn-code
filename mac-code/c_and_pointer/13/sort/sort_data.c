#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product_data.h"
#include "common_macro.h"


#define	INT					(0)
#define	STRING				(1)

#define	sort_int			sort_framework
#define	sort_string			sort_framework


typedef int (*pfCmpNotify_t)(const void*, const void*);

static int 
cmp_int(const void* s1, const void* s2)
{
	return (int *)s1 > (int *)s2 ? 1 : 0;
}

static int 
cmp_string(const void* s1, const void* s2)
{
	return strcmp((char *)s1, (char *)s2) ? 1 : 0;
}

static void
bubble_sort(FILE* pfile, pfCmpNotify_t cmp)
{
}

static void
quick_sort(FILE* pfile, pfCmpNotify_t cmp)
{
}

static void
insert_sort(FILE* pfile, pfCmpNotify_t cmp)
{
}

static void
sort(FILE* pfile, int mode)
{
	pfCmpNotify_t callback[] = 
		{
			cmp_int,	cmp_string,
		};

	
}

static void
sort_framework(const char* filename, int mode)
{
	FILE* pfile = fopen(filename, "r");
	if (pfile == NULL)
	{
		fprintf(stderr, "%s failure\n", filename);
		return;
	}

	sort(pfile, mode);	

	if (fclose(pfile))
	{
		fprintf(stderr, "close failure\n");
		return;
	}
}

PUBLIC void
sort_data(const char* intfile, const char* strfile)
{
	sort_int(intfile, INT);

	sort_string(strfile, STRING);
}
