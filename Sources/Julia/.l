/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:11:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/27 11:25:57 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include <stdio.h>

int					ft_calc_it(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;
	double	zsqr;
	double	d1;
	double	d2;
	double	d3;
	double	r;

	it = 0;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
		zsqr = tmp.r + tmp.i;
		d1 = sqrt(zsqr);
		r = atan2(z.r, z.i);
		r *= 1.75;
		d2 = d1 * d1 * d1 * d1 * d1 * d1 * d1;
		d3 = pow(d2, 0.25);
		z.r = cos(r) + d3 + image->c.r;
		z.i = sin(r) + d3 + image->c.i;
		it++;
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
	}
	return (it);
}


int					ft_calc_itt(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;

	it = 0;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
	//	z = ft_mult_im(image->c, ft_cos_im(ft_mult_im(z, image->c)));
		/*if (z.r * image->c.i + image->c.r * z.i >= 0)*/
		/*if (z.r >= 0)
			z = ft_mult_im(image->c, ft_add_imr(z, -1.0));
		else
			z = ft_mult_im(image->c, ft_add_imr(z, 1.0));*/
	//		z = ft_add_im(ft_exp_im(ft_cos_im(ft_mult_im(z, z))), image->c);
		z = ft_add_im(ft_pow_imr(z, 1.75), image->c);
	/*	z = ft_add_im(ft_mult_im(z, z), image->c);			avec c0 = z0 = pix;
		image->c = ft_add_im(ft_mult_imr(image->c, 0.5), z);*/
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
		it++;
	}
	return (it);
}

void				ft_d_on_image(t_image *image)
{
	int		px;
	int		py;
	t_im_nb	z;
	char	*str;
	t_im_nb tmp;

	str = image->image;
	py = 0;
	while (py < I_HEIGHT)
	{
		px = 0;
		while (px < I_SIZE)
		{
			z.r = TPS(px, MAXXJ, MINXJ, I_SIZE) / ZOOM + image->base->r;
			z.i = TPS(py, MAXYJ, MINYJ, I_HEIGHT) / ZOOM + image->base->i;
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += 4;
			px ++;
		}
		py++;
	}
}

void				ft_d_on_image_pix(t_image *image)
{
	int		px;
	int		py;
	int		it;
	t_im_nb	z;
	char	*str;
	t_im_nb tmp;

	str = image->image;
	py = 0;
	while (py < I_HEIGHT)
	{
		px = 0;
		while (px <= I_SIZE)
		{
			z.r = TPS(px, MAXXJ, MINXJ, I_SIZE) / ZOOM + image->base->r;
			z.i = TPS(py, MAXYJ, MINYJ, I_HEIGHT) / ZOOM + image->base->i;
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += (px != I_SIZE - 1) ? 8: 4 * (I_SIZE + 1);
			px += 2;
		}
		py += 2;
	}
	ft_fcolor(image->image, image, 1);
}

