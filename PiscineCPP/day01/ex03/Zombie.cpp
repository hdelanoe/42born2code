/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:52:59 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:53:37 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_type << " (" << this->_name << ")> " << "Braiiiiiiiinnnsss...." << std::endl; 
	return ;
}

void	Zombie::setType(std::string type)
{
	this->_type = type;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}
