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
	int		temp;
}				t_struct;

void	draw_line(t_struct *line);

#endif
