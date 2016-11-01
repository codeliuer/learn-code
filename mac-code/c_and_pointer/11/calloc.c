#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


static void* 
mycalloc(size_t count, size_t size)
{
	void* tmp = NULL;

	tmp = malloc(count*size);
	assert(tmp != NULL);

	printf("tmp = %p\n", tmp);

	return tmp;
}


int
main(int argc, char* argv[])
{
	mycalloc(100, 2);

	return EXIT_SUCCESS;
}
