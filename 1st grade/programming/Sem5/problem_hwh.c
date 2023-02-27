#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

typedef int (*get_hash_t)(const char *s);
int get_hash (const char *start, const char *fin);
int update_hash (int current, int n, char cprev, char cnext);
unsigned long long pow_mod (unsigned n, unsigned k, unsigned m);

int main(void)
{
    int res = 0, answer_number = 0, haystack_len = 0, needle_len = 0;
    char * haystack = NULL;
    char * needle = NULL;

    res = scanf("%d %d", &answer_number, &haystack_len);
    assert(res == 2);

    haystack = calloc(haystack_len, sizeof(int));

    for (int i = 0; i < haystack_len; i++)
    {
        res = scanf("%s", &haystack[i]);
        assert(res == 1);
    }

    res = scanf("%d", &needle_len);
    assert(res == 1);

    needle = calloc(needle_len, sizeof(int));

    for (int i = 0; i < needle_len; i++)
    {
        res = scanf("%s", &needle[i]);
        assert(res == 1);
    }

    

    free(haystack);

    return 0;
}