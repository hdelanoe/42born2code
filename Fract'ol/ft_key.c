/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:34:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:59:07 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_key	ft_init_key(void)
{
	t_key key;

	key.r = 1;
	key.g = 1;
	key.b = 1;
	key.plus = 1;
	key.lock = 0;
	return (key);
}

void	translate(int keycode, t_env *e)
{
	if (keycode == 0)
	{
		e->win.x1 -= 0.1 * e->win.winx / e->win.zoomx;
		e->win.x2 -= 0.1 * e->win.winx / e->win.zoomx;
	}
	if (keycode == 2)
	{
		e->win.x1 += 0.1 * e->win.winx / e->win.zoomx;
		e->win.x2 += 0.1 * e->win.winx / e->win.zoomx;
	}
	if (keycode == 1)
	{
		e->win.y1 += 0.1 * e->win.winy / e->win.zoomy;
		e->win.y2 += 0.1 * e->win.winy / e->win.zoomy;
	}
	if (keycode == 13)
	{
		e->win.y1 -= 0.1 * e->win.winy / e->win.zoomy;
		e->win.y2 -= 0.1 * e->win.winy / e->win.zoomy;
	}
	ft_fractal(e->arg, *e);
}

void	color(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		if (e->key.plus == 1)
			e->key.r++;
		else
			e->key.r--;
	}
	if (keycode == 5)
	{
		if (e->key.plus == 1)
			e->key.g++;
		else
			e->key.g--;
	}
	if (keycode == 11)
	{
		if (e->key.plus == 1)
			e->key.b++;
		else
			e->key.b--;
	}
}

void	pot(int keycode, t_env *e)
{
	if (keycode == 34)
	{
		if (e->key.plus == 1)
			e->win.iter++;
		else
			e->win.iter--;
	}
	if (keycode == 35)
	{
		if (e->key.plus == 1)
			e->img.intensity++;
		else
			e->img.intensity--;
	}
	if (keycode == 37)
	{
		if (e->key.lock == 0)
			e->key.lock = 1;
		else
			e->key.lock = 0;
	}
}

int		ft_key(int keycode, t_env *e)
{
	if (keycode <= 2 || keycode == 13)
		translate(keycode, e);
	if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 35)
		color(keycode, e);
	if (83 <= keycode && keycode <= 88)
	{
		e->key = ft_init_key();
		mlx_destroy_window(e->win.mlx, e->win.win);
		ft_comp_mand(ft_itoa(keycode - 82), *e);
	}
	if (keycode == 34 || keycode == 35 || keycode == 37)
		pot(keycode, e);
	if (keycode == 69)
		e->key.plus = 1;
	if (keycode == 78)
		e->key.plus = 0;
	if (keycode == 53)
		exit(1);
	ft_fractal(e->arg, *e);
	return (0);
}
