#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *replace(char *str, char const *from, char const *to);
char *read_word(int *len);

int main(void) 
{
    int from_len = 0, to_len = 0, str_len;
    char *from, *to, *str;
    from = read_word(&from_len);
    to = read_word(&to_len);
    str = read_word(&str_len);
    str = replace(str, from, to);
    printf("%s\n", str);
    free(str);
}

char *replace(char *str, char const *from, char const *to)
{
    int str_len = strlen(str);
    int from_len = strlen(from);
    int to_len = strlen(to);
    char * start, * first;
    int counter = 0, size = 0;
    char * str_new;
    char * str_iter;
    char * tmp_first;

    start = str;
    while (start)
    {
        start = strstr(start, from);
        if (start == NULL)
            break;
        counter++;
        start = start + from_len;
    }
    size = str_len - counter * from_len + counter * to_len;
    str_new = (char *) calloc(size + 2, sizeof(char));
    start = str;
    first = str;
    str_iter = str_new;

    while (first)
    {
        tmp_first = strstr(first, from);
        if (tmp_first == NULL)
            break;
        
        while (start != tmp_first)
            *str_iter++ = *start++;
        
        str_new = strcat(str_new, to);
        start = first = tmp_first + from_len;
        str_iter += to_len;
    }
    while (str_iter - str_new < size)
        *str_iter++ = *first++;

    return str_new;
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

    for (i = 0; i < *len; ++i) 
    {
        res = scanf("%c", text + i);
        assert(res);
    }

    return text;
}
