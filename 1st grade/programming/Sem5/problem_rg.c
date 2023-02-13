#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef int (*generator_t)(int);

struct node_t 
{
    struct node_t *next;
    int data;
};

unsigned cycle_len(generator_t gen);
struct node_t * generate_list(generator_t gen);
struct node_t * add_to_list(struct node_t * bottom, int num);
void delete_list(struct node_t *top);
int generator(int x);


int main(void) 
{
    int res = 0;
    res = cycle_len(generator);
    printf("%d\n", res);

    return 0;
}

unsigned cycle_len(generator_t gen)
{
    struct node_t * top = generate_list(gen);
    struct node_t * top_head = top;
    struct node_t * step = top;
    int counter1 = 1, counter2 = 0;

    step = step->next;
    while (1)
    {
        while (step->data != top_head->data)
        {
            step = step->next;
            counter1++;
            //printf("counter = %d, data = %d\n", counter1, step->data);
        }
        //printf("%d %d\n", top_head->data, step->data);
        while (top_head->data == step->data && top_head != NULL && step != NULL && counter2 < counter1)
        {
            top_head = top_head->next;
            step = step->next;
            counter2++;
            //printf("%d %d\n", top_head->data, step->data);
        }

        if (counter1 == counter2)
        {
            delete_list(top);
            return counter1;
        }
    }

    delete_list(top);

    return 0;
}

struct node_t *generate_list(generator_t gen)
{
    struct node_t *list = NULL;
    struct node_t *list_head = NULL;

    list = add_to_list(list, gen(0));

    list_head = list;    

    for (int i = 1; i <= 10000; i++)
    {
        list = add_to_list(list, gen(list->data));
        //printf("%d ", list->data);
    }
    //printf("\n");

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

int generator(int x)
{
    int f = 0;
    f = (1009 * x + 2009) % 3009 + 7;

    return f;
}
