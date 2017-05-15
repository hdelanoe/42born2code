/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:35:27 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/13 12:12:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned long	i;
	unsigned long	dlen;

	dlen = 0;
	while (dest[dlen] != '\0')
		dlen++;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dest);
}
