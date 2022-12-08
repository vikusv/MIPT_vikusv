#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * strstrci(char const * needle, char const * haystack);

int main(void) 
{
    char const *needle = "Ab", *src = "abracadaBra";
    char *pos1, *pos2, *pos3; 
    pos1 = strstrci(needle, src);
    assert(pos1 != NULL);
    //pos3 = strstrci(pos2 + 2, needle);
    //assert(pos3 == NULL);
}

char * strstrci(char const * needle, char const * haystack)
{
    char * pos = (char *) haystack;
    int len = strlen(needle);
    char * pos0;
    char * needle1 = (char *) needle;

    while (*pos != '\0')
    {
        if (tolower(*pos) == tolower(*needle))
        {
            pos0 = pos;
            pos++;
            needle1++;
            while (*needle1 != '\0' && *pos != '\0' && tolower(*pos) == tolower(*needle1))
            {
                pos++;
                needle1++;
            }
            if (pos == pos0 + len)
                return pos0;
        }
        pos++;
        needle1 = (char *) needle;
    }

    return NULL;
}
