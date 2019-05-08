/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 01:56:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:39:07 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"
#include "ncurses.h"

Missile::Missile(void) {}
Missile::Missile(Missile const &iRef) { *this = iRef; }
Missile::~Missile(void) {}

Missile &Missile::operator=(Missile const &iRef)
{
	if (this != &iRef)
	{
		_sprite = iRef.getSprite();
		_x = iRef.getX();
		_y = iRef.getY();
		_w = iRef.getW();
		_h = iRef.getH();
		_vX = iRef.getVX();
		_vY = iRef.getVY();
	}
	return *this;
}

Missile::Missile(int const &iPosX, int const &iPosY)
	: AEnemy(iPosX, iPosY, MISSILE_W, MISSILE_H, 
		MISSILE_S, MISSILE_T, MISSILE_HP, MISSILE_SV, MISSILE_SPD) { _vY = 0; _color = COLOR_RED; }

void	Missile::pattern(void){}
