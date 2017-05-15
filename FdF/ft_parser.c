/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:23:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 19:06:13 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

static int		count_n(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i])
	{
		if (!(ft_isascii(line[i])))
			ft_error(1);
		if ((ft_isprint(line[i])) && !(ft_isprint(line[i + 1])))
			n++;
		i++;
	}
	return (n);
}

static int		*init_tab(char *line, t_size *size)
{
	int i;
	int x;
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * size->x)))
		ft_error(2);
	i = ft_strlen(line);
	x = size->x - 1;
	while (x >= 0)
	{
		while (!(ft_isdigit(line[i])) && i > 0)
		{
			if (ft_isdigit(line[i - 1]))
				line[i] = '\0';
			i--;
		}
		while (ft_isdigit(line[i]) && i > 0)
			i--;
		tab[x] = ft_atoi(&line[i]);
		x--;
	}
	return (tab);
}

static void		go_map(t_map **map, int y, int *z, t_size *size)
{
	int x;

	x = 0;
	while (x < size->x)
	{
		map[y][x].y = y;
		map[y][x].x = x;
		map[y][x].z = z[x];
		if (z[x] > size->z)
			size->z = z[x];
		x++;
	}
	free(z);
}

static t_map	**init_map(t_map **map, char *line, char *file, t_size *size)
{
	int fd;
	int x;
	int y;
	int *z;

	fd = open(file, O_RDONLY);
	y = 0;
	while (y < size->y)
	{
		x = 0;
		if ((get_next_line(fd, &line)) == -1)
			ft_error(3);
		z = init_tab(line, size);
		if (!(map[y] = (t_map*)malloc(sizeof(t_map) * size->x)))
			ft_error(2);
		go_map(map, y, z, size);
		if (*line)
			free(line);
		y++;
	}
	close(fd);
	return (map);
}

t_map			**ft_parser(char **argv, t_size *size)
{
	int		fd;
	int		i;
	int		y;
	char	*line;
	t_map	**map;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		if (i == -1)
		{
			close(fd);
			ft_error(3);
		}
		size->x = count_n(line);
		free(line);
		y++;
	}
	close(fd);
	if (!(map = (t_map**)malloc(sizeof(t_map*) * y)))
		ft_error(2);
	size->y = y;
	map = init_map(map, line, argv[1], size);
	return (map);
}
