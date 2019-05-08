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

int main()
{
	Bureaucrat *a;
	Bureaucrat *b;

	try { a = new Bureaucrat("Wesley", 150); } catch (std::exception & e) { a = new Bureaucrat(); std::cout << e.what() << std::endl; }
	try { b = new Bureaucrat("Tyler", 0); } catch (std::exception & e) { b = new Bureaucrat(); std::cout << e.what() << std::endl; }

	std:: cout << a;
	std:: cout << b;

	try { a->downGrade(); } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { b->upGrade(); } catch (std::exception & e) { std::cout << e.what() << std::endl; }

	std:: cout << a;
	std:: cout << b;

	return 0;
}