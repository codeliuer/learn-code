#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUL             ('\0')

#define STRING_LEN      (50)

static int commonSubLen(const char *sa, const char *sb)
{
    int len = 0;
            
    while (*sa != NUL && *sb != NUL && *sa == *sb)    
    {
        len++;
        sa += 1;
        sb += 1;
    }
                
    return len;
}

static int maxSubLen(const char *sa, const char *sb)
{
    int ai = 0;
    int bi = 0;
    int la = 0;
    int lb = 0;
    int thislen = 0;
    int maxlen = 0;
                                
    if (sa == NULL || sb == NULL)
    {
        return 0;
    }
                                    
    la = strlen(sa);
    lb = strlen(sb);
                                            
    for (ai = 0; ai < la; ai++)
    {
        for (bi = 0; bi < lb; bi++)
        {
            if (sa[ai] == sb[bi])
            {
                thislen = commonSubLen(&sa[ai], &sb[bi]);
                if (thislen > maxlen)
                {
                    maxlen = thislen;
                }
            }
        }
    }
                                                
    return maxlen;
}

int main(int argc, char *argv[])
{
    int maxsublen = 0;
    char stra[STRING_LEN] = "";
    char strb[STRING_LEN] = "";
                    
    scanf("%s", stra);
    scanf("%s", strb);
                            
    maxsublen = maxSubLen(stra, strb);
    printf("%d", maxsublen);
                                    
    return EXIT_SUCCESS;
}
