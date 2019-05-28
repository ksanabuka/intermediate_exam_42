	struct s_node {
		void *content;
		struct s_node *next;
	};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node * l1 = lst1;
	struct s_node * l2 = lst2;
struct s_node * tmp = l1; 
struct s_node * l2tmp = l2; 

if (l1 && l2)
{
	while (l1)
	{
		while (l2)
		{
			if (&tmp == &l2)
				return tmp->content; 
			else 
				l2=l2->next; 
		}
		tmp = l1->next; 
		l2 = l2tmp; 	   	
	}
	return 0; 
}
return 0;
}



