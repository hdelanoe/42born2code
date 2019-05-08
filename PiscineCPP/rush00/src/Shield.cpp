/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shield.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:11:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <math.h>
#include "Shield.hpp"

Shield::Shield(void)
{
	_h = 1;
	_w = 5;
	_x = COLS -1 - _w;
	_y =  2 + rand() % (LINES - 10);
	_speed = 1 ;
	_vX = -1;
	_vY = 0;
	_sprite = "(|||)";
	_type = "shield";
	_color = COLOR_BLUE;

}

Shield::Shield(Shield const &iRef) {*this = iRef;}
Shield::~Shield(void) {}

Shield	& Shield::operator =(Shield const & rhs)
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
