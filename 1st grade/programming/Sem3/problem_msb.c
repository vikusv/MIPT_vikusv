#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int max_bit_count(unsigned long long num);

int main(void)
{
    unsigned long long num = 0;
    int res = 0, max_bit = 0;
    res = scanf("%llu", &num);
    assert(res == 1);
    max_bit = max_bit_count(num);
    printf("%d\n", max_bit);
    return 0;
}

int max_bit_count(unsigned long long num)
{
    int val = 0, count = -1;
    for (int i = 0; i < 8 * sizeof(unsigned long long); )
    {
        val = (num >> (i)) & 1u;
        if (val == 1)
            count = i;
        i++;
    }
    return count;
}
