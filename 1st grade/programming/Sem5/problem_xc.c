#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define HASH_MAX 10

typedef int (*get_hash_t)(const char *s);

int ncollisions(char **strs, int n, get_hash_t f);

int main(void)
{
    
}

int ncollisions(char **strs, int n, get_hash_t f)
{
    int number = 0;
    int * arr = calloc(HASH_MAX, sizeof(int));

    if (strs == NULL)
        return number;

    for (int i = 0; i < n; i++)
    {
        arr[f(*strs)] += 1;
        strs++;
    }

    for (int i = 0; i < HASH_MAX; i++)
    {
        if (arr[i] > 0)
            number = number + (arr[i] - 1);
    }

    free(arr);

    return number;
}
