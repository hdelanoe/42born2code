/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:28:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 17:10:11 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAME_ENTITY_HPP
#define AGAME_ENTITY_HPP

#include <string>
#include "ft_retro.hpp"

class AProjectile;
class AEnemy;

class AGameEntity
{
  protected:
	std::string _sprite;
	std::string _type;
	int _x;
	int _y;
	int _w;
	int _h;
	int _vX;
	int _vY;
	int _speed;
	int _hitPoints;
	int	_color;

  public:
	AGameEntity(void);
	AGameEntity(AGameEntity const &iRef);
	virtual ~AGameEntity(void);

	AGameEntity &operator=(AGameEntity const &rhs);

	AGameEntity(int const &iPosX,
				int const &iPosY,
				int const &iWidth,
				int const &iHeight,
				int const &iVectX,
				int const &iVectY);

	AGameEntity(int const &iPosX,
				int const &iPosY,
				int const &iWidth,
				int const &iHeight,
				int const &iVectX,
				int const &iVectY,
				std::string const &iSprite,
				int const &iSpeed);

	std::string getSprite(void) const;
	std::string getType(void) const;
	int getX(void) const;
	int getY(void) const;
	int getW(void) const;
	int getH(void) const;
	int getVX(void) const;
	int getVY(void) const;
	int getSpeed(void) const;
	int getHP(void) const;
	int getColor(void) const;


	void setPos(int const &iPosX, int const &iPosY);
	void setX(int const &iVal);
	void setY(int const &iVal);
	void setVY(int const &iVal);
	void setSprite(std::string const &iVal);
	void setW(int const &iVal);
	void setH(int const &iVal);

	AGameEntity *shoot(void) const;

	bool isAlive(void) const;

	bool checkHitBox(AGameEntity const *iRef) const;
	int checkEntities(AGameEntity **e, int nb);
	int checkEntities(AEnemy **e, int nb);
};

#endif
