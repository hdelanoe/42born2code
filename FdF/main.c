/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 05:37:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 15:40:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	isvalid(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
			ft_putendl_fd("File name is missing.", 2);
		else
			ft_putendl_fd("Too many arguments.", 2);
		ft_putendl_fd("fdf <file name>.fdf", 2);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_map	**map;
	t_size	size;

	if (!(isvalid(argc)))
		return (0);
	size.z = 0;
	if (!(map = ft_parser(argv, &size)))
		return (0);
	ft_tracer(map, &size);
	return (0);
}
