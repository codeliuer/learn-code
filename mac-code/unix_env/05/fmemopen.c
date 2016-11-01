#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    size_t n = 0;
    FILE* fp = NULL;
    char* ptr = NULL;

    fp = open_memstream(&ptr, &n);
    if (fp  == NULL)
    {
        fprintf(stderr, "open memory stream failure\n");
        exit(EXIT_FAILURE);
    }
    fwrite("123", 1, 3, fp);
    fflush(fp);
    printf("str[n] = %d\n", ptr[12]);
    fwrite("123", 1, 3, fp);
    fwrite("123", 1, 3, fp);
    fwrite("123", 1, 3, fp);
    fflush(fp);
//    fclose(fp);
    printf("n = %ld\n", n);
    printf("str: %s\n", ptr);
    printf("str[n] = %d\n", ptr[12]);
    fclose(fp);

    return EXIT_SUCCESS;
}
