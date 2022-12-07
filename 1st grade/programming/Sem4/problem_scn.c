#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void str_reverse(char * start, int len);
char *read_word(int *len);
void swap(char *v1, char *v2);

int main(void) 
{
    char str;
    int res = 0, sum = 0;
    res = scanf("%c", &str);
    assert(res);
    while (res == 1 && str != '\0') 
    {
        sum += str;
        res = scanf("%c", &str);
        assert(res);
    }
    printf("%d\n", sum);
    
    return 0;
}
