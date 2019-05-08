/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

	public:

		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);

		Character &	operator=(Character const & rhs);

		virtual	std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		int			getCount() const;

	protected:

		std::string	_name;
		int			_count;
		AMateria*	_materia[4];

};

#endif
