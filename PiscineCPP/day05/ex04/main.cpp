/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:47:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 10:47:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"


int main()
{

	Intern	idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(&idiotOne);
	ob.setSigner(&bob);
	ob.setExecutor(&hermes);

	try { ob.doBureaucracy("mutant pigtermination", "Pigley"); } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { ob.doBureaucracy("shrubbery creation", "Shrubb"); } catch (std::exception & e) { std::cout << e.what() << std::endl; }

	return 0;
}