#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	test(n)				#n

#define LOGS(...)       printf(__VA_ARGS__)
#define PRINTF(__VA_ARGS__)    printf(#__VA_ARGS__)

int
main(int argc, char* argv[])
{
    LOGS("%d %d %.1s\n", 1, 2, "123");
    PRINTF("...\n");

	printf("%s\n", test("asdfasdfasd"));

    return EXIT_SUCCESS;
}
