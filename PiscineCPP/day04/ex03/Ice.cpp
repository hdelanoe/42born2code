/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:02 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:03 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice(std::string const &type) : AMateria(type)
{
	return ;	
}

Ice::Ice(Ice const & src)
{
	*this = src;
}

Ice::~Ice(void)
{
	return ;
}


Ice & Ice::operator=(Ice const & rhs)
{
	if (this != &rhs) {
		this->_type = rhs.getType();
		this->_XP = rhs.getXP();

	}
	return *this;
}

void		Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria* 	Ice::clone() const
{
	return new Ice(*this);
}
