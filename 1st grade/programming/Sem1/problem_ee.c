#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

unsigned long long gcd(long long int *x, long long int *y);
void sort(long long int *x, long long int *y, long long int *a, long long int *b, unsigned long long *d);

int main() 
{
    unsigned long long d = 0;
    int res;
    long long int a = 0, b = 0, x = 0, y = 0, xold = 0, yold = 0;
    
    res = scanf("%lld %lld", &x, &y);
    xold = x; yold = y;
    assert(res == 2);
    while ((d = gcd(&x, &y)) == 0);
    sort(&xold, &yold, &a, &b, &d);
    printf("%lld %lld %lld\n", a,b,d);
    return 0;
}

unsigned long long gcd(long long int *x, long long int *y) 
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

void sort(long long int *x, long long int *y, long long int *a, long long int *b, unsigned long long *d) 
{
    long long int help;
    long long int xold, yold;
    //*x = abs(*x); *y = abs(*y);
    xold = *x, yold = *y;
    if (*x < 0 && *y < 0)
    {
        *x = abs(*x); 
        *y = abs(*y);
    }
    if (*x > *y)
    {
        if (*y < 0)
        {
            help = abs(*y);
            *y = *x;
            *x = (-1) * help;
        }
        else
        {
            help = *y;
            *y = *x;
            *x = help;
        }
    }

    if (*x < 0)
    {
        help = (-1) * (-(*d) + (*b) * (*y)) % (abs(*x));
        while (help != 0)
        {
            (*b)++;
            if ((*b) * (*y) >= (*d))
            {
                help = (-(*d) + (*b) * (*y)) % (abs(*x));
                *a = (-(*d) + (*b) * (*y)) / (abs(*x));
                *a = (*a);
            }
            else 
            {
                help = ((*d) - (*b) * (*y)) % (abs(*x));
                *a = ((*d) - (*b) * (*y)) / (abs(*x));
                *a = (*a);
            }
        }
        
        if (*b == 0)
            *a = (-1) * (*d) / (abs(*x));

        if (xold > yold)
        {
            help = *a;
            *a = *b;
            *b = help;
        }
    }
    else
    {
        help = (-(*d) + (*b) * (*y)) % (*x);
        while (help != 0)
        {
            (*b)++;
            if ((*b) * (*y) >= (*d))
            {
                help = (-(*d) + (*b) * (*y)) % (*x);
                *a = (-(*d) + (*b) * (*y)) / (*x);
                *a = -(*a);
            }
            else 
            {
                help = ((*d) - (*b) * (*y)) % (*x);
                *a = ((*d) - (*b) * (*y)) / (*x);
                *a = -(*a);
            }
        }
        if (*b == 0)
            *a = (*d) / (*x);
        if (xold < 0 && yold < 0)
        {
            if (xold < yold)
            {
                help = *a;
                *a = *b;
                *b = help;
            }
            *a = -(*a); 
            *b = -(*b);
        }
        else
        {
            if (xold > yold)
            {
                help = *a;
                *a = *b;
                *b = help;
            }
        }
    }
}