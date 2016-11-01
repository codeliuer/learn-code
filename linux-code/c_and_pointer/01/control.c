#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define		A					'A'
#define		B					'B'
#define		C					'C'


#define		forever_true()		for(;;)


static struct INFO_t
{
	pthread_mutex_t		lock;
	int					num;
	struct 
	{
		int					cur;
		int					next;
	} s[3];
} info = 
	{
		0, 0,
		{A, B},
		{B, C},
		{C, A},
	};

static void
cntl_init(struct INFO_t *pinfo)
{
}

static void 
relation(struct INFO_t *pinfo)
{
}

static void
cntl_uninit(struct INFO_t *pinfo)
{
}


int
main(int argc, char* argv[])
{
	cntl_init(&info);

	relation(&info);

	cntl_uninit(&info);

	return EXIT_SUCCESS;
}
