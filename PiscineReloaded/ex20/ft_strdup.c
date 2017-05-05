/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:01:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/10 12:42:10 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	dup = (char*)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
