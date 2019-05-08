/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:02 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 15:24:06 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Noname"), _signGrade(150), _executGrade(150), _signed(false) {}
Form::Form(Form const & src) : _signGrade(src.getSignGrade()), _executGrade(src.getExecutGrade()) { *this = src; }
Form::~Form(void) {}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned();
	return *this;
}

Form::Form(std::string const &name, int const &signGrade, int const &executGrade) :
						_name(name), _signGrade(signGrade), _executGrade(executGrade), _signed(false)
{
	if (signGrade < 1 || executGrade < 1) throw Form::GradeTooHighException();
	if (signGrade > 150 || executGrade > 150) throw GradeTooLowException();
}

std::string const 	Form::getName() const			{ return _name; }
int 				Form::getSignGrade() const 		{ return _signGrade; }
int 				Form::getExecutGrade() const 	{ return _executGrade; }
bool			 	Form::getSigned() const			{ return _signed; }


void				Form::beSigned(Bureaucrat const & signer)
{
	if (signer.getGrade() > _signGrade) throw Form::GradeTooLowException();
	_signed = true;
}

void				Form::execute(Bureaucrat const & executor)
{
	if (!_signed) throw FormNotSignedException();
	if (executor.getGrade() > _executGrade) throw Form::GradeTooLowException();
	std::cout << executor.getName() << " (grade " << executor.getGrade() << ") executes " << _name << std::endl;
}

std::ostream &operator<<(std::ostream & o, Form const *b)
{
	if (b)
		o << "Form " << b->getName() << ":" << std::endl <<
				"signedGrade : " << b->getSignGrade() << std::endl <<
		  		"executGrade : " << b->getExecutGrade() << std::endl <<
		  		"signed: " << b->getSigned() << std::endl;
	else
		o << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw() 	{ return ("grade is too high."); }
const char* Form::GradeTooLowException::what() const throw() 	{ return ("grade is too low."); }
const char* Form::FormNotSignedException::what() const throw() 	{ return ("form is not signed."); }



