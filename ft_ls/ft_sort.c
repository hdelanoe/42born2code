/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:06:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/12 21:55:01 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_way	*n_sort(t_way **current, t_sort sort, char *file)
{
	if (ft_strcmp((*current)->dir, file) > 0)
	{
		sort.new->next = (*current);
		return (sort.new);
	}
	while ((*current)->next &&
			ft_strcmp((*current)->next->dir, file) < 0)
		(*current) = (*current)->next;
	sort.tmp = (*current)->next;
	(*current)->next = sort.new;
	sort.new->next = sort.tmp;
	return (sort.begin);
}

t_way	*tt_sort(t_way **current, t_sort sort, char *file)
{
	int diff;

	if ((diff = sort.new->stat.st_mtime - (*current)->stat.st_mtime) > 0
			|| (diff == 0 && ft_strcmp((*current)->dir,
					file) > 0))
	{
		sort.new->next = (*current);
		return (sort.new);
	}
	while ((*current)->next && ((diff = sort.new->stat.st_mtime -
					(*current)->next->stat.st_mtime) < 0
				|| (diff == 0 && ft_strcmp((*current)->next->dir,
						file) < 0)))
		(*current) = (*current)->next;
	sort.tmp = (*current)->next;
	(*current)->next = sort.new;
	sort.new->next = sort.tmp;
	return (sort.begin);
}

t_way	*ss_sort(t_way **current, t_sort sort, char *file)
{
	int	diff;

	if ((diff = sort.new->stat.st_size - (*current)->stat.st_size) > 0 ||
		(diff == 0 && ft_strcmp((*current)->dir,
		file) > 0))
	{
		sort.new->next = (*current);
		return (sort.new);
	}
	while ((*current)->next && ((diff = sort.new->stat.st_size -
			(*current)->next->stat.st_size) < 0 ||
			(diff == 0 && ft_strcmp((*current)->next->dir,
			file) < 0)))
		(*current) = (*current)->next;
	sort.tmp = (*current)->next;
	(*current)->next = sort.new;
	sort.new->next = sort.tmp;
	return (sort.begin);
}

t_way	*ft_sort(t_env_ls *e, t_entry **list, t_way **current)
{
	t_sort	sort;

	sort.new = ft_newway(e, list, (*list)->file);
	if ((*current) == NULL)
		return (sort.new);
	sort.begin = (*current);
	if (e->last_sort == 9)
		sort.begin = ss_sort(current, sort, (*list)->file);
	else if (e->last_sort == 4)
		sort.begin = tt_sort(current, sort, (*list)->file);
	else
		sort.begin = n_sort(current, sort, (*list)->file);
	return (sort.begin);
}
