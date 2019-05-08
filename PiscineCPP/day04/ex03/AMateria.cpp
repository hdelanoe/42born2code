/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:24:49 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:24:50 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	return ;	
}

AMateria::AMateria(std::string const &type) : _type(type), _XP(0)
{
	return ;	
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
	return ;
}


AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs) {
		_type = rhs.getType();
		_XP = rhs.getXP();

	}
	return *this;
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
	_XP += 10;
	return ;
}


std::string	const & AMateria::getType() const 
{
	return _type;
}

unsigned int		AMateria::getXP() const 
{
	return _XP;
}