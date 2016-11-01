/*
** test list interface
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int
main(int argc, char * argv[])
{
    PERSON *head = NULL;

    insert_info(&head, "mac", 21);
    insert_info(&head, "apple", 22);
    insert_info(&head, "node 7", 23);
    insert_info(&head, "iphone 7s", 29);
    print_info(head);
    printf("------------------------------------------------------\n");
    printf("------------------------------------------------------\n");

    printf("delete info\n");
    delete_info(&head, "apple", NAME_F);
    delete_info(&head, (void *)29, AGE_F);
    print_info(head);

    return EXIT_SUCCESS;
}
