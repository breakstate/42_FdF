/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2dint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:57:30 by bmoodley          #+#    #+#             */
/*   Updated: 2018/01/12 12:57:32 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			while (++j < x)
			{
				ft_putnbr(arr[i][j]);
				ft_putchar(';');
			}
			ft_putendl("");
		}
	}
}
