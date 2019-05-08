/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:38 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:25:39 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"


Victim::Victim(std::string name) : _name(name)
{	
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}


Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Victim const & rhs)
{
	o << "I am " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

std::string 	Victim::getName(void) const 
{
	return this->_name;
}

void			Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

