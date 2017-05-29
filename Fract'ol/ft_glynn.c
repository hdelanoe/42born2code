/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glynn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:48:26 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:51:56 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_glynn(t_env e)
{
	while (ZR * ZR + ZI * ZI < 4 && I < e.win.iter)
	{
		e.plan.tmp = ZR;
		ZR = ABS(ZR);
		ZI = ABS(ZI);
		ZR = ZR * ZR - ZI * ZI + e.win.cr;
		ZI = 2 * ZI * e.plan.tmp + e.win.ci;
		ZR = ABS(ZR);
		ZI = ABS(ZI);
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

void	ft_glynn(t_env e)
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
			draw_glynn(e);
			Y++;
		}
		X++;
	}
	mlx_put_image_to_window(e.win.mlx, e.win.win, e.img.ptr, 0, 0);
}
