/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{	
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
	*this = src;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return ;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_apCost = rhs.getAPCost();
		this->_damage = rhs.getDamage();

	}
	return *this;
}

void		PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
