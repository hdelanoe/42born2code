/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:22:09 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 12:37:16 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	unset_env(char *name, char ***env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(name);
	while ((*env)[i] && (ft_strncmp((*env)[i], name, len)
				|| (*env)[i][len] != '='))
		i++;
	if ((*env)[i])
	{
		while ((*env)[i + 1])
		{
			ft_swap(&(*env)[i], &(*env)[i + 1]);
			i++;
		}
		ft_strdel(&(*env)[i]);
	}
}

void	unsetenv_builtin(char **cmd, char ***env)
{
	if (cmd[1])
	{
		if (cmd[2])
		{
			write(1, "unsetenv: too many arguments.\n", 30);
			write(1, "Usage: unsetenv [NAME]\n", 23);
			return ;
		}
		unset_env(cmd[1], env);
	}
	else
		write(1, "Usage: [NAME]\n", 14);
}
