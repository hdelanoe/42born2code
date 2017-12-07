/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:33:15 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/22 11:45:11 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	put_cmd(char **cmd, int i)
{
	int j;

	j = 0;
	init_path(cmd, &g_env);
	lauch_command(cmd, &g_env);
	while (cmd[j] && i > 0)
	{
		ft_strdel(&cmd[j]);
		j++;
	}
}

void	init_command(char ***cmd)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while ((*cmd)[++i])
	{
		if (!(ft_strcmp((*cmd)[i], ";")))
		{
			while (!ft_strcmp((*cmd)[i], ";"))
			{
				ft_strdel(&(*cmd)[i]);
				i++;
			}
			put_cmd(&(*cmd)[j], j);
			j = i;
			i--;
		}
	}
	put_cmd(&(*cmd)[j], j);
}

void	check_multi(char ***cmd)
{
	int		i;
	char	*buf;
	char	*home_path;

	if (!cmd)
		return ;
	home_path = get_env("HOME=", g_env);
	i = -1;
	while ((*cmd)[++i])
	{
		if ((*cmd)[i][0] == '~' && home_path)
		{
			if ((*cmd)[i][1] && (*cmd)[i][1] == '/')
				buf = ft_strjoin(home_path, &(*cmd)[i][1]);
			else if ((*cmd)[i][1] && (*cmd)[i][1] != '/' &&
					ft_strstr(home_path, "/Users/"))
				buf = ft_strjoin("/Users/", &(*cmd)[i][1]);
			else
				buf = ft_strdup(home_path);
			ft_strdel(&(*cmd)[i]);
			(*cmd)[i] = buf;
		}
	}
	init_command(cmd);
}
