/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:27:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 13:48:51 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	name(t_env_ls *e, t_way *way)
{
	if (e->flag[11] > 0)
	{
		if (S_ISLNK(way->stat.st_mode))
			ft_printf("{M}%s{E} -> %s", way->dir, way->link);
		else if (S_ISDIR(way->stat.st_mode))
			ft_printf("{C}%s{E}", way->dir);
		else if (way->stat.st_mode & S_IXUSR)
			ft_printf("{R}%s{E}", way->dir);
		else if (S_ISSOCK(way->stat.st_mode))
			ft_printf("{G}%s{E}", way->dir);
		else if (S_ISCHR(way->stat.st_mode))
			ft_printf("{Y}%s{E}", way->dir);
		else
			ft_putstr(way->dir);
	}
	else
	{
		if (S_ISLNK(way->stat.st_mode))
			ft_printf("%s -> %s", way->dir, way->link);
		else
			ft_putstr(way->dir);
	}
	ft_putchar('\n');
}

void	lttl_l(t_env_ls *e, t_entry **list, t_way *way)
{
	char	*mode;

	mode = ft_mode(way);
	ft_printf("%-12.12s", mode);
	ft_printf("%*d", (*list)->sz_l, way->stat.st_nlink);
	if (way->pwd != NULL && e->flag[6] == 0 && e->flag[10] == 0)
		ft_printf(" %-*s ", (*list)->sz_u, way->pwd->pw_name);
	else if (e->flag[7] == 0)
		ft_printf(" %-*d ", (*list)->sz_uid, way->stat.st_uid);
	if (way->grp != NULL && e->flag[8] == 0 && e->flag[10] == 0)
		ft_printf(" %-*s ", (*list)->sz_g, way->grp->gr_name);
	else if (e->flag[8] == 0)
		ft_printf(" %-*d ", (*list)->sz_gid, way->stat.st_gid);
	if (S_ISREG(way->stat.st_mode) || S_ISDIR(way->stat.st_mode) ||
			S_ISLNK(way->stat.st_mode))
	{
		if (ft_block(e, way->stat.st_size) == -1)
			ft_printf(" %*jd", (*list)->sz_b, (intmax_t)way->stat.st_size);
	}
	else
		ft_printf("%4i,%4i", major(way->stat.st_rdev),
				minor(way->stat.st_rdev));
	ft_printf(" %s ", way->date);
	name(e, way);
	free(mode);
}

void	print(t_env_ls *e, t_entry *list, int size)
{
	int		col;
	t_way	*ptr;

	col = 0;
	while (list->way != NULL)
	{
		ptr = list->way;
		if (e->last_format == 3)
			lttl_l(e, &list, ptr);
		else if (e->last_format == 5)
		{
			ft_printf("%*-s", list->biggest + 1, ptr->dir);
			col++;
			if (col == size)
			{
				ft_putchar('\n');
				col = 0;
			}
		}
		else
			name(e, ptr);
		ft_free_ptr(ptr);
		list->way = list->way->next;
	}
	(e->last_format == 5 && col != 0) ? ft_putchar('\n') : NULL;
}

void	end_of(t_env_ls *e, t_entry *ptr, char *tmp, int size)
{
	ft_strdel(&ptr->path);
	ft_strdel(&tmp);
	if (e->last_sort == 3 && ptr->empty == 0)
		ft_printf("total %i\n", ptr->block);
	print(e, ptr, size);
	if (ptr->next != NULL)
		ft_putchar('\n');
	e->list = e->list->next;
	free(ptr);
}

void	ft_print(t_env_ls *e)
{
	int		size;
	t_entry	*ptr;
	char	*tmp;

	while (e->list != NULL)
	{
		ptr = e->list;
		size = e->ws.ws_col / (ptr->biggest + 1);
		tmp = ft_strsub(ptr->path, 0, ft_strlen(ptr->path) - 1);
		if ((e->flag[5] > 0) && (ptr->empty != 1 || ptr->perm != 1) &&
				e->flag[7] > 7)
			ft_putchar('\n');
		if ((e->one != 1 && (ptr->dir || ptr->perm == 0) &&
					ft_strcmp(tmp, ".") != 0))
			ft_printf("%s:\n", tmp);
		if (ptr->perm == 0)
		{
			ft_strcpy(tmp, &tmp[2]);
			ft_printf("ft_ls : %s: Permission denied\n", ptr->path);
		}
		end_of(e, ptr, tmp, size);
	}
}
