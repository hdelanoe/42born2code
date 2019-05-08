/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:31 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:32 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"


PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
	return ;	
}

PowerFist::PowerFist(PowerFist const & src)
{
	*this = src;
}

PowerFist::~PowerFist(void)
{
	return ;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_apCost = rhs.getAPCost();
		this->_damage = rhs.getDamage();

	}
	return *this;
}

void		PowerFist::attack() const	
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
