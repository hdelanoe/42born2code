/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:05:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:10:49 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_win	init_julia(char *arg)
{
	t_win	win;

	win.x1 = -1.5;
	win.x2 = 1.5;
	win.y1 = -1.5;
	win.y2 = 1.5;
	win.iter = 40;
	win.winx = 1024;
	win.winy = 768;
	win.zoomx = win.winx / (win.x2 - win.x1);
	win.zoomy = win.winy / (win.y2 - win.y1);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.winx, win.winy, arg);
	win.cr = -0.8;
	win.ci = 0.2;
	return (win);
}

void	draw_img(t_env e)
{
	while (ZR * ZR + ZI * ZI < 4 && I < e.win.iter)
	{
		e.plan.tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + e.win.cr;
		ZI = 2 * ZI * e.plan.tmp + e.win.ci;
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

void	ft_julia(t_env e)
{
	X = 0;
	while (X < SL)
	{
		Y = 0;
		while (Y < e.win.winy)
		{
			I = 0;
			ZR = X / e.win.zoomx + e.win.x1;
			ZI = Y / e.win.zoomy + e.win.y1;
			draw_img(e);
			Y++;
		}
		X++;
	}
	mlx_put_image_to_window(e.win.mlx, e.win.win, e.img.ptr, 0, 0);
}
