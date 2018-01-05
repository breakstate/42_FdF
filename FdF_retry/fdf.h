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

typedef struct	s_mlx{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_env{
	int		**map;
	char	*file;
	int		fd;
	int		w;
	int		h;
}				t_env;

#endif
