/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:01:00 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/22 23:42:31 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	write_env(char *buf, char *value, int overwrite, char ***env)
{
	int	i;
	int path;

	i = 0;
	path = 0;
	while ((*env)[i] && (path = (ft_strncmp((*env)[i], buf, ft_strlen(buf)))))
		i++;
	if (path)
	{
		if (!((*env)[i] = (char*)ft_memalloc(sizeof(char) *
						ft_strlen(buf) + ft_strlen(value) + 1)))
			exit_shell(1);
		ft_strcpy((*env)[i], buf);
		if (value)
			ft_strcat((*env)[i], value);
	}
	else if (overwrite)
	{
		free((*env)[i]);
		(*env)[i] = ft_strjoin(buf, value);
	}
}

void	set_env(char *name, char *value, int overwrite, char ***env)
{
	char	buf[BUF_SIZ];

	ft_strcpy(buf, name);
	if (name[ft_strlen(name) - 1] != '=')
		ft_strcat(buf, "=");
	if (!(*env))
	{
		if (!((*env) = (char**)ft_memalloc(sizeof(char*) * (ENV_LEN + 1))))
			exit_shell(1);
	}
	write_env(buf, value, overwrite, env);
}

void	setenv_builtin(char **cmd, char ***env)
{
	int i;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 1 || ft_strchr(cmd[1], '='))
		write(1, "Usage: [NAME] (value) (overwrite)\n", 34);
	else if (i == 2)
		set_env(cmd[1], NULL, 1, env);
	else if (i == 3)
		set_env(cmd[1], cmd[2], 1, env);
	else if (i == 4)
		set_env(cmd[1], cmd[2], ft_atoi(cmd[3]), env);
	else
	{
		write(1, "setenv: too many arguments.\n", 28);
		write(1, "Usage: setenv [NAME] (value) (overwrite)\n", 41);
	}
}

char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	int		len;
	char	*path;

	if (!env)
		return (NULL);
	path = NULL;
	i = 0;
	len = ft_strlen(name);
	while (env[i] && !(path = ft_strnstr(env[i], name, len)))
		i++;
	if (!path)
		return (NULL);
	j = 0;
	while (path[j] != '=')
		j++;
	j++;
	return (&path[j]);
}
