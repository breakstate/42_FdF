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
	float		mgrad;
	int			x1incrmnt;
	int			y1incrmnt;
	int			x2incrmnt;
	int			y2incrmnt;
}				t_struct;

void	init_values(t_struct *a)
{
	
}

void	m(t_struct *a)
{
	if (a->endx - a->startx < a->endy - a->starty)
	{

	}
	//a->mgrad = (a->endy - a->starty) / (a->endx - a->startx);
	//printf("m: %.4f\n", a->mgrad);//remove
}
/*
void	line_decision(t_struct *a)
{
	if (a->endx//dx >= y
	{

	}
	else
	{
		a->x = a->starty;
		a->starty = a->startx;
		a->startx = a->x;
	}
}
*/
void	bres(t_struct *a)
{
	a->a = 2 * (a->endy - a->starty);
	a->b = a->a - (2 * (a->endx - a->startx));
	a->p = a->a - (a->endx - a->startx);
	printf("a: %d, b: %d, p: %d m: %.4f\n", a->a, a->b, a->p, a->mgrad);
}

int		mouse_input(int button, int x, int y, t_struct *a)
{
	if (button == 1)
	{
		a->startx = x;
		a->starty = y;
		mlx_pixel_put(a->mlx, a->win, x, y, 0x0000FF00);
		printf("start x: %d, start y: %d\n", a->startx, a->starty);
	}
	if (button == 2)
	{
		a->endx = x;
		a->endy = y;
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FF0000);
		printf("end x: %d, end y: %d\n", a->endx, a->endy);
	}
	return (0);
}

void	draw(t_struct *a)
{
	printf("enter draw()\n");//remove
	a->x = a->startx;
	a->y = a->starty;
	bres(a);
	m(a);
	printf("draw - a: %d, b: %d, p: %d\n", a->a, a->b, a->p);
	printf("start (%d;%d), end (%d;%d)", a->startx, a->starty, a->endx, a->endy );
	while (a->y <= a->endy && a->x <= a->endx)
	{
		//bres(a);
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
		printf("(%d;%d), p: %d, m: %f\n", a->x, a->y, a->p, a->mgrad);//remove
	}	
}

int		key_input(int keycode, t_struct *a)
{
	if (keycode == 2)
	{
		printf("draw!\n");
		draw(a);
	}
	if (keycode == 8)
	{
		mlx_clear_window(a->mlx, a->win);
		a->startx = 0;
		a->starty = 0;
		a->endx = 0;
		a->endy = 0;
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

	a.startx = 3;//atoi(argv[1]);
	a.starty = 4;//atoi(argv[2]);
	a.endx = 16;//atoi(argv[1]);
	a.endy = 9;//atoi(argv[2]);

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 400, 400, "[Window title]");
	mlx_mouse_hook(a.win, mouse_input, &a);
	mlx_key_hook(a.win, key_input, &a);
	mlx_loop(a.mlx);
	return (0);
}
