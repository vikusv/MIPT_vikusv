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

struct node_t * reverse(struct node_t *top);
struct node_t * read_list(FILE *inp);
struct node_t * add_to_list(struct node_t * bottom, int num);
void delete_list(struct node_t *top);

int main(void) 
{
    FILE *inp;
    struct node_t *fin_struct = NULL;
    inp = fopen("problem_al_file.txt", "r");
    fin_struct = read_list(inp);
    struct node_t * fin_struct_head = fin_struct;

    fin_struct = reverse(fin_struct);
    
    while (fin_struct != NULL)
    {
        printf("%d ", fin_struct->data);
        fin_struct = fin_struct->next;
    }
    printf("\n");
    
    delete_list(fin_struct_head);

    fclose(inp);

    return 0;
}

struct node_t * reverse(struct node_t *top)
{
    struct node_t *xs = NULL;
    int counter = 1;
    struct node_t ** arr = NULL;
    struct node_t *new_head = NULL;
    struct node_t *new_list = NULL;
    
    if (top == NULL)
        return 0;

    xs = top;

    while (top->next)
    {
        top = top->next;
        counter++;
    }
    
    arr = calloc(counter, sizeof(struct node_t *));
    arr[0] = xs;

    for (int i = 1; i < counter; i++)
    {
        arr[i] = xs->next;
        xs = xs->next;
    }

    new_head = arr[counter - 1];
    new_list = new_head;

    for (int i = counter - 1; i > 0; i--)
    {
        new_head->next = arr[i - 1];
        new_head = new_head->next;
    }
    
    new_head->next = NULL;

    free(arr);

    return new_list;
}

struct node_t *read_list(FILE *inp)
{
    int num = 0;
    struct node_t *list = NULL;
    struct node_t *list_head = NULL;

    fscanf(inp, "%d", &num);

    list = add_to_list(list, num);

    list_head = list;    

    while (fscanf(inp, "%d", &num) == 1)
        list = add_to_list(list, num);

    return list_head;
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
