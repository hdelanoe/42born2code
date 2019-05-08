/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:39:49 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 15:39:50 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name, std::string const &target) : Form(name, target, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(Form const & src) :
												 Form(src.getName(), src.getTarget(), src.getSignGrade(), src.getExecutGrade()) { *this = src; }
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(Form const & rhs)
{
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

void				ShrubberyCreationForm::action() const
{
	std::ofstream f(_target + "_shrubbery");

	f << "\n";
	f << "               ,@@@@@@@,\n";
	f << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	f << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	f << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	f << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	f << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	f << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	f << "       |o|        | |         | |\n";
	f << "       |.|        | |         | |\n";
	f << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_\n";

	f.close();
	return;
}


