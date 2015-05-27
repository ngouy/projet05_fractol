/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:40:17 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:40:20 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_ini_image_mandel2(t_image *ret)
{
	ret->zoom = ZZ;
	ret->max_it = MM;
	X->r = 0;
	X->i = 0;
	ret->zz = 0;
	ret->type = 'm';
	ret->oldp = NULL;
	ret->pix = 0;
	ret->zoom_fact = 2;
	ret->xmax = 0.5;
	ret->xmin = -2.0;
	ret->ymin = -1.2;
	ret->ymax = 1.2;
}

t_image				*ft_ini_image_mandel(t_image *ret)
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
	ft_ini_image_mandel2(ret);
	return (ret);
}
