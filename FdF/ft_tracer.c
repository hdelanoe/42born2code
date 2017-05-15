/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:26:07 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 18:33:29 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		put_pixel(t_bres algo, t_key_struct key, t_map point1, t_map point2)
{
	if (key.erase == 1)
	{
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x00000000);
		return ;
	}
	if (!(point1.z > key.size->z * -0.1 || point2.z > key.size->z * -0.1))
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x000000AA);
	else if (!(point1.z > key.size->z * 0.0 || point2.z > key.size->z * 0.0))
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x000050AA);
	else if (!(point1.z > key.size->z * 0.1 || point2.z > key.size->z * 0.1))
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x0050AA00);
	else if (!(point1.z > key.size->z * 0.5 || point2.z > key.size->z * 0.5))
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x00AAAA00);
	else if (!(point1.z > key.size->z * 0.9 || point2.z > key.size->z * 0.9))
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x00AA5000);
	else
		mlx_pixel_put(key.ptr.mlx, key.ptr.win,
				(int)algo.x1, (int)algo.y1, 0x00FEFEFE);
}

t_mlx_ptr	init_win(void)
{
	t_mlx_ptr	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 1618, 1618, "FdF");
	return (ptr);
}

void		proj_iso(t_map **map, t_size *size, t_mlx_ptr ptr, int erase)
{
	int x;
	int y;

	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x)
		{
			map[y][x].xp = size->initx + ((0.516 * map[y][x].x)
					- (0.618 * map[y][x].y)) * size->scalex;
			map[y][x].yp = size->inity - map[y][x].z * size->scalez
				+ ((0.516 / 2 * map[y][x].x) + (0.618 / 2
							* map[y][x].y)) * size->scaley;
			x++;
		}
		y++;
	}
	ft_algo(map, size, ptr, erase);
}

void		ft_tracer(t_map **map, t_size *size)
{
	int			erase;
	t_mlx_ptr	ptr;

	erase = 0;
	size->scalex = 1618 / size->x;
	size->scaley = 1618 / size->y;
	size->initx = 1618 / 2;
	size->inity = 1618 / 6 * (size->y / size->x);
	size->scalez = 1;
	ptr = init_win();
	proj_iso(map, size, ptr, erase);
	return ;
}
