/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:47:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 18:47:49 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <stdexcept>
# include <iostream>
# include <string>

class Form;


class Intern {

	public:

		Intern(void);
		Intern(Intern const &rhs);
		~Intern(void);
		Intern &operator=(Intern const &rhs);

		Form*	makeForm(std::string const &formName, std::string const &formTarget);

		class UnknownFormNameException: public std::exception { virtual const char* what() const throw(); };


};

#endif
