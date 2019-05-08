/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:43:13 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:53:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <math.h>
#include "Light.hpp"

Light::Light(void)
{
	std::string arr[3] = {".", "*", "_"};
	_type = "light";
	_x = COLS -1;
	_y = rand() % LINES - 4;
	_speed = 4 + round(rand() % 4);
	_vX = -1;
	_sprite = arr[rand() % 3];
	_h = 1;
	_w = 1;
	_color = COLOR_WHITE;

}

Light::Light(Light const &iRef) { *this = iRef; }
Light::~Light(void) {}

Light &Light::operator=(Light const &rhs)
{
	if (this != &rhs)
	{
		_sprite = rhs.getSprite();
		_x = rhs.getX();
		_y = rhs.getY();
		_w = rhs.getW();
		_h = rhs.getH();
		_speed = rhs.getSpeed();
	}
	return *this;
}
