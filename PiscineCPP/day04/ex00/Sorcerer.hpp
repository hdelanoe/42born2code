/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:25:13 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"



class Sorcerer {

	public:

		Sorcerer(std::string name = "Roger", std::string title = "sorcerer");
		Sorcerer(Sorcerer const & src);
		~Sorcerer(void);

		Sorcerer &	operator=(Sorcerer const & rhs);

		void			polymorph(Victim const & v) const;

		std::string 	getName() const;
		std::string 	getTitle() const;


	private:

		std::string	_name;
		std::string _title;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
