/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int arrpopcount(const unsigned char *parr, int len);

int main(void)
{
    int len = 5, count = 0;
    const unsigned char parr[5] = {26, 9, 1, 11, 217};
    count = arrpopcount(parr, len);
    printf("%d\n", count);
    return 0;
}
*/
int arrpopcount(const unsigned char *parr, int len)
{
    int val = 0, count = 0;
    for (int i = 0; i < len; )
    {
        for (int ii = 0; ii < 8; )
        {
            val = (parr[i] >> (ii)) & 1u;
            if (val == 1)
                count++;
            ii++;
        }
        i++;
    }
    return count;
}
