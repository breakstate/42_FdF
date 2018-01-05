#include "libft"

int		**ft_alloc2dint(int x, int y)
{
	int		**arr;
	int		i;

	i = -1;
	if (x && y)
	{
		arr = (int **)malloc(sizeof(int*) * y);
		while (++i < x)
			arr[i] = (int *)malloc(sizeof(int) * x);
	}
	else
		return (NULL);
	return (arr);
}
