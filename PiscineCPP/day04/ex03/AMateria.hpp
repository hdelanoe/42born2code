/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:24:54 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:24:55 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP


# include <string>
# include <iostream>

class ICharacter;

class AMateria
{
	public:

		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & rhs);

		std::string	const & getType() const;
		unsigned int		getXP() const;

		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target);	

	protected:

		std::string		_type;
		unsigned int	_XP;
};

#endif
