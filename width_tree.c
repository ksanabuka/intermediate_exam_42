
#include <stdlib.h>
#include <stdio.h>
#define max(a, b) (a > b ? a : b)

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int height(struct s_node *n, int indicator)
{
    
}

void doJob(struct s_node * r, int * max)
{
    if (!r)
        return ;
    int left_leg1 = 0; 
    int right_leg1 = 0;
    if (r->left)
    {
        left_leg1 =  height(r->left, &left_leg1);
    }
    if (r->right)
    {
        right_leg1 =  height(r->right, &right_leg1);
    }
    *max = (*max < (left_leg1 + right_leg1)) ? left_leg1 + right_leg1 : *max; 
}

void traverse(struct s_node * r, void * info, void (*fn)(struct s_node *, int *))
{
    int *max = (int*)info;

    if (r->left)
        traverse(r->left, info, fn);
    if (r->right)
        traverse(r->right, info, fn);
    fn(r, (int *)info);
}

int	width_tree(struct s_node *n)
{
        int max = 0;
        traverse(n, &max, &doJob);
        return (max + 1);
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
    r->left->left->right = addnode(13);
    r->left->left->right->left = addnode(14);

    int counter = 0;
    

    //doJob(r, &max);
    //height(r, &counter);
    printf("%d\n", height(r, &counter));
   //printf("%d\n", width_tree(r));
    return 0;
}