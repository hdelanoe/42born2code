/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:32:59 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/31 16:54:21 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"
#include "Drone.hpp"
#include "Missile.hpp"

Drone::Drone(void) {}
Drone::Drone(Drone const &iRef) { *this = iRef; }
Drone::~Drone(void) {}

Drone	& Drone::operator =(Drone const & rhs)
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

Drone::Drone(int const &iPosX, int const &iPosY)
	: AEnemy(iPosX, iPosY, DRONE_W, DRONE_H, DRONE_S, DRONE_T, DRONE_HP, DRONE_SV, DRONE_SPD) {}

AEnemy *Drone::shoot(void) const { return new Missile(_x - 1, _y); }

void	Drone::pattern(void)
{
	if (clock() - _timer > 1000000) {
			_vY *= -1;
			_timer = clock();
	}
}

