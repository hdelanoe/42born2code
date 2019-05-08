/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:35:51 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 19:35:53 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "Form.hpp"

OfficeBlock::OfficeBlock(void) {}
OfficeBlock::~OfficeBlock(void) {}
OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor) :
_intern(&intern), _signer(&signer), _executor(&executor) {}

void	OfficeBlock::doBureaucracy(std::string const &formName, std::string const &formTarget)
{
	Form *form;
	try {
		if (!_intern) { throw InternException(); }
		form = _intern->makeForm(formName, formTarget);
	} catch (std::exception & e) { std::cout << e.what() << std::endl; throw BureaucracyException(); }
	try {
		if (!_signer) { throw SignerException(); }
		_signer->signForm(*form);
	} catch (std::exception & e) { std::cout << e.what() << std::endl; throw BureaucracyException(); }
	try {
		if (!_executor) { throw ExecutorException(); }
		_executor->executeForm(*form);
	} catch (std::exception & e) { std::cout << e.what() << std::endl; throw BureaucracyException(); }
	std:: cout << form;

}

void	OfficeBlock::setIntern(Intern* intern) 				{ _intern = intern; }
void	OfficeBlock::setSigner(Bureaucrat* signer) 			{ _signer = signer; }
void	OfficeBlock::setExecutor(Bureaucrat* executor) 		{ _executor = executor; }

Bureaucrat*	OfficeBlock::getSigner(void)	{  if (!_signer) return nullptr; return _signer; }
Bureaucrat*	OfficeBlock::getExecutor(void)	{ if (!_executor) return nullptr; return _executor; }


const char* OfficeBlock::InternException::what() const throw() { return ("Office doesn't have intern."); }
const char* OfficeBlock::SignerException::what() const throw() { return ("Bureaucracy doesn't have signer."); }
const char* OfficeBlock::ExecutorException::what() const throw() { return ("Bureaucracy doesn't have executor."); }
const char* OfficeBlock::BureaucracyException::what() const throw() { return ("Bureaucracy doesn't work very well."); }





