/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:11:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:49:22 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_ini_image_o2(t_image *ret)
{
	ret->zoom = ZZ;
	ret->max_it = MM;
	ret->xmax = 3.0;
	ret->xmin = -3.0;
	ret->ymin = -3.0;
	ret->ymax = 3.0;
	ret->co.r = ret->c.r;
	ret->co.i = ret->c.i;
	ret->zz = 0;
	ret->oldp = NULL;
	ret->pix = 0;
	ret->zoom_fact = 2;
}

static t_im_nb		ft_c(int i)
{
	t_im_nb		c;

	if (i == '1')
	{
		c.r = -0.182749;
		c.i = 1.247360;
	}
	if (i == '2')
	{
		c.r = -0.465234;
		c.i = 1.207656;
	}
	if (i == '4')
	{
		c.r = -1.923237;
		c.i = -0.156522;
	}
	if (i == '5')
	{
		c.r = 0.3;
		c.i = 0.0;
	}
	return (c);
}

t_image				*ft_ini_image_o(t_image *ret, int i)
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
	ret->type = i;
	ret->c = ft_c(i);
	ft_ini_image_o2(ret);
	return (ret);
}
