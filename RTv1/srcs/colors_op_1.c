/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_op_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:47:16 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/01/31 14:47:18 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		c_c_mult(t_color *a, t_color *b)
{
	t_color	color;

	color.b = a->b * b->b;
	color.g = a->g * b->g;
	color.r = a->r * b->r;
	return (color);
}

t_color		c_double_mult(t_color *a, double b)
{
	t_color	color;

	color.b = a->b * b;
	color.g = a->g * b;
	color.r = a->r * b;
	return (color);
}

t_color		c_double_div(t_color *a, double b)
{
	t_color	new;

	new.b = a->b / b;
	new.g = a->g / b;
	new.r = a->r / b;
	new.b = new.b > 1 ? 1 : new.b;
	new.g = new.g > 1 ? 1 : new.g;
	new.r = new.r > 1 ? 1 : new.r;
	return (new);
}

void		print_color(t_color *color, t_datas *d, int x, int y)
{
	if ((x >= 0 && x < d->window_width) && (y >= 0 && y < d->window_height))
	{
		d->mlx.data[(x + y * d->window_width) * 4 + 0] = color->b * 255;
		d->mlx.data[(x + y * d->window_width) * 4 + 1] = color->g * 255;
		d->mlx.data[(x + y * d->window_width) * 4 + 2] = color->r * 255;
	}
}

t_color		c_double_pow(t_color *a, double b)
{
	t_color	color;

	color.b = pow(a->b, b);
	color.g = pow(a->g, b);
	color.r = pow(a->r, b);
	if (color.b > 1)
		color.b = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.r > 1)
		color.r = 1;
	return (color);
}
