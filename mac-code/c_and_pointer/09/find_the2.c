#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int 
find_substring(const char* string, const char* sub)
{
    int i = 0;
    int j = 0;
    int num = 0;
    int string_len = strlen(string);
    int sub_len = strlen(sub);

    for (i = sub_len-1; i < string_len; i++)
    {
        if (string[i] == sub[sub_len-1])
        {
            for (j = 0; (j < sub_len-1) && (sub[j]==string[i-sub_len+1+j]); j++)
            {
                ;
            }

            if (j == sub_len-1)
            {
                num++;
            }
        }
    }

    return num;
}


int
main(int argc, char* argv[])
{
    int num = find_substring("eeeeee", "eee");

    printf("num = %d\n", num);

    return EXIT_SUCCESS;
}
