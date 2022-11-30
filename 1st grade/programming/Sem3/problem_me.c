/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int majority_element(const int *parr, int len);

int main(void)
{
    int len = 8, maj_elem = 0;
    const int parr[8] = {3, 3, 4, 2, 4, 4, 2, 4};
    maj_elem = majority_element(parr, len);
    printf("%d\n", maj_elem);
    return 0;
}
*/
int majority_element(const int *parr, int len)
{
    int parr1[100000];
    int parr2[100000];
    int i = 0, len1 = len, len2 = len, maj_elem1 = 0, maj_elem2 = 0, count1 = 0, count2 = 0;
    i = (len - 1) / 2;
    while (len > 1)
    {
        if (len == 2) 
        {
            if (parr[0] == parr[1])
                return parr[0];
            else
                return -1;
        }
        if (len == 3) 
        {
            if (parr[0] == parr[1] || parr[0] == parr[2])
                return parr[0];
            else if (parr[1] == parr[2])
                return parr[1];
            else
                return -1;
        }
        if (len % 2 == 1)
            len1 = len / 2 + 1;
        else
            len1 = len / 2;
        len2 = len - len1;
        for (int ii = 0; ii <= len1 - 1; )
        {
            parr1[ii] = parr[ii];
            ii++;
        }
        for (int ii = 0; ii <= len2 - 1; )
        {
            parr2[ii] = parr[ii + i + 1];
            ii++;
        }
        if (len1 > 0)
            maj_elem1 = majority_element(parr1, len1);
        if (len2 > 0)
            maj_elem2 = majority_element(parr2, len2);
        break;
    }
    //return 0;
    for (i = 0; i <= len - 1; )
    {
        if (parr[i] == maj_elem1)
        {
            count1++;
        }
        else if (parr[i] == maj_elem2)
        {
            count2++;
        }
        i++;
    }
    if (count1 > len / 2)
        return maj_elem1;
    else if (count2 > len / 2)
        return maj_elem2;
    else
        return -1;
}
