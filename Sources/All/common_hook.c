/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 15:58:58 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:01:29 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_pos(t_image *image, int i)
{
	if (i == 4)
	{
		image->xmax += (image->xmax - image->xmin) / TT;
		image->xmin += (image->xmax - image->xmin) / TT;
	}
	if (i == 6)
	{
		image->xmax -= (image->xmax - image->xmin) / TT;
		image->xmin -= (image->xmax - image->xmin) / TT;
	}
	if (i == 2)
	{
		image->ymax -= (image->ymax - image->ymin) / TT;
		image->ymin -= (image->ymax - image->ymin) / TT;
	}
	if (i == 8)
	{
		image->ymax += (image->ymax - image->ymin) / TT;
		image->ymin += (image->ymax - image->ymin) / TT;
	}
	return (0);
}

int					ft_key_hook(int key_code, t_image *image)
{
	key_code == 78 ? (ft_zoom(image, 0)) : 0;
	key_code == 69 ? (ft_zoom(image, 1)) : 0;
	key_code == 123 ? (ft_pos(image, 4)) : 0;
	key_code == 126 ? (ft_pos(image, 8)) : 0;
	key_code == 124 ? (ft_pos(image, 6)) : 0;
	key_code == 125 ? (ft_pos(image, 2)) : 0;
	key_code == (46) ? ft_display('m') : (void)0;
	key_code == (38) ? ft_display('j') : (void)0;
	key_code == (11) ? ft_display('b') : (void)0;
	((key_code >= 18 && key_code <= 21) || (key_code == 23)) ?
	ft_display(DISP(key_code)) : (void)0;
	if (key_code >= 83 && key_code <= 87)
		image->col = key_code - 82;
	if (image->type == 'j')
		ft_key_hook_julia(key_code, image);
	if (image->type == 'm')
		ft_key_hook_m(key_code, image);
	if (image->type == 'b')
		ft_key_hook_b(key_code, image);
	if (image->type >= '1' && image->type <= '5')
		ft_key_hook_o(key_code, image);
	mlx_put_image_to_window(image->mlx, image->wdw, image->mm, 0, 0);
	return (0);
}

int					ft_expose_hook(t_image *image)
{
	if (image->type == 'j')
		ft_expose_hook_j(image);
	else if (image->type == 'm')
		ft_expose_hook_m(image);
	else if (image->type == 'b')
		ft_expose_hook_b(image);
	else
		ft_expose_hook_o(image);
	return (0);
}

int					ft_motion(int x, int y, t_image *image)
{
	if (image->type == 'j')
		ft_motion_j(x, y, image);
	else if (image->type >= '1' && image->type <= '5')
		ft_motion_o(x, y, image);
	return (0);
}

int					ft_mouse_hook(int button, int x, int y, t_image *image)
{
	if (image->type == 'j')
		ft_mouse_hook_j(button, x, y, image);
	else if (image->type == 'm')
		ft_mouse_hook_m(button, x, y, image);
	else if (image->type == 'b')
		ft_mouse_hook_b(button, x, y, image);
	else
		ft_mouse_hook_o(button, x, y, image);
	return (0);
}
