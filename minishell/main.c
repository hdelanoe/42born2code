/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:55:28 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/22 23:44:58 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <term.h>

void	display_prompt(void)
{
	char	*pwd;
	char	*home_path;
	int		len;

	home_path = NULL;
	if (!(pwd = get_env("PWD=", g_env)) ||
			!(home_path = get_env("HOME=", g_env)))
	{
		ft_printf("{C}>-<(((('>{E} ");
		return ;
	}
	len = ft_strlen(home_path);
	if (ft_strstr(pwd, home_path))
		ft_printf("{G}~~~{~{{R}@{E} ~%s > ", &pwd[len]);
	else
		ft_printf("{M}(. Y .){E} %s > ", pwd);
}

void	init_env(char **environ)
{
	int i;

	if (!environ)
		return ;
	if (!(g_env = (char**)ft_memalloc(sizeof(char*) * (ENV_LEN + 1))))
		exit_shell(1);
	i = 0;
	while (environ[i])
	{
		if (!(g_env[i] = ft_strdup(environ[i])))
		{
			ft_freearr(&g_env);
			exit_shell(1);
		}
		i++;
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	*buf;
	char	**cmd;

	cmd = NULL;
	init_env(environ);
	print_computer(argv);
	while (42)
	{
		mini_signal(1);
		display_prompt();
		if ((get_next_line(0, &buf) == 1))
		{
			cmd = ft_strsplit(buf, ' ');
			check_multi(&cmd);
			ft_freearr(&cmd);
			free(buf);
		}
		else
		{
			write(1, "\n", 1);
			break ;
		}
	}
	(void)argc;
	return (0);
}
