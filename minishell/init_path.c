/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:07:49 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 12:40:01 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		set_path(char **path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		if (!ft_strcmp(path[i], "."))
			ft_strdel(&path[i]);
		if (!(ft_strcmp(path[i], "..")) && i != 0)
		{
			j = 0;
			while (path[i + j] && !ft_strcmp(path[i + j], ".."))
			{
				ft_strdel(&path[i + j]);
				j++;
				if (i - j >= 0)
					ft_strdel(&path[i - j]);
			}
			i += j - 1;
		}
		i++;
	}
	return (i);
}

void	attach_path(char **cmd, char **path)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		ft_strcat(path[i], "/");
		if (!(tmp = ft_strjoin(path[i], (*cmd))))
			exit_shell(1);
		if ((fd = open(tmp, O_RDONLY)) > 0)
		{
			free((*cmd));
			(*cmd) = tmp;
			close(fd);
			return ;
		}
		free(tmp);
		i++;
	}
	close(fd);
}

void	init_path(char **cmd, char ***env)
{
	char	*path;
	char	**path_to_search;

	if (!(path = get_env("PATH=", (*env))))
		return ;
	if (!(path_to_search = ft_strsplit(path, ':')))
		exit_shell(1);
	if (ft_strlen(cmd[0]) && !(ft_strchr(cmd[0], '/'))
		&& !(parse_builtin(cmd[0])))
		attach_path(cmd, path_to_search);
	ft_freearr(&path_to_search);
}
