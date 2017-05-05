/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:23:30 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/10 15:36:25 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_arg(char *s, char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i] != '\0')
		i++;
	i--;
	while (i > 1)
	{
		j = 0;
		while (j <= i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				s = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = s;
			}
			j++;
		}
		i--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*s;

	i = 1;
	s = NULL;
	ft_sort_arg(s, argv);
	while (argv[i] != '\0' && argc >= 1)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
