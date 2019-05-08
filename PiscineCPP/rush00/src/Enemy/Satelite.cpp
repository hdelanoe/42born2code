/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Satelite.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:51:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:51:22 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <math.h>
#include "AEnemy.hpp"
#include "Satelite.hpp"
#include "Missile.hpp"

Satelite::Satelite(void) {}
Satelite::Satelite(Satelite const &iRef) { *this = iRef; }
Satelite::~Satelite(void) {}

Satelite	& Satelite::operator =(Satelite const & rhs)
{
	if (this != &rhs) {
		_sprite = rhs.getSprite();
		_x = rhs.getX();
		_y = rhs.getY();
		_w = rhs.getW();
		_h = rhs.getH();
		_speed = rhs.getSpeed();
	}
	return *this;
}

Satelite::Satelite(int const &iPosX, int const &iPosY) :
AEnemy(iPosX, iPosY, SATELITE_W, SATELITE_H, SATELITE_S, SATELITE_T, SATELITE_HP, SATELITE_SV, SATELITE_SPD) 
{
	_vX = -2;
	_vY = -1;
	_rd = 1 + (rand() % 4);
}

AEnemy *Satelite::shoot(void) const { return new Missile(_x - 1, _y - 1); }


void	Satelite::pattern(void)
{
	if (_x < COLS / _rd)
		_pattern = true;
	if ((clock() - _timer) > 2500000)
	{
			_vY *= -1;
			_y += _speed * _vY;
			_timer = clock();

	}
	if (_pattern == true && (clock() - _timer2) > 350000)
	{
			_vX *= -1;
			_timer2 = clock();
	}
}