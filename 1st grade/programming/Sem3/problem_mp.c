#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

struct polinom {
    unsigned pow;
    unsigned *koeff;
};

struct polinom init_pol(unsigned n) 
{
    unsigned *koeff = (unsigned *) calloc(n, sizeof(unsigned));
    struct polinom res = {n, koeff};
    assert ((n > 1) && (koeff != NULL));
    for (int i = 0; i < n; )
    {
        res.koeff[i] = 0;
        i++;
    }
    return res;    
};

struct polinom pol_mult(struct polinom pol1, struct polinom pol2, struct polinom pol_res);

int main(void)
{
    int pow1 = 0, pow2 = 0, res = 0, max_pow = 0;

    struct polinom pol1;
    struct polinom pol2;
    struct polinom pol_res;
    res = scanf("%d %d", &pow1, &pow2);
    assert(res == 2);
    max_pow = pow1 + pow2 - 1;
    pol1 = init_pol(max_pow);
    pol2 = init_pol(max_pow);
    pol_res = init_pol(max_pow);
    for (int i = 0; i < pow1; )
    {
        res = scanf("%d", &pol1.koeff[i]);
        assert(res == 1);
        i++;
    }
    for (int i = 0; i < pow2; )
    {
        res = scanf("%d", &pol2.koeff[i]);
        assert(res == 1);
        i++;
    }
    pol_res = pol_mult(pol1, pol2, pol_res);
    for (int i = 0; i < max_pow - 1; )
    {
        printf("%d ", pol_res.koeff[i]);
        i++;
    }
    if (pol_res.koeff[max_pow - 1] != 0)
        printf("%d ", pol_res.koeff[max_pow - 1]);

    return 0;
}

struct polinom pol_mult(struct polinom pol1, struct polinom pol2, struct polinom pol_res)
{
    for (int i = 0; i <= pol_res.pow; )
    {
        for (int ii = 0; ii <= i; )
        {
            pol_res.koeff[i] = pol_res.koeff[i] + pol1.koeff[ii] * pol2.koeff[i - ii];
            ii++;
        }
        i++;
    }
    return pol_res;
}
