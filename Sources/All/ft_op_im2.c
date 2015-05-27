/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_im2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:04:47 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:04:59 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_im_nb				ft_cos_im(t_im_nb z)
{
	t_im_nb	ret;

	ret.r = (cos(z.r) * cosh(z.i));
	ret.i = -(sin(z.r) * sinh(z.i));
	return (ret);
}

t_im_nb				ft_mult_im(t_im_nb z1, t_im_nb z2)
{
	t_im_nb		ret;

	ret.r = z1.r * z2.r - z1.i * z2.i;
	ret.i = z1.i * z2.r + z1.r * z2.i;
	return (ret);
}

t_im_nb				ft_mult_imr(t_im_nb z1, double i)
{
	t_im_nb		ret;

	ret.r = z1.r * i;
	ret.i = z1.i * i;
	return (ret);
}

t_im_nb				ft_add_imr(t_im_nb z1, double i)
{
	t_im_nb		ret;

	ret.i = z1.i;
	ret.r = z1.r + i;
	return (ret);
}

t_im_nb				ft_add_im(t_im_nb z1, t_im_nb z2)
{
	t_im_nb		ret;

	ret.i = z1.i + z2.i;
	ret.r = z1.r + z2.r;
	return (ret);
}
