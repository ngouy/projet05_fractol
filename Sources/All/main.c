/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:11:05 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/30 15:56:51 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_fork_fract(int argc, char **argv, char **envp)
{
	pid_t	son;

	son = fork();
	if (son > 0)
		(void)argc;
	if (son == 0)
		execve("./fractol", argv, envp);
}

void				ft_display(int i)
{
	t_image		*image;

	image = NULL;
	if (i == 'b')
		image = ft_ini_image_b(image);
	else if (i == 'm')
		image = ft_ini_image_mandel(image);
	else if (i == 'j')
		image = ft_ini_image_julia(image);
	else if (i <= '5' && i >= '1')
		image = ft_ini_image_o(image, i);
	mlx_expose_hook(image->wdw, ft_expose_hook, image);
	mlx_hook(image->wdw, 6, 1L << 6, ft_motion, image);
	mlx_mouse_hook(image->wdw, ft_mouse_hook, image);
	mlx_key_hook(image->wdw, ft_key_hook, image);
	mlx_loop(image->mlx);
}

int					ft_check_args(char **argv)
{
	int		ind;

	ind = 0;
	(argv)++;
	while (*argv)
	{
		if (ft_strequ(*argv, "-all"))
		{
			if (ind != 0 || argv[1])
				return (0);
			return (1);
		}
		if (!ft_strequ(*argv, "-j") && !ft_strequ(*argv, "-m") &&
				!ft_strequ(*argv, "-b") && !ft_strequ(*argv, "-5") &&
				!ft_strequ(*argv, "-4") && !ft_strequ(*argv, "-3") &&
				!ft_strequ(*argv, "-2") && !ft_strequ(*argv, "-1"))
			return (0);
		ind++;
		argv++;
	}
	return (ind);
}

int					main(int argc, char **argv, char **envp)
{
	int			nb;
	int			i;
	char		*rules;

	rules = ft_rules();
	i = 0;
	if (argc == 1 || !(nb = ft_check_args(argv)))
	{
		ft_putstr(rules);
		return (0);
	}
	if (nb == 1 && argv[1][1] == 'a')
		ft_disp_t(envp);
	else if (nb == 1)
		ft_display(argv[1][1]);
	else
	{
		ft_fork_fract(argc - 1, argv + 1, envp);
		ft_display(argv[1][1]);
	}
	return (0);
}

void				ft_disp_t(char **envp)
{
	char	**argv;

	argv = malloc(sizeof(char *) * 9 + 1);
	argv[0] = "fractol";
	argv[1] = "-j";
	argv[2] = "-m";
	argv[3] = "-b";
	argv[4] = "-1";
	argv[5] = "-2";
	argv[6] = "-3";
	argv[7] = "-4";
	argv[8] = "-5";
	argv[9] = 0;
	main(10, argv, envp);
}
