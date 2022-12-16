#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp);
void swap_char(char *v1, char *v2);
void swap(void *v1, void *v2, int size);
int intcmp(const void *x, const void *y);

int main(void)
{
    int sorted[21] = {1, 1, 2, 3, 3, 5, 5, 7, 7, 5, 5, 7, 9, 6, 7, 5, 8, 9, 9, 6, 8};
    int i = 6, len = 21;
    while (i <= len)
    {
        selstep(sorted, sizeof(int), len, i, intcmp);
        i++;
        for (int i = 0; i < len; i++)
            printf("%d ", sorted[i]);
        printf("\n");
    }
    
    return 0;
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp)
{
    const char *pos_min;
    int pos_min_elem = 0, res = 0;

    pos_min_elem = 0;
    pos_min = (void *) parr + nsorted * eltsize;

    for (int count = nsorted; count < numelts; count++)
    {
        res = cmp((void *) parr + count * eltsize, pos_min);
        //printf("1: %d %d %d\n", count, res, pos_min_elem);
        if (res == 1)
        {
            pos_min = (void *) parr + count * eltsize;
            pos_min_elem = count;
        }
        //printf("2: %d %d %d\n", count, cmp((void *) parr + count * eltsize, pos_min), pos_min_elem);
    }
    if (pos_min_elem >= nsorted)
    {
        swap((void *)parr + nsorted * eltsize, (void *)parr + pos_min_elem * eltsize, eltsize);
    }
    //pos_min_elem += nsorted;

    return 0;
}

void swap_char(char *v1, char *v2)
{
    char tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void swap(void *v1, void *v2, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        swap_char((char *)v1 + i, (char *)v2 + i);
}

int intcmp(const void *x, const void *y)
{
    int ix = *(int *) x;
    int iy = *(int *) y;
    if (ix == iy)
        return 0;
    if (ix < iy)
        return 1;
    return -1;
}
