/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:50:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 13:52:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_file(t_env_ls *e, t_entry *list, char *arg)
{
	int len;

	e->one = 2;
	list->empty = 0;
	len = readlink(arg, list->link, 1024);
	list->link[len] = '\0';
	if (list->biggest < (int)ft_strlen(arg))
		list->biggest += 8;
	list->file = arg;
	list->way = ft_sort(e, &list, &list->way);
}

void		parse_arg(t_env_ls *e, t_entry *list, char *arg)
{
	if (list->dir == NULL)
	{
		e->one = 0;
		if (errno == ENOENT)
		{
			ft_printf("ft_ls: %s: ", arg);
			perror("");
			return ;
		}
		else if (errno == ENOTDIR)
		{
			if (arg[ft_strlen(arg) - 1] == '/')
			{
				ft_printf("ft_ls: %s: ", arg);
				perror("");
				return ;
			}
			put_file(e, list, arg);
		}
	}
}

void		dispay_file(t_env_ls *e, char **path)
{
	int		i;
	t_entry	*list;

	list = ft_newelem();
	ft_init_list(list, ".");
	i = 0;
	while (path[i])
	{
		list->dir = opendir(path[i]);
		parse_arg(e, list, path[i]);
		if (list->dir)
			closedir(list->dir);
		i++;
	}
	if (e->one == 2)
	{
		if (e->flag[1] > 0)
			ft_reverse(&list->way);
		e->list = list;
	}
	else
	{
		free(list->path);
		free(list);
	}
}

void		sort_arg(t_env_ls *e, char **tab)
{
	int			i;
	int			len;
	struct stat	stat1;
	struct stat	stat2;

	len = 1;
	while (tab[len])
		len++;
	while (--len > 0)
	{
		i = -1;
		while (++i < len)
		{
			lstat(tab[i], &stat1);
			lstat(tab[i + 1], &stat2);
			if ((e->last_sort == 4 && stat1.st_mtime < stat2.st_mtime) ||
					(stat1.st_mtime - stat2.st_mtime == 0
					&& ft_strcmp(tab[i], tab[i + 1]) > 0)
					|| (e->last_sort == 9 && stat1.st_size < stat2.st_size)
					|| (e->last_sort == 0 && ft_strcmp(tab[i], tab[i + 1]) > 0))
				ft_swap(&tab[i], &tab[i + 1]);
		}
	}
	ft_reverse_arg(e, tab);
}

int			main(int argc, char **argv)
{
	t_env_ls	e;
	int			i;

	ft_init_env(&e);
	i = ft_flag(&e, argv);
	if (!argv[i])
		e.list = ft_ls(&e, ft_newelem(), ".");
	else
	{
		sort_arg(&e, &argv[i]);
		dispay_file(&e, &argv[i]);
		while (argv[i])
		{
			if (e.list == NULL)
				e.list = ft_ls(&e, ft_newelem(), argv[i]);
			else if ((e.lst_tmp = ft_ls(&e, ft_newelem(),
							argv[i])) != NULL)
				ft_listadd(&e.list, e.lst_tmp);
			i++;
		}
	}
	ft_print(&e);
	(void)argc;
	return (0);
}
