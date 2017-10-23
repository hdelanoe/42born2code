/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:42:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 14:02:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag2(t_env_ls *e, char letter)
{
	if (letter == 'a')
		e->flag[0]++;
	else if (letter == 'r')
		e->flag[1]++;
	else if (letter == 'R')
		e->flag[2]++;
	else if (letter == 'g')
		e->flag[6]++;
	else if (letter == 'd')
		e->flag[7]++;
	else if (letter == 'o')
		e->flag[8]++;
	else if (letter == 'n')
		e->flag[10]++;
	else if (letter == 'G')
		e->flag[11]++;
	else if (letter == 'h')
		e->flag[12]++;
	else
		ft_illegal();
}

void	flag(t_env_ls *e, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'l' || arg[i] == 'g' ||
				arg[i] == 'o' || arg[i] == 'n')
			e->last_format = 3;
		if (arg[i] == 'x')
			e->last_format = 5;
		if (arg[i] == 't')
			e->last_sort = 4;
		if (arg[i] == 'S')
			e->last_sort = 9;
		flag2(e, arg[i]);
		i++;
	}
}

int		ft_flag(t_env_ls *e, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_strcmp(argv[i], "--help") == 0)
		ft_help();
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2])
			ft_illegal();
		flag(e, argv[i]);
		i++;
	}
	return (i);
}
