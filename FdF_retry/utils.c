/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:31:17 by bmoodley          #+#    #+#             */
/*   Updated: 2018/01/11 15:31:18 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initwin(t_env *env)
{
	env->winx = 1920 - ((500 - env->w) * 2);
	env->winy = 1080 - ((500 - env->h));
}

void		ft_init(t_env *env)
{
	if (env->w > 50)
		env->zoom = 8;
	else if (env->w > 100)
		env->zoom = 6;
	else if (env->w > 200)
		env->zoom = 4;
	else if (env->w > 300)
		env->zoom = 2;
	else
		env->zoom = 10;
	env->xoff = 200;
	env->yoff = 200;
	ft_initwin(env);
}
