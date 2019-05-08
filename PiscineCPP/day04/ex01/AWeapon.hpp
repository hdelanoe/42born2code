/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:56:54 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:56:56 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>
# include <iostream>

class AWeapon {

	public:

		AWeapon(void);
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		~AWeapon(void);

		AWeapon &	operator=(AWeapon const & rhs);

		std::string	getName() const;
		int			getAPCost() const;
		int			getDamage() const;

		virtual void		attack() const = 0;	

	protected:

		std::string	_name;
		int			_apCost;
		int			_damage;

};

#endif
