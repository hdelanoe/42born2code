/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:40:44 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:40:46 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:

		PresidentialPardonForm(std::string const &name = "presidential pardon", std::string const &target = "Notarget");
		PresidentialPardonForm(Form const & src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm &	operator=(Form const & rhs);

		virtual void				action() const;


};

#endif
