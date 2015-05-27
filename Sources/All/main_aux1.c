/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_aux1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:11:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:30:17 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char				*ft_rules(void)
{
	char	*str;

	str = "\n**- Fractol -**:\n----------Params----------\n -j for \
julia\n -m for mandelbroat\n -b \
for burning ship\n -<nb> with 1 <= nb <= 5 for bonus fractol\n \
-all for all 8 at the same time\n you can combine params to\
open many windows with different fractals like -j -m -m -j -b \n\
\n----------cmds----------\n j, m, ... open a new window with \
new fractal\n 1-5 pad to change color settings\n <esc> to quit\n \
zoom (or/and modify form on julia and julia-like) with mouse \
wheel\n use + and - to up and down iterations number\n\n";
	return (str);
}

int					ft_zoom_m(t_image *image, int i, int x, int y)
{
	double	tempx;
	double	tempy;
	double	xx;
	double	yy;

	xx = (double)x / (double)I_SIZE;
	yy = (double)y / (double)I_HEIGHT;
	tempx = (image->xmax - image->xmin) / (TT / 5);
	tempy = (image->ymax - image->ymin) / (TT / 5);
	if (i == 1)
	{
		image->xmax -= (tempx * (1 - xx));
		image->xmin += tempx * (xx);
		image->ymax -= tempy * (1 - yy);
		image->ymin += tempy * (yy);
	}
	else
	{
		image->xmax += (tempx * (1 - xx));
		image->xmin -= tempx * (xx);
		image->ymax += tempy * (1 - yy);
		image->ymin -= tempy * (yy);
	}
	return (0);
}

int					ft_zoom(t_image *image, int i)
{
	if (i == 1)
		image->max_it += 50;
	else if (image->max_it > 50)
		image->max_it -= 50;
	return (0);
}
