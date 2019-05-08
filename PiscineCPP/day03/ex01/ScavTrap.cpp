/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:52:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 17:52:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _HitPoints(100), _MaxHitPoints(100), _EnergyPoints(50), _MaxEnergyPoints(50),
							_Level(1), _Name(name), _MeleeAttackDamage(20), _RangedAttackDamage(15), _ArmorDamageReduction(3) {

	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) {

	std::cout << "This time it'll be awesome, I promise!" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void) {

	std::cout << " I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
	return ;	
}


ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	
	if (this != &rhs) {
		this->_HitPoints = rhs.getHitPoints();
		this->_MaxHitPoints = rhs.getMaxHitPoints();
		this->_EnergyPoints = rhs.getEnergyPoints();
		this->_MaxEnergyPoints = rhs.getMaxEnergyPoints();
		this->_Level = rhs.getLevel();
		this->_Name = rhs.getName();
		this->_MeleeAttackDamage = rhs.getMeleeAttackDamage();
		this->_RangedAttackDamage = rhs.getRangedAttackDamage();
		this->_ArmorDamageReduction = rhs.getArmorDamageReduction();
		std::cout << "Holy crap, that worked?" << std::endl;
	}
	return *this;
}

void	ScavTrap::rangedAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "Da, da da da! It's electric!" << "FR4G-TP " << this->_Name << " shocks " << target << ", causing " << this->_RangedAttackDamage << " points of electric damage !" << std::endl;
	else if (type == 1)
		std::cout << "Ice to meet you." << "FR4G-TP " << this->_Name << " throws a big ice lance on " << target << " and inflict " << this->_RangedAttackDamage << " points of ice damage !" << std::endl;
	else
		std::cout << "FR4G-TP " << this->_Name << " farts a huge  rainbows, causing " << this->_RangedAttackDamage << " points of wonderful damage to " << target << " !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "FR4G-TP " << this->_Name << " use his \"Hyperiooooon Punch!\" secret technic on the face of" << target << ", causing " << this->_MeleeAttackDamage << " points of damage !" << std::endl;
	else if (type == 1)
		std::cout << "One, two... PUNCH!" << "FR4G-TP " << this->_Name << " is in a 3X COMBO and inflict " << this->_MeleeAttackDamage << " points of  damage to " << target << " !" << std::endl;
	else
		std::cout << "Things are exploded and... stuff. " << target << " as well." << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	amount -= this->_ArmorDamageReduction;
	if (amount > this->_HitPoints)
		amount = this->_HitPoints;
	this->_HitPoints -= amount;
	if (this->_HitPoints == 0)
		std::cout << "FR4G-TP " << this->_Name << " take " << amount << " points of damage ! Robot down!" << std::endl;
	else
		std::cout << "FR4G-TP " << this->_Name << " take " << amount << " points of damage ! Crap!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints + amount > this->_MaxHitPoints)
		amount = this->_MaxHitPoints - this->_HitPoints;
	this->_HitPoints += amount;
	std::cout << "FR4G-TP " << this->_Name << " repairing for " << amount << " points of damage ! Shield me, maiden!" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "I'mmmmm so tiiiiiiireeeed....." << std::endl;
		return ;
	}
	else {
		std:: cout << "Oh my gosh, a challenge!" << std::endl;
		this->_EnergyPoints -= 25;
		int style = rand() % 3;
		if (style == 0)
			std::cout <<  this->_Name << " wanna doooooo.... A dance battle! Or, you know... regular battle. Hope " << target << " is ok !" << std::endl;
		else if (style == 1)
			std::cout <<  "HEY! " << target << " ! You wanna fight with me?! Put 'em up! ... Put 'em up?" << std::endl;
		else
			std::cout <<  "Does " << this->_Name << " did a challenge? Yeah he did a challenge!" << std::endl;

	}
}

unsigned int 	ScavTrap::getHitPoints(void) const 
{
	return this->_HitPoints;
}

unsigned int 	ScavTrap::getMaxHitPoints(void) const
{
	return this->_MaxHitPoints;
}

unsigned int 	ScavTrap::getEnergyPoints(void) const
{
	return this->_EnergyPoints;
}

unsigned int 	ScavTrap::getMaxEnergyPoints(void) const
{
	return this->_MaxEnergyPoints;
}

unsigned int 	ScavTrap::getLevel(void) const
{
	return this->_Level;
}

std::string 	ScavTrap::getName(void) const
{
	return this->_Name;
}

unsigned int 	ScavTrap::getMeleeAttackDamage(void) const
{
	return this->_MeleeAttackDamage;
}

unsigned int 	ScavTrap::getRangedAttackDamage(void) const
{
	return this->_RangedAttackDamage;
}

unsigned int 	ScavTrap::getArmorDamageReduction(void) const
{
	return this->_ArmorDamageReduction;
}
