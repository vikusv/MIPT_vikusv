#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

unsigned long long gcd(int *x, int *y);
int sort(int *x, int *y, int *a, int *b, int*d);

int main() 
{
    int a = 0, b = 0, x = 0, y = 0, xold = 0, yold = 0, d = 0, res = 0;
    
    res = scanf("%d %d %d", &x, &y, &d);
    xold = x; yold = y;
    assert(res == 3);
    res = sort(&xold, &yold, &a, &b, &d);
    if (res == 1)
        printf("%d %d\n", a,b);
    else if (res == 0)
        printf("NONE\n");

    return 0;
}

int sort(int *x, int *y, int *a, int *b, int *d) 
{
    int help, xold, yold;
    xold = *x, yold = *y;
    if (*x < 0 && *y < 0)
    {
        *x = abs(*x); 
        *y = abs(*y);
        *d = -(*d);
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
            if ((*b) == (pow(2, (8*sizeof(int))) / 2 - 1))
                return 0;
            if ((*b) * (*y) >= (*d))
            {
                help = (-(*d) + (*b) * (*y)) % (abs(*x));
                *a = (-(*d) + (*b) * (*y)) / (abs(*x));
                if (xold > 0)
                    *a = -(*a);
            }
            else 
            {
                help = ((*d) - (*b) * (*y)) % (abs(*x));
                *a = ((*d) - (*b) * (*y)) / (abs(*x));
                if (xold > 0)
                    *a = -(*a);
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
            if ((*b) == (pow(2, 16) / 2 - 1))
                return 0;
            if ((*b) * (*y) >= (*d))
            {
                help = (-(*d) + (*b) * (*y)) % (*x);
                *a = (-(*d) + (*b) * (*y)) / (*x);
            }
            else 
            {
                help = ((*d) - (*b) * (*y)) % (*x);
                *a = ((*d) - (*b) * (*y)) / (*x);
            }
            if (*d > abs(xold) || *d > abs(yold))
                *a = (*a);
            else 
                *a = -(*a);
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

    return 1;
}