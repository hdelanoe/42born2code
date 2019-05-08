/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:25:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 18:25:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "Booting sequence complete." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	std::cout << "Hello! I am your new steward bot." << std::endl;
	*this = src;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NOOOOOOOOOOOO!!!!" << std::endl;
}


void	NinjaTrap::rangedAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "RUN FOR YOUR LIIIIIVES!!!" << "FR4G-TP " << this->_Name << " atomize " << target << " until he disappear." << std::endl;
	else if (type == 1)
		std::cout << "Step right up, to the Bulletnator 9000! " << "FR4G-TP " << this->_Name << " sprays a volley of bullets on " << target << ", causing " << this->_RangedAttackDamage << " points of damage !" << std::endl;
	else if (type == 2)
		std::cout << "Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "In yo' FACE!" << std::endl;
	else if (type == 1)
		std::cout  << "FR4G-TP " << this->_Name << " unleash his fury on " << target << " until he's down. Coffee? Black... like my soul." << std::endl;
	else if (type == 2)
		std::cout << "Ready for the PUNCHline " << target << " ?!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap*)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "Huuumm... Not this time !" << std::endl;
	}
	else {
		this->_EnergyPoints -= 25;
		std:: cout << "A ClapTrap ? Are... are you my father?" << std::endl;
		std:: cout << "Are you god? Am I dead?" << std::endl;
		std:: cout << " I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
	}
	return ;
}

void	NinjaTrap::ninjaShoebox(ScavTrap* trap)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "Huuumm... Not this time !" << std::endl;
	}
	else {
		this->_EnergyPoints -= 25;
		std::cout << trap->getName() << ": Knock Knock." << std::endl;
		std::cout << this->_Name << ": Who's there?" << std::endl;
		std::cout << trap->getName() << "Wub." << std::endl;
		std::cout << this->_Name << ": Wub who?" << std::endl;
		std::cout << trap->getName() << "Wubwubwubwubwub." << std::endl;
	}
	return ;
}

void	NinjaTrap::ninjaShoebox(FragTrap*)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "Huuumm... Not this time !" << std::endl;
	}
	else {
		this->_EnergyPoints -= 25;
		std::cout << "Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!" << std::endl;
	}
	return ;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap* trap)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "Huuumm... Not this time !" << std::endl;
	}
	else {
		this->_EnergyPoints -= 25;
		std::cout << this->_Name << ": You wanna fight with me?! Put 'em up! ... Put 'em up?" << std::endl;
		std::cout << trap->getName() << ": Now? But I... I just... okay..." << std::endl;
		std::cout << this->_Name << ": You versus me! Me versus you! Either way!" << std::endl;
		std::cout << "* FR4G-TP " << trap->getName() << " intimidate " << this->_Name << " with his big [...] *" << std::endl;
		std::cout << "... " << std::endl;
		std::cout << this->_Name << ": Who's a badass robot? This guy!" << std::endl;
	}
	return ;
}

