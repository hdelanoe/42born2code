/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:56:59 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:00 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	return ;	
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apCost(apcost), _damage(damage)
{
	return ;	
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon(void)
{
	return ;
}


AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_apCost = rhs.getAPCost();
		this->_damage = rhs.getDamage();

	}
	return *this;
}


std::string 	AWeapon::getName(void) const 
{
	return this->_name;
}

int			 	AWeapon::getAPCost(void) const 
{
	return this->_apCost;
}

int			 	AWeapon::getDamage(void) const 
{
	return this->_damage;
}