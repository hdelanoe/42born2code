/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sentinel.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:26:59 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:51:35 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "AEnemy.hpp"
#include "Sentinel.hpp"
#include "Missile.hpp"

Sentinel::Sentinel(void) {}
Sentinel::Sentinel(Sentinel const &iRef) { *this = iRef; }
Sentinel::~Sentinel(void) {}

Sentinel	& Sentinel::operator =(Sentinel const & rhs)
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

Sentinel::Sentinel(int const &iPosX, int const &iPosY) :
AEnemy(iPosX, iPosY, SENTINEL_W, SENTINEL_H, SENTINEL_S, SENTINEL_T, SENTINEL_HP, SENTINEL_SV, SENTINEL_SPD){}

AEnemy*	Sentinel::shoot(void)
{
	if (clock() - _timer2 > 750000) {
		_timer2 = clock();
		return new Missile(_x -1, _y);
	}
	return nullptr;
}

void	Sentinel::pattern(void)
{
	if ( !_pattern && clock() - _timer > 1750000) {
			_vY *= -1;
			_timer = clock();
	}
	if (_x <COLS/ 2)
	{
		_pattern = true;
		_vX *= -1;
	}
}
