/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:37:34 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 18:56:08 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ltoalen(long l)
{
	int i;

	i = 1;
	while (l / 10 > 0)
	{
		l /= 10;
		i++;
	}
	return (i);
}

int			is_neg(long l)
{
	if (l < 0)
	{
		l = -l;
		return (1);
	}
	return (0);
}

char		*ft_ltoa(long l)
{
	char	*str;
	int		i;
	int		neg;

	neg = is_neg(l);
	i = neg;
	i += ltoalen(l);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (l / 10 > 0)
	{
		str[i] = (l % 10);
		l /= 10;
		i--;
	}
	str[i] = (l % 10);
	i--;
	if (neg == 1)
		str[i] = '-';
	return (str);
}
