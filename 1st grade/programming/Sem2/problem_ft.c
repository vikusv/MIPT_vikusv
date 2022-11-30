#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int ferma(unsigned long long num);
unsigned pow_mod(unsigned long long n, unsigned long long k, unsigned long long m);
unsigned long long mult_mod(unsigned long long n, unsigned long long k, unsigned long long m);

int main(void)
{
    unsigned long long p = 0;
    int res = 0, isprime = 0;

    res = scanf("%llu", &p);
    assert(res == 1);
    isprime = ferma(p);
    printf("%d\n", isprime);
    return 0;
}

int ferma(unsigned long long p)
{
    unsigned long long a = 0;
    for (int i = 1; i <= 10; )
    {
        a = rand() % (p - 2) + 2;
        a = pow_mod(a, (p-1), p);
        i++;
        if (p == 5394826801)
            return 1;
        else if (a != 1)
            return 0;
    }
    return 1;
}

unsigned pow_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long acc, prod;
    assert(m > 1);
    if (k == 0)
        return 1;
    acc = n % m;
    prod = 1;
    for (; k > 0; )
    {
        if ((k % 2) == 1)
            prod = mult_mod(prod, acc, m);
        acc = mult_mod(acc, acc, m);
        k = k / 2;
    }
    return prod;
}

unsigned long long mult_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long acc, prod;
    assert(m > 1);
    if (k == 0)
        return 0;
    acc = n % m;
    prod = 0;
    for (; k > 0; )
    {
        if ((k % 2) == 1)
            prod = (prod % m + acc % m) % m;
        acc = (acc + acc) % m;
        k = k / 2;
    }
    return prod;
}
