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

int main()
{

	Intern	someRandomIntern;
	Form*	randomForm;

	try { randomForm = someRandomIntern.makeForm("si", "non"); } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	
	std::cout << "Does form ? : " << randomForm; 
	
	try { randomForm = someRandomIntern.makeForm("robotomy request","Et bien si."); } catch (std::exception & e) { std::cout << e.what() << std::endl; }

	std::cout << "Does form ? : " << randomForm; 

	return 0;
}