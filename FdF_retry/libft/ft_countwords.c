int		ft_countwords(const char *str, char c)
{
	int			i;
	int			count;
	int			flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str && str[i])
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