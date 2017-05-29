/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:00:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 19:01:13 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	error_arg(int error, char *arg)
{
	if (error == 1)
	{
		ft_putstr("fract'ol need a fractal name.\n Try Mandelbrot, Julia, ");
		ft_putstr("burningship, voodoo, dendrite or Glynn.\n");
	}
	if (error == 2)
	{
		ft_putstr(arg);
		ft_putstr(" is not a valid fractal.\nTry Mandelbrot, Julia, ");
		ft_putstr("burningship, voodoo, dendrite  or Glynn.\n");
	}
	exit(1);
}

void	ft_comp_jul(char *arg, t_env e)
{
	if (ft_strcmp(arg, "Julia") == 0 || ft_strcmp(arg, "julia") == 0 ||
			ft_strcmp(arg, "2") == 0 ||
			ft_strcmp(arg, "Dendrite") == 0 ||
			ft_strcmp(arg, "dendrite") == 0 ||
			ft_strcmp(arg, "6") == 0)
	{
		e.win = init_julia(arg);
		e.img = ft_image(e.win);
		ft_fractal(e.arg, e);
	}
}

void	ft_comp_mand(char *arg, t_env e)
{
	e.arg = arg;
	if (ft_strcmp(arg, "Mandelbrot") == 0 || ft_strcmp(arg, "1") == 0 ||
			ft_strcmp(arg, "mandelbrot") == 0 ||
			ft_strcmp(arg, "Burningship") == 0 || ft_strcmp(arg, "3") == 0 ||
			ft_strcmp(arg, "burningship") == 0 ||
			ft_strcmp(arg, "Voodoo") == 0 || ft_strcmp(arg, "voodoo") == 0 ||
			ft_strcmp(arg, "4") == 0 ||
			ft_strcmp(arg, "Glynn") == 0 || ft_strcmp(arg, "glynn") == 0 ||
			ft_strcmp(arg, "5") == 0)
	{
		e.win = init_mandel(arg);
		e.img = ft_image(e.win);
		ft_fractal(e.arg, e);
	}
	else
		ft_comp_jul(arg, e);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		error_arg(1, argv[1]);
	e.key = ft_init_key();
	ft_putstr("---Fractol---\n---buttons---\n");
	ft_putstr("'+' : ++\n'-' : --\n'i' : iterate\n");
	ft_putstr("'p' : intensity\n'r', 'g', 'b' : colors\n");
	ft_putstr("'a', 'w', 's', 'd' : translate\n");
	ft_putstr("'l' : lock\n");
	ft_putstr("number '1'<->'6' : reboot\n");
	ft_putstr("'mouse' : zoom\n");
	ft_putstr("-------------\n");
	ft_comp_mand(argv[1], e);
	error_arg(2, argv[1]);
	return (0);
}

void	ft_fractal(char *arg, t_env e)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0 ||
			ft_strcmp(arg, "mandelbrot") == 0 || ft_strcmp(arg, "1") == 0)
		ft_mandel(e);
	if (ft_strcmp(arg, "Julia") == 0 ||
			ft_strcmp(arg, "julia") == 0 || ft_strcmp(arg, "2") == 0)
		ft_julia(e);
	if (ft_strcmp(arg, "Burningship") == 0 ||
			ft_strcmp(arg, "burningship") == 0 || ft_strcmp(arg, "3") == 0)
		ft_burnin(e);
	if (ft_strcmp(arg, "Voodoo") == 0 ||
			ft_strcmp(arg, "voodoo") == 0 || ft_strcmp(arg, "4") == 0)
		ft_voodoo(e);
	if (ft_strcmp(arg, "Glynn") == 0 ||
			ft_strcmp(arg, "glynn") == 0 || ft_strcmp(arg, "5") == 0)
		ft_glynn(e);
	if (ft_strcmp(arg, "Dendrite") == 0 ||
			ft_strcmp(arg, "dendrite") == 0 || ft_strcmp(arg, "6") == 0)
		ft_dend(e);
	mlx_hook(e.win.win, 6, 6, ft_curs, &e);
	mlx_key_hook(e.win.win, ft_key, &e);
	mlx_mouse_hook(e.win.win, ft_mouse, &e);
	mlx_loop(e.win.mlx);
}
