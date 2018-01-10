#include "fdf.h"

void	ft_drawline(t_env *env)
{
	//int 	i;
	//i = 0;
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
	for (int i = 0; i <= env->line.step; i++)
	{
   	 mlx_pixel_put(env->mlx, env->win, env->line.x, env->line.y, 0x00FFFFFF);
   	 env->line.x += env->line.xinc;
   	 env->line.y += env->line.yinc;
	}
}

void	ft_drawgrid_if1(t_env *env, int i, int j)
{
	env->line.x2  = ((j - (i + 1)) * env->zoom) + env->xoff;
	env->line.y2 = ENV((((j + (i + 1)) * env->zoom) / 2) + env->yoff, i + 1, j);
	ft_drawline(env);
}

void	ft_drawgrid_if2(t_env *env, int i, int j)
{
	env->line.x2 = (((j + 1) - i) * env->zoom) + env->xoff;
	env->line.y2 = ENV(((((j + 1) + i) * env->zoom) / 2) + env->yoff, i, j + 1);
	ft_drawline(env);
}

void	ft_drawgrid(t_env *env)
{
	int		i;
	int 	j;

	i = -1;
	while (++i < env->h)
	{
		j = -1;
		while(++j < env->w)
		{
			env->line.x1  = ((j - i) * env->zoom) + env->xoff;
			env->line.y1 = ENV(((((j + i) * env->zoom) / 2) + env->yoff), i, j);
			if (i + 1 < env->h)
			{
				ft_drawgrid_if1(env, i, j);
			}
			if (j + 1 < env->w)
			{
				ft_drawgrid_if2(env, i, j);
			}
		}
	}
}