/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:07:10 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/30 16:22:53 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"
#include <ncurses.h>

AEnemy::AEnemy(void) {}
AEnemy::AEnemy(AEnemy const &iRef) { *this = iRef; }
AEnemy::~AEnemy(void) {}

AEnemy &AEnemy::operator=(AEnemy const &iRef)
{
	if (this != &iRef)
	{
		(AGameEntity) *this = (AGameEntity)iRef;
		this->_type = iRef._type;
		this->_status = iRef._status;
		this->_hitPoints = iRef._hitPoints;
		this->_scoreValue = iRef._scoreValue;
	}
	return *this;
}

AEnemy::AEnemy(int const &iPosX, int const &iPosY, int const &iWidth, int const &iHeight,
			std::string const &iSprite, std::string const &iType,
			int const &iHitPoints, int const &iScoreValue, int const &iSpeed):	AGameEntity(iPosX, iPosY, iWidth, iHeight, -1, -1, iSprite, iSpeed),
_type(iType), _status(true), _hitPoints(iHitPoints), _scoreValue(iScoreValue), _timer(clock()), _timer2(clock())
{
	_color = COLOR_YELLOW;
	_pattern = false;  
}

std::string AEnemy::getType(void) const { return this->_type; }
bool AEnemy::getStatus(void) const { return this->_status; }
int AEnemy::getHitPoints(void) const { return this->_hitPoints; }
int AEnemy::getScoreValue(void) const { return this->_scoreValue; }

void AEnemy::setType(std::string const &iVal) { this->_type = iVal; }
void AEnemy::setStatus(bool const &iVal) { this->_status = iVal; }
void AEnemy::setHitPoints(int const &iVal) { this->_hitPoints = iVal; }
void AEnemy::setScoreValue(int const &iVal) { this->_scoreValue = iVal; }
