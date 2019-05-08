/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:40:21 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:40:24 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

	public:

		RobotomyRequestForm(std::string const &name = "Roboto my request", std::string const &target = "Notarget");
		RobotomyRequestForm(Form const & src);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &	operator=(Form const & rhs);

		virtual void				action() const;


};

#endif
