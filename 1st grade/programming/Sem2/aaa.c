#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

unsigned long long sieve_bound(unsigned num);
double log(double x);

struct sieve_t {
    unsigned size;
    unsigned char *sieve;
};

struct sieve_t init_sieve(unsigned n) 
{
    unsigned char *sieve = (unsigned char *) calloc(sieve_bound(n), sizeof(unsigned char));
    struct sieve_t res = {sieve_bound(n), sieve};
    assert ((n > 1) && (sieve != NULL));
    res.sieve[0] = res.sieve[1] = 1;
    unsigned long long bound = sieve_bound(n);

    for (int i=2; i <= bound; i++) 
        res.sieve[i] = 0;
    for (int i = 2; i <= bound; i++) 
        for (int j = 2; j*j <= i; ++j)
        if ((i % j) == 0) 
        {
           res.sieve[i] = 1;
           break; 
        }
    return res;    
};

int is_prime(struct sieve_t s, unsigned n);

int main(void)
{
    int N = 0, res = 0;

    res = scanf("%d", &N);
    assert(res == 1);
    struct sieve_t sv = init_sieve(100);
    res = is_prime(sv, N);
    printf("%d\n", res);

    return 0;
}

unsigned long long sieve_bound(unsigned num) 
{
    assert(num > 20);
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (unsigned long long)dres;
}

double log(double x) 
{
    double y = 2;
    unsigned long long kol = 1;

    while (y <= x) 
    {
        y *= 2;
        kol++;
    } 
    return kol;
}

int is_prime(struct sieve_t s, unsigned n) 
{
    assert(n < s.size);
    return (s.sieve[n] == 1) ? 0 : 1;
}
