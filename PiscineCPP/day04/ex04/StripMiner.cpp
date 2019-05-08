/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:09:45 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:09:46 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"
#include "IAsteroid.hpp"
#include <iostream>

class IAsteroid;

StripMiner::StripMiner(void)
{
	return ;
}

StripMiner::StripMiner(StripMiner const & src)
{
	*this = src;
}

StripMiner::~StripMiner(void)
{
	return ;
}

StripMiner & StripMiner::operator=(StripMiner const & rhs)
{
	(void)rhs;
	return *this;
}

void StripMiner::mine(IAsteroid* a)
{
	std::cout << "* strip mining ... got " << a->beMined(this) << " *" << std::endl;
}

