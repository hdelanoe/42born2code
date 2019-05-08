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

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name)
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
