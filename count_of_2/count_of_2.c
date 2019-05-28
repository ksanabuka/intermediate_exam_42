int count2(int n)
{
	int 	counter = 0;
	if (n == 2)
		return 1;
	while (n > 0)
	{
		if (n % 10 == 2)
			counter++;
		n = n/10;
	}
	return counter;
}

int    count_of_2(int n)
{
	if (n <= 1)
		return 0;
	int c = 0; 
	int i = 1;
	while (i <= n)
	{
		c += count2(i);
		i++;
	}
	return c;
}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int ac, char ** av)
//{
//	ac = 0;
//	printf("%d\n", count_of_2(atoi(av[1])));
//	return 0;
//}

