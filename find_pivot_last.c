int	find_pivot(int *arr, int n)
{
	int i = 0;
	int total = 0;

	while(i < n)
	{
		total+= arr[i];
		i++;
	}
	i = 0;
	int sum = 0;
	while (i < n - 1)
	{
		if (sum * 2 + arr[i]== total)
			return i;
		sum += arr[i];
		i++;
	}
	return -1;
}