/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:43:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:47:03 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_tree(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;
	double	zsqr;
	double	d1;
	double	d3;
	double	r;

	it = 0;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
		zsqr = tmp.r + tmp.i;
		d1 = sqrt(zsqr);
		r = atan2(z.i, z.r);
		r *= 1.75;
		d3 = pow(d1 * d1 * d1 * d1 * d1 * d1 * d1, 0.25);
		z.r = cos(r) * d3 + image->c.r;
		z.i = sin(r) * d3 + image->c.i;
		it++;
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
	}
	return (it);
}

t_im_nb				ft_z(t_im_nb z, t_im_nb c, int i)
{
	if (i == '1')
		return (ft_add_im(ft_cos_im(z), c));
	else if (i == '2')
	{
		if (z.r >= 0)
			return (ft_mult_im(c, ft_add_imr(z, -1.0)));
		else
			return (ft_mult_im(c, ft_add_imr(z, 1.0)));
	}
	else
		return (ft_add_im(ft_exp_im(ft_cos_im(ft_mult_im(z, z))), c));
}

int					ft_calc_ito(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;

	it = 0;
	if (image->type == '5')
		return (ft_tree(tmp, z, image));
	if (image->type == '3')
		image->c = z;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
		if (image->type != '3' && image->type != '5')
			z = ft_z(z, image->c, image->type);
		else if (image->type == '3')
		{
			z = ft_add_im(ft_mult_im(z, z), image->c);
			image->c = ft_add_im(ft_mult_imr(image->c, 0.5), z);
		}
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
		it++;
	}
	return (it);
}

void				ft_d_on_imageo(t_image *image)
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
			z.r = TPS(px, MAXX, MINX, I_SIZE);
			z.i = TPS(py, MAXY, MINY, I_HEIGHT);
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_ito(tmp, z, image), str, image);
			str += 4;
			px++;
		}
		py++;
	}
}

void				ft_d_on_image_pixo(t_image *image)
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
		while (px <= I_SIZE)
		{
			z.r = TPS(px, MAXX, MINX, I_SIZE);
			z.i = TPS(py, MAXY, MINY, I_HEIGHT);
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_ito(tmp, z, image), str, image);
			str += (px != I_SIZE - 1) ? 8 : 4 * (I_SIZE + 1);
			px += 2;
		}
		py += 2;
	}
	ft_fcolor(image->image, image, 1);
}
