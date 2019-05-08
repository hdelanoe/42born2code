/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:39:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:39:56 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

	public:

		ShrubberyCreationForm(std::string const &name = "Shrubbery creation", std::string const &target = "Notarget");
		ShrubberyCreationForm(Form const & src);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm &	operator=(Form const & rhs);

		virtual void				action() const;


};

#endif
