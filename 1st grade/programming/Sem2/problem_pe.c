#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
/*
struct sieve_t {
    unsigned size;
    unsigned char *sieve;
};

struct sieve_t init_sieve(unsigned n) 
{
    unsigned char *sieve = (unsigned char *) calloc(n, sizeof(unsigned char));
    struct sieve_t res = {n, sieve};
    assert ((n > 1) && (sieve != NULL));

    for (int byte = 0; byte <= n; byte++)
    {
        for (int bit = 0; bit <= 7; bit++)
            for (int j = 2; j*j <= (byte*8 + bit); ++j)
                if (((byte*8 + bit) % j) == 0)
                {
                    res.sieve[byte] = res.sieve[byte] ^ (1u << bit);
                    break;
                }
    }
    return res;    
};


int is_prime(struct sieve_t sv, unsigned n);

int main(void)
{
    int N = 0, res = 0;

    res = scanf("%d", &N);
    assert(res == 1);
    struct sieve_t sv = init_sieve(10);
    res = is_prime(sv, N);
    printf("%d\n", res);

    return 0;
}
*/
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

struct sieve_t {
    unsigned n;
    unsigned char *s;
};

int is_prime(struct sieve_t *sv, unsigned n)
{
    int val = (sv->s[n / 8] >> (n % 8)) & 1u;
    return !val;
}


void fill_sieve(struct sieve_t *sv)
{
    int val = 0;
    for (int i = 2; i < sv->n; i++)
    {
        if (is_prime(sv, i))
        {
            for (int mul = i * i; mul < sv->n; mul += i)
                sv->s[mul / 8] |= (1u << (mul % 8));
        }
    }
    for (int i = 0; i < 8; i++)
    {
        val = (sv->s[i / 8] >> (i % 8)) & 1u;
        printf("%d", val);
    }
    printf("\n");
}


int main (void)
{
    int len = 0, count = 0, i = 0, res = 0;
    res = scanf ("%d", &len);
    assert (res == 1);
    unsigned char *sv_buf = (unsigned char *) calloc (160, sizeof (char));
    struct sieve_t sv = {160, sv_buf};
    fill_sieve(&sv);
    while (count <= len + 1)
    {
        if (is_prime(&sv, i))
            count++;
        i++;
    }

    printf ("%d\n", i - 1);

    return 0;
}
