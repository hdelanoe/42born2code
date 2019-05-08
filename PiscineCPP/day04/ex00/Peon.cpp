/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:26:00 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"


Peon::Peon(std::string name) : Victim(name)
{	
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src)
{
	*this = src;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}


Peon & Peon::operator=(Peon const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
	}
	return *this;
}

void			Peon::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

