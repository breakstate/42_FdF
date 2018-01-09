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

# define ENV(x, i, j) x - (env->map[i][j] * 10)

typedef struct	s_mlx{
	void	*mlx;
	void	*win;
}				t_mlx;

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
	t_line	line;
	int		**map;
	char	*file;
	int		fd;
	int		w;
	int		h;
	void	*mlx;
	void	*win;
}				t_env;

void	ft_draw_grid(t_env *env);

#endif
