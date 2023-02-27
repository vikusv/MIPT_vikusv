#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int coin_exchange(int sum, int qt, int * nominal_arr);
int minimum(int qt, int * nominal_arr, int * res_arr, int i);
int comp (int * a, int * b);

int main(void)
{
    int res = 0, sum = 0, qt = 0, min_qt = 0;
    int * nominal_arr = NULL;

    res = scanf("%d %d", &sum, &qt);
    assert(res == 2);

    nominal_arr = calloc(qt, sizeof(int));

    for (int i = 0; i < qt; i++)
    {
        res = scanf("%d", &nominal_arr[i]);
        assert(res == 1);
    }
    qsort(nominal_arr, qt, sizeof (int), (int(*) (const void *, const void *)) comp);

    min_qt = coin_exchange(sum, qt, nominal_arr);

    printf("%d\n", min_qt);

    free(nominal_arr);

    return 0;
}

int coin_exchange(int sum, int qt, int * nominal_arr) 
{
    int res = 0, i = 0, min_elem = 0;
    int * res_arr = calloc(sum + 1, sizeof(int));

    res_arr[i] = 0;
    i++;
    
    while (i < nominal_arr[0])
    {
        res_arr[i] = -1;
        i++;
    }

    for (; i <= sum; i++)
    {
        min_elem = minimum(qt, nominal_arr, res_arr, i);
        if (min_elem == -1)
            res_arr[i] = -1;
        else
            res_arr[i] = 1 + min_elem;
    }

    res = res_arr[sum];
    free(res_arr);

    return res;
}

int minimum(int qt, int * nominal_arr, int * res_arr, int i)
{
    int min_elem = res_arr[i - nominal_arr[0]];
    
    for (int j = 0; j < qt && nominal_arr[j] <= i; j++)
    {
        if (res_arr[i - nominal_arr[j]] != -1)
        {
            if (min_elem == -1)
                min_elem = res_arr[i - nominal_arr[j]];
            else 
            {
                if (res_arr[i - nominal_arr[j]] <= min_elem)
                    min_elem = res_arr[i - nominal_arr[j]];
            }
        }
    }
    return min_elem;
}

int comp (int * a, int * b)
{
    return *a - *b;
}
