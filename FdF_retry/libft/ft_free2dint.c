/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:55:51 by bmoodley          #+#    #+#             */
/*   Updated: 2018/01/12 12:56:11 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free2dint(int **arr, int y)
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
