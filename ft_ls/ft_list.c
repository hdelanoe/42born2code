/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:25:41 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/18 19:09:14 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_entry	*ft_newelem(void)
{
	t_entry	*list;

	if (!(list = (t_entry*)malloc(sizeof(t_entry))))
		ft_error();
	list->dir = NULL;
	list->next = NULL;
	return (list);
}

void	ft_listadd(t_entry **current, t_entry *new)
{
	t_entry *tmp;

	tmp = (*current);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_way	*ft_newway(t_env_ls *e, t_entry **list, char *file)
{
	int		len;
	t_way	*way;
	char	*newpath;

	way = ft_init_way(list, file);
	if (e->flag[7] > 0)
	{
		if (!(newpath = ft_strdup(file)))
			ft_error();
	}
	else
	{
		if (!(newpath = ft_strjoin((*list)->path, file)))
			ft_error();
	}
	lstat(newpath, &way->stat);
	ft_init_size(list, way);
	if (!(way->date = ft_strsub(ctime(&way->stat.st_mtime), 4, 12)))
		ft_error();
	len = readlink(newpath, way->link, sizeof(way->link));
	way->link[len] = '\0';
	(*list)->block += way->stat.st_blocks;
	free(newpath);
	return (way);
}
