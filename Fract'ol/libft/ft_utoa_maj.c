/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_maj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:00:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 17:30:35 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_u(unsigned long u, int base)
{
	int i;

	i = 1;
	while (u / base > 0)
	{
		u /= base;
		i++;
	}
	return (i);
}

static char	goa(unsigned long u)
{
	unsigned long	i;
	char			*str;

	str = "0123456789ABCDEF";
	i = 0;
	while (i < u)
		i++;
	return (str[i]);
}

char		*ft_utoa_maj(unsigned long u, int base)
{
	int		i;
	char	*str;

	i = count_u(u, base);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (u / base > 0)
	{
		str[i] = goa(u % base);
		u /= base;
		i--;
	}
	str[i] = goa(u % base);
	return (str);
}
