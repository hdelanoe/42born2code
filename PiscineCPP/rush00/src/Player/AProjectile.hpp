/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AProjectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:48:33 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/29 18:48:34 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APROJECTILE_HPP
#define APROJECTILE_HPP

#include "../AGameEntity.hpp"

class AProjectile : public AGameEntity
{
  protected:
	AProjectile(void);

  public:
	AProjectile(AProjectile const &iRef);
	virtual ~AProjectile(void);

	AProjectile &operator=(AProjectile const &iRef);

	AProjectile(int const &iPosX,
				int const &iPosY,
				int const &iWidth,
				int const &iHeight,
				int const &iVectX,
				int const &iVecY);
};

#endif
