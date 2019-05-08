/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:05:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 18:05:13 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name) : _HitPoints(100), _MaxHitPoints(100), _EnergyPoints(100), _MaxEnergyPoints(100),
							_Level(1) ,_Name(name), _MeleeAttackDamage(30), _RangedAttackDamage(20), _ArmorDamageReduction(5) {

	std::cout << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {

	std::cout << "Recompiling my combat code!" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "No fair! I wasn't ready." << std::endl;
}


ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints + amount > this->_MaxHitPoints)
		amount = this->_MaxHitPoints - this->_HitPoints;
	this->_HitPoints += amount;
	std::cout << "FR4G-TP " << this->_Name << " repairing for " << amount << " points of damage !" << std::endl;
}

unsigned int 	ClapTrap::getHitPoints(void) const 
{
	return this->_HitPoints;
}

unsigned int 	ClapTrap::getMaxHitPoints(void) const
{
	return this->_MaxHitPoints;
}

unsigned int 	ClapTrap::getEnergyPoints(void) const
{
	return this->_EnergyPoints;
}

unsigned int 	ClapTrap::getMaxEnergyPoints(void) const
{
	return this->_MaxEnergyPoints;
}

unsigned int 	ClapTrap::getLevel(void) const
{
	return this->_Level;
}

std::string 	ClapTrap::getName(void) const
{
	return this->_Name;
}

unsigned int 	ClapTrap::getMeleeAttackDamage(void) const
{
	return this->_MeleeAttackDamage;
}

unsigned int 	ClapTrap::getRangedAttackDamage(void) const
{
	return this->_RangedAttackDamage;
}

unsigned int 	ClapTrap::getArmorDamageReduction(void) const
{
	return this->_ArmorDamageReduction;
}