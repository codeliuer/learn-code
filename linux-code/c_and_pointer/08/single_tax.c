/*
** The federal government to use there rules to compute each citizen's
** personal income tax in 1995
*/

/*********************************************************************************
  If your tax revenue       But i don't     Your shall          More than the  
  is greater than           noisy over      be the              amount of the part
  --------------------------------------------------------------------------------
        $0                  $23,350                  15%                $0
    23 350                   56,550         $3502.50+28%            23 350
    56 550                  117,950        12 798.50+31%            56 550
   117 950                  256,500        31 832.50+36%           117 950
   256 500                     ----       81 710.50+39.6%          256 500
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE            (1)


static void
clear(void)
{
    scanf("%*[^\n]");
    scanf("%*c");
}

static int 
isincome(double* pd)
{
    while (TRUE)
    {
        printf("Enter income(0 replace quit):");
        if (scanf("%lf", pd) && *pd >= 0)
        {
            clear();
            return (*pd == 0) ? 0 : !0;
        }
        clear();
    }
}

static float
singal_tax(float income)
{
    unsigned int value = (unsigned int)income;

    if (0 < value && value <= 23350)
    {
        return value*0.15;
    }
    else if (value > 23350 && value <= 56550)
    {
        return 3502.50+(value-23350)*0.28;
    }
    else if (value > 56550 && value <= 117950)
    {
        return 12798.50+(value-56550)*0.31;
    }
    else if (value > 117950 && value <= 256500)
    {
        return 31832.50+(value-117950)*0.36;
    }
    else
    {
        return 81710.50+(value-256500)*0.396;
    }
}

int
main(int argc, char* argv[])
{
    double income = 0.0;

    while (isincome(&income))
    {
        printf("%f\n", singal_tax((float)income));
    }

    return EXIT_SUCCESS;
}
