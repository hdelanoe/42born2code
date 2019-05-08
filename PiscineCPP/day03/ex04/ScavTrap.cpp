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

ScavTrap::ScavTrap(std::string const name) : ClapTrap(100, 100, 50, 50, 1, name, 20, 13, 3)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "This time it'll be awesome, I promise!" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << " I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}


void	ScavTrap::rangedAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "Da, da da da! It's electric!" << "FR4G-TP " << this->_Name << " shocks " << target << ", causing " << this->_RangedAttackDamage << " points of electric damage !" << std::endl;
	else if (type == 1)
		std::cout << "Ice to meet you." << "FR4G-TP " << this->_Name << " throws a big ice lance on " << target << " and inflict " << this->_RangedAttackDamage << " points of ice damage !" << std::endl;
	else if (type == 2)
		std::cout << "FR4G-TP " << this->_Name << " farts a huge  rainbows, causing " << this->_RangedAttackDamage << " points of wonderful damage to " << target << " !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target, int type) const
{
	if (type == 0)
		std::cout << "FR4G-TP " << this->_Name << " use his \"Hyperiooooon Punch!\" secret technic on the face of" << target << ", causing " << this->_MeleeAttackDamage << " points of damage !" << std::endl;
	else if (type == 1)
		std::cout << "One, two... PUNCH!" << "FR4G-TP " << this->_Name << " is in a 3X COMBO and inflict " << this->_MeleeAttackDamage << " points of  damage to " << target << " !" << std::endl;
	else if (type == 2)
		std::cout << "Things are exploded and... stuff. " << target << " as well." << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	if (this->_EnergyPoints < 25) {
		std::cout << "I'mmmmm do tiiiiiiireeeed....." << std::endl;
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