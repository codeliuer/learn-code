#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <math.h>


extern int errno;

int
main(int argc, char* argv[])
{
	char array[10] = "";
	const char* buffer = "0xFFFFFFFFFFFFFFFF";

	printf("%lu\n", strtoul(buffer, NULL, 16));
	printf("%lu\n", ULONG_MAX);
	printf("errno = %d\n", errno);

	printf("%lu\n", strtoul("0xFFFFFFFFFFFFFFFFFFF", NULL, 16));
	printf("errno = %d\n", errno);

	printf("%lf\n", HUGE_VAL);

	printf("%s\n", "111111111111111"
			"2222222222222222222222"
			"3333333333333333333333"
#if 1
			"4444444444444444444444"
			"5555555555555555555555"
#endif	//1
			"6666666666666666666666"
			"7777777777777777777777"
			"8888888888888888888888"
#if 0
			"9999999999999999999999"
#endif	//0
			"AAAAAAAAAAAAAAAAAAAAAA"
			);

        printf("%ld\n", strtol("12345", NULL, -5));

	return EXIT_SUCCESS;
}
