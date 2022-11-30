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
    int len1 = 0, len2 = 0;
    char *word, *str, *start;
    word = read_word(&len1);
    str = read_word(&len2);
    
    start = str;
    while ((str + len2 - 1) - start - len1 >= 0)
    {
        start = strstr(start, word);
        if (start == NULL)
            break;
        str_reverse(start, len1);
    }
    for (int i = 0; i < len2; i++)
        printf("%c", str[i]);
    printf("\n");
    free(word);
    free(str);
    
    return 0;
}

void str_reverse(char * start, int len)
{
    for (int i = 0; i <= len / 2; i++)
        swap(start + i, start + len - 1 - i);
}

char *read_word(int *len) 
{
    char *text;
    int res, i;

    res = scanf("%d", len);
    assert(res == 1);

    text = calloc(*len + 1, sizeof(char));
    assert(text != NULL);

    res = scanf("%*c");

    for (i = 0; i < *len; ++i) {
        res = scanf("%c", text + i);
        assert(res);
    }

    return text;
}

void swap(char *v1, char *v2)
{
  char tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}
