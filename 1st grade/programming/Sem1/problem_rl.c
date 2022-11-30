#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

unsigned long long gcd(unsigned long long *x, unsigned long long *y);

int main() 
{
    unsigned long long x = 0, y = 0, g;
    int res;
    
    res = scanf("%llu %llu", &x, &y);
    assert(res == 2);
    while ((g = gcd(&x, &y)) == 0);
    printf("%llu\n", g);
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
