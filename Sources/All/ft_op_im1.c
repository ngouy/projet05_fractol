/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_im1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:01:58 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:02:35 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_im_nb				ft_pow_imr(t_im_nb z, float i)
{
	t_im_nb		ret;

	ret = ft_exp_im(ft_mult_imr(ft_log_im(z), i));
	return (ret);
}

t_im_nb				ft_log_im(t_im_nb z)
{
	t_im_nb		ret;

	ret.r = log(sqrt(z.r * z.r + z.i * z.i));
	ret.i = ft_arg_im(z);
	return (ret);
}

double				ft_arg_im(t_im_nb z)
{
	return (atan2(z.r, z.i));
}

t_im_nb				ft_exp_im(t_im_nb z)
{
	t_im_nb	ret;

	ret.r = exp(z.r) * cos(z.i);
	ret.i = exp(z.r) * sin(z.i);
	return (ret);
}

t_im_nb				ft_sin_im(t_im_nb z)
{
	t_im_nb	ret;

	ret.r = (sin(z.r) * cosh(z.i));
	ret.i = +(cos(z.r) * sinh(z.i));
	return (ret);
}
