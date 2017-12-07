/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:45:23 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/23 15:26:03 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	set_vi(char *cmd, t_env_flag *flag, char ***env)
{
	if (ft_strchr(cmd, 'v'))
		flag->v++;
	if (ft_strchr(cmd, 'i'))
	{
		if (flag->v == 1)
			write(1, "#env clearing environ\n", 22);
		ft_freearr(env);
	}
}

int		is_illegal(char *arg)
{
	if (!ft_strchr(arg, 'i') && !ft_strchr(arg, 'u') &&
		!ft_strchr(arg, 'P') && !ft_strchr(arg, 'v'))
	{
		write(1, "env: illegal option\n", 20);
		write(1, "usage: env [-iv] [-P utilpath] [-u name]\n", 41);
		write(1, "           [name=value ...] [utility [argument ...]]\n", 53);
		return (1);
	}
	return (0);
}

void	print_u(char *name, t_env_flag *flag, char **env)
{
	if (flag->v)
		ft_printf("#env unset:     %s\n", name);
	if (env)
		unset_env(name, &env);
}

int		check_flag(char **cmd, t_env_flag *flag, char ***env, int i)
{
	int len;

	while (cmd[i] && cmd[i][0] == '-')
	{
		len = ft_strlen(cmd[i]) - 1;
		if (is_illegal(cmd[i]))
			return (0);
		set_vi(cmd[i], flag, env);
		if (cmd[i][len] == 'u' && cmd[i + 1])
		{
			print_u(cmd[i + 1], flag, *env);
			i++;
		}
		if (cmd[i][len] == 'P' && cmd[i + 1] && !flag->altpath[0])
		{
			ft_strcpy(flag->altpath, cmd[i + 1]);
			flag->altpath[ft_strlen(cmd[i + 1])] = '/';
			i++;
		}
		i++;
	}
	return (i);
}
