/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 10:04:05 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/19 15:33:24 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (little[0] != '\0')
	{
		while (big[i])
		{
			if (big[i] == little[j])
			{
				while (big[i + j] == little[j] && big[i + j])
				{
					j++;
					if (little[j] == '\0')
						return ((char *)&big[i]);
				}
				j = 0;
			}
			i++;
		}
	}
	else
		return ((char *)big);
	return (NULL);
}
