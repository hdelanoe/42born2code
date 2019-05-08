/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:58:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 19:58:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : FragTrap(0), NinjaTrap(0, name) {
	std::cout << "Directive three: Dance! At the beginning!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & src) {

	std::cout << "Recompiling my combat code!" << std::endl;
	*this = src;
	return ;
}

SuperTrap::~SuperTrap(void) {

	std::cout << "Just death." << std::endl;
	return ;	
}

void	SuperTrap::rangedAttack(std::string const & target, int type) const
{
	return (FragTrap::rangedAttack(target, type));
}

void	SuperTrap::meleeAttack(std::string const & target, int type) const
{
	return (NinjaTrap::meleeAttack(target, type));
}

