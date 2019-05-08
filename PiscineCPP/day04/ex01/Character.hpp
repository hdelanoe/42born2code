/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:32 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:33 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {

	public:

		Character();
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);

		Character &	operator=(Character const & rhs);

		void			recoverAP();
		void			equip(AWeapon*);
		void			attack(Enemy*);

		std::string	getName() const;
		AWeapon *	getWeapon() const;
		int			getAP() const;

	private:

		std::string	_name;
		int			_AP;
		AWeapon *	_weapon;

};

std::ostream &	operator<<(std::ostream & o, Character const & rhs);

#endif
