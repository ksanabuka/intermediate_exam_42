	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

struct s_node *min(struct s_node *bst)
{
	struct s_node *bst1 = bst;

	if (bst1)
	{
		while (bst1->left)
			bst1 = bst1->left;
		return bst1;
	}
	return 0; 
}

struct s_node *max(struct s_node *bst)
{
	struct s_node *bst1 = bst;

	if (bst1)
	{
		while (bst1->right)
			bst1 = bst1->right;
		return bst1;
	}
	return 0; 
}


void doJob(struct s_node *r, void * inf)
{
	struct s_node ** p = (struct s_node **)inf; 
	if (*p)
		(*p)->right = r; 
	r->left = *p; 
	*p = r; 
}


void traverse(struct s_node *r, void * inf, void (*fn)(struct s_node *, void *))
{
	if (r)
	{
	if (r->left)
		traverse(r->left, inf, fn);
	fn(r, inf);

	if (r->right)
		traverse(r->right, inf, fn);
	}
	return ; 
	
}


struct s_node *convert_bst(struct s_node *bst)
{

	if (bst)
	{
	struct s_node * min1 = min(bst);
	struct s_node * max1 = max(bst);
	struct s_node * prev = 0; 

	if (min1 && max1)
	{
		traverse(bst, &prev, &doJob);
	}
	min1->left = max1;
	max1->right = min1;
	return min1;
	}
	return 0; 	
}
//
//#include <stdlib.h>
//#include <stdio.h>
//
//struct s_node *addNode(int data)
//{
//	struct s_node * node = (struct s_node *)malloc(sizeof(struct s_node));
//	node->value = data;
//	node->left = 0;
//	node->right = 0;
//   return node;
//}
//
//
//int main(void)
//{
//
//	struct s_node *root = addNode(34);
//
//	root->left = addNode(20);
//	root->right = addNode(83);
//
//	root->left->left = addNode(1);
//	root->left->right = addNode(22);
//
//	root->right->left = addNode(55);
//
//	struct s_node *r = convert_bst(root);
//	
//	int i = 0;
//	while (i++ < 7)
//	{
//		printf("%d\n", r->value);
//		r = r->right; 
//	}
//	return 0;
//}





