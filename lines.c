#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

typedef struct	s_struct{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		startx;
	int		starty;
	int		endx;
	int		endy;
	float	mgrad;
	float	delta;
	int		delta_y;
	int		delta_x;
	int		adjust;
	float	offset;
	double	thresh;
}				t_struct;

void	big_grad(t_struct *line)
{
	printf("big_grad start\n");
	int temp;
	line->delta = fabs((float)line->delta_x / line->delta_y);
	line->x = line->startx;
	printf("dx=%d, dy=%d\n", line->delta_x, line->delta_y);
	if (line->endy < line->starty)
	{
		temp = line->starty;
		line->starty = line->endy;
		line->endy = temp;
		line->x = line->endx;
	}
	line->y = line->starty;
	while (line->y <= line->endy)
	{
		mlx_pixel_put(line->mlx, line->win, line->x, line->y, 0x00FFFFFF);
		line->offset += line->delta;
		if (line->offset >= line->thresh)
		{
			line->x+= line->adjust;
			line->thresh += 1;
		}
		line->y++;
		printf("(%d;%d)\n", line->x, line->y);
		printf("2 y=%d, adjust=%d, thresh=%f, delta=%f, offset=%f\n", line->y, line->adjust, line->thresh, line->delta, line->offset);//remove
	}
}

void	little_grad(t_struct *line)
{	
	printf("little_grad start\n");//remove
	int temp;
	line->mgrad = (float)line->delta_y / line->delta_x;
	line->offset = 0;
	line->adjust = 1;
	if (line->mgrad < 0)
		line->adjust = -1;
	line->thresh = 0.5;//wait for opti ----also might need to be initialized elsewhere
	if (line->mgrad <= 1 && line->mgrad >= -1)
	{
		//printf();
		line->delta = fabs(line->mgrad);
		line->y = line->starty;
		if (line->endx < line->startx)
		{
			temp = line->startx;
			line->startx = line->endx;
			line->endx = temp;
			line->y = line->endy;
		}
		line->x = line->startx;
		printf("initial (%d;%d) m=%f\n", line->x, line->y, line->mgrad);
		while (line->x <= line->endx)
		{
			mlx_pixel_put(line->mlx, line->win, line->x, line->y, 0x00FFFFFF);
			line->offset += line->delta;
			if (line->offset >= line->thresh)
			{
				line->y += line->adjust;
				line->thresh += 1;
				printf("1 y=%d, adjust=%d, thresh=%f\n", line->y, line->adjust, line->thresh);//remove
			}
				printf("2 y=%d, adjust=%d, thresh=%f, delta=%f, offset=%f\n", line->y, line->adjust, line->thresh, line->delta, line->offset);//remove
			line->x++;
			printf("(%d;%d)\n", line->x, line->y);
		}
	}
	else 
		big_grad(line);
}

void	no_grad(t_struct *line)
{
	int temp;
	if (line->endy < line->starty)
	{
		temp = line->starty;
		line->starty = line->endy;
		line->endy = temp;
	}
	line->y = line->starty;
	while (line->y < line->endy)
	{
		line->y++;
		mlx_pixel_put(line->mlx, line->win, line->startx, line->y, 0x00FFFFFF);
		printf("(%d;%d)\n", line->x, line->y);
	}
}

void	draw_init(t_struct *line)
{
	printf("draw init\n");//remove
	//line->startx = 50;
	//line->starty = 100;
	//line->endx = 50;
	//line->endy = 300;
	printf("points initialized- start (%d;%d) end(%d;%d)\n", line->startx, line->starty, line->endx, line->endy);//remove
	line->delta_y = line->endy - line->starty;
	line->delta_x = line->endx - line->startx;
	printf("deltas - delta_y(%d) delta_x(%d)\n", line->delta_y, line->delta_x);//remove

	if (line->delta_x == 0)
	{
		printf("no grad\n");
		no_grad(line);
	}
	else
	{
		printf("little_grad\n");
		little_grad(line);
	}
}

void	draw_line(t_struct *line)
{
	draw_init(line);
}

int		key_input(int keycode, t_struct *line)
{
	if (keycode == 2)
	{
		printf("draw!\n");
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
	}
	if (button == 2)
	{
		line->endx = x;
		line->endy = y;
		mlx_pixel_put(line->mlx, line->win, x, y, 0x00FF0000);
	}
	return (0);
}

int		main()
{
	t_struct line;

	line.mlx = mlx_init();
	line.win = mlx_new_window(line.mlx, 400, 400, "[Window title]");
	mlx_key_hook(line.win, key_input, &line);
	mlx_mouse_hook(line.win, mouse_input, &line);
	mlx_loop(line.mlx);
}
