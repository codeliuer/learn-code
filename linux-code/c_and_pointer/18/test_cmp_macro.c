#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define OFILED                      (0)
#define OTABLE                      (1 * CHAR_BIT)
#define PFIELD                      (2 * CHAR_BIT)
#define PTABLE                      (3 * CHAR_BIT)
#define SFIELD                      (4 * CHAR_BIT)
#define STABLE                      (5 * CHAR_BIT)


#define DV_CMPBIT                   (CHAR_BIT)


/* n <= 31 (32bits system) */
#define make_1(n)                           ~(((unsigned)~0 >> (n)) << (n))
/* truncate low truncs bit */
#define truncate(values, nshifts, truncs)   (((values) >> (nshifts)) & make_1(truncs))

/*
 * ** values, cmpValues :  compared data
 * ** nShift :             left-shift bits
 * ** cmpBits:             low compared
 * */
#define IS_EQUAL(values, cmpValues, nShift, cmpBits)                \
        ((truncate(values, nShift, cmpBits) == truncate(cmpValues, nShift, cmpBits)) ? 0 : -1)


/* filed version */
#define OTHER_FIELD_CMP(values, cmpValues)      IS_EQUAL(values, cmpValues, OFILED, DV_CMPBIT)
#define PROGRAM_FILED_CMP(values, cmpValues)    IS_EQUAL(values, cmpValues, PFIELD, DV_CMPBIT)
#define SYSTEM_FIELD_CMP(values, cmpValues)     IS_EQUAL(values, cmpValues, SFIELD, DV_CMPBIT)

/* table version */
#define OTHER_TABLE_CMP(values, cmpValues)      IS_EQUAL(values, cmpValues, OTABLE, DV_CMPBIT)
#define PROGRAM_TABLE_CMP(values, cmpValues)    IS_EQUAL(values, cmpValues, PTABLE, DV_CMPBIT)
#define SYSTEM_TABLE_CMP(values, cmpValues)     IS_EQUAL(values, cmpValues, STABLE, DV_CMPBIT)


int
main(int argc, char* argv[])
{
    long int cmp1 = 0x0102030405;
    long int cmp2 = 0x0302040500;

    if (PROGRAM_TABLE_CMP(cmp1, cmp2) == 0)
    {
        printf("%s\n", "equal");
    }

    return EXIT_SUCCESS;
}
