/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:47:43 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 18:47:44 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {}
Intern::Intern(Intern const & rhs) { *this = rhs; }
Intern::~Intern(void) {}

Intern & Intern::operator=(Intern const & rhs) { (void)rhs; return *this; }

Form*	Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
	Form* form;

	if (formName == "shrubberycreation" || formName == "shrubbery creation")
		form =  new ShrubberyCreationForm(formName, formTarget);
	else if (formName == "robotomyrequest" || formName == "robotomy request")
		form = new RobotomyRequestForm(formName, formTarget);
	else if (formName == "presidentialpardon" || formName == "presidential pardon")
		form = new PresidentialPardonForm(formName, formTarget);
	else
		throw Intern::UnknownFormNameException();
	std::cout << "Intern creates " << form->getName() << " with " << form->getTarget() << " target." << std::endl;
	return form;
}

const char* Intern::UnknownFormNameException::what() const throw() 	{ return ("Unknown form name."); }
