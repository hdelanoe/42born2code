/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:39:14 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 14:04:14 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(void)
{
	ft_printf("{R}Error in malloc{E}\n");
	exit(-1);
}

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_reverse_arg(t_env_ls *e, char **tab)
{
	int i;
	int len;

	if (e->flag[1] > 0)
	{
		i = 0;
		len = 0;
		while (tab[len])
			len++;
		len--;
		while (i < len)
		{
			ft_swap(&tab[i], &tab[len]);
			i++;
			len--;
		}
	}
}

int		print_block(int a, int i, int rest)
{
	char	*b;
	char	*res;

	if (!(res = ft_itoa(a)))
		exit(-1);
	b = "BKMGTP";
	if (i == 6)
		return (-1);
	if (a > 922)
		ft_printf("%*i.%i%c", 3, 1, 0, b[i + 1]);
	else if (ft_strlen(res) == 1 && i)
		ft_printf("%*i.%i%c", 3, a, rest, b[i]);
	else
	{
		if (rest > 5)
			a++;
		ft_printf("%*i%c", 5, a, b[i]);
	}
	free(res);
	return (0);
}

int		ft_block(t_env_ls *e, int a)
{
	int		i;
	int		rest;
	int		h;

	if (e->flag[12] == 0)
		return (-1);
	rest = 0;
	i = 0;
	while (a / 1024)
	{
		i++;
		rest = a % 1024;
		a /= 1024;
		h = rest % 102;
		rest /= 102;
		if (h >= 56)
			rest++;
		if (rest == 10)
		{
			a++;
			rest = 0;
		}
	}
	return (print_block(a, i, rest));
}
