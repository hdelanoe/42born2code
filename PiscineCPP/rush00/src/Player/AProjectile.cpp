/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AProjectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:50:01 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/29 18:50:03 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AProjectile.hpp"

AProjectile::AProjectile(void) {}
AProjectile::AProjectile(AProjectile const &iRef) { *this = iRef; }
AProjectile::~AProjectile(void) {}

AProjectile &AProjectile::operator=(AProjectile const &iRef)
{
	if (this != &iRef)
	{
		_sprite = iRef.getSprite();
		_x = iRef.getX();
		_y = iRef.getY();
		_w = iRef.getW();
		_h = iRef.getH();
		_speed = getSpeed();
	}
	return *this;
}

AProjectile::AProjectile(int const &iPosX,
						 int const &iPosY,
						 int const &iWidth,
						 int const &iHeight,
						 int const &iVectX,
						 int const &iVecY)
	: AGameEntity(iPosX, iPosY, iWidth, iHeight, iVectX, iVecY) {}
