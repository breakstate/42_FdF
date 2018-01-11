#include "libft.h"

void	ft_free2dchar(char **arr)
{
	int		i;
	
	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
		}
		free(arr[i]);
		free(arr);
	}
}