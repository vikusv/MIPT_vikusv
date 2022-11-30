#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned n);

int main(void) 
{
    unsigned long long N = 0, i = 0, count = 0;
    int res;
    
    res = scanf("%llu", &N);
    assert(res == 1);
    while (count < N)
    {
        i++;
        if (is_prime(i))
            count++;
    }
    printf("%llu\n", i);
    return 0;
}

int is_prime(unsigned n)
{
    if ((n == 2) || (n == 3)) 
        return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) 
        return 0;
    for (int j = 5; j * j <= n; j += 6)
    {
        if (((n % j) == 0) || ((n % (j + 2)) == 0))
            return 0;
    }
    return 1;
}
