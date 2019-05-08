/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:48:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:47:37 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Laser.hpp"

Laser &Laser::operator=(Laser const &iRef)
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

Laser::~Laser(void) {}

Laser::Laser(int const &iPosX,
			 int const &iPosY,
			 int const &iWidth,
			 int const &iHeight,
			 int const &iVectX,
			 int const &iVectY)
	: AProjectile(iPosX, iPosY, iWidth, iHeight, iVectX, iVectY)
{
	_speed = 4;
	_color = COLOR_GREEN;
	_type = "laser";
	_sprite= "-";
}
