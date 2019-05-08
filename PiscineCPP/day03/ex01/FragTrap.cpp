/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:09:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 14:09:49 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _HitPoints(100), _MaxHitPoints(100), _EnergyPoints(100), _MaxEnergyPoints(100),
							_Level(1), _Name(name), _MeleeAttackDamage(30), _RangedAttackDamage(20), _ArmorDamageReduction(5) {

	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) {

	std::cout << "Recompiling my combat code!" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {

	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
	return ;	
}


FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void	FragTrap::rangedAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " at range, causing " << this->_RangedAttackDamage << " points of damage !" << std::endl;
	else if (type == 1)
		std::cout << "FR4G-TP " << this->_Name << " fire on " << target << " with his Skatergun SMG, causing " << this->_RangedAttackDamage << " points of explosive damage !" << std::endl;
	else if (type == 2)
		std::cout << "FR4G-TP " << this->_Name << " throws a rocket on " << target << " with his Redemption, causing " << this->_RangedAttackDamage << " points of splash damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "FR4G-TP " << this->_Name << " punch " << target << " on the face, causing " << this->_MeleeAttackDamage << " points of damage !" << std::endl;
	else if (type == 1)
		std::cout << "FR4G-TP " << this->_Name << " crush " << target << " while dancing, causing " << this->_MeleeAttackDamage << " points of shame damage !" << std::endl;
	else if (type == 2)
		std::cout << "FR4G-TP " << this->_Name << " bore " << target << " with the story of his life, causing " << this->_MeleeAttackDamage << " points of annoyance damage !" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	amount -= this->_ArmorDamageReduction;
	if (amount > this->_HitPoints)
		amount = this->_HitPoints;
	this->_HitPoints -= amount;
	if (this->_HitPoints == 0)
		std::cout << "FR4G-TP " << this->_Name << " take " << amount << " points of damage ! Robot down!" << std::endl;
	else
		std::cout << "FR4G-TP " << this->_Name << " take " << amount << " points of damage ! Ouch!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints + amount > this->_MaxHitPoints)
		amount = this->_MaxHitPoints - this->_HitPoints;
	this->_HitPoints += amount;
	std::cout << "FR4G-TP " << this->_Name << " repairing for " << amount << " points of damage !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "Need some ammo!" << std::endl;
		return ;
	}
	else {
		this->_EnergyPoints -= 25;
		int style = rand() % 2;
		int type = rand() % 3;
		void (FragTrap::*arr[2])(std::string const &, int type) const = {&FragTrap::meleeAttack, &FragTrap::rangedAttack};
		(this->*arr[style])(target, type);
	}
}

unsigned int 	FragTrap::getHitPoints(void) const 
{
	return this->_HitPoints;
}

unsigned int 	FragTrap::getMaxHitPoints(void) const
{
	return this->_MaxHitPoints;
}

unsigned int 	FragTrap::getEnergyPoints(void) const
{
	return this->_EnergyPoints;
}

unsigned int 	FragTrap::getMaxEnergyPoints(void) const
{
	return this->_MaxEnergyPoints;
}

unsigned int 	FragTrap::getLevel(void) const
{
	return this->_Level;
}

std::string 	FragTrap::getName(void) const
{
	return this->_Name;
}

unsigned int 	FragTrap::getMeleeAttackDamage(void) const
{
	return this->_MeleeAttackDamage;
}

unsigned int 	FragTrap::getRangedAttackDamage(void) const
{
	return this->_RangedAttackDamage;
}

unsigned int 	FragTrap::getArmorDamageReduction(void) const
{
	return this->_ArmorDamageReduction;
}
