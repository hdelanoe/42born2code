/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:27:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/22 11:42:11 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	exit_shell(int flag)
{
	if (flag == 1)
		write(1, "Error in memory allocation.\n", 28);
	if (flag == 2)
		write(1, "Error in processus creation.\n", 29);
	exit(1);
}

void	cmd_handle_int(int sign)
{
	char *buf;

	if (sign == SIGQUIT)
		signal(SIGINT, handle_int);
	if (sign == SIGTSTP)
	{
		write(1, "process suspended\n", 19);
		while (42)
		{
			if ((get_next_line(0, &buf) == 1))
			{
				kill(0, SIGCONT);
				free(buf);
				break ;
			}
		}
	}
}

void	handle_int(int sign)
{
	if (sign == SIGINT)
	{
		write(1, "\n", 1);
		display_prompt();
	}
	if (sign == SIGQUIT)
	{
		write(1, "\n", 1);
		exit(42);
	}
	signal(SIGINT, handle_int);
}

void	mini_signal(int i)
{
	if (i == 1)
	{
		signal(SIGINT, handle_int);
		signal(SIGQUIT, handle_int);
	}
	else if (i == 2)
	{
		signal(SIGINT, cmd_handle_int);
		signal(SIGTSTP, cmd_handle_int);
		signal(SIGQUIT, cmd_handle_int);
	}
}

int		parse_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") ||
		!ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "setenv") ||
		!ft_strcmp(cmd, "unsetenv") ||
		!ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}
