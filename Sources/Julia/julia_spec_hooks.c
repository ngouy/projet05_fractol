/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_spec_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:38:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:38:38 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_expose_hook_j(t_image *image)
{
	image->pix == 1 ? ft_d_on_image_pix(image) : ft_d_on_image(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}

int					ft_key_hook_julia(int key_code, t_image *image)
{
	if (key_code == 35)
		image->pix = image->pix == 1 ? 0 : 1;
	key_code == 15 ? ft_ini_image_julia(image) : NULL;
	if (key_code == 53)
		exit(0);
	image->pix == 1 ? ft_d_on_image_pix(image) : ft_d_on_image(image);
	return (0);
}

int					ft_mouse_hook_j(int button, int x, int y, t_image *image)
{
	button == 4 ? ft_zoom_m(image, 0, x, y) : 0;
	button == 5 ? ft_zoom_m(image, 1, x, y) : 0;
	if (button == 3)
		image->zz = image->zz != 0 ? 0 : 2;
	image->pix == 1 ? ft_d_on_image_pix(image) : ft_d_on_image(image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}

int					ft_motion_j(int x, int y, t_image *image)
{
	if (image->oldp == NULL || image->zz == 2)
	{
		if (image->oldp == NULL)
			image->oldp = malloc(sizeof(t_im_nb));
		else
			image->zz = 1;
		image->oldp->r = x;
		image->oldp->i = y;
	}
	if (image->zz == 1)
	{
		if (image->fl > FRAME)
		{
			image->c.r += BX;
			image->c.i += BY;
			image->oldp->r = x;
			image->oldp->i = y;
			image->zz == 0 ? ft_d_on_image(image) : ft_d_on_image_pix(image);
			mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
			image->fl = 0;
		}
		else
			(image->fl)++;
	}
	return (0);
}
