/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:47:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:51:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	memoryLeak()
{
	std::string	panthere = "String panthere";
	std::cout << panthere << std::endl;
}

int		main()
{
	memoryLeak();
	while(42);
	return (0);
}
