#include <stdio.h>
#include <stdlib.h>

unsigned long long pisano_period(unsigned long long n, unsigned long long m);
unsigned long long fib_mod(unsigned long long n, unsigned long long m);
int main() {
    unsigned long long x, m;
    unsigned long long fmod = 0, period = 60;
    int res;
    res = scanf("%llu %llu", &x, &m);
    if (res != 2) {
        printf("%s\n", "Wrong input");
        abort();
    }
    if (x == 0)
    {
        printf("%llu %llu\n", fmod, period);
        return 0;
    }
    period = pisano_period(x, m);
    fmod = fib_mod((x % period), m);
    printf("%llu %llu\n", fmod, period);
    return 0;
}

unsigned long long pisano_period(unsigned long long n, unsigned long long m) 
{
    unsigned long long first = 0ull, second = 1ull, idx;
    if (n == 0)
        return 0ull;
    for (idx = 2; idx <= n; ++idx) 
    {
        unsigned long long tmp = second;
        second = (second + first) % m;
        first = tmp;
        if ((second == 1) && (first == 0))
            break;
    }
    return idx - 1;
}

unsigned long long fib_mod(unsigned long long n, unsigned long long m) 
{
    unsigned long long first = 0ull, second = 1ull;
    int idx;
    if (n == 0)
        return 0ull;
    for (idx = 2; idx <= n; ++idx) {
        unsigned long long tmp = second;
        second = (second + first) % m;
        first = tmp;
    }
    return second;
}
