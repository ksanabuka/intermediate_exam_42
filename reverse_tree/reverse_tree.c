struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};


void doJob(struct s_node * r)
{
//	int tmp; 
	struct s_node *tmp1; 

	if (r)
	{
		if (r->left != 0 && r->right != 0)
		{
			
			tmp1 = r->left;
		   	r->left = r->right;
			r->right = tmp1; 

	//		tmp = r->left->value;
	//		r->left->value = r->right->value;
	//		r->right->value = tmp; 
		}

		else if (r->left != 0 && r->right == 0)
		{
			tmp1 = r->left;
		   	r->left = 0;
			r->right = tmp1; 
		}
		else if (r->left == 0 && r->right != 0)
		{
			tmp1 = r->right;
		   	r->left = tmp1;
			r->right = 0; 
		}
	}

	return ;
}


void reverse_tree(struct s_node *root)
{
	if (!root)
		return ;

	if (root)
	{	
		doJob(root); 
		if (root->right)
			reverse_tree(root->right);
		if (root->left)
			reverse_tree(root->left);
	}
}

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
//	struct s_node *root = addNode(94);	
//
//	root->left = addNode(34);	
//	root->right = addNode(52);
//
//	root->left->left = addNode(1);	
//	root->left->left->left = addNode(20);	
//
//	root->left->right = addNode(99);	
//	root->left->right->left = addNode(83);	
//
//	root->left->right->left->right = addNode(61);	
//	root->left->right->right = addNode(39);	
//	root->left->right->right->left = addNode(37);	
//	root->left->right->right->right = addNode(67);	
//
//	reverse_tree(root);
//	
//	printf("%p\n", root->right->right->left);
//
//}
