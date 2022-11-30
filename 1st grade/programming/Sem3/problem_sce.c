#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef int (*cmp_t)(const void *key, const void *elt);

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp);
void swap(void *v1, void *v2, unsigned size);
void swap_char(char *v1, char *v2);
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
    char *min_elem;
    char *ielem;
    int pos_min = 0, result = 0;

    min_elem = (char *) parr + (nsorted + 1) * eltsize;
    for (int i = nsorted; i < numelts; i++)
    {
        ielem = (char *) parr + i * eltsize;
        result = cmp((const void *) ielem, (const void *) min_elem);
        if (result >= 0)
        {
            min_elem = ielem;
            pos_min = i;
        }
    }
    printf("%d\n", pos_min);
    if (pos_min != 0)
        swap((char *) parr + pos_min * eltsize, (char *)parr + nsorted * eltsize, eltsize);

    return 0;
}

void swap_char(char *v1, char *v2)
{
  char tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

void swap(void *v1, void *v2, unsigned size)
{
  unsigned i;
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
