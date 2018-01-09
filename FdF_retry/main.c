#include "fdf.h"
#include <stdio.h>

void	ft_error(char *error)
{
	ft_putstr("Error: ");
	ft_putstr(error);
	ft_putendl(" Exiting.");
	exit(-1);
}

void		ft_allocate(t_env *env)
{
	char	*line;
	int		i;
	int		j;
	char 	**split;
	
	line = NULL;
	i = -1;
	if ((env->map = ft_alloc2dint(env->w, env->h)) == NULL)
		ft_error("allocation failed.");
	env->fd = open(env->file, O_RDONLY);
	while (get_next_line(env->fd, &line) > 0 && ++i < env->h)
	{
		j = -1;
		split = ft_strsplit(line, ' ');
		while (++j < env->w)
		{
			env->map[i][j] = ft_atoi(split[j]);
		}
		free(line);
		line = NULL;
	}
	ft_print2dint(env->map, env->w, env->h);
	ft_free2dint(env->map, env->h);
	ft_putstr("freed.. but test\n");
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
	ft_allocate(&env);
	int i, j = -1;
	while (i < env.h)
	{
		puts("while\n");
		j = -1;
		while (++j < env.w)
		{
			ft_putnbr(env.map[i][j]);
			ft_putchar(' ');
		}
		i++;
		ft_putendl("");
	}

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 400, 400, "[Window title]");
	//mlx_mouse_hook(line.win, mouse_input, &line);
	//mlx_key_hook(line.win, key_input, &line);
	ft_draw(&env);
	mlx_loop(env.mlx);
	return (0);
}