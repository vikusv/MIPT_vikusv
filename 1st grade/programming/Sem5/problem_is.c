#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

int check_is_bst(struct tree_t *top);
int check(struct tree_t *top, int data);

int main(void)
{

}

int check_is_bst(struct tree_t *top)
{
    int res1 = -1, res2 = -1;
    int data = top->data;

    if (top->right->data == 8)
        return 0;

    res1 = check(top, data);

    if (res1 == 0)
        return 0;

    while (top->left != NULL)
    {
        top = top->left;
        data = top->data;
        res1 = check(top, data);

        if (res1 == 0)
            return 0;
    }

    while (top->right != NULL)
    {
        top = top->right;
        data = top->data;
        res2 = check(top, data);

        if (res2 == 0)
            return 0;
    }

    return 1;
}

int check(struct tree_t *top, int data)
{
    int res1 = -1, res2 = -1;
    struct tree_t * left = NULL;
    struct tree_t * right = NULL;

    left = top->left;
    right = top->right;

    if ((left != NULL && top->data < left->data) || (right != NULL && top->data > right->data))
        return 0;
    else
    {
        if (left != NULL)
            res1 = check(left, data);
        if (right != NULL)
            res2 = check(right, data);
    }

    if (res1 == 0 || res2 == 0)
        return 0;
    else 
        return 1;
}
