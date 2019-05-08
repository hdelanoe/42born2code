/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:25 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"


RadScorpion::RadScorpion(int hp, std::string const & type) : Enemy(hp, type)
{	
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const & src)
{
	*this = src;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this != &rhs) {
		this->_HP = rhs.getHP();
		this->_type = rhs.getType();

	}
	return *this;
}

void 			RadScorpion::takeDamage(int damage)
{
	this->_HP -= (damage -3);
}
