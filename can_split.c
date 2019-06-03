#include <stdlib.h>
#include <stdio.h>

struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};


void total_nodes(struct s_node *r, void * info)
{
    int * counter = (int *)info; 

    if (r->left)
        total_nodes(r->left, counter);
    if (r->right)
        total_nodes(r->right, counter);
    (*counter)++;
}

void doJob(struct s_node *r, int total, void *info)
{
    int * res = (int *)info; 
    int local_total = 0;
    total_nodes(r, &local_total);
    if (total - local_total == local_total)
    {
        *res = 1; 
    }
}
void traverse(struct s_node *r,  int total, void *res, void (*fn)(struct s_node *, int, void *))
{
     int * result = (int *)res; 

    if (r->left)
        traverse(r->left, total, res, fn); 
    if (r->right)
        traverse(r->right, total, res, fn); 
    fn(r, total, result); 
}

int can_split(struct s_node *n)
{
    int counter = 0;
    int res = 0; 
    total_nodes(n, &counter);
    if (counter % 2 == 1)
        return res; 
    traverse(n,  counter, &res, &doJob);
    return (res);
}

struct s_node * addnode(int value)
{
    struct s_node * node = (struct s_node *)malloc(sizeof(struct s_node));
    node->left = 0;
    node->right = 0; 
    node->value = value; 
    return node; 
}


int main(void)
{
    struct s_node * r = addnode(28);
    r->left = addnode(51);
    r->left->left = addnode(26);
    r->left->right = addnode(48);
    r->left->left->left = addnode(76);
    //r->left->left->right = addnode(13);

    int counter = 0;
    total_nodes(r, &counter);
    printf("%d\n", counter);
    printf("%d\n", can_split(r));
    return 0;
}