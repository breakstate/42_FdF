/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 23:57:06 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/01 12:05:57 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"

/*
**	keycode reference:
**
**	+ = 69
**	- = 78
**	esc = 53
**	left = 123
**	right = 124
**	up = 126
**	down = 125
**	smaller than = 43
**	bigger than = 47
*/

typedef struct	s_line{
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		x;
	float		y;
	float		step;
}				t_line;

typedef struct	s_env{
	t_line		line;
	int			**map;
	char		*file;
	int			fd;
	int			w;
	int			h;
	int			winx;
	int			winy;
	void		*mlx;
	void		*win;
	int			zoom;
	int			xoff;
	int			yoff;
	int			z;
}				t_env;

void			ft_drawgrid(t_env *env);
int				ft_keyinput(int keycode, t_env *env);
int				ft_redclose(t_env *env);
void			ft_init(t_env *env);

#endif
