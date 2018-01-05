#include "libft.h"

void	ft_print2dchar(char **arr)
{
	int		i;

	i = -1;
	while (arr && arr[++i])
		ft_putendl(arr[i]);
}
