#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *strcat_r(char *dest, const char *src, int *bufsz);

int main(void) 
{
    char *s;
    s = (char *) calloc(6, sizeof(char));
    s = strcpy(s, "Hello");
    int i = 6;
    s = strcat_r(s, " world!", &i);
    printf("%s\n", s);
    free(s);
}

char *strcat_r(char *dest, const char *src, int *bufsz)
{
    int size = strlen(dest) + strlen(src) + 2;
    if (size > *bufsz)
    {
        dest = realloc(dest, size + 1);
        assert(dest);
    }
    dest = strcat(dest, src);

    return dest;
}
