#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void merge_sort_imp(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void merge_sort(int *arr, int n);
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
    merge_sort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    return 0;
}

void merge_sort_imp(int *arr, int l, int r)
{
    if (l >= r) 
        return;
    int m = (l + r) / 2;
    merge_sort_imp(arr, l, m);
    merge_sort_imp(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge_sort(int *arr, int n)
{
    merge_sort_imp(arr, 0, n - 1);
}

void merge(int *arr, int l, int m, int r)
{
    int *arr_dop;
    int i = l;
    int i1 = l, i2 = m + 1, res = r + 1;
    arr_dop = (int*) malloc(res * sizeof(int));
    do 
    {
        if (arr[i1] <= arr[i2])
        {
            arr_dop[i] = arr[i1];
            i1++;
            i++;
        }
        else
        {
            arr_dop[i] = arr[i2];
            i2++;
            i++;
        }
    } while (i <= r && i1 <= m && i2 <= r);
    i = i - 1;
    while (i1 <= m)
    {
        i++;
        arr_dop[i] = arr[i1];
        i1++;
    }
    while (i2 <= r)
    {
        i++;
        arr_dop[i] = arr[i2];
        i2++;
    }
    for (int i0 = l; i0 <= i; )
    {
        arr[i0] = arr_dop[i0];
        i0++;
    }
    free(arr_dop);
}

void swap(int *v1, int *v2)
{
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}