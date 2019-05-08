/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:07 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal(void)
{
	_name = "AsteroBocal";
}

AsteroBocal::AsteroBocal(AsteroBocal const & src)
{
	*this = src;
}

AsteroBocal::~AsteroBocal(void)
{
	return ;
}

AsteroBocal & AsteroBocal::operator=(AsteroBocal const & rhs)
{
	if (this != &rhs)
		_name = rhs.getName();
	return *this;
}

std::string AsteroBocal::beMined(DeepCoreMiner*) const
{
	return "Thorite";
}

std::string AsteroBocal::beMined(StripMiner*) const
{
	return "Flavium";
}


std::string AsteroBocal::getName() const
{
	return _name;
}
