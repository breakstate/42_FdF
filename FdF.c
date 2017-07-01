#include "FdF.h"
#include <stdio.h>

int		key_input(int keycode, t_struct *line)
{
	if (keycode == 2)
	{
		draw_line(line);
	}
	if (keycode == 8)
	{
		mlx_clear_window(line->mlx, line->win);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(line->mlx, line->win);
		exit(0);
	}
	return (0);
}

int		mouse_input(int button, int x, int y, t_struct *line)
{
	if (button == 1)
	{
		line->startx = x;
		line->starty = y;
		mlx_pixel_put(line->mlx, line->win, x, y, 0x0000FF00);
		printf("start %d;%d\n", x, y);
	}
	if (button == 2)
	{
		line->endx = x;
		line->endy = y;
		mlx_pixel_put(line->mlx, line->win, x, y, 0x00FF0000);
		printf("end %d;%d\n", x, y);
		draw_line(line);
	}
	return (0);
}

int		main()
{
	t_struct line;

	line.startx = 3;
	line.starty = 3;
	line.endx = 3;
	line.endy = 50;

	line.mlx = mlx_init();
	line.win = mlx_new_window(line.mlx, 400, 400, "[Window title]");
	mlx_mouse_hook(line.win, mouse_input, &line);
	mlx_key_hook(line.win, key_input, &line);
	mlx_loop(line.mlx);
	return (0);
}
