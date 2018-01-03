/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/12/14 14:27:03 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

static char	*ft_count_alloc(int n, int *len)
{
	int		temp_num;
	int		temp_len;
	char	*allocation;

	temp_len = 1;
	if (n < 0)
	{
		temp_len++;
	}
	temp_num = n;
	while (temp_num /= 10)
	{
		temp_len++;
	}
	allocation = (char *)malloc(sizeof(char) * (temp_len + 1));
	if (allocation == NULL)
		return (NULL);
	ft_bzero(allocation, temp_len + 1);
	*len = temp_len;
	return (allocation);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		neg;

	len = 0;
	neg = 0;
	neg += (n < 0) ? 1 : 0;
	str = ft_count_alloc(n, &len);
	if (!(str))
		return (NULL);
	while ((len) > 0)
	{
		str[len - 1] = ft_abs(n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg)
		str[len] = '-';
	return (str);
}
