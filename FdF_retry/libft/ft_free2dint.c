#include "libft.h"

void	ft_free2dint(int **arr, int y)
{
	int		i;

	i = -1;
	if (arr)
	{
		while (++i < y)
		{
			free(arr[i]);
		}
		free(arr);
	}
}