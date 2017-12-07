/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lauch_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:01:33 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/22 23:46:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*check_ctrl(char **cmd)
{
	int y;

	y = 0;
	while (cmd[0][y] == 27)
	{
		y++;
		if (cmd[0][y] == 91)
			y += 2;
	}
	return (&cmd[0][y]);
}

void	call_exec(char **cmd, char ***env)
{
	int		i;
	pid_t	pid;
	char	*buff;

	i = -1;
	pid = fork();
	mini_signal(2);
	if (pid == 0)
	{
		buff = check_ctrl(cmd);
		i = execve(buff, cmd, (*env));
		if (i < 0)
		{
			ft_printf("%s: %s: %s\n", "minishell", "command not found", buff);
			exit(1);
		}
	}
	else
		wait(&pid);
}

void	lauch_command(char **cmd, char ***env)
{
	if (!cmd[0])
		return ;
	if (ft_strcmp(cmd[0], "echo") == 0)
		echo_builtin(&cmd[1]);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		cd_builtin(cmd, env);
	else if (!ft_strcmp(cmd[0], "setenv"))
		setenv_builtin(cmd, env);
	else if (!ft_strcmp(cmd[0], "unsetenv"))
		unsetenv_builtin(cmd, env);
	else if (!ft_strcmp(cmd[0], "env"))
		env_builtin(cmd, env);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		exit(1);
	else
		call_exec(cmd, env);
}
