#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HUNDRED                 (100)
#define THOUSAND                (1000)

#define STRNCPY(dest, src)      strncpy(dest, src, strlen(src))


static char* word_low[] = 
            {
                "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
                "EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ", 
                "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
                "NINETEEN ",
            };

static char* word_mid[] = 
            {
                "", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", 
                "SEVENTY ", "EIGHTY ", "NINETY ",
            };

static char* word_high[] = 
            {
                "", "THOUSAND ", "MILLION ", "BILLION ",
            };

static void
do_one_group(unsigned int value, char* string, char** class)
{
    int tmp = 0;

    tmp = value / THOUSAND;
    if (tmp > 0)
    {
        do_one_group(tmp, string, class+1);
    }

    value %= THOUSAND;
    tmp = value / HUNDRED;
    if (tmp > 0)
    {
        strcat(string, word_low[tmp]);
        strcat(string, "HUNDRED ");
    }

    tmp = value % HUNDRED;
    if (tmp >= 20)
    {
        strcat(string, word_mid[tmp/10]);
        tmp %= 10;
    }
    strcat(string, word_low[tmp]);

    strcat(string, *class);
}

static void
written_buffer(unsigned int value, char* string)
{
    if (value == 0)
    {
        /*
        ** Special case of zero 
        */
        STRNCPY(string, "ZERO");
    }
    else
    {
        do_one_group(value, string, word_high);
    }
}

int
main(int argc, char* argv[])
{
    char string[BUFSIZ] = "";
    unsigned int value = 0;

    printf("Enter value = ");
    while (scanf("%d", &value))
    {
        written_buffer(value, string);
        printf("%s\n", string);
        printf("Enter value = ");
        memset(string, 0, strlen(string));
    }

    return EXIT_SUCCESS;
}
