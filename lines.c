#include "FdF.h"
#include <stdio.h>

void	swap_coords(int *first, int *second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

void	big_grad(t_struct *line)
{
	printf("big_grad\n");
	line->delta = fabs((float)line->delta_x / line->delta_y);
	line->x = line->startx;
	if (line->endy < line->starty)
	{
		swap_coords(&line->starty, &line->endy);
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
	}
}

void	little_grad(t_struct *line)
{
	if (line->mgrad < 0)
		line->adjust = -1;
	if (line->mgrad <= 1 && line->mgrad >= -1)
	{
		printf("little_grad\n");
		line->delta = fabs(line->mgrad);
		line->y = line->starty;
		if (line->endx < line->startx)
		{
			printf("start before %d\n", line->startx);//remove
			swap_coords(&line->startx, &line->endx);
			line->y = line->endy;
			printf("start after %d\n", line->startx);//
		}
		line->x = line->startx - 1;//fixed below by using -1
		printf("before while\n");
		while (line->x++ < line->endx)// misses a pixel but negates line 76
		{
			mlx_pixel_put(line->mlx, line->win, line->x, line->y, 0x00FFFFFF);
			line->offset += line->delta;
			printf("start(%d;%d) end(%d;%d), coord(%d;%d)\n", line->startx, line->starty, line->endx, line->endy, line->x, line->y);//remove
			if (line->offset >= line->thresh)
			{
				line->y += line->adjust;
				line->thresh += 1;
			}
		}
	}
	else 
		big_grad(line);
}

void	no_grad(t_struct *line)
{
	printf("srsly tho, no grad\n");
	if (line->endy < line->starty)
	{
		swap_coords(&line->starty, &line->endy);
	}
	line->y = line->starty - 1;
	printf("|start(%d;%d) end(%d;%d), coord(%d;%d)\n", line->startx, line->starty, line->endx, line->endy, line->x, line->y);//remove
	while (line->y <= line->endy)
	{
		printf("start(%d;%d) end(%d;%d), coord(%d;%d)\n", line->startx, line->starty, line->endx, line->endy, line->x, line->y);//remove
		line->y++;
		mlx_pixel_put(line->mlx, line->win, line->startx, line->y, 0x00FFFFFF);
	}
}

void	draw_line(t_struct *line)
{
	line->delta_y = line->endy - line->starty;
	line->delta_x = line->endx - line->startx;
	line->mgrad = (float)line->delta_y / line->delta_x;
	line->offset = 0;
	line->adjust = 1;
	line->thresh = 0.5;//wait for opti ----also might need to be initialized elsewhere

	if (line->delta_x == 0)
	{
		printf("no grad\n");
		no_grad(line);
	}
	else
	{
		little_grad(line);
	}
}
