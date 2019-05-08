/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shield.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:11:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIELD_HPP
# define SHIELD_HPP

#include "AGameEntity.hpp"

class Shield: public AGameEntity
{
	
	public:	
		Shield(void);
		Shield(Shield const &iRef);
		~Shield(void);
		
		Shield	& operator =(Shield const &iRef);
};

#endif
