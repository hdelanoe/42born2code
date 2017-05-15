/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:56:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 17:48:26 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bres	init_bresenham(t_map point1, t_map point2)
{
	t_bres algo;

	algo.plusx = 1;
	algo.plusy = 1;
	algo.x1 = point1.xp;
	algo.y1 = point1.yp;
	algo.x2 = point2.xp;
	algo.y2 = point2.yp;
	algo.dx = point2.xp - point1.xp;
	algo.dy = point2.yp - point1.yp;
	if (algo.dx < 0)
	{
		algo.dx = -algo.dx;
		algo.plusx = -1;
	}
	if (algo.dy < 0)
	{
		algo.dy = -algo.dy;
		algo.plusy = -1;
	}
	return (algo);
}

void	draw_line(t_bres algo, t_map point1, t_map point2, t_key_struct key)
{
	while (algo.x1 * algo.plusx <= algo.x2 * algo.plusx)
	{
		put_pixel(algo, key, point1, point2);
		if (algo.e >= 0)
		{
			algo.y1 += algo.plusy;
			algo.e += algo.incy;
		}
		else
			algo.e += algo.incx;
		algo.x1 += algo.plusx;
	}
}

void	draw_rev(t_bres algo, t_map point1, t_map point2, t_key_struct key)
{
	algo.e = 2 * algo.dx - algo.dy;
	algo.incx = 2 * algo.dx;
	algo.incy = 2 * (algo.dx - algo.dy);
	while (algo.y1 * algo.plusy <= algo.y2 * algo.plusy)
	{
		put_pixel(algo, key, point1, point2);
		if (algo.e >= 0)
		{
			algo.x1 += algo.plusx;
			algo.e += algo.incy;
		}
		else
			algo.e += algo.incx;
		algo.y1 += algo.plusy;
	}
}

void	algo_bresenham(t_map point1, t_map point2, t_key_struct key)
{
	t_bres algo;

	algo = init_bresenham(point1, point2);
	algo.incx = 2 * algo.dy;
	algo.incy = 2 * (algo.dy - algo.dx);
	algo.e = 2 * algo.dy - algo.dx;
	if ((algo.dx >= algo.dy))
		draw_line(algo, point1, point2, key);
	else
		draw_rev(algo, point1, point2, key);
}

void	ft_algo(t_map **map, t_size *size, t_mlx_ptr ptr, int erase)
{
	int				x;
	int				y;
	t_key_struct	key;

	key.map = map;
	key.size = size;
	key.ptr = ptr;
	key.erase = erase;
	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x)
		{
			if (x < size->x - 1)
				algo_bresenham(map[y][x], map[y][x + 1], key);
			if (y < size->y - 1)
				algo_bresenham(map[y][x], map[y + 1][x], key);
			x++;
		}
		y++;
	}
	mlx_key_hook(ptr.win, ft_key, &key);
	mlx_loop(ptr.mlx);
}
