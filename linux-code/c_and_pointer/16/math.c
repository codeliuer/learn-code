#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int
main(int argc, char* argv[])
{
	printf("%lf\n", floor(3.3));
	printf("%lf\n", floor(-3.3));
	printf("%lf\n", ceil(3.3));
	printf("%lf\n", ceil(-3.3));

	printf("%lf\n", fabs(-3.3));
	printf("%lf\n", fmod(3.3, -2.4));

	printf("lf\n", HUGE_VAL);
	printf("%lf\n", strtod("-999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", NULL));

	return EXIT_SUCCESS;
}
