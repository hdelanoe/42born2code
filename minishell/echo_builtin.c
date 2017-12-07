/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:50:54 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/09 11:59:12 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		is_slash(char c)
{
	if (c == 'n' || c == 'v' || c == 'f')
		return (1);
	if (c == '\\')
		return (2);
	if (c == 't')
		return (3);
	return (0);
}

void	echo_out(char *str, int len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i <= len)
	{
		if (str[i] == '\\' && is_slash(str[i + 1]))
		{
			ft_putnstr(&str[j], i - j);
			if (is_slash(str[i + 1]) == 1)
				write(1, "\n", 1);
			if (is_slash(str[i + 1]) == 2)
				write(1, "\\", 1);
			if (is_slash(str[i + 1]) == 3)
				write(1, "\t", 1);
			i++;
			j = i + 1;
		}
	}
	ft_putnstr(&str[j], i - j - 1);
}

void	check_quote(char buf[BUF_SIZ], int i, int j)
{
	char tmp;

	while (buf[++i])
	{
		if (buf[i] == '\'' || buf[i] == '\"')
		{
			tmp = buf[i];
			buf[i] = '\0';
			echo_out(&buf[j], i - j);
			buf[i] = tmp;
			j = i;
			i++;
			while (buf[i] && buf[j] != buf[i])
				i++;
			tmp = buf[i];
			buf[i] = '\0';
			echo_out(&buf[j + 1], i - j);
			buf[i] = tmp;
			j = i + 1;
		}
	}
	echo_out(&buf[j], i - j);
}

void	echo_builtin(char **args)
{
	int		i;
	int		n_flag;
	char	buf[BUF_SIZ];

	ft_bzero(buf, BUF_SIZ);
	n_flag = 0;
	if (ft_strcmp(args[0], "-n") == 0)
		n_flag = 1;
	i = n_flag - 1;
	while (args[++i])
	{
		ft_strcat(buf, args[i]);
		if (args[i + 1])
			ft_strcat(buf, " ");
	}
	check_quote(buf, -1, 0);
	if (!n_flag)
		write(1, "\n", 1);
}
