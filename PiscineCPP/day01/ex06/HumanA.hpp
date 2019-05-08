/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:07:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 21:07:50 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void attack(void) const;

private:

	const std::string	_name;
	Weapon				&_weapon;
};

#endif
