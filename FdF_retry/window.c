#include "fdf.h"

void		ft_getcol(t_env *env)
{
	if (env->z1 > 0 || env->z2 > 0)
		env->col = 0x0000EE00;
	else if (env->z1 < 0 || env->z2 < 0)
		env->col = 0x00EE0000;
	else
		env->col = 0x00FFFFFF;
}

void		ft_drawline(t_env *env)
{
	int		i;
	
	ft_getcol(env);
	i = -1;
	// calculate dx , dy
	env->line.dx = env->line.x2 - env->line.x1;
	env->line.dy = env->line.y2 - env->line.y1;

// Depending upon absolute value of dx & dy
// choose number of steps to put pixel as
// steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy)
	env->line.step = fabs(env->line.dx) > fabs(env->line.dy) ?
	fabs(env->line.dx) : fabs(env->line.dy);

// calculate increment in x & y for each steps
	env->line.xinc = env->line.dx / (float) env->line.step;
	env->line.yinc = env->line.dy / (float) env->line.step;

// Put pixel for each step
	env->line.x = env->line.x1;
	env->line.y = env->line.y1;

	while (++i <= env->line.step)
	{
		mlx_pixel_put(env->mlx, env->win, env->line.x, env->line.y, env->col);
		env->line.x += env->line.xinc;
		env->line.y += env->line.yinc;
	}
}

void		ft_drawgrid_if1(t_env *env, int i, int j)
{
	env->z2 = (env->map[i][j] / scale) * env->zoomz;
	env->line.x2 = ((j - i) * env->zoom) + env->xoff;
	env->line.y2 = ((((j + i) * env->zoom) / 2) + env->yoff) - env->z2;
	ft_drawline(env);
}

void		ft_drawgrid_if2(t_env *env, int i, int j)
{
	env->z2 = (env->map[i][j] / scale) * env->zoomz;
	env->line.x2 = ((j - i) * env->zoom) + env->xoff;
	env->line.y2 = ((((j + i) * env->zoom) / 2) + env->yoff) - env->z2;
	ft_drawline(env);
}

void		ft_drawgrid(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->h)
	{
		j = -1;
		while (++j < env->w)
		{
			env->z1 = (env->map[i][j] / scale) * env->zoomz;
			env->line.x1 = ((j - i) * env->zoom) + env->xoff;
			env->line.y1 = ((((j + i) * env->zoom) / 2) + env->yoff) - env->z1;
			if (i + 1 < env->h)
				ft_drawgrid_if1(env, i + 1, j);
			if (j + 1 < env->w)
				ft_drawgrid_if2(env, i, j + 1);
		}
	}
}
