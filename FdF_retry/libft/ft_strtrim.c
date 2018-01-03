/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:57:04 by bmoodley          #+#    #+#             */
/*   Updated: 2017/12/14 14:15:48 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	end = 0;
	start = 0;
	if (s)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		start = i;
		i = ft_strlen(s) - 1;
		while (i > -1 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			i--;
		}
		end = i + 1;
		if ((end - start) > 0)
			return (ft_strsub(s, start, end - start));
		else
			return (ft_strnew(0));
	}
	return (NULL);
}
