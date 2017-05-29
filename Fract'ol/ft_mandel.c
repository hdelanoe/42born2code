/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:01:15 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:14:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_win	init_mandel(char *arg)
{
	t_win	win;

	win.x1 = -2.1;
	win.x2 = 0.6;
	win.y1 = -1.2;
	win.y2 = 1.2;
	win.iter = 50;
	win.winx = 1024;
	win.winy = 768;
	win.zoomx = win.winx / (win.x2 - win.x1);
	win.zoomy = win.winy / (win.x2 - win.x1);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.winx, win.winy, arg);
	win.cr = 0.975;
	win.ci = -1.125;
	return (win);
}

void	draw_mandel(t_env e)
{
	while (ZR * ZR + ZI * ZI < 4 && I < e.win.iter)
	{
		e.plan.tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + e.fract.cr;
		ZI = 2 * ZI * e.plan.tmp + e.fract.ci;
		I++;
	}
	if (I == e.win.iter)
	{
		e.img.str[4 * (X + (Y * SL))] = 0;
		e.img.str[1 + 4 * (X + (Y * SL))] = 0;
		e.img.str[2 + 4 * (X + (Y * SL))] = 0;
	}
	else if (I < e.win.iter)
	{
		e.img.str[4 * (X + (Y * SL))] = I * e.img.intensity * e.key.b;
		e.img.str[1 + 4 * (X + (Y * SL))] = I * e.img.intensity * e.key.g;
		e.img.str[2 + 4 * (X + (Y * SL))] = I * e.img.intensity * e.key.r;
	}
}

void	ft_mandel(t_env e)
{
	X = 0;
	while (X < SL)
	{
		Y = 0;
		while (Y < e.win.winy)
		{
			I = 0;
			e.fract.cr = X / e.win.zoomx + e.win.x1;
			e.fract.ci = Y / e.win.zoomy + e.win.y1;
			ZR = 0;
			ZI = 0;
			draw_mandel(e);
			Y++;
		}
		X++;
	}
	mlx_put_image_to_window(e.win.mlx, e.win.win, e.img.ptr, 0, 0);
}
