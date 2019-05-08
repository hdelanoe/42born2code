/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:22:44 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:38 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRONE_HPP
#define DRONE_HPP

#include <string>
#include "../AGameEntity.hpp"
#include "AEnemy.hpp"

class Drone: public AEnemy
{
  private:
	Drone(void);

  public:
	Drone(Drone const &iRef);
	~Drone(void);
	virtual void		pattern(void);
		

	Drone &operator=(Drone const &iRef);

	Drone(int const &iPosX, int const &iPosY);

	AEnemy *shoot(void) const;
};

#endif
