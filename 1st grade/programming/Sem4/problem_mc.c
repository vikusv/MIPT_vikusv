#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int coin_exchange(int sum, int qt, int * nominal_arr);

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

    min_qt = coin_exchange(sum, qt, nominal_arr);

    printf("%d\n", min_qt);

    free(nominal_arr);

    return 0;
}

int coin_exchange(int sum, int qt, int * nominal_arr) 
{
    int i, j, x, y;
    int lookupTable[sum + 1][qt];

    if (sum <= 0 || qt <= 0)
        return 0;
    
    for (i = 0; i < qt; i++)
        lookupTable[0][i] = 1;

    for (i = 1; i < sum + 1; i++) 
    {
        for (j = 0; j < qt; j++) 
        {
        x = (i - nominal_arr[j] >= 0) ? lookupTable[i - nominal_arr[j]][j] : 0;
        y = (j >= 1) ? lookupTable[i][j - 1] : 0;
        lookupTable[i][j] = x + y;
        }
    }
    return lookupTable[sum][qt - 1];
}