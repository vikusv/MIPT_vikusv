#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int next_turn(int total, int possible);
void fib_sum(int x, int *result);
int fib(int n);
int fib_near(int n);
/*
int main(void)
{
    int res = 0, total = 1, possible = 0;
    
    res = scanf("%d %d", &total, &possible);
    assert(res == 2);
    res = next_turn(total, possible);
    printf("%d\n", res);
    return 0;
}
*/
int next_turn(int total, int possible)
{
    int fib_num = 0;
    int arr[100] = {};
    int long long i = 0;
    int count = 1;
    fib_sum(total, arr);
    while (arr[i] == 0)
    {
        i++;
        count++;
    }
    fib_num = fib(count);
    if (fib_num > possible)
        return 1;
    else
        return fib_num;
}

void fib_sum(int x, int *result) 
{
    int fib_num = 0, sum = 1, stop = 0;
    int i = 2;
    int fib_arr[100] = {};
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
    while (i >= 1)
    {
        i--;
        result[i] = 0;
    }
    i = stop;
}

int fib(int n) 
{
    int first = 0, second = 1;
    int idx;
    if (n == 0)
        return 0;
    for (idx = 2; idx <= n; ++idx) {
        int tmp = second;
        second = second + first;
        first = tmp;
    }
    
    return second;
}

int fib_near(int n)
{
    int first = 0, second = 1;
    int idx;
    if (n == 0)
        return 0;
    while (second + first < n)
    {
        idx = second;
        second = second + first;
        first = idx;
    }
    return second;
}
