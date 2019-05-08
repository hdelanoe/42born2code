/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Satelite.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:51:39 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SATELITE_HPP
#define SATELITE_HPP

#include <string>
#include "../AGameEntity.hpp"
#include "AEnemy.hpp"

class Satelite : public AEnemy
{
	private:
		Satelite(void);
		int		_rd;
	
	public:	
		Satelite(int const &iPosX, int const &iPosY);
		Satelite(Satelite const &iRef);
		~Satelite(void);
		
		Satelite	& operator =(Satelite const &iRef);

		AEnemy*				shoot(void) const;
		virtual void		pattern(void);
		


};

#endif
