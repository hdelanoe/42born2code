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

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat("Tyler", 100);
	Form *b = new Form("contract", 99, 80);

	a->signForm(*b);

	std:: cout << b;
	
	try { a->upGrade(); } catch (std::exception & e) { std::cout << e.what() << std::endl; }

	a->signForm(*b);

	std:: cout << b;
	

	return 0;
}