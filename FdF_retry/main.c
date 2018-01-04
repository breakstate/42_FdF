#include "fdf.h"

int		ft_readin(int	fd)
{
	char	*line;
	int		numlines;
	int		n;
	int		width;

	line = NULL;
	numlines = 0;
	n = 0;
	get_next_line(fd, &line);
	width = ft_strlen(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (numlines == 0)
			ft_strnsplit(line, ' ', &width);//count words better suited for this
		if (ft_strlen(line) == 0 || ft_strnsplit(line, ' ', &n) != width)//and this
		{
			ft_putstr("Error: bad line.");
			exit(-1);
		}
		numlines++;
	}
	return (numlines);//or return allocated 2d array
}

int		ft_usage(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("Error: wrong number of parameters.");
		return (-1);
	}
	if (fd = open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr("Error: file does not exist.");
		return (-1);
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	t_struct line;
	int		fd;

	if ((fd = ft_usage) == -1)
		exit(-1);

	ft_readin(fd);

	line.mlx = mlx_init();
	line.win = mlx_new_window(line.mlx, 400, 400, "[Window title]");
	mlx_mouse_hook(line.win, mouse_input, &line);
	mlx_key_hook(line.win, key_input, &line);
	mlx_loop(line.mlx);
	return (0);
}