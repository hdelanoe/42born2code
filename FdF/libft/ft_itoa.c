/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:54:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/16 14:46:17 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoalen(int n)
{
	int tmp;
	int i;

	tmp = n;
	i = 1;
	while (tmp / 10 > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

static int	ft_isneg(int n)
{
	int	neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	return (neg);
}

static char	*ft_inititoa(int n)
{
	char *str;

	str = (char*)malloc(sizeof(char) *
			(ft_itoalen(n) + 2));
	if (str == NULL)
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;
	long	nb;

	neg = ft_isneg(n);
	nb = (long)n * neg;
	if (!(str = ft_inititoa(n)))
		return (NULL);
	i = 0;
	while (nb / 10 != 0)
	{
		str[i] = (nb % 10 + '0');
		nb = nb / 10;
		i++;
	}
	str[i] = nb % 10 + '0';
	i++;
	if (neg == -1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
