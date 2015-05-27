/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_spec_hooks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:17:47 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:32:49 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_expose_hook_b(t_image *image)
{
	ft_d_on_image_b(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}

int					ft_key_hook_b(int key_code, t_image *image)
{
	key_code == 15 ? ft_ini_image_b(image) : NULL;
	if (key_code == 53)
		exit(0);
	ft_d_on_image_b(image);
	return (0);
}

int					ft_mouse_hook_b(int button, int x, int y, t_image *image)
{
	button == 4 ? ft_zoom_m(image, 0, x, y) : 0;
	button == 5 ? ft_zoom_m(image, 1, x, y) : 0;
	ft_d_on_image_b(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}
