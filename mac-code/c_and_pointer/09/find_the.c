#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int 
find_string(char* string, const char* restrict dest)
{
    int count = 0;
    char* word = NULL;
    const char seg[] = " ";

    for (word = strtok(string, seg);
            word != NULL;
        word = strtok(NULL, seg))
    {
        if (strcmp(word, dest) == 0)
        {
            count++;
        }
    }

    return count;
}

int
main(int argc, char* argv[])
{
    char string[] = "the the aathe the theaa";

    printf("%d\n", find_string(string, "the"));

    return EXIT_SUCCESS;
}
