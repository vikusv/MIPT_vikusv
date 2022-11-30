#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void celsort(int *arr, unsigned len, int pos);
void swap(int *v1, int *v2);

int main(void)
{
    int res = 0;
    unsigned len = 0, pos = 0;
    int *arr;
    res = scanf("%d", &len);
    arr = (int*) malloc(len * sizeof(int));
    assert(res == 1);

    for (int i = 0; i < len; )
    {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
        i++;
    }
    res = scanf("%d", &pos);
    assert(res == 1);
    celsort(arr, len, pos);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    return 0;
}

void celsort(int *arr, unsigned len, int pos)
{
    unsigned min_elem = 0, pos_min = 0;
    min_elem = arr[pos];
    for (unsigned i = pos; i < len; i++)
    {
        if (arr[i] < min_elem)
        {
            min_elem = arr[i];
            pos_min = i;
        }
    }
    if (pos_min != 0)
        swap(&arr[pos], &arr[pos_min]);
}

void swap(int *v1, int *v2) 
{
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
