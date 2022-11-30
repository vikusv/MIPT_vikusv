#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int ferma(unsigned long long num);
unsigned pow_mod(unsigned long long n, unsigned long long k, unsigned long long m);
unsigned long long pow_simple(unsigned long long n, unsigned long long k);
unsigned long long mult_mod(unsigned long long n, unsigned long long k, unsigned long long m);
unsigned long long prime_fib(int k, int n);
unsigned long long fib(unsigned long long n);

int main(void)
{
    unsigned long long prime = 0;
    int res = 0, k = 0, n = 0;

    res = scanf("%d %d", &k, &n);
    assert(res == 2);
    prime = prime_fib(k, n);
    printf("%llu\n", prime);
    return 0;
}

unsigned long long prime_fib(int k, int n)
{
    unsigned long long max = (pow_simple(2, 62) + (pow_simple(2, 62) - 1)), fib_0 = 0, fib_1 = 1, fib_2 = 0, prime_fib = 0;
    fib_0 = k * fib_1 + n * fib_2;
    fib_2 = fib_1;
    fib_1 = fib_0;
    if ((fib_0 > 2 && ferma(fib_0) == 1) || fib_0 == 2)
        prime_fib = fib_0;
    fib_0 = k * fib_1 + n * fib_2;
    fib_2 = fib_1;
    fib_1 = fib_0;
    if ((fib_0 > 2 && ferma(fib_0) == 1) || fib_0 == 2)
        prime_fib = fib_0;
    while (max - k * fib_1 > n * fib_2)
    {
        fib_0 = k * fib_1 + n * fib_2;
        if (ferma(fib_0) == 1)
            prime_fib = fib_0;
        fib_2 = fib_1;
        fib_1 = fib_0;
    }
    return prime_fib;
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

unsigned long long pow_simple(unsigned long long n, unsigned long long k)
{
    unsigned long long prod = n;
    if (k == 0)
        return 1;
    for (int i = 0; i < k; )
    {
        prod = prod * n;
        i++;
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

unsigned long long fib(unsigned long long n)
{
    unsigned long long first = 0, second = 1;
    unsigned long long idx, tmp = 0;
    if (n == 0)
        return 0;
    for (idx = 2; idx <= n; ++idx) {
        tmp = second;
        second = second + first;
        first = tmp;
    }
    
    return second;
}
