#include <stdio.h>
#include <stdlib.h>

typedef struct	s_struct{
	int		startx;
	int		starty;
	int		x;
	int		y;
	int 	endx;
	int 	endy;
	int 	a;
	int 	b;
	int 	p;
	float	mgrad;
	int		pincrmnt;
}				t_struct;

float	m(t_struct *a)
{
	float m;
	m = (a->endy - a->starty) / (a->endx - a->startx);
	printf("m: %.4f\n", m);
	return (m);
}

void line_decision(t_struct *a)
{
	int temp;

	if (m(a) > 1)//swap
	{
		a->x = a->starty;
		a->starty = a->startx;
		a->startx = a->x; 
	}
}

void	bres(t_struct *a)
{
	a->a = 2 * (a->endy - a->starty);
	a->b = a->a - (2 * (a->endx - a->startx));
	a->p = a->a - (a->endx - a->startx);
	printf("a: %d, b: %d, p: %d\n", a->a, a->b, a->p);
}

void	print_grid(char arr[20][20])
{
	int x = 0;
	int y = 0;

	while (y < 20)
	{
		while (x < 20)
		{
			printf(" %c", arr[y][x]);
			x++;
		}
		x = 0;
		printf("\n");
		y++;
	}
	printf("\n");
}

void	draw_line(t_struct *a, char arr[20][20])
{
	a->x = a->startx;
	a->y = a->starty;
	
	//bres(a); uh uh ahh
	while (a->y < a->endy && a->x < a->endx)
	{
		printf("coord: (%d;%d)\n", a->x, a->y);
		if (a->p < 0)
		{
			a->x++;
			arr[a->y][a->x] = 'X';
			a->p = a->p + a->a;
		}
		else
		{
			a->x++;
			a->y++;
			arr[a->y][a->x] = 'X';
			a->p = a->p + a->b;
		}
		printf("new p: %d\n", a->p);
	}
	printf("coord: (%d;%d)\n", a->x, a->y);
	print_grid(arr);
}

void	grid_init(char arr[20][20])
{
	int y = 0;
	int x = 0;

	while (y < 20)
	{
		while (x < 20)
		{
			arr[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	arr[0][0] = '0';
}

int		main(int argc, char **argv)
{
	char 		arr[20][20];
	t_struct 	a;


	a.startx = atoi(argv[1]);
	a.starty = atoi(argv[2]);
	a.endx = atoi(argv[3]);
	a.endy = atoi(argv[4]);

	printf("start (%d;%d), end (%d;%d)\n", a.startx, a.starty, a.endx, a.endy);

	grid_init(arr);
	draw_line(&a, arr);
	
	return (0);
}
