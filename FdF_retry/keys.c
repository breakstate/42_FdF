#include "fdf.h"

int		ft_redclose(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

int		ft_keyinput2(int keycode, t_env *env)
{
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 123 || keycode == 124)
			env->xoff += keycode == 124 ? 10 : -10;
		else
			env->yoff += keycode == 125 ? 10 : -10;
		mlx_clear_window(env->mlx, env->win);
		ft_drawgrid(env);				
	}
	return (0);
}

int		ft_keyinput(int keycode, t_env *env)
{
	if (keycode == 8)
	{
		mlx_clear_window(env->mlx, env->win);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == 69 || keycode == 78)
	{
		env->zoom += keycode == 69 ? 2 : -2;
		env->zoomz += keycode == 69 ? 2 : -2;
		if (env->zoom < 2)
			env->zoom = 2;
		if (env->zoomz < 2)
			env->zoomz = 2;
		mlx_clear_window(env->mlx, env->win);
		ft_drawgrid(env);
	}
	ft_keyinput2(keycode, env);
	return (0);
}