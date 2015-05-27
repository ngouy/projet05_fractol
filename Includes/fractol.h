/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 18:30:02 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 16:25:58 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/Volumes/Data/nfs/zfs-student-5/users/2014/ngouy/mlx/mlx.h"
# include "./../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

/*
** DEFINE
*/
# define ABS(x) (x > 0 ? x : -x)
# define ZF image->zoom_fact
# define BX (((MAXX - MINX) / (float)(I_SIZE / DX)) * ABS(XM + image->xmin))
# define BY (((MAXY - MINY) / (float)(I_HEIGHT / DY)) * ABS(YM + image->xmin))
# define XM image->xmax
# define YM image->ymax
# define FRAME 1
# define I_SIZE 699
# define I_HEIGHT 599
# define MAX_IT (image->max_it)
# define ZOOM (image->zoom)
# define ZZ 15.0
# define TT 20
# define MM 150.0
# define MINX image->xmin
# define MINY image->ymin
# define MAXX image->xmax
# define MAXY image->ymax
# define DX (x - image->oldp->r)
# define DY (y - image->oldp->i)
# define TPS(a, b, c, d) (c + ((a) * ((b - c) / d)))
# define X (ret->base)
# define XX (image->base)
# define DISP(a) (a == 23 ? '5' : '1' - 18 + a)

/*
** Structures
*/

typedef struct		s_im_nb
{
	double				r;
	double				i;
}					t_im_nb;

typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct		s_image
{
	void			*mlx;
	void			*wdw;
	void			*mm;
	char			*image;
	int				*b_p_p;
	int				*size_line;
	int				*edian;
	double			zoom;
	t_im_nb			*base;
	double			max_it;
	t_im_nb			co;
	t_im_nb			c;
	int				zz;
	char			type;
	int				fl;
	int				pix;
	t_im_nb			*oldp;
	int				col;
	float			zoom_fact;
	float			xmin;
	float			xmax;
	float			ymin;
	float			ymax;
}					t_image;

/*
** Prototypes
*/

char				*ft_rules(void);
t_im_nb				ft_log_im(t_im_nb z);
t_im_nb				ft_pow_imr(t_im_nb z, float i);
t_im_nb				ft_exp_im(t_im_nb z);
double				ft_arg_im(t_im_nb z);
t_im_nb				ft_cos_im(t_im_nb z);
t_im_nb				ft_mult_imr(t_im_nb z1, double i);
t_im_nb				ft_sin_im(t_im_nb z);
t_im_nb				ft_add_imr(t_im_nb z1, double i);
t_im_nb				ft_mult_im(t_im_nb z1, t_im_nb z2);
t_im_nb				ft_add_im(t_im_nb z1, t_im_nb z2);
int					ft_zoom(t_image *image, int i);
void				ft_display(int i);
int					ft_expose_hook(t_image *image);
int					ft_expose_hook_j(t_image *image);
int					ft_expose_hook_m(t_image *image);
int					ft_expose_hook_b(t_image *image);
int					ft_expose_hook_o(t_image *image);
int					ft_motion_j(int x, int y, t_image *image);
int					ft_motion(int x, int y, t_image *image);
int					ft_motion_o(int x, int y, t_image *image);
int					ft_mouse_hook(int button, int x, int y, t_image *image);
int					ft_mouse_hook_j(int button, int x, int y, t_image *image);
int					ft_mouse_hook_m(int button, int x, int y, t_image *image);
int					ft_mouse_hook_b(int button, int x, int y, t_image *image);
int					ft_mouse_hook_o(int button, int x, int y, t_image *image);
int					ft_key_hook(int key_code, t_image *image);
int					ft_key_hook_julia(int key_code, t_image *image);
int					ft_key_hook_m(int key_code, t_image *image);
int					ft_key_hook_b(int key_code, t_image *image);
int					ft_key_hook_o(int key_code, t_image *image);
int					ft_zoom_m(t_image *image, int i, int x, int y);
void				ft_d_on_image_b(t_image *image);
void				ft_d_on_image_pix_b(t_image *image);
void				ft_d_on_image(t_image *image);
void				ft_d_on_image_m(t_image *image);
void				ft_d_on_imageo(t_image *image);
void				ft_d_on_image_pix_m(t_image *image);
void				ft_d_on_image_pix(t_image *image);
void				ft_d_on_image_pixo(t_image *image);
t_image				*ft_ini_image_julia(t_image *ret);
t_image				*ft_ini_image_o(t_image *ret, int i);
t_image				*ft_ini_image_mandel(t_image *ret);
t_image				*ft_ini_image_b(t_image *ret);
void				ft_colorpx(int ir, char *str, t_image *image);
void				ft_fcolor(char *str, t_image *image, int i);
void				ft_disp_t(char **envp);

#endif
