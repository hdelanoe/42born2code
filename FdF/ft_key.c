/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:11:54 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 15:34:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include <math.h>

void		erase_map(void *param, int erase)
{
	int				x;
	int				y;
	t_key_struct	*key;

	key = (t_key_struct*)param;
	key->erase = erase;
	y = 0;
	while (y < key->size->y)
	{
		x = 0;
		while (x < key->size->x)
		{
			if (x < key->size->x - 1)
				algo_bresenham(key->map[y][x], key->map[y][x + 1], *key);
			if (y < key->size->y - 1)
				algo_bresenham(key->map[y][x], key->map[y + 1][x], *key);
			x++;
		}
		y++;
	}
}

static void	translate(int keycode, t_key_struct *key)
{
	if (keycode == 123)
		key->size->initx -= 56;
	if (keycode == 124)
		key->size->initx += 56;
	if (keycode == 125)
		key->size->inity -= 56;
	if (keycode == 126)
		key->size->inity += 56;
}

static void	zoom(int keycode, t_key_struct *key)
{
	if (keycode == 67)
	{
		key->size->scalex = 1618 / key->size->x;
		key->size->scaley = 1618 / key->size->y;
	}
	if (keycode == 69)
	{
		key->size->scalex *= 1.5;
		key->size->scaley *= 1.5;
		key->size->inity -= 1618 / 6 * (key->size->y / key->size->x);
	}
	if (keycode == 78)
	{
		key->size->scalex /= 1.5;
		key->size->scaley /= 1.55;
		key->size->inity += 1618 / 6 * (key->size->y / key->size->x);
	}
}

static void	stretch(int keycode, t_key_struct *key)
{
	if (keycode == 89)
		key->size->scalez++;
	if (keycode == 83)
		key->size->scalez--;
	if (keycode == 92)
	{
		key->size->scalex += 5;
		key->size->scaley += 5;
	}
	if (keycode == 85)
	{
		key->size->scalex -= 5;
		key->size->scaley -= 5;
	}
	if (keycode == 84)
		key->size->scaley -= 5;
	if (keycode == 91)
		key->size->scaley += 5;
}

int			ft_key(int keycode, void *param)
{
	t_key_struct	*key;

	key = (t_key_struct *)param;
	if (keycode == 53)
		exit(1);
	if (keycode >= 123)
		translate(keycode, key);
	if (keycode < 80)
		zoom(keycode, key);
	if (keycode == 86)
	{
		key->size->scalex *= -1;
		key->size->scaley *= 1;
	}
	if (keycode == 88)
	{
		key->size->scalex *= 1;
		key->size->scaley *= -1;
	}
	else
		stretch(keycode, key);
	erase_map(param, 1);
	proj_iso(key->map, key->size, key->ptr, 0);
	return (0);
}
