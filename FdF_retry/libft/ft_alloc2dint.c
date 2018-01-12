/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc2dint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:53:49 by bmoodley          #+#    #+#             */
/*   Updated: 2018/01/12 12:53:50 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while (++i < y)
			arr[i] = (int *)malloc(sizeof(int) * x);
	}
	return (arr);
}
