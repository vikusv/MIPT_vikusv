#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *key, const void *elt);

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp);
int intcmp(const void *x, const void *y);

int main(void) 
{
    int sorted[40] = {44, 60, 65, 153, 153, 174, 190, 192, 196, 236, 257, 264, 267, 300, 319, 324, 376, 445, 452, 464, 511, 576, 584, 609, 671, 682, 684, 693, 735, 737, 840, 906, 918, 931, 936, 940, 955, 960, 965, 975};
    
    int key = 324;
    
    void *bf = cbsearch(&key, sorted, 40, sizeof(int), intcmp);
    assert(bf != NULL);
    printf("%p\n", bf);
    
    return 0;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp)
{
    const char *pivot;
    int result;

    while (num > 0)
    {
        pivot = (const char *) base + (num / 2) * size;
        result = cmp(key, (const void *) pivot);
        if (result == 0)
            return (void *) pivot;
        if (result < 0)
        {
            base = base;
            num = num / 2;
        }
        else
        {
            base = pivot;
            num = num - num / 2;
        }
    }
    return NULL;
}

int intcmp(const void *x, const void *y)
{
    int ix = *(int *) x;
    int iy = *(int *) y;
    if (ix == iy)
        return 0;
    if (ix < iy)
        return -1;
    return 1;
}
