/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:40:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:40:18 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &name, std::string const &target) : Form(name, target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(Form const & src) :
						Form(src.getName(), src.getTarget(), src.getSignGrade(), src.getExecutGrade()) { *this = src; }
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(Form const & rhs)
{
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

void				RobotomyRequestForm::action() const
{
	system("afplay drilling_noises.wav ");
	srand(time(NULL));
	int _robotomize = rand() % 100;
	if (_robotomize >= 50)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Failure." << std::endl;
}

