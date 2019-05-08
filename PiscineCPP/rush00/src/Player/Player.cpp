/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:11:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:54:55 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "AProjectile.hpp"
#include "Laser.hpp"
#include <ncurses.h>

Player::Player(void):
AGameEntity(PLAYER_START_X, PLAYER_START_Y, PLAYER_W, PLAYER_H, 1, 1, PLAYER_S, PLAYER_SPD)
{
	_hitPoints = PLAYER_HP;
	_shield = false;
	_color = COLOR_GREEN;
	_timer = clock();
	_cs = false;
	_up = false;
	_down = false;
	_right = false;
	_left = false;

}

Player::Player(Player const & src) {*this = src;}
Player::~Player(void) {}

Player &Player::operator=(Player const &iRef)
{
	if (this != &iRef)
	{
		_sprite = iRef.getSprite();
		_x = iRef.getX();
		_y = iRef.getY();
	}
	return *this;
}

AProjectile *Player::shoot(void) const { return new Laser(_x + 3, _y + 1, 1, 1, 1, 1); }

bool			Player::getShield(void) 		{ return  _shield; }
void			Player::setShield(bool shield)
{
	_shield = shield;
	_color = 9;
}

void			Player::checkShield()
{

	if (_cs && clock() - _timer > 4000000) {
		_shield = false;
		_timer = 0;
		_color = COLOR_GREEN;
		_cs = false;
	}
}

void			Player::setTimer(int clock)
{
	_timer = clock;
	_cs = true;
}


bool		Player::isHit(void)
{
	if (clock() - _timer < 4000000 && _shield)
		return false;
	if(_shield) {
		_shield = false;
		_color = COLOR_GREEN;
		return false;
	}
	else
		_hitPoints--;
	return true;
}

void	Player::Input(int const & iInput)
{
	if (iInput == 'i' && _down)
		_down = false;
	else if (iInput == 'i' && !_down)
		_up = true;
	if (iInput == 'k' && _up)
		_up = false;
	else if (iInput == 'k' && !_up)
		_down = true;
	if (iInput == 'j' && _right)
		_right = false;
	else if (iInput == 'j' && !_right)
		_left = true;
	if (iInput == 'l' && _left)
		_left = false;
	else if (iInput == 'l' && !_left)
		_right = true;

	/*{
		_up = true;
		_down = false;
	}

	if (iInput == 's')
	{
		_up = false;
		_down = true;
	}	

	if (iInput == 'a')
	{
		_left = true;
		_right = false;
	}

	if (iInput == 'd')
	{
		_left = false;
		_right = true;
	}*/
}

bool			Player::getUp(void) {return _up;}
bool			Player::getDown(void) {return _down;}
bool			Player::getLeft(void) {return _left;}
bool			Player::getRight(void) {return _right;}



		



