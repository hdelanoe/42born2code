/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:37:07 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 12:48:55 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	verbose_env(char **cmd, char *tmp, int flag, int i)
{
	int j;

	if (flag)
	{
		ft_printf("#env executing: %s\n", tmp);
		ft_printf("#env    arg[%i]= '%s'\n", 0, tmp);
		j = 1;
		while (cmd[++i])
		{
			ft_printf("#env    arg[%i]= '%s'\n", j, cmd[i]);
			j++;
		}
	}
}

void	lauch_env(char **cmd, t_env_flag *flag, char ***t_env, int i)
{
	char	*tmp;
	int		l;

	l = 0;
	if (flag->altpath[i])
	{
		tmp = ft_strjoin(flag->altpath, cmd[i]);
		free(cmd[i]);
		cmd[i] = tmp;
	}
	else
	{
		l = 1;
		tmp = ft_strdup(cmd[i]);
		init_path(&cmd[i], t_env);
	}
	verbose_env(cmd, tmp, flag->v, i);
	lauch_command(&cmd[i], t_env);
	if (l)
		free(tmp);
}

char	**init_eb(t_env_flag *flag, char ***env)
{
	int		i;
	char	**t_env;

	t_env = NULL;
	flag->v = 0;
	ft_bzero(flag->altpath, BUF_SIZ);
	ft_bzero(flag->unset, BUF_SIZ);
	if (!(*env))
		return (NULL);
	if (!(t_env = (char**)ft_memalloc(sizeof(char*) * (ENV_LEN + 1))))
		exit_shell(1);
	i = 0;
	while ((*env)[i])
	{
		if (!(t_env[i] = ft_strdup((*env)[i])))
		{
			ft_freearr(&t_env);
			exit_shell(1);
		}
		i++;
	}
	return (t_env);
}

int		put_env(char **cmd, char ***env, t_env_flag flag, int i)
{
	int		j;
	char	buf[BUF_SIZ];

	while (ft_strchr(cmd[i], '='))
	{
		j = 0;
		while (cmd[i][j] != '=')
			j++;
		ft_strncpy(buf, cmd[i], j);
		set_env(buf, &cmd[i][j + 1], 1, env);
		if (flag.v)
			ft_printf("#env setenv:    %s\n", cmd[i]);
		i++;
	}
	if (!cmd[i])
		i = 0;
	return (i);
}

void	env_builtin(char **cmd, char ***env)
{
	int			i;
	int			k;
	char		**t_env;
	t_env_flag	flag;

	i = 1;
	k = 0;
	t_env = init_eb(&flag, env);
	if (cmd[i])
		if (!(i = (check_flag(cmd, &flag, &t_env, 1))))
			return ;
	if (cmd[i])
		k = put_env(cmd, &t_env, flag, i);
	if (!k && t_env)
	{
		i = -1;
		while (t_env[++i])
			ft_putendl(t_env[i]);
	}
	else if (k)
		lauch_env(cmd, &flag, &t_env, k);
	ft_freearr(&t_env);
}
