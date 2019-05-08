/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:36 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"
# include <string>

class PowerFist : public AWeapon {

	public:

		PowerFist(std::string const & name = "Power Fist", int apcost = 8, int damage = 50);
		PowerFist(PowerFist const & src);
		~PowerFist(void);

		PowerFist & operator=(PowerFist const & rhs);

		virtual void		attack() const;	

};

#endif
