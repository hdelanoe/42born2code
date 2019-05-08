/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:23 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:23 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid(void)
{
	_name = "BocalSteroid";
}

BocalSteroid::BocalSteroid(BocalSteroid const & src)
{
	*this = src;
}

BocalSteroid::~BocalSteroid(void)
{
	return ;
}

BocalSteroid & BocalSteroid::operator=(BocalSteroid const & rhs)
{
	if (this != &rhs)
		_name = rhs.getName();
	return *this;
}

std::string BocalSteroid::beMined(DeepCoreMiner*) const
{
	return "Zazium";
}

std::string BocalSteroid::beMined(StripMiner*) const
{
	return "Krpite";
}

std::string BocalSteroid::getName() const
{
	return _name;
}