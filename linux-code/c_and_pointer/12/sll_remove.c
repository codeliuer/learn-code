#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int 
sll_remove(struct NODE** rootp, struct NODE* node)
{
	if (*rootp == NULL || node == NULL)
	{
		return EXIT_SUCCESS;
	}

	while (*rootp != node)
	{
		rootp = &(*rootp)->next;
	}

	*rootp = (*rootp)->next;
	free(node);

	return EXIT_SUCCESS;
}
