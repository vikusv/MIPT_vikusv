#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void q_sort(int *arr, unsigned len);
void qsort_impl(int *arr, unsigned low, unsigned high);
unsigned partition(int *arr, unsigned low, unsigned high);
void swap(int *v1, int *v2);

int main(void)
{
    int res = 0;
    unsigned len = 0;
    int *arr;
    res = scanf("%u", &len);
    assert(res == 1);
    arr = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; )
    {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
        i++;
    }
    q_sort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    return 0;
}

void qsort_impl(int *arr, unsigned low, unsigned high) 
{
    if (low >= high) 
        return;
    unsigned pi = partition(arr, low, high);
    if (pi > low) 
        qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void q_sort(int *arr, unsigned len) 
{
    qsort_impl(arr, 0u, len - 1);
}

unsigned partition(int *arr, unsigned low, unsigned high) 
{
    int i = low - 1, ii = high;
    if (i == -1)
        i += 1;
    while (ii - i > 0)
    {
        i++;
        if (arr[i] >= arr[low])
        {
            while (arr[ii] >= arr[low] && i < ii)
                ii--;
            if (arr[i] >= arr[ii])
                swap(&arr[i], &arr[ii]);
        }
    }
    if (low == 0)
    {
        while (i != high && i > 0 && arr[low] == arr[i - 1])
            i--;
    }
    if (i != high && arr[low] > arr[i - 1] && i > 0)
    {
        swap(&arr[low], &arr[i - 1]);
        i = i - 1;
    }
    else if (i == high && arr[low] > arr[i] && i >= 0)
    {
        swap(&arr[low], &arr[i]);
        i = i;
    }
    if (i < 0)
        i = 0;
    return i;
}

void swap(int *v1, int *v2)
{
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
