/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:16:24 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:17:21 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_ini_image_b2(t_image *ret)
{
	ret->max_it = MM;
	X->r = 0;
	X->i = 0;
	ret->zz = 0;
	ret->type = 'b';
	ret->oldp = NULL;
	ret->pix = 0;
	ret->zoom_fact = 2;
	ret->xmin = -1.65;
	ret->xmax = -1.61;
	ret->ymin = -0.05;
	ret->ymax = 0.003;
}

t_image				*ft_ini_image_b(t_image *ret)
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
	ft_ini_image_b2(ret);
	return (ret);
}
