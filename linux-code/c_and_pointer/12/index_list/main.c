#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "index.h"


int
main(int argc, char* argv[])
{
	struct SINGLE_LIST* head = NULL;

	insert_word(&head, "liuwei");
	insert_word(&head, "liuwei");
	insert_word(&head, "liuwei");
	insert_word(&head, "liuwei");
	insert_word(&head, "liuwei");
	insert_word(&head, "wending");
	insert_word(&head, "liu");
	insert_word(&head, "a");
	insert_word(&head, "aaa");
	insert_word(&head, "bbb");
	show(head);

	return EXIT_SUCCESS;
}
