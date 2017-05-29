/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burnin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:03:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:52:04 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burnin(t_env e)
{
	while (ZR * ZR + ZI * ZI < 4 && I < e.win.iter)
	{
		e.plan.tmp = ZR;
		ZR = ABS(ZR);
		ZI = ABS(ZI);
		ZR = ZR * ZR - ZI * ZI + e.fract.cr;
		ZI = 2 * ZI * e.plan.tmp + e.fract.ci;
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

void	ft_burnin(t_env e)
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
			draw_burnin(e);
			Y++;
		}
		X++;
	}
	mlx_put_image_to_window(e.win.mlx, e.win.win, e.img.ptr, 0, 0);
}
