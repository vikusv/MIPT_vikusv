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

struct polinom pol_mult(struct polinom pol1, struct polinom pol2, struct polinom pol_res, int powA, int powB);

int main(void)
{
    int powA = 0, powB = 0, res = 0, max_pow = 0;

    struct polinom polA;
    struct polinom polB;
    struct polinom pol_res;

    res = scanf("%d %d", &powA, &powB);
    assert(res == 2);
    for (int i = 0; i < powA; )
    {
        res = scanf("%d", &polA.koeff[i]);
        assert(res == 1);
        i++;
    }
    for (int i = 0; i < powB; )
    {
        res = scanf("%d", &polB.koeff[i]);
        assert(res == 1);
        i++;
    }
    polA = init_pol(powA);
    polB = init_pol(powB);
    pol_res = init_pol(powA + powB - 1);
    pol_res = pol_mult(polA, polB, pol_res, powA, powB);
    for (int i = 0; i < (powA + powB) - 1; )
    {
        printf("%d ", pol_res.koeff[i]);
        i++;
    }
    printf("\n");

    return 0;
}

struct polinom pol_mult(struct polinom polA, struct polinom polB, struct polinom pol_res, int powA, int powB)
{
    for (int i1 = powA, i2 = powA + powB; i1 >= 0 && i2 >= 0; )
    {
        //unsigned A1B1 = polA.koeff[powA] * polB.koeff[powB];
        //unsigned A0B0 = polA.koeff[powA - 1] * polB.koeff[powB - 1]; 
        struct polinom polA_begin;
        struct polinom polB_begin;
        struct polinom polA_end;
        struct polinom polB_end;

        unsigned middle = powA / 2;
        if (middle > 0)
        {
            polA_begin = init_pol(middle);
            polB_begin = init_pol(middle);
            polA_end = init_pol(powA - middle);
            polB_end = init_pol(powB - middle);
            for (int i = 0; i < middle; i++)
            {
                polA_begin.koeff[i] = polA.koeff[i];
                polB_begin.koeff[i] = polA.koeff[i];
            }
            for (int i = middle; i < powA; i++)
            {
                polA_end.koeff[i] = polA.koeff[i];
                polB_end.koeff[i] = polA.koeff[i];
            }
        }
        
    }
    
    return pol_res;
}