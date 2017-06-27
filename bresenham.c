#include <stdio.h>
#include <stdlib.h>

/*struct holding start and end coordinates*/
typedef struct s_struct{
	int Ax;
	int Ay;
	int Bx;
	int By;
}				t_struct;

/*struct holding bresenham's a, b and p*/
typedef struct s_struct2{
	int a;
	int b;
	int p;
}				t_struct2;

/*draws the grid*/
void draw_grid(char arr[20][20])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 20)
		{
			printf(" %c", arr[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	printf("\n");
}

/*updates the Bresenham's values*/
void bres_step(t_struct2 *bres, t_struct *co)//updates p value as per bres-algo
{
	bres->a = 2 * (co->By - co->Ay);
	bres->b = bres->a - (2 * (co->Bx - co->Ax));
	bres->p = bres->a - (co->Bx - co-> Ax);	
}

/*draws the calculated line pixel by pixel*/
void draw_line(t_struct *co, char arr[20][20])
{
	t_struct2 bres;
	int x;
	int y;
	int i;
	
	i = 0;
	x = co->Ax;
	y = co->Ay;

/*initializing a, b and p*/
	bres_step(&bres, co);// co and not &co because co is a pointer here
	printf("a = %d, b = %d, p = %d\n", bres.a, bres.b, bres.p);

	while (x != co->Bx)//needs better stopping condition
	{
		printf("p = %d\n", bres.p);
		if (bres.p < 0)
		{
			x++;
			arr[y][x] = 'X';
			bres.p = bres.p + bres.a;
		}
		else
		{
			x++;
			y++;
			arr[y][x] = 'X';
			bres.p = bres.p + bres.b;
		}
		printf("x = %d, y = %d\n", x, y);
		i++;
	}
	draw_grid(arr);
}

/*takes start and end coords, initializes grid*/
int main(int argc, char **argv)
{
	int i;
	int j;
	char arr[20][20];
	t_struct co;
	co.Ax = atoi(argv[1]);
	co.Ay = atoi(argv[2]);
	co.Bx = atoi(argv[3]); 
	co.By = atoi(argv[4]);

	i = 0;
	j = 0;

	while (i < 20)
	{
		while (j < 20)
		{
			arr[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 20)
		{
			printf(" %c", arr[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	draw_line(&co, arr);
	return (0);
}
