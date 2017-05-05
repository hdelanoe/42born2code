/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:54:40 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/02 15:54:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int			ft_isvalid(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		else if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		write(2, "fillit <file name>\n", 19);
		exit(0);
	}
	return (1);
}

char		*ft_make_string(char *av, int i)
{
	char	*str;
	int		j;
	int		fd;
	char	buff;

	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	fd = open(av, O_RDONLY);
	while (read(fd, &buff, 1) != 0)
	{
		str[j] = buff;
		j++;
	}
	str[j] = '\0';
	close(fd);
	return (str);
}

char		*ft_read(int argc, char **argv)
{
	char	buff;
	int		fd;
	char	*str;
	size_t	i;

	if (!(ft_isvalid(argc)))
		return (0);
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		fd_error(1);
	while (read(fd, &buff, 1) != 0)
	{
		i++;
		if (i > 545)
			fd_error(2);
	}
	close(fd);
	str = ft_make_string(argv[1], i);
	if (!(ft_check(str)))
		return (NULL);
	return (str);
}

t_piece		*malloc_piece(void)
{
	t_piece *piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(piece->init = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->init);
	if (!(piece->first = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->first);
	if (!(piece->second = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->second);
	if (!(piece->third = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->third);
	if (!(piece->next = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->next = NULL;
	return (piece);
}
