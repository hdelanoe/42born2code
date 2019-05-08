/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:48:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LASER_HPP
#define LASER_HPP

#include "AProjectile.hpp"
#include "../AGameEntity.hpp"

class Laser : public AProjectile
{
  private:
	Laser(void);

  public:
	Laser(Laser const &iRef);
	~Laser(void);

	Laser &operator=(Laser const &iRef);

	Laser(int const &iPosX,
		  int const &iPosY,
		  int const &iWidth,
		  int const &iHeight,
		  int const &iVectX,
		  int const &iVectY);
};

#endif
