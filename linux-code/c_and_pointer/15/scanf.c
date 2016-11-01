#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	char c;
	int num = 0;

	//scanf("num = %d", &num);
	//printf("num = %d\n", num);

	//scanf("%1d", &num);
	//printf("num = %d\n", num);

	//scanf("%d", &num);
	//printf("%d\n", printf("num = %d\n", num));

	//printf("%d..\n", scanf("%2c%n", &c, &num));
	//printf("%c\n", c);
	//printf("num = %d", num);

	scanf("%*4s %d", &num);
	printf("num = %d\n", num);

	return EXIT_SUCCESS;
}
