/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:22 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:24 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {

	public:

		Cure(std::string const & type = "cure");
		Cure(Cure const & src);
		~Cure(void);

		Cure &	operator=(Cure const & rhs);

		virtual AMateria* 	clone() const;
		virtual void		use(ICharacter& target);	

};

#endif
