/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:50:35 by bmoodley          #+#    #+#             */
/*   Updated: 2018/01/10 11:44:11 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_gw_helper(int *count, int *flag, int *pos, int i)
{
	(*count)++;
	*flag = 1;
	*pos = i;
}

static char		*ft_get_words(const char *str, char c, int index)
{
	int			i;
	int			count;
	int			flag;
	int			pos;

	i = -1;
	flag = 0;
	count = 0;
	pos = 0;
	while (str[++i])
	{
		if (str[i] == c)
			flag = 0;
		else if (str[i] != c && flag == 0)
			ft_gw_helper(&count, &flag, &pos, i);
		if (index == (count))
		{
			while (str[i] != c)
				i++;
			return (ft_strsub(str, pos, i - pos));
		}
	}
	return (0);
}

static int		ft_count_words(const char *str, char c)
{
	int			i;
	int			count;
	int			flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			count_words;
	char		**word_array;

	i = 0;
	word_array = NULL;
	if (s != NULL)
	{
		count_words = ft_count_words(s, c);
		word_array = (char **)ft_memalloc(sizeof(char *) * (count_words + 1));
		if (word_array == NULL)
			return (NULL);
		while (i < count_words)
		{
			word_array[i] = ft_get_words(s, c, i + 1);
			i++;
		}
	}
	else
		word_array = (char **)ft_memalloc(sizeof(char *) * 1);
	return (word_array);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	char **split;
	int		i;

	i = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr("big while");
		//split = ft_strsplit(line, ' ');
		//while (split[i])
		//{
			//printf("[%s]\n", split[i]);
		//	i++;
		//}
		ft_putendl(line);
		ft_putnbr(i++);
	}
	return (0);
}
