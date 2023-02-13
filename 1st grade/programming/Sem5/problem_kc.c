#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define R 1
#define Q 1

int get_hash(const char *start, const char *fin);
int update_hash(int current, int n, char cprev, char cnext);
unsigned long long pow_mod(unsigned n, unsigned k, unsigned m);
int rabin_karp(const char *needle, const char *haystack);

int main(void)
{

}

int rabin_karp(const char *needle, const char *haystack)
{
    unsigned n = 0, target = 0, cur = 0, count = 0, left = 0, right = strlen(needle);
    
    target = get_hash(needle, needle + right);
    cur = get_hash(haystack, haystack + right);
    n = pow_mod(R, right - 1, Q);

    while(1) 
    {
        cur = update_hash(cur, n, haystack[left], haystack[right]);
        left += 1;
        right += 1;

                
    }
    
    return (target == cur) ? left : -1;
}


unsigned long long pow_mod(unsigned n, unsigned k, unsigned m) 
{
    unsigned long long acc, prod;
    assert(m > 1);

    if (k == 0)
        return 1;

    acc = n % m;
    prod = 1;

    for (; k > 0;)
    {
        if ((k % 2) == 1)
        prod = (prod * acc) % m;
        acc = (acc * acc) % m;
        k = k / 2;
    }

    return prod;
}
