#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX(x, y)       ((x) > (y) ? (x) : (y))


static int cross(int *pint, int x, int y, int n, int d)
{
        int i = 0;
            int sum = 0;
                
                for (i = 0; i < d; i++)
                        {
                                    sum += pint[x*n + y+i];
                                        }
                    
                    return sum;
}


static int rightlower(int *pint, int x, int y, int n, int d)
{
        int i = 0;
            int sum = 0;
                
                for (i = 0; i < d; i++)
                        {
                                    sum += pint[(x+i)*n + y+i];
                                        }
                    
                    return sum;
}

static int vertical(int *pint, int x, int y, int n, int d)
{
        int i = 0;
            int sum = 0;
                
                for (i = 0; i < d; i++)
                        {
                                    sum += pint[(x+i)*n + y];
                                        }
                    
                    return sum;
}

static int leftlower(int *pint, int x, int y, int n, int d)
{
        int i = 0;
            int sum = 0;
                
                for (i = 0; i < d; i++)
                        {
                                    sum += pint[(x+i)*n + y-i];
                                        }
                    
                    return sum;
}

static int find_maxadd(int *pint, int n, int d)
{
        int i = 0;
            int j = 0;
                int sum = 0;
                    int max = cross(pint, 0, 0, n, d);
                        
                        for (i = 0; i < n; i++)
                                {
                                            for (j = 0; j < n; j++)
                                                        {
                                                                        if (j + d <= n) // 从左到右
                                                                                        {
                                                                                                            sum = cross(pint, i, j, n, d);
                                                                                                                            max = MAX(max, sum);
                                                                                                                                        }
                                                                                    if (j + d <= n && i + d <= n) // 左上到右下
                                                                                                    {
                                                                                                                        sum = rightlower(pint, i, j, n, d);
                                                                                                                                        max = MAX(max, sum);
                                                                                                                                                    }
                                                                                                if (i + d <= n) // 从上到下
                                                                                                                {
                                                                                                                                    sum = vertical(pint, i, j, n, d);
                                                                                                                                                    max = MAX(max, sum);
                                                                                                                                                                }
                                                                                                            if (i - d >= -1 && j - d >= -1) // 右上到左下
                                                                                                                            {
                                                                                                                                                sum = leftlower(pint, i, j, n, d);
                                                                                                                                                                max = MAX(max, sum);
                                                                                                                                                                            }
                                                                                                                        
                                                                                                                        printf("max = %d", max);
                                                                                                                                }
                                                }
                            
                            return max;
}


int main(int argc, char *argv[])
{
    int i = 0;
    int n = 0;
    int d = 0;
    int max = 0;
    int *pint = NULL;
                            
    scanf("%d", &n);
    scanf("%d", &d);

    pint = (int *)malloc(n * n * sizeof(*pint));
    assert(pint);

    for (i = 0; i < n * n; i++)
    {
        scanf("%d", &pint[i]);
    }
                                                
    max = find_maxadd(pint, n, d);
    printf("%d", max);
                                                        
    return EXIT_SUCCESS;
}
