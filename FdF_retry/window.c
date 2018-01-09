#include "fdf.h"

void	ft_draw(t_env *env)
{
	int		i;
	int 	j;

	i = -1;
	while (++i < env->h)
	{
		j = -1;
		while(++j < env->w)
		{
			mlx_pixel_put(env->mlx, env->win, (i * 10) + 100, (j * 10) + 100, 0x00FFFFFF);
		}
	}
}