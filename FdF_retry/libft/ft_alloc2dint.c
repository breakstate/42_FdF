#include "libft.h"

int		**ft_alloc2dint(int x, int y)
{
	int		**arr;
	int		i;

	i = -1;
	arr = NULL;
	if (x && y)
	{
		arr = (int **)malloc(sizeof(int*) * y);
		while (++i < x)
			arr[i] = (int *)malloc(sizeof(int) * x);
	}
	return (arr);
}
