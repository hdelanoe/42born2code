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

FragTrap::FragTrap(std::string const name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5) {

	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {

	std::cout << "Recompiling my combat code!" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {

	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
	return ;	
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
