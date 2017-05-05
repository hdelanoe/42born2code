/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:09:44 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/10 12:43:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	long	r;
	int		*tab;

	i = 0;
	r = (long)max - (long)min;
	if (r <= 0)
	{
		tab = NULL;
		return (0);
	}
	tab = (int*)malloc(sizeof(int) * r + 1);
	if (tab == NULL)
		return (0);
	while (i < r)
	{
		tab[i] = i + min;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
