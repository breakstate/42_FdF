#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_struct{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			startx;
	int			starty;
	int			endx;
	int 		endy;
	int			a;
	int			b;
	int			p;
}				t_struct;

void	bres(t_struct *a)
{
	a->a = 2 * (a->endy - a->starty);
	a->b = a->a - (2 * (a->endx - a->startx));
	a->p = a->a - (a->endx - a->startx);
}

int		mouse_input(int button, int x, int y, t_struct *a)
{
	if (button == 1)
	{
		a->startx = x;
		a->starty = y;
		printf("start x: %d, start y: %d\n", a->startx, a->starty);
	}
	if (button == 2)
	{
		a->endx = x;
		a->endy = y;
		printf("end x: %d, end y: %d\n", a->endx, a->endy);
	}
	return (0);
}

void	draw(t_struct *a)
{
	a->x = a->startx;
	a->y = a->starty;
	while (a->y != a->endy)
	{
		bres(a);
		if (a->p < 0)
		{
			a->x++;
			mlx_pixel_put(a->mlx, a->win, a->x, a->y, 0x00FFFFFF);
			a->p = a->p + a->a;
		}
		else
		{
			a->x++;
			a->y++;
			mlx_pixel_put(a->mlx, a->win, a->x, a->y, 0x00FFFFFF);
			a->p = a->p + a->b;
		}
	}	
}

int		key_input(int keycode, t_struct *a)
{
	if (keycode == 2)
	{
		draw(a);
	}
	if (keycode == 8)
	{
		mlx_clear_window(a->mlx, a->win);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_struct a;

	//a.startx = atoi(argv[1]);
	//a.starty = atoi(argv[2]);
	//a.endx = atoi(argv[3]);
	//a.endy = atoi(argv[4]);

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 400, 400, "[Window title]");
	mlx_mouse_hook(a.win, mouse_input, &a);
	mlx_key_hook(a.win, key_input, &a);
	mlx_loop(a.mlx);
	return (0);
}
