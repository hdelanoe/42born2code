/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:29 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:25:30 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>


class Victim {

	public:

		Victim(std::string name = "Bolhos");
		Victim(Victim const & src);
		~Victim(void);

		Victim &	operator=(Victim const & rhs);

		std::string 	getName() const;
		virtual void	getPolymorphed() const;

	protected:

		std::string	_name;
};

std::ostream &	operator<<(std::ostream & o, Victim const & rhs);

#endif
