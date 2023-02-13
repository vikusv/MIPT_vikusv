#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node_t 
{
    struct node_t *next;
    int data;
};

int list_is_a_loop(struct node_t *top);

int main(void) 
{
    FILE *inp;
    int res;
    struct node_t *fin_struct = NULL;
    inp = fopen("problem_al_file.txt", "r");
    fin_struct = read_list(inp);
    res = list_is_a_loop(fin_struct);
    printf("%d\n", res);

    fclose(inp);

    return 0;
}

int list_is_a_loop(struct node_t *top)
{
    struct node_t * rabbit = top;
    struct node_t * turtle = top;

    while (rabbit)
    {
        rabbit = rabbit->next;
        if (rabbit)
            rabbit = rabbit->next;
        else
            return 0;

        turtle = turtle->next;

        if (rabbit == turtle)
        {
            return 1;
        }
    }

    return 0;
}

