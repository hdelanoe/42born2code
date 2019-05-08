/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(std::string const &type) : AMateria(type)
{
	return ;	
}

Cure::Cure(Cure const & src)
{
	*this = src;
	
}

Cure::~Cure(void)
{
	return ;
}


Cure & Cure::operator=(Cure const & rhs)
{
	if (this != &rhs) {
		_type = rhs.getType();
		_XP = rhs.getXP();

	}
	return *this;
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds*" << std::endl;
}

AMateria* 	Cure::clone() const
{
	return new Cure(*this);
}
