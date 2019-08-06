#include <stdio.h>
//void *memcpy(void *str1, const void *str2, size_t n)
#include <stdlib.h>
#include <string.h>

void print_arr(int * arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}

int my_factorial(int n)
{
	int res = n;
	while (--n > 1)
		res *= n;
	return res;
}

void	permute(int **tab, int *avail, int *soln, int n, int cur, int *soln_i)
{
	int i = 0; 

	if (cur == n)
	{
		//print_arr(soln, n);
		// printf("1:*soln_i %d 2:tab[*soln_i] 3:%d\n %d\n", *soln_i, (int)tab[*soln_i],  (int)sizeof(int) * n);
		memcpy(tab[(*soln_i)], soln, sizeof(int) * n);
				// print_arr(tab[*soln_i], n);

		(*soln_i)++;
	}
	else 
	{
		while (i < n)
		{
			if (avail[i] == 1)
			{
				avail[i] = 0;
				soln[cur] = i; 
				permute(tab, avail, soln, n, cur + 1, soln_i);
				avail[i] = 1; 
			}
			i++;
		}
	}
}


int ** range_comb(int n)
{
	if (n <= 0)
		return 0;

	int num_permutations = my_factorial(n);
	int *avail = (int *)malloc(sizeof(int) * n);
	int *soln = (int *)malloc(sizeof(int) * n);

	int i = 0; 

	while (i < n)
	{
		avail[i] = 1;
		i++; 
	}

	int ** tab = (int**)malloc(sizeof(int*) * (num_permutations + 1));
	tab[num_permutations] = 0;
	i = 0;
	while (i < num_permutations)
	{
		tab[i] = malloc(sizeof(int) * n);
		i++;
	}

	int soln_i = 0; 

	permute(tab, avail, soln, n, 0, &soln_i);
	free(avail);
	free(soln);
	return tab; 
}


int main (void)
{
	int n = 3; 
	int ** res = range_comb(n);
	int size = my_factorial(n);
	int i = 0;
	while ( i < size)
	{
		print_arr(res[i], n);
		printf("\n");
		i++;
	}
	if (res[i] == 0)
		printf("%s\n", "yes");

	return 0;
}