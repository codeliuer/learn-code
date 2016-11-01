#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define	DEBUG		printf("%d\n", __LINE__)

#define	ARRAYNUM(arr)			(sizeof(arr)/sizeof(arr[0]))


static int 
cmp_string(const void* key1, const void* key2)
{
	return (strcmp(*(const char **)key1, *(const char **)key2)) > 0 ? 1 : 0;
}


static void
swap(char* dest, char* src, size_t size)
{
	char tmp[size];

	memcpy(tmp, dest, size);
	memcpy(dest, src, size);
	memcpy(src, tmp, size);
}

static void
sort(void* array, int n, size_t size, 
		int(*cmp)(const void*, const void*))
{
	int i = 0;
	int left = 0;
	char* carr = (char *)array;

	if (n <= 0)
	{
		return;
	}

	swap(&carr[0], &carr[(n/2)*size], size);
	for (i = 1; i < n; i++)
	{
		if (cmp(&carr[0], &carr[i*size]) > 0)
		{
			left++;
			swap(&carr[i*size], &carr[left*size], size);
		}
	}
	swap(&carr[0], &carr[left*size], size);

	sort(carr, left-1, size, cmp);
	sort(&carr[(left+1)*size], n-left-1, size, cmp);
}

static void
show(void* array, size_t n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%s,    ", ((char **)array)[i]);
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	char* name[] = 
		{
			"liuwei",		"liuzhiming",	"liukangcheng",
			"lixinguang",	"liuchanglong",	"wangfeng",
			"leiyu",		"hushengyang",	"huzhaohui",
			"lipeng",		"zhaozhiyang",	"meidongting",
			"lijianhua",	"linhaijin",	"zhangjizhen",
			"zhaolubo",		"liuguangquan",	"fulingfan",
			"maxiao",		"machengtao",	"liangxianggen",
			"luzhishen",	"suchuan",		"liangwei",
		};

	setvbuf(stdout, NULL, _IONBF, 0);

	sort(name, ARRAYNUM(name), sizeof(*name), cmp_string);
	show(name, ARRAYNUM(name));

	return EXIT_SUCCESS;
}
