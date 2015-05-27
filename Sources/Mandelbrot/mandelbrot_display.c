/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroat_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:45:28 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:39:55 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			ft_calc_it(t_im_nb tmp, t_im_nb z, t_image *image)
{
	int		it;

	z.i = 0;
	z.r = 0;
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

void				ft_d_on_image_m(t_image *image)
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
			image->c.r = (TPS(px, MAXX, MINX, I_SIZE));
			image->c.i = (TPS(py, MAXY, MINY, I_HEIGHT));
			tmp.r = 0;
			tmp.i = 0;
			ft_colorpx((double)ft_calc_it(tmp, z, image), str, image);
			str += 4;
			px++;
		}
		py++;
	}
}
