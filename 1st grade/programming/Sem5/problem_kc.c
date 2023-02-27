#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define R 5
#define Q 10

int get_hash(const char *start, const char *fin);
int update_hash(int current, int n, char cprev, char cnext);
unsigned long long pow_mod(unsigned n, unsigned k, unsigned m);
int rabin_karp(const char *needle, const char *haystack);

int main(void)
{
    int position = 0;
    const char haystack[150] = {'s', 'c', 'f', 'h', 'y', 'j', 's', 'J', 'p', 'I', 'G', 'O', 'l', 'k', 'p', 'W', 'H', 'u', 'M', 'Q', 'o', 'o', 'Y', 'y', 'j', 's', 'J', 'p', 'I', 'G', 'O', 'l', 'k', 'b', 'D', 'T', 'e', 'p', 'R', 'c', 'I', 'P', 'A', 'k', 'A', 'T', 'Z', 'g', 'r', 'W', 'b', 'q', 'r', 'G', 'N', 'y', 'j', 's', 'J', 'p', 'y', 'j', 's', 'J', 'p', 'I', 'G', 'O', 'l', 'k', 'I', 'G', 'O', 'l', 'k', 'd', 'w', 'B', 'r', 'j', 'm', 'n', 'd', 'H', 'j', 't', 'y', 'Q', 'Q', 'o', 'y', 'j', 's', 'J', 'p', 'I', 'G', 'O', 'l', 'k', 'd', 'q', 'j', 'Z', 'P', 'd', 'I', 't', 'A', 'n', 'd', 'S', 'W', 'N', 'j', 'a', 'p', 'y', 'g', 'l', 'd', 's', 'Y', 'e', 'Z', 'z', 'm', 'e', 'O', 'G', 'K', 'j', 'l', 'P', 'f', 'h', 'd', 'J', 'z', 'L', 'N', 'w', 'j', 'C', 'r', 'Y', 'v', 'm', 'D'};
    const char needle[10] = {'y', 'j', 's', 'J', 'p', 'I', 'G', 'O', 'l', 'k'};

    position = rabin_karp(needle, haystack);
    printf("%d\n", position);

    return 0;
}

int rabin_karp(const char *needle, const char *haystack)
{
    unsigned n = 0, target = 0, cur = 0, left = 0, right = strlen(needle), needle_len = strlen(needle), haystack_len = strlen(haystack);
    unsigned i = 0;
    
    target = get_hash(needle, needle + right);
    cur = get_hash(haystack, haystack + right);
    n = pow_mod(R, right - 1, Q);

    if (target == cur)
    {
        while (haystack[left + i] == needle[i] && i < needle_len)
            i++;
        if (i == needle_len)
            return left;
    }
    i = 0;

    while (right <= haystack_len - 1) 
    {
        cur = update_hash(cur, n, haystack[left], haystack[right]);
        left += 1;
        right += 1;

        if (target == cur)
        {
            while (haystack[left + i] == needle[i] && i < needle_len)
                i++;
            if (i == needle_len)
                return left;
        }
        i = 0;
    }
    
    return -1;
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

int get_hash(const char *start, const char *fin)
{
    
}
