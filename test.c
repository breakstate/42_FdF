#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_ptrs{
	void		*mlx;
	void		*win;
} 				t_ptrs;

int mouse_input(int button, int x, int y, t_ptrs *a)
{
	printf("mouse button - %d\n", button);
	printf("mouse co-ords - x: %d, y: %d\n", x, y);
	if (button == 1)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FFFFFF);
	}
	if (button == 2)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FF0000);
	}
	return (0);
}

int key_input(int keycode, t_ptrs *a)
{
	static int x = 100;
	static int y = 100;
	printf("key - %d\n", keycode);
	if (keycode == 8)
	{
		mlx_clear_window(a->mlx, a->win);
	}
	if (keycode == 125)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FFFFFF);
		y++;
	}
	if (keycode == 126)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FFFFFF);
		y--;
	}
	if (keycode == 124)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FFFFFF);
		x++;
	}
	if (keycode == 123)
	{
		mlx_pixel_put(a->mlx, a->win, x, y, 0x00FFFFFF);
		x--;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	return (0);
}

int main()
{

	void *mlx;
	void *win;
	int x;
	int y;
	t_ptrs a;
	int i = 0;

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 400, 400, "[Window title]");
	y = 100;
	x = 100;
	while (y <= 300)
	{
		while (x < 300)
		{
			mlx_pixel_put(a.mlx, a.win, x, y, 0x00FF0000);
			x++;
		}
		y += 10;
		x = 100;
	}
	y = 100;
	while (x <= 300)
	{
		while (y <= 300)
		{
			mlx_pixel_put(a.mlx, a.win, x, y, 0x0000EE00);
			y++;
		}
		x += 10;
		y = 100;
	}
	x = 100;
	while (x <= 300 && y <= 300)
	{
		mlx_pixel_put(a.mlx, a.win, x, y, 0x00FFFFFF);
		x++;
		i++;
		y = y + i;	
	}
	mlx_key_hook(a.win, key_input, &a);
	mlx_mouse_hook(a.win, mouse_input, &a);
	mlx_loop(a.mlx);
	return (0);
}

/*
 * y = axsqr + bx +c
*/
