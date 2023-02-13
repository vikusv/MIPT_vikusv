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

int loop_len(struct node_t *top);
struct node_t *read_list(FILE *inp);
struct node_t * add_to_list(struct node_t * bottom, int num);
void delete_list(struct node_t *top);

int main(void) 
{
    FILE *inp;
    int res;
    struct node_t *fin_struct = NULL;
    struct node_t *list_head = NULL;
    inp = fopen("problem_al_file.txt", "r");
    fin_struct = read_list(inp);

    list_head = fin_struct;

    res = loop_len(fin_struct);
    printf("%d\n", res);

    delete_list(list_head);

    fclose(inp);

    return 0;
}

int loop_len(struct node_t *top)
{
    struct node_t * rabbit = top;
    struct node_t * turtle = top;
    struct node_t * loop_head = NULL;
    int counter = 1;

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
            loop_head = turtle;
            turtle = turtle->next;
            while (turtle != loop_head)
            {
                turtle = turtle->next;
                counter++; 
            }

            return counter;
        }
    }

    return 0;
}

struct node_t *read_list(FILE *inp)
{
    int num = 0;
    struct node_t *list = NULL;
    struct node_t *list_head = NULL;

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
