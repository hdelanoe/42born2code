/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:25:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{	
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}


Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

void			Sorcerer::polymorph(Victim const & v) const
{
	v.getPolymorphed();
}


std::string 	Sorcerer::getName(void) const 
{
	return this->_name;
}

std::string 	Sorcerer::getTitle(void) const 
{
	return this->_title;
}
