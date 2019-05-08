/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:47:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 15:27:38 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	Bureaucrat *president = new Bureaucrat("Zaphod", 1);
	Bureaucrat *secretary = new Bureaucrat("Diana", 25);

//	Form *form = new PresidentialPardonForm("Apologize", "Norminet");
//	Form *form = new ShrubberyCreationForm("I like trees", "42");
	Form *form = new RobotomyRequestForm("Robot", "Rock");


	try { president->executeForm(*form); } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	secretary->signForm(*form);
	try { secretary->executeForm(*form); } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { president->executeForm(*form); } catch (std::exception & e) { std::cout << e.what() << std::endl; }

	return 0;
}
