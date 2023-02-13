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

struct node_t *read_list(FILE *inp);
void delete_list(struct node_t *top);
struct node_t * add_to_list(struct node_t * bottom, int num);

int main(void) 
{
    FILE *inp;
    struct node_t *fin_struct = NULL;
    inp = fopen("problem_al_file.txt", "r");
    fin_struct = read_list(inp);
    struct node_t * fin_struct_head = fin_struct;
    while (fin_struct != NULL)
    {
        printf("%d", fin_struct->data);
        fin_struct = fin_struct->next;
    }
    delete_list(fin_struct_head);

    fclose(inp);

    return 0;
}

struct node_t *read_list(FILE *inp)
{
    int num = 0;
    struct node_t *top_even = NULL;
    struct node_t *top_odd = NULL;
    struct node_t *bottom_even = NULL;
    struct node_t *bottom_odd = NULL;
    while (fscanf(inp, "%d", &num) == 1)
    {
        if (num % 2 == 0)
        {
            bottom_even = add_to_list(bottom_even, num);
            if (top_even == NULL)
                top_even = bottom_even;
        }
        else
        {
            bottom_odd = add_to_list(bottom_odd, num);
            if (top_odd == NULL)
                top_odd = bottom_odd;
        }
    }

    if (bottom_even == NULL)
        return top_odd;
    else
    {
        bottom_even->next = top_odd;
        return top_even;
    }
}

struct node_t * add_to_list(struct node_t * bottom, int num)
{
    struct node_t *elem = calloc(1, sizeof(struct node_t));
    elem->next = NULL;
    elem->data = num;

    if (bottom != NULL)
        bottom->next = elem;

    return elem;
}

void delete_list(struct node_t *top)
{
    assert(top);
    while (top->next != NULL)
    {
        struct node_t *newtop = top->next;
        free(top);
        top = newtop;
    }

    free(top);
}
