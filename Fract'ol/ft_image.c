/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:29:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/23 17:43:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	ft_image(t_win win)
{
	t_img	img;

	img.i = 0;
	img.intensity = 1;
	img.ptr = mlx_new_image(win.mlx, win.winx, win.winy);
	img.str = mlx_get_data_addr(img.ptr, &img.bpp, &img.s_l, &img.endian);
	return (img);
}
