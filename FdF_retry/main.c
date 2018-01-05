#include "fdf.h"
#include <stdio.h>
/*
int		**ft_allocate(t_env *env)
{
	int		**internal;
	char	*line;
	int		i;
	
	line = NULL;
	i = -1;
	internal = (int **)ft_memalloc((sizeof(int *) * numlines) + 1);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		internal[++i] = line;
	}
	return (internal);
}
*/
void	ft_error(char *error)
{
	ft_putstr("Error: ");
	ft_putstr(error);
	ft_putendl(" Exiting.");
	exit(-1);
}

void	ft_countlines(t_env *env)
{
	char	*line;

	line = NULL;
	env->h = 0;
	env->w = 0;
	while (get_next_line(env->fd, &line) > 0)
	{
		if (env->h == 0)
			env->w = ft_countwords(line, ' ');
		if (ft_strlen(line) == 0 || ft_countwords(line, ' ') < env->w)
			ft_error("bad line in file.");
		env->h++;
	}
	if (!(env->h))
		ft_error("no data found.");
	close(env->fd);
}

int		ft_checkargs(int argc, char **argv, t_env *env)
{
	int		fd;

	if (argc != 2)
		ft_error("wrong number of parameters.");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("file does not exist.");
	env->file = argv[1];
	return (fd);
}

int		main(int argc, char **argv)
{
	//t_struct line;
	t_env	env;
	int		numlines;
	int		fd;

	env.fd = ft_checkargs(argc, argv, &env);
	ft_countlines(&env);
	//ft_allocate(&env);

	//line.mlx = mlx_init();
	//line.win = mlx_new_window(line.mlx, 400, 400, "[Window title]");
	//mlx_mouse_hook(line.win, mouse_input, &line);
	//mlx_key_hook(line.win, key_input, &line);
	//mlx_loop(line.mlx);
	return (0);
}