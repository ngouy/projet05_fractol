/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:19:27 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:37:13 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_calc_it(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;

	it = 0;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
		z = ft_add_im(ft_mult_im(z, z), image->c);
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
			z.r = TPS(px, MAXX, MINX, I_SIZE);
			z.i = TPS(py, MAXY, MINY, I_HEIGHT);
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += 4;
			px++;
		}
		py++;
	}
}

void				ft_d_on_image_pix(t_image *image)
{
	t_pt	p;
	t_im_nb	z;
	char	*str;
	t_im_nb tmp;

	str = image->image;
	p.y = 0;
	while (p.y < I_HEIGHT)
	{
		p.x = 0;
		while (p.x <= I_SIZE)
		{
			z.r = TPS(p.x, MAXX, MINX, I_SIZE);
			z.i = TPS(p.y, MAXY, MINY, I_HEIGHT);
			tmp.r = z.r * z.r;
			tmp.i = z.i * z.i;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += (p.x != I_SIZE - 1) ? 8 : 4 * (I_SIZE + 1);
			p.x += 2;
		}
		p.y += 2;
	}
	ft_fcolor(image->image, image, 1);
}
