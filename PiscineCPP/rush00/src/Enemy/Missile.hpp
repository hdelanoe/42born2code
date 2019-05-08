/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 01:56:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:37 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "AEnemy.hpp"

class Missile : public AEnemy
{
  private:
	Missile(void);

  public:
	Missile(Missile const &iRef);
	~Missile(void);

	Missile &operator=(Missile const &iRef);

	Missile(int const &iPosX, int const &iPosY);

	virtual void	pattern(void);
};

#endif
