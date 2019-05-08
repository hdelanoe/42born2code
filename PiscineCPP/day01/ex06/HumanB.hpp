/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:07:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 21:07:56 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"


class HumanB
{
public:

	HumanB(std::string name);
	~HumanB(void);
	void	setWeapon(Weapon &weapon);
	void	attack(void) const;

private:

	const std::string	_name;
	Weapon				*_weapon;
};

#endif
