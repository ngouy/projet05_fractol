/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:36:35 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:37:40 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					ft_ini_image_julia2(t_image *ret)
{
	ret->zoom = ZZ;
	ret->max_it = MM;
	ret->xmax = 1.5;
	ret->xmin = -1.5;
	ret->ymin = -1.2;
	ret->ymax = 1.2;
	ret->c.i = 0.054463;
	ret->co.i = ret->c.i;
	ret->c.r = -0.748624;
	ret->co.r = ret->c.r;
	ret->zz = 0;
	ret->type = 'j';
	ret->oldp = NULL;
	ret->pix = 0;
	ret->zoom_fact = 2;
}

t_image					*ft_ini_image_julia(t_image *ret)
{
	if (ret == NULL)
	{
		ret = malloc(sizeof(*ret));
		X = malloc(sizeof(*X));
		ret->b_p_p = malloc(8);
		ret->size_line = malloc(8);
		ret->edian = malloc(8);
		ret->mlx = mlx_init();
		ret->wdw = mlx_new_window(ret->mlx, I_SIZE, I_HEIGHT, "fractol");
		ret->mm = mlx_new_image(ret->mlx, I_SIZE, I_HEIGHT);
		ret->image = mlx_get_data_addr(ret->mm, ret->b_p_p, ret->size_line,
				ret->edian);
		ret->col = 5;
	}
	ft_ini_image_julia2(ret);
	return (ret);
}
