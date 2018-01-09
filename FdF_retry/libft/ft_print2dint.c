#include "libft.h"

void	ft_print2dint(int **arr, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	if (arr)
	{
		while (++i < y)
		{
			j = -1;
			while(++j < x)
			{
				ft_putnbr(arr[i][j]);
				ft_putchar(';');
			}
			ft_putendl("");
		}
	}
}
