/*
** eight queen question
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N           (10)

#define Q           'Q'
#define X           'X'

#define SET         (0)
#define CLEAR       (1)


typedef unsigned char   bool;
typedef unsigned char   utype_t;


static unsigned int count = 0;
static utype_t queen[N][N] = {0};


static void
z_hash(int line, int row, bool flg)
{
    int i = 0;

    for (i = 0; i < N; i++)
    {
        if (i != line)
        {
            (flg==CLEAR) ? queen[i][row]-- : queen[i][row]++;
        }
    }
}

static void
h_hash(int line, int row, bool flg)
{
    for (; row < N; row++)
    {
        (flg==CLEAR) ? queen[line][row]-- : queen[line][row]++;
    }
}

static void
x_hash(int line, int row, bool flg)
{
    for (; (line<N) && (row<N); line++, row++)
    {
        (flg==CLEAR) ? queen[line][row]-- : queen[line][row]++;
    }
}

static void
y_hash(int line, int row, bool flg)
{
    for (; (line>=0) && (row<N); line--, row++)
    {
        (flg==CLEAR) ? queen[line][row]-- : queen[line][row]++;
    }
}

/*     y_hash
** --XX----
** --QXXXXX  h_hash
** --XX----
** --X-X---
**z_hash x_hash
*/
static void
hash_queen(int line, int row, bool flg)
{
    z_hash(line, row, flg);
    h_hash(line, row+1, flg);
    x_hash(line+1, row+1, flg);
    y_hash(line-1, row+1, flg);
}

static void
seg_symbol(int num)
{
    int i = 0;

    for (i = 0; i < num*N; i++)
    {
        putchar('#');
    }
    putchar('\n');
}

static void
show(void)
{
    int i = 0;
    int j = 0;
    int num = 3;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-*.c", num, (queen[i][j]==Q) ? Q : '.');
        }

        printf("\n");
    }

    seg_symbol(num);
}

static void
eight_queen_question(int row)
{
    int i = 0;

    for (i = 0; i < N; i++)
    {
        if (queen[i][row] == 0)
        {
            queen[i][row] = Q;
            hash_queen(i, row, SET);

            if (row+1 != N)
            {
                eight_queen_question(row+1);
            }
            else
            {
                show();
                count++;
            }
        }

        if (queen[i][row] == Q)
        {
            queen[i][row] = 0;
            hash_queen(i, row, CLEAR);
        }
    }
}

int
main(int argc, char* argv[])
{
    eight_queen_question(0);
    printf("count = %d\n", count);

    return EXIT_SUCCESS;
}
