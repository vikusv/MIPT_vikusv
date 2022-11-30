#include <stdio.h>
#include <stdlib.h>

unsigned long long fib_mod(unsigned n, unsigned m) 
{
    unsigned long long first = 0ull, second = 1ull;
    int idx;
    if (n == 0)
      return 0ull;
    for (idx = 2; idx <= n; ++idx) 
    {
      unsigned long long tmp = second;
      second = (second + first) % m;
      first = tmp;
    }
    return second;
}

int main() 
{
    unsigned x, m;
    unsigned fmod;
    int res;
    res = scanf("%u %u", &x, &m);
    if (res != 2) {
      printf("%s\n", "Wrong input");
      abort();
    }
    fmod = fib(x, m);
    printf("%u\n", fmod);
    return 0;
}
