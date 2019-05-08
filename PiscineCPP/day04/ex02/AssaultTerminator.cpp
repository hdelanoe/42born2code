/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:31 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:32 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	(void)rhs;
	return *this;
}

ISpaceMarine*		AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void	AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void	AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
