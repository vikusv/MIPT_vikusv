#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef int (*xcmp_t)(void *lhs, int lsz, void *rhs, int rsz);

void merge(void *arr, int l, int m, int r, int * sizes, xcmp_t cmp);
void merge_sort_imp(void *arr, int l, int r, int * sizes, xcmp_t cmp);
void xmsort(void *mem, int *sizes, int nelts, xcmp_t cmp);
int intcmp(void *lhs, int lsz, void *rhs, int rsz);
void swap(void *v1, void *v2, int size1, int size2);

int main(void)
{
    int arr[10] = {8, 9, 9, 7, 1, 7, 9, 9, 1, 8};
    int sizes[10] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
    int i = 6, len = 21;
    while (i <= len)
    {
        xmsort(arr, sizes, len, intcmp);
        i++;
        for (int i = 0; i < len; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    
    return 0;
}

void merge(void *arr, int l, int m, int r, int * sizes, xcmp_t cmp)
{
    void * elem1 = 0, * elem2 = 0;
    int i = l;
    int i1 = l, i2 = m + 1, res = r + 1;
    elem1 = (void *) arr + i1 * sizes[i1];
    elem2 = (void *) arr + i2 * sizes[i2];
    do 
    {
        res = cmp(elem1, sizes[i1], elem2, sizes[i2]);
        if (res >= 0)
        {
            swap((void *) arr + i * sizes[i], elem1, sizes[i], sizes[i1]);
            i1++;
            i++;
        }
        else
        {
            swap((void *) arr + i * sizes[i], elem2, sizes[i], sizes[i2]);
            i2++;
            i++;
        }
    } while (i <= r && i1 <= m && i2 <= r);
    i = i - 1;
    while (i1 <= m)
    {
        i++;
        swap((void *) arr + i * sizes[i], elem1, sizes[i], sizes[i1]);
        i1++;
    }
    while (i2 <= r)
    {
        i++;
        swap((void *) arr + i * sizes[i], elem2, sizes[i], sizes[i2]);
        i2++;
    }
}

void merge_sort_imp(void *arr, int l, int r, int * sizes, xcmp_t cmp)
{
    int m = (l + r) / 2;
    if (l >= r)
        return;
    merge_sort_imp(arr, l, m, sizes, cmp);
    merge_sort_imp(arr, m + 1, r, sizes, cmp);
    merge(arr, l, m, r, sizes, cmp);
}

void xmsort(void *arr, int *sizes, int n, xcmp_t cmp)
{
    merge_sort_imp(arr, 0, n - 1, sizes, cmp);
}

void swap_char(char *v1, char *v2)
{
    char tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void swap(void *v1, void *v2, int size1, int size2)
{
    int max_size = 0;
    int i;
    if (size1 >= size2)
    {
        v2 = realloc(v2, size1);
        max_size = size1;
    }
    if (size2 > size1)
    {
        v1 = realloc(v1, size2);
        max_size = size2;
    }

    for (i = 0; i < max_size; ++i)
        swap_char((char *)v1 + i, (char *)v2 + i);
}

//int intcmp(void *x, void *y)
int intcmp(void *lhs, int lsz, void *rhs, int rsz)
{
    int ix = *(int *) lhs;
    int iy = *(int *) rhs;
    if (ix == iy)
        return 0;
    if (ix < iy)
        return 1;
    return -1;
}
