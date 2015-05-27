/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:11:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:30:34 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_col2(int it, char *str, t_image *image)
{
	if (image->col == 4)
	{
		if (it == (int)image->max_it)
			*(str + 0) = 0;
		else
			*(str + 0) = 254 * pow(it / image->max_it, 0.5);
		*(str + 2) = 0;
		*(str + 1) = 0;
	}
	if (image->col == 5)
	{
		if (it == (int)image->max_it && (*(str + 0) = 0) + 1)
		{
			*(str + 2) = 0;
			*(str + 1) = 0;
		}
		else
		{
			*(str + 0) = 50 + 204 * pow(it / image->max_it, 0.5);
			*(str + 1) = 50 + 204 - 154 * pow(it / image->max_it, 0.5);
			*(str + 2) = 0;
		}
	}
}

void				ft_colorpx(int it, char *str, t_image *image)
{
	if (image->col == 1)
	{
		*(str + 2) = (it == image->max_it) ? 0 : 254 * (tan(it));
		*(str + 1) = (it == image->max_it) ? 0 :
			254 - 254 * (tan(it * it * (image->zoom)));
		*(str + 0) = (it == image->max_it) ? 0 : 254 * sin(it * 20);
	}
	if (image->col == 2)
	{
		if (it == (int)image->max_it)
			*(str + 2) = 0;
		else
			*(str + 2) = 254 * pow(it / image->max_it, 0.5);
		*(str + 1) = 0;
		*(str + 0) = 0;
	}
	if (image->col == 3)
	{
		*(str + 1) = (it == (int)image->max_it) ? 0 : (254 *
			pow(it / image->max_it, 0.5));
		*(str + 2) = 0;
		*(str + 0) = 0;
	}
	else
		ft_col2(it, str, image);
}

int					ft_moychar(char i, char j)
{
	int ii;
	int jj;

	ii = i < 0 ? 255 + i + 1 : i;
	jj = j < 0 ? 255 + j + 1 : j;
	return ((jj + ii) / 2);
}

int					ft_fcoloraux(int x, int y, char **str, int i)
{
	char	*temp;

	if (i == 0)
	{
		temp = *str;
		if (y % 2 == 0)
			*temp = ft_moychar(*(temp - 4), *(temp + 4));
		else
		{
			*temp =
				(ft_moychar(*(temp - 4 * (I_SIZE)), *(temp + 4 * (I_SIZE))));
			if (x != 0)
				*(temp - 4) = ft_moychar(*(temp - 8), *temp);
		}
	}
	else
	{
		if (y % 2 == 0)
		{
			(*str) += 4;
			return (1);
		}
	}
	return (0);
}

void				ft_fcolor(char *str, t_image *image, int i)
{
	int		x;
	int		y;
	char	*temp;

	if (i == 1 || i == 2)
	{
		ft_fcolor(image->image + 1, image, 0);
		ft_fcolor(image->image + 2, image, 0);
	}
	y = 0;
	temp = str;
	while (y < I_HEIGHT)
	{
		x = ft_fcoloraux(x, y, &temp, 1);
		while (x < I_SIZE)
		{
			ft_fcoloraux(x, y, &temp, 0);
			temp += (x == I_SIZE - 1 && y % 2) ? 4 : 8;
			x += 2;
		}
		y++;
	}
}
