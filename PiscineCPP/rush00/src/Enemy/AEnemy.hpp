/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:07:20 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/30 16:22:38 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAEnemy_HPP
#define AAEnemy_HPP

#include <string>
#include "../AGameEntity.hpp"

class AEnemy : public AGameEntity
{
  protected:
	AEnemy(void);
	std::string	_type;
	bool		_status;
	int			_hitPoints;
	int			_scoreValue;
	int 		_timer;
	int 		_timer2;
	bool		_pattern;


  public:
	AEnemy(AEnemy const &iRef);
	virtual ~AEnemy(void);
	AEnemy &operator=(AEnemy const &iRef);

	AEnemy(int const &iPosX,
		   int const &iPosY,
		   int const &iWidth,
		   int const &iHeight,
		   std::string const &iSprite,
		   std::string const &iType,
		   int const &iHitPoints,
		   int const &iScoreValue,
		   int const &iSpeed);

	std::string getType(void) const;
	bool getStatus(void) const;
	int getHitPoints(void) const;
	int getScoreValue(void) const;

	void setType(std::string const &iVal);
	void setStatus(bool const &iVal);
	void setHitPoints(int const &iVal);
	void setScoreValue(int const &iVal);
	virtual void		pattern(void) = 0;

};

#endif
