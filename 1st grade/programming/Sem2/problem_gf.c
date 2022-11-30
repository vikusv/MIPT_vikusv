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

int near_prime_min(int N, struct sieve_t sv);
int is_prime(struct sieve_t s, unsigned n);

int main(void)
{
    int N = 0, res = 0, x = 0, count = 0, count0 = 0, a0 = 0, b0 = 0;
    int b = 0, a = 0;
    struct sieve_t sv = init_sieve(10000);

    res = scanf("%d", &N);
    assert(res == 1);
    b = near_prime_min(N - 1, sv);
    while (b > 2)
    {
        while (a < N)
        {
            do
            {
                x = count * count - a * count + b;
                count++;
            } while ((x > 0) && (is_prime(sv, x) == 1));
            if (count >= count0)
            {
                count0 = count;
                a0 = a;
                b0 = b;
            }
            a++;
            count = 0;
        }
        b = near_prime_min(b - 1, sv);
        a = 0;
    }
    printf("%d %d %d\n", -a0, b0, count0 - 1);

    return 0;
}

int near_prime_min(int N, struct sieve_t sv)
{
    while (is_prime(sv, N) != 1)
        N = N - 1;
    return N;
}

int is_prime(struct sieve_t s, unsigned n)
{
    assert(n < s.size);
    return (s.sieve[n] == 1) ? 0 : 1;
}
