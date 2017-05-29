/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:41:43 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:25:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_dend(t_env e)
{
	while (ZR * ZR + ZI * ZI < 4 && I < e.win.iter)
	{
		e.plan.tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + e.fract.cr;
		ZI = 2 * ZI * e.plan.tmp + e.fract.ci;
		I++;
	}
	if (I % 2 == 0)
	{
		e.img.str[4 * (X + (Y * SL))] = ft_rgb(I, e.win.iter) * e.key.b;
		e.img.str[1 + 4 * (X + (Y * SL))] = ft_rgb(I, e.win.iter) * e.key.g;
		e.img.str[2 + 4 * (X + (Y * SL))] = ft_rgb(I, e.win.iter) * e.key.r;
	}
	else
	{
		e.img.str[4 * (X + (Y * SL))] = I * ft_rgb(I, e.win.iter) * e.key.b;
		e.img.str[1 + 4 * (X + (Y * SL))] = I * ft_rgb(I, e.win.iter) * e.key.g;
		e.img.str[2 + 4 * (X + (Y * SL))] = I * ft_rgb(I, e.win.iter) * e.key.r;
	}
}

void	ft_dend(t_env e)
{
	X = 0;
	while (X < SL)
	{
		Y = 0;
		while (Y < e.win.winy)
		{
			I = 0;
			e.fract.cr = 0.0;
			e.fract.ci = 1.0;
			ZR = X / e.win.zoomx + e.win.x1;
			ZI = Y / e.win.zoomy + e.win.y1;
			draw_dend(e);
			Y++;
		}
		X++;
	}
	mlx_put_image_to_window(e.win.mlx, e.win.win, e.img.ptr, 0, 0);
}
