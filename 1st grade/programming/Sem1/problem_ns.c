#include <stdio.h>
#include <math.h>
#include <assert.h>

void scale(unsigned int x, unsigned int y, unsigned int *arr, int *i);
int main(void)
{
    unsigned int x = 0, y = 0, res = 0;
    int i = 0;
    unsigned int newnumarr[100] = {};
    
    res = scanf("%u %u", &x, &y);
    assert(res == 2);
    scale(x, y, newnumarr, &i);
    while (i >= 0)
    {
        printf("%u", newnumarr[i]);
        i--;
    }

    return 0;
}

void scale(unsigned int x, unsigned int y, unsigned int *arr, int *i)
{
    while (x >= y)
    {
        arr[*i] = x % y;
        x = x / y;
        (*i)++;
    } 
    arr[*i] = x;
}
