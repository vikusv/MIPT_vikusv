#include <stdio.h>
#include <stdlib.h>

void fib_sum(unsigned long long x);
unsigned long long fib(unsigned long long n);
int main() 
{
    unsigned long long x;
    int res;
    res = scanf("%llu", &x);
    if (res != 1) 
    {
        printf("%s\n", "Wrong input");
        abort();
    }
    fib_sum(x);

    return 0;
}

void fib_sum(unsigned long long x) 
{
    unsigned long long fib_num = 0, sum = 1, stop = 0;
    int long long i = 2;
    unsigned long long fib_arr[100] = {};
    unsigned long long result[100] = {};
    while (fib_num < x)
    {
        i++;
        fib_num = fib(i);
        fib_arr[i - 2] = fib(i - 1);
    } 
    stop = i - 2;
    i = stop;
    result[i] = 1;
    sum = x - fib_arr[i];
    while (sum != 0)
    {
        i--;
        while (sum < fib_arr[i])
        {
            result[i] = 0;
            i--;
        }
        result[i] = 1;
        sum = sum - fib_arr[i];
    }
    while (i >= 0)
    {
        i--;
        result[i] = 0;
    }
    i = stop;
    while (i > 0)
    {
        printf("%llu", result[i]);
        i--;
    }
}

unsigned long long fib(unsigned long long n) 
{
    unsigned long long first = 0ull, second = 1ull;
    unsigned long long idx;
    if (n == 0)
        return 0ull;
    for (idx = 2; idx <= n; ++idx) {
        unsigned long long tmp = second;
        second = second + first;
        first = tmp;
    }
    
    return second;
}
