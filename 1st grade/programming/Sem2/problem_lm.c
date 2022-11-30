#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

unsigned long long gcd(unsigned long long *x, unsigned long long *y);
unsigned long long lcm(unsigned long long x, unsigned long long y);

int main() 
{
    unsigned long long y = 0, i = 2, lcm_num = 2;
    int res;
    
    res = scanf("%llu", &y);
    assert(res == 1);
    while (i < y)
    {
        i++;
        lcm_num = lcm(lcm_num,i);
    }
    printf("%llu\n", lcm_num);
    return 0;
}

unsigned long long gcd(unsigned long long *x, unsigned long long *y) 
{
    unsigned long long q, help;
    *y = abs(*y);
    *x = abs(*x);
    if (*y > *x)
    {
        help = *y;
        *y = *x;
        *x = help;
        return 0;
    }
    assert (*y > 0);
    q = *x % *y;
    if (q == 0)
        return *y;
    *x = *y;
    *y = q;
    return 0;
}

unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    unsigned long long help1, help2;
    help1 = x * y;
    while ((help2 = gcd(&x, &y)) == 0);

    return help1/help2;
}
