/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:09 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:10 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"


SuperMutant::SuperMutant(int hp, std::string const & type) : Enemy(hp, type)
{	
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const & src)
{
	*this = src;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
	if (this != &rhs) {
		this->_HP = rhs.getHP();
		this->_type = rhs.getType();

	}
	return *this;
}

void 			SuperMutant::takeDamage(int damage)
{
	this->_HP -= (damage -3);
}
