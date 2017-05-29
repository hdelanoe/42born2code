/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:19:34 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 20:09:37 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	cursy(int y, t_env *e)
{
	if (y < e->win.winy / 2 && e->win.ci > 0)
	{
		e->win.ci -= 0.01;
		e->fract.ci *= 0.9;
		e->win.zi -= 0.01;
	}
	else if (y > e->win.winx / 2 && e->win.ci < 1)
	{
		e->win.ci += 0.01;
		e->fract.ci *= 1.1;
		e->win.zi += 0.01;
	}
}

int		ft_curs(int x, int y, t_env *e)
{
	if (e->key.lock == 0)
	{
		if (x < e->win.winx / 2 && e->win.cr < 2)
		{
			e->win.cr -= 0.01;
			e->fract.cr *= 0.9;
			e->win.zr -= 0.01;
		}
		else if (x > e->win.winx / 2 && e->win.cr > -2)
		{
			e->win.cr += 0.01;
			e->fract.cr *= 1.1;
			e->win.zr += 0.01;
		}
		cursy(y, e);
		ft_fractal(e->arg, *e);
	}
	return (0);
}

void	zoom_in(int x, int y, t_env *e)
{
	e->win.x1 += (x - 0.5 * e->win.winx) / e->win.zoomx;
	e->win.x2 += (x - 0.5 * e->win.winx) / e->win.zoomx;
	e->win.y1 += (y - 0.5 * e->win.winy) / e->win.zoomx;
	e->win.y2 += (y - 0.5 * e->win.winy) / e->win.zoomy;
	e->win.zoomx *= 1.5;
	e->win.zoomy *= 1.5;
	e->win.x1 += 0.25 * (e->win.winx) / e->win.zoomx;
	e->win.x2 += 0.25 * (e->win.winx) / e->win.zoomx;
	e->win.y1 += 0.25 * (e->win.winy) / e->win.zoomy;
	e->win.y2 += 0.25 * (e->win.winy) / e->win.zoomy;
	ft_fractal(e->arg, *e);
}

void	zoom_out(int x, int y, t_env *e)
{
	e->win.x1 -= (x - 0.5 * e->win.winx) / e->win.zoomx;
	e->win.x2 -= (x - 0.5 * e->win.winx) / e->win.zoomx;
	e->win.y1 -= (y - 0.5 * e->win.winy) / e->win.zoomx;
	e->win.y2 -= (y - 0.5 * e->win.winy) / e->win.zoomy;
	e->win.zoomx *= 0.5;
	e->win.zoomy *= 0.5;
	e->win.x1 -= 0.25 * e->win.winx / e->win.zoomx;
	e->win.x2 -= 0.25 * e->win.winx / e->win.zoomx;
	e->win.y1 -= 0.25 * e->win.winy / e->win.zoomy;
	e->win.y2 -= 0.25 * e->win.winy / e->win.zoomy;
	ft_fractal(e->arg, *e);
}

int		ft_mouse(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
		zoom_in(x, y, e);
	if (button == 2 || button == 4)
		zoom_out(x, y, e);
	return (0);
}
