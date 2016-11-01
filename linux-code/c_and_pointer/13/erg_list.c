#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	PUBLIC	//extern interface


struct NODE
{
	void*			pData;
	struct NODE*	next;
};


typedef void (*FPNotify)(struct NODE *);


static void
notify(struct NODE* node)
{
	printf("%p\n", node->pData);
}

PUBLIC int 
erg_list(struct NODE* phead, FPNotify callback)
{
	while (phead != NULL)
	{
		callback(phead);

		phead = phead->next;
	}

	return 0;
}

int
main(int argc, char* argv[])
{
	struct NODE* phead = NULL;

	erg_ist(phead, notify);

	return EXIT_SUCCESS;
}
