/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:17:14 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 13:48:06 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_entry		*dont_ls(t_entry *list)
{
	if (errno == EACCES)
	{
		list->perm = 0;
		return (list);
	}
	if (list->free_path == 1)
		free(list->path);
	free(list);
	return (NULL);
}

void		ft_reverse(t_way **begin)
{
	t_way	*prev;
	t_way	*next;

	if ((*begin) == NULL)
		return ;
	prev = NULL;
	while ((*begin) != NULL)
	{
		next = (*begin)->next;
		(*begin)->next = prev;
		prev = (*begin);
		(*begin) = next;
	}
	(*begin) = prev;
}

void		recurse(t_env_ls *e, t_entry *list)
{
	t_way	*tmp;
	char	*newpath;
	int		famdir;

	tmp = list->way;
	while (tmp)
	{
		famdir = 0;
		if (ft_strcmp(tmp->dir, ".") == 0 ||
				ft_strcmp(tmp->dir, "..") == 0)
			famdir = 1;
		if (famdir == 0 && tmp->type == 4 && tmp->perm == 1 &&
				e->flag[7] == 0)
		{
			e->one = 0;
			if (!(newpath = ft_strjoin(list->path, tmp->dir)))
				ft_error();
			ft_listadd(&list, ft_ls(e, ft_newelem(), newpath));
			free(newpath);
		}
		tmp = tmp->next;
	}
}

void		put_ls(t_env_ls *e, t_entry *list, char *path)
{
	list->file = list->dirent->d_name;
	list->type = list->dirent->d_type;
	if (e->flag[7] > 0)
		list->file = path;
	if (list->biggest < (int)ft_strlen(list->file))
		list->biggest += 8;
	list->way = ft_sort(e, &list, &list->way);
	list->empty = 0;
}

t_entry		*ft_ls(t_env_ls *e, t_entry *list, char *path)
{
	ft_init_list(list, path);
	list->dir = opendir(list->path);
	if (list->dir != NULL)
	{
		while ((list->dirent = readdir(list->dir)) != NULL)
		{
			if (list->dirent->d_name[0] != '.' ||
					e->flag[0] > 0 || e->flag[7] > 0)
				put_ls(e, list, path);
			if (e->flag[7] > 0)
				break ;
		}
		closedir(list->dir);
		if (e->flag[1] > 0)
			ft_reverse(&list->way);
		if (e->flag[7] == 0 && e->flag[2] > 0)
			recurse(e, list);
		return (list);
	}
	return (dont_ls(list));
}
