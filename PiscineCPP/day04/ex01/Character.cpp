/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	return ;	
}

Character::Character(std::string const & name) : _name(name), _AP(40), _weapon(NULL)
{
	return ;	
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(void)
{
	return ;
}


Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_AP = rhs.getAP();
		this->_weapon = rhs.getWeapon();

	}
	return *this;
}

std::string 	Character::getName(void) const 
{
	return this->_name;
}

int			 	Character::getAP(void) const 
{
	return this->_AP;
}

AWeapon *		Character::getWeapon(void) const 
{
	return this->_weapon;
}

void 			Character::attack(Enemy* enemy)
{
	if (this->_weapon != NULL) {

		if (this->_AP - this->_weapon->getAPCost() < 0)
			std::cout << "No ammos !" << std::endl;
		else
		{
			this->_AP -= this->_weapon->getAPCost();
			std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl ; 
			this->_weapon->attack();

			enemy->takeDamage(this->_weapon->getDamage());
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
	else
		std::cout << "No gun !" << std::endl;

}

void 			Character::recoverAP()
{
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
}

void			Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}

std::ostream &	operator<<(std::ostream & o, Character const & rhs)
{
	if (rhs.getWeapon() != NULL)
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " and is unarmed" << std::endl;
	return o;
}
