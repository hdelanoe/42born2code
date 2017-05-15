/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:38:23 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 15:40:44 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putendl_fd("File error.", 2);
	if (i == 2)
		ft_putendl_fd("Malloc error.", 2);
	if (i == 3)
		ft_putendl_fd("Read error.", 2);
	exit(1);
}
