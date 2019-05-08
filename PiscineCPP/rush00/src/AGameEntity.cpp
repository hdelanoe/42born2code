/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:35:15 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:59:00 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "AGameEntity.hpp"
#include "Enemy/AEnemy.hpp"

AGameEntity::AGameEntity(void) {}
AGameEntity::AGameEntity(AGameEntity const &iRef) { *this = iRef; }
AGameEntity::~AGameEntity(void) {}

AGameEntity &AGameEntity::operator=(AGameEntity const &iRef)
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
		_speed = iRef.getSpeed();
	}
	return *this;
}

AGameEntity::AGameEntity(int const &iPosX,
						 int const &iPosY,
						 int const &iWidth,
						 int const &iHeight,
						 int const &iVectX,
						 int const &iVectY)
	: _x(iPosX), _y(iPosY), _w(iWidth), _h(iHeight), _vX(iVectX), _vY(iVectY) {}

AGameEntity::AGameEntity(int const &iPosX,
						 int const &iPosY,
						 int const &iWidth,
						 int const &iHeight,
						 int const &iVectX,
						 int const &iVectY,
						 std::string const &iSprite,
						 int const &iSpeed)
	: _sprite(iSprite), _x(iPosX), _y(iPosY), _w(iWidth), _h(iHeight), _vX(iVectX), _vY(iVectY), _speed(iSpeed) {}

std::string AGameEntity::getSprite(void) const { return _sprite; }
std::string AGameEntity::getType(void) const { return _type; }
int AGameEntity::getX(void) const { return _x; }
int AGameEntity::getY(void) const { return _y; }
int AGameEntity::getW(void) const { return _w; }
int AGameEntity::getH(void) const { return _h; }
int AGameEntity::getVX(void) const { return _vX; }
int AGameEntity::getVY(void) const { return _vY; }
int AGameEntity::getSpeed(void) const { return _speed; }
int AGameEntity::getHP(void) const { return _hitPoints; }
int AGameEntity::getColor(void) const { return _color; }


void AGameEntity::setX(int const &iVal) { _x = iVal; }
void AGameEntity::setY(int const &iVal) { _y = iVal; }
void AGameEntity::setPos(int const &iPosX, int const &iPosY)
{
	_x = iPosX;
	_y = iPosY;
}
void AGameEntity::setVY(int const &iVal) { _vY = iVal; }
void AGameEntity::setSprite(std::string const &iVal) { _sprite = iVal; }
void AGameEntity::setW(int const &iVal) { _w = iVal; }
void AGameEntity::setH(int const &iVal) { _h = iVal; }

bool AGameEntity::isAlive(void) const { return _hitPoints > 0 ? true : false; }
int AGameEntity::checkEntities(AGameEntity **arr, int nb)
{
	for (int i = 0; i < nb - 1; i++)
	{
		if (checkHitBox(arr[i]))
			return i;
	}
	return -1;
}

int AGameEntity::checkEntities(AEnemy **arr, int nb)
{
	for (int i = 0; i < nb - 1; i++)
	{
		if (checkHitBox(dynamic_cast<AGameEntity *>(arr[i])))
			return i;
	}
	return -1;
}

AGameEntity *AGameEntity::shoot(void) const { return nullptr; }

bool AGameEntity::checkHitBox(AGameEntity const *iRef) const
{
	int l1[2] = {this->_x, this->_y};
	int r1[2] = {this->_x + this->_w  -1 + this->_speed * abs(this->_vX), this->_y + this->_h - 1 + this->_speed * abs(this->_vY)};

	int l2[2] = {iRef->getX(), iRef->getY()};
	int r2[2] = {iRef->getX() + iRef->getW() - 1 + iRef->getSpeed() * abs(iRef->getVX()), iRef->getY() + iRef->getH() - 1 + iRef->getSpeed() * abs(iRef->getVY())};

	
	if (l1[0] > r2[0] || l2[0] > r1[0])
		return false;
	if (l1[1] > r2[1] || l2[1] > r1[1])
		return false;

	return true;
}
