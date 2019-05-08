/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:39 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:40 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
	for (int i = 0; i < 4; i += 1)
    {
        _laser[i] = NULL;
    }
}

MiningBarge::MiningBarge(MiningBarge const & src)
{
	*this = src;
}

MiningBarge::~MiningBarge(void)
{
	return ;
}

MiningBarge & MiningBarge::operator=(MiningBarge const & rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < 4; i += 1)
        {
            _laser[i] = NULL;
            _laser[i] = rhs._laser[i];
        }
        _count = rhs._count;

	}
	return *this;
}

void MiningBarge::equip(IMiningLaser* laser)
{
	if (_count < 3)
	{
		_laser[_count] = laser;
		_count += 1;
	}
}

void MiningBarge::mine(IAsteroid* a) const
{
	for (int i = 0 ; i < _count ; i++)
		_laser[i]->mine(a);
}

int			MiningBarge::getCount(void) const
{
	return _count;
}
