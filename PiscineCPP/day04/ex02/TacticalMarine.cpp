/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	*this = src;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs)
{
	(void)rhs;
	return *this;
}

ISpaceMarine*		TacticalMarine::clone() const
{
	return new TacticalMarine(*this);
}

void	TacticalMarine::battleCry() const
{
	std::cout << "For the Holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with the chainsword *" << std::endl;
}