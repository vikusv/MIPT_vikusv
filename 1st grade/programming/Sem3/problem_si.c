/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void inssort(int *arr, int len);
int moveright(int *arr, int key, int last);

int main(void)
{
    int len = 6;
    int arr[6] = {1, 2, 4, 5, 3, 2};
    inssort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d", arr[i]);

    return 0;
}

void inssort(int *arr, int len)
{
    int key = 0, pos = 0;
    for (int i = 0; i < len; ++i) 
    {
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}
*/
int moveright(int *arr, int key, int last)
{
    int i = 0;
    for (i = 0; i < last; )
    {
        if (arr[i] > key)
        {
            for (int ii = last; ii > i; )
            {
                arr[ii] = arr[ii - 1];
                ii--;
            }
            return i;
        }
        i++;
    }
    return i;
}
