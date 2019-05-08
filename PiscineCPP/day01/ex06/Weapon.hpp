/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:07:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 21:07:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
#include <sstream>
#include <ios>

class Weapon
{
public:

	Weapon(std::string type);
	~Weapon(void);
	const std::string	getType() const;
	void				setType(std::string type);

private:
	
	std::string	_type;
};

#endif
