#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <sys/acct.h>


#define ARR_NUMS(arr)	(sizeof(arr)/sizeof(arr[0]))

#define RECORD_FILE		"record.txt"


struct INFO
{
	const char *name;
	int len;
};


static void 
print_title(struct INFO *pinfo, size_t len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("%-*s", pinfo[i].len, pinfo[i].name);
	}
	printf("\n");
}


static void 
parse_file(FILE *fp, struct INFO *pinfo, size_t len)
{
	int i = 0;
	struct acct acct;

	while (fread(&acct, sizeof(acct), 1, fp) > 0)
	{
		i = 0;

		printf("%-*s", pinfo[i++].len, acct.ac_comm);
		printf("%-*u", pinfo[i++].len, acct.ac_utime);
		printf("%-*u", pinfo[i++].len, acct.ac_stime);
		printf("%-*u", pinfo[i++].len, acct.ac_etime);
		printf("%-*u", pinfo[i++].len, acct.ac_btime);
		printf("%-*u", pinfo[i++].len, acct.ac_uid);
		printf("%-*u", pinfo[i++].len, acct.ac_gid);
		printf("%-*u", pinfo[i++].len, acct.ac_mem);
		printf("%-*u", pinfo[i++].len, acct.ac_io);
		printf("%-*u", pinfo[i++].len, acct.ac_tty);
		printf("%-*u", pinfo[i++].len, acct.ac_flag);

		printf("\n");
	}
}


int
main(int argc, char *argv[])
{
	int i = 0;
	FILE *fp = NULL;
	struct INFO info[] = 
	{
		{"command name", 14}, {"user time", 11}, {"system time", 13}, 
		{"elapsed time", 14}, {"starting time", 15}, {"user id", 9}, 
		{"group id", 10}, {"memory", 8}, {"IO blocks", 11},
		{"controlling tty", 17}, {"accounting flag", 17},
	};

	if ((fp = fopen(RECORD_FILE, "r")) < 0)
	{
		fprintf(stderr, "open %s failure\n", RECORD_FILE);
		return EXIT_FAILURE;
	}

	print_title(info, ARR_NUMS(info));
	parse_file(fp, info, ARR_NUMS(info));

	return EXIT_SUCCESS;
}
