/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sentinel.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:26:53 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SENTINEL_HPP
#define SENTINEL_HPP

#include <string>
#include "../AGameEntity.hpp"
#include "AEnemy.hpp"

class Sentinel : public AEnemy
{
  private:
		Sentinel(void);
		virtual void		pattern(void);

  public:
	Sentinel(Sentinel const &iRef);
	~Sentinel(void);

	Sentinel &operator=(Sentinel const &iRef);

	Sentinel(int const &iPosX, int const &iPosY);

	AEnemy *shoot(void);
};

#endif
