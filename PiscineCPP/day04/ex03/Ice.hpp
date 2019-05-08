/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:08 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:09 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

	public:

		Ice(std::string const & type = "ice");
		Ice(Ice const & src);
		~Ice(void);

		Ice &	operator=(Ice const & rhs);

		virtual AMateria* 	clone() const;
		virtual void		use(ICharacter& target);	


};

#endif
