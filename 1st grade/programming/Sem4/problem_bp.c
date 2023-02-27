#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int bagpack(int weight, int qt, int * weight_arr);
int maximum(int qt, int * weight_arr, int * res_arr, int i);
int comp (int * a, int * b);

int main(void)
{
    int res = 0, bag_weight = 0, qt = 0, max_qt = 0;
    int * weight_arr = NULL;

    res = scanf("%d %d", &bag_weight, &qt);
    assert(res == 2);

    weight_arr = calloc(qt, sizeof(int));

    for (int i = 0; i < qt; i++)
    {
        res = scanf("%d", &weight_arr[i]);
        assert(res == 1);
    }
    qsort(weight_arr, qt, sizeof (int), (int(*) (const void *, const void *)) comp);

    max_qt = bagpack(bag_weight, qt, weight_arr);

    printf("%d\n", max_qt);

    free(weight_arr);

    return 0;
}

int bagpack(int weight, int qt, int * weight_arr) 
{
    int res = 0, i = 0, max_elem = 0;
    int * res_arr = calloc(weight + 1, sizeof(int));
    
    for (; i < weight_arr[0]; i++)
        res_arr[i] = 0;

    for (; i <= weight; i++)
    {
        max_elem = maximum(qt, weight_arr, res_arr, i);
        res_arr[i] = 1 + max_elem;
    }

    res = res_arr[weight];
    free(res_arr);

    return res;
}

int maximum(int qt, int * weight_arr, int * res_arr, int i)
{
    int weight_cur = 0;

    for (int j = 0; j < qt; j++)
    {
        weight_cur += weight_arr[j];
        if (weight_cur <= i)
            res_arr[i] += 1;
        else
            return (res_arr[i] - 1);
    }
    return (res_arr[i] - 1);
}

int comp (int * a, int * b)
{
    return *a - *b;
}