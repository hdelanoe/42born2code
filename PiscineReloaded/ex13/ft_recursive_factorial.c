/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:47:08 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/10 12:02:35 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int f;

	if (nb < 0 || nb > 12)
		f = 0;
	else if (nb == 0)
		f = 1;
	else
		f = nb * ft_recursive_factorial(nb - 1);
	return (f);
}
