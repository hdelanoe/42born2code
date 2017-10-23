/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 12:53:42 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/18 17:06:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	other(t_way *list, char *buff)
{
	if ((list->stat.st_mode & S_IROTH) != 0)
		buff[7] = 'r';
	if ((list->stat.st_mode & S_IWOTH) != 0)
		buff[8] = 'w';
	if ((list->stat.st_mode & S_IXOTH) != 0)
	{
		buff[9] = 'x';
		if ((list->stat.st_mode & S_ISVTX) != 0)
			buff[9] = 't';
	}
	else if ((list->stat.st_mode & S_ISVTX) != 0)
		buff[9] = 'T';
}

void	right(t_way *list, char *buff)
{
	if ((list->stat.st_mode & S_IRUSR) != 0)
		buff[1] = 'r';
	if ((list->stat.st_mode & S_IWUSR) != 0)
		buff[2] = 'w';
	if ((list->stat.st_mode & S_IXUSR) != 0)
	{
		buff[3] = 'x';
		if ((list->stat.st_mode & S_ISUID) != 0)
			buff[3] = 's';
	}
	else if ((list->stat.st_mode & S_ISUID) != 0)
		buff[3] = 'S';
	if ((list->stat.st_mode & S_IRGRP) != 0)
		buff[4] = 'r';
	if ((list->stat.st_mode & S_IWGRP) != 0)
		buff[5] = 'w';
	if ((list->stat.st_mode & S_IXGRP) != 0)
	{
		buff[6] = 'x';
		if ((list->stat.st_mode & S_ISGID) != 0)
			buff[6] = 's';
	}
	else if ((list->stat.st_mode & S_ISGID) != 0)
		buff[6] = 'S';
	other(list, buff);
}

char	*ft_mode(t_way *list)
{
	char	*buff;

	if (!(buff = ft_memalloc(11)))
		ft_error();
	ft_memset((void*)buff, (int)'-', 11);
	if (S_ISDIR(list->stat.st_mode) != 0)
		buff[0] = 'd';
	if (S_ISCHR(list->stat.st_mode) != 0)
		buff[0] = 'c';
	if (S_ISBLK(list->stat.st_mode) != 0)
		buff[0] = 'b';
	if (S_ISFIFO(list->stat.st_mode) != 0)
		buff[0] = 'p';
	if (S_ISLNK(list->stat.st_mode) != 0)
		buff[0] = 'l';
	if (S_ISSOCK(list->stat.st_mode) != 0)
		buff[0] = 's';
	right(list, buff);
	buff[10] = '\0';
	return (buff);
}
