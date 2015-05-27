/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_spec_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:40:35 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:40:48 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_expose_hook_m(t_image *image)
{
	ft_d_on_image_m(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}

int					ft_key_hook_m(int key_code, t_image *image)
{
	if (key_code == 35)
		image->pix = image->pix == 1 ? 0 : 1;
	key_code == 15 ? ft_ini_image_mandel(image) : NULL;
	if (key_code == 53)
		exit(0);
	ft_d_on_image_m(image);
	return (0);
}

int					ft_mouse_hook_m(int button, int x, int y, t_image *image)
{
	button == 4 ? ft_zoom_m(image, 0, x, y) : 0;
	button == 5 ? ft_zoom_m(image, 1, x, y) : 0;
	ft_d_on_image_m(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}
