/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroat_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:45:28 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:15:33 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			ft_calc_it(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;
	double	p1;
	double	p2;

	z.i = 0;
	z.r = 0;
	it = 0;
	while (tmp.r + tmp.i < 4.0 && it < MAX_IT)
	{
		p1 = (z.r) > 0 ? z.r : -z.r;
		p2 = (z.i) > 0 ? z.i : -z.i;
		z.r = tmp.r - tmp.i + image->c.r;
		z.i = 2 * p1 * p2 + image->c.i;
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
		it++;
	}
	return (it);
}

void				ft_d_on_image_b(t_image *image)
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
			image->c.r = TPS(px, MAXX, MINX, I_SIZE) + XX->r;
			image->c.i = TPS(py, MAXY, MINY, I_HEIGHT) + XX->i;
			tmp.r = 0;
			tmp.i = 0;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += 4;
			px++;
		}
		py++;
	}
}
