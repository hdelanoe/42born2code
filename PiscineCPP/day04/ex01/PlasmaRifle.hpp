/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:13 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:15 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"
# include <string>

class PlasmaRifle : public AWeapon {

	public:

		PlasmaRifle(std::string const & name = "Plasma Rifle", int apcost = 5, int damage = 21);
		PlasmaRifle(PlasmaRifle const & src);
		~PlasmaRifle(void);

		PlasmaRifle & operator=(PlasmaRifle const & rhs);


		virtual void		attack() const;	

};

#endif
