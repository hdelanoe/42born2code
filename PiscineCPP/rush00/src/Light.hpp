/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:43:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:53:26 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "AGameEntity.hpp"

class Light : public AGameEntity
{
  public:
	Light(void);
	Light(Light const &iRef);
	~Light(void);

	Light &operator=(Light const &iRef);
};

#endif
