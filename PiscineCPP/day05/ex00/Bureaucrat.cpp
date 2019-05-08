/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:47:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 15:12:52 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "Bureaucrat.hpp"
 
Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(150) {}
Bureaucrat::Bureaucrat(Bureaucrat const & rhs) { _grade = rhs.getGrade(); }
Bureaucrat::~Bureaucrat(void) {}
 
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	  if (this != &rhs) {
		      _grade = rhs.getGrade();
			    }
	    return *this;
}
 
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	  if (grade < 1) throw Bureaucrat::GradeTooHighException();
	    if (grade > 150) throw GradeTooLowException();
		  _grade = grade;
		    return ;
}
 
std::string const   Bureaucrat::getName() const    { return _name; }
int         Bureaucrat::getGrade() const   { return _grade; }
 
void Bureaucrat::upGrade()
{
	  if (_grade == 1) throw GradeTooHighException();
	    _grade--;
		 
}
 
void Bureaucrat::downGrade()
{
	  if (_grade == 150) throw GradeTooLowException();
	    _grade++;
		 
}
 
const char* Bureaucrat::GradeTooHighException::what() const throw()   { return ("Grade too high."); }
const char* Bureaucrat::GradeTooLowException::what() const throw()   { return ("Grade too low."); }
 
std::ostream &operator<<(std::ostream & o, Bureaucrat const *b)
{
	  if (b)
		      o << "Bureaucrat " << b->getName() << " is grade " << b->getGrade() << "." << std::endl;
	    return o;
}
