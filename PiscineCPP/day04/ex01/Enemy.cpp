/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:46 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:47 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	return ;	
}

Enemy::Enemy(int hp, std::string const & type) : _HP(hp), _type(type)
{
	return ;	
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs) {
		this->_HP = rhs.getHP();
		this->_type = rhs.getType();

	}
	return *this;
}

int			 	Enemy::getHP(void) const 
{
	return this->_HP;
}

std::string 	Enemy::getType(void) const 
{
	return this->_type;
}


void 			Enemy::takeDamage(int damage)
{
	this->_HP -= damage;
} 
