/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:40:38 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:40:39 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &name, std::string const &target) : Form(name, target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(Form const & src) :
						Form(src.getName(), src.getTarget(), src.getSignGrade(), src.getExecutGrade()) { *this = src; }
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(Form const & rhs)
{
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

void				PresidentialPardonForm::action() const { std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl; }

