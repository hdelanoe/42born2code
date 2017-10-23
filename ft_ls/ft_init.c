/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:44:41 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/18 23:14:00 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	size_ugb(t_entry **list, t_way *way, int len)
{
	char	*u;
	char	*g;
	char	*b;

	u = NULL;
	g = NULL;
	b = NULL;
	if (!(u = ft_itoa(way->stat.st_uid)) ||
			!(g = ft_itoa(way->stat.st_gid)) ||
			!(b = ft_itoa(way->stat.st_size)))
		ft_error();
	if ((*list)->sz_uid < (len = ft_strlen(u)))
		(*list)->sz_uid = len;
	if ((*list)->sz_gid < (len = ft_strlen(g)))
		(*list)->sz_gid = len;
	if ((*list)->sz_b < (len = ft_strlen(b)))
		(*list)->sz_b = len;
	free(u);
	free(g);
	free(b);
}

void	ft_init_size(t_entry **list, t_way *way)
{
	int		len;
	char	*lk;

	lk = NULL;
	if (!(lk = ft_itoa(way->stat.st_nlink)))
		ft_error();
	if ((*list)->sz_l < (len = ft_strlen(lk)))
		(*list)->sz_l = len;
	if ((way->pwd = getpwuid(way->stat.st_uid)) != NULL &&
			(*list)->sz_u < (len = ft_strlen(way->pwd->pw_name)))
		(*list)->sz_u = len;
	if ((way->grp = getgrgid(way->stat.st_gid)) != NULL &&
			(*list)->sz_g < (len = ft_strlen(way->grp->gr_name)))
		(*list)->sz_g = len;
	free(lk);
	size_ugb(list, way, len);
}

void	ft_init_env(t_env_ls *e)
{
	e->flag[0] = 0;
	e->flag[1] = 0;
	e->flag[2] = 0;
	e->flag[3] = 0;
	e->flag[4] = 0;
	e->flag[5] = 0;
	e->flag[6] = 0;
	e->flag[7] = 0;
	e->flag[8] = 0;
	e->flag[9] = 0;
	e->flag[10] = 0;
	e->flag[11] = 0;
	e->flag[12] = 0;
	e->last_sort = 0;
	e->last_format = 0;
	e->one = 1;
	e->list = NULL;
	e->lst_tmp = NULL;
	ioctl(0, TIOCGWINSZ, &e->ws);
}

t_way	*ft_init_way(t_entry **list, char *file)
{
	t_way *way;

	way = NULL;
	if (!(way = malloc(sizeof(t_way))) ||
		!(way->dir = ft_strdup(file)))
		ft_error();
	way->type = (*list)->type;
	way->perm = (*list)->perm;
	way->next = NULL;
	return (way);
}

void	ft_init_list(t_entry *list, char *path)
{
	if (!(list->path = ft_strjoin(path, "/")))
		ft_error();
	list->free_path = 1;
	list->type = 0;
	list->empty = 1;
	list->perm = 1;
	list->block = 0;
	list->biggest = 15;
	list->sz_l = 0;
	list->sz_u = 0;
	list->sz_g = 0;
	list->sz_b = 0;
	list->sz_uid = 0;
	list->sz_gid = 0;
	list->way = NULL;
}
