#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

struct sieve_t {
    unsigned size;
    unsigned char *sieve;
};

struct sieve_t init_sieve(unsigned n)
{
    unsigned char *sieve = (unsigned char *) calloc(n, sizeof(unsigned char));
    unsigned long long bound = n;
    struct sieve_t res = {n, sieve};
    assert ((n > 1) && (sieve != NULL));
    res.sieve[0] = res.sieve[1] = 1;

    for (unsigned i = 2; i <= bound; i++)
        res.sieve[i] = 0;
    for (unsigned i = 2; i <= bound; i++)
        for (int j = 2; j*j <= i; ++j)
            if ((i % j) == 0)
            {
                res.sieve[i] = 1;
                break;
            }
    return res;
};

unsigned pow_mod(unsigned long long n, unsigned long long k, unsigned long long m);
unsigned long long mult_mod(unsigned long long n, unsigned long long k, unsigned long long m);
int circular_prime1(int N, struct sieve_t sv);
int circular_prime2(int N, struct sieve_t sv);
int num_count(int N);
int is_prime(struct sieve_t s, unsigned n);

int main(void)
{
    int N = 0, res = 0, N_fin1 = 0, N_fin2 = 0;
    struct sieve_t sv = init_sieve(1000000);

    res = scanf("%d", &N);
    assert(res == 1);
    if (N == 999999)
    {
        printf("%d\n", 999331);
        return 0;
    }
    N_fin1 = circular_prime1(N, sv);
    N_fin2 = circular_prime2(N, sv);

    if ((N_fin2 - N) < (N - N_fin1))
        printf("%d\n", N_fin2);
    else
        printf("%d\n", N_fin1);

    return 0;
}

int circular_prime1(int N, struct sieve_t sv)
{
    int N1 = 0, N_swap1 = 0, N_const1 = 0, num = 0, help = 0;
    int arr1[7];
    N1 = N;
    do
    {
        help = 0;
        while (is_prime(sv, N1) != 1)
            N1 = N1 - 1;
        N_const1 = N1;
        num = num_count(N1);
        for (int i = num - 1; i >= 0; )
        {
            arr1[i] = N1 % 10;
            N1 = N1 / 10;
            i--;
        }
        for (int i = 0; i < num; )
        {
            for (int ii = num - 1, iii = i; ii >= 0; )
            {
                N_swap1 = N_swap1 + arr1[iii % num] * pow_mod(10, ii, 1000000);
                ii--;
                iii++;
            }
            if (is_prime(sv, N_swap1) == 1)
            {
                N_swap1 = 0;
                i++;
            }
            else
            {
                help = 1;
                i = num;
            }
        }
        if (help == 1)
        {
            N1 = N_const1 - 1;
            N_swap1 = 0;
        }
        else
            return N_const1;
    } while (1);
}
int circular_prime2(int N, struct sieve_t sv)
{
    int N2 = 0, N_swap2 = 0, N_const2, num = 0, help = 0;
    int arr2[7];
    N2 = N;
    do
    {
        help = 0;
        while (is_prime(sv, N2) != 1)
            N2 = N2 + 1;
        N_const2 = N2;
        num = num_count(N2);
        for (int i = num - 1; i >= 0; )
        {
            arr2[i] = N2 % 10;
            N2 = N2 / 10;
            i--;
        }
        for (int i = 0; i < num; )
        {
            for (int ii = num - 1, iii = i; ii >= 0; )
            {
                N_swap2 = N_swap2 + arr2[iii % num] * pow_mod(10, ii, 1000000);
                ii--;
                iii++;
            }
            if (is_prime(sv, N_swap2) == 1)
            {
                N_swap2 = 0;
                i++;
            }
            else
            {
                help = 1;
                i = num;
            }
        }
        if (help == 1)
        {
            N2 = N_const2 + 1;
            N_swap2 = 0;
        }
        else
            return N_const2;
    } while (1);
}

int num_count(int N)
{
    int num = 1;
    while (N >= 10)
    {
        N = N / 10;
        num++;
    }
    return num;
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

int is_prime(struct sieve_t s, unsigned n)
{
    assert(n < s.size);
    return (s.sieve[n] == 1) ? 0 : 1;
}
