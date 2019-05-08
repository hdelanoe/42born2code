/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:57:45 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:57:47 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"
#include "Base.hpp"

Base*	generate(void)
{
	srand(time(NULL));
    int     i = rand() % 3;
    Base    *base;

    if (i == 0) { base = new A(); std::cout << "Class A has been generated!" << std::endl; }
    if (i == 1) { base = new B(); std::cout << "Class B has been generated!" << std::endl; }
    if (i == 2) { base = new C(); std::cout << "Class C has been generated!" << std::endl; }
    return base;
}

void	identify_from_pointer(Base* ptr)
{
    if (dynamic_cast<A*>(ptr)) { std::cout << "A identified from pointer" << std::endl; }
    if (dynamic_cast<B*>(ptr)) { std::cout << "B identified from pointer" << std::endl; }
    if (dynamic_cast<C*>(ptr)) { std::cout << "C identified from pointer" << std::endl; }
}

void	identify_from_reference(Base & ref)
{
	try { A a = dynamic_cast<A&>(ref); std::cout << "A identified from reference" << std::endl; } catch (std::exception & e) {}
	try { B b = dynamic_cast<B&>(ref); std::cout << "B identified from reference" << std::endl; } catch (std::exception & e) {}
	try { C c = dynamic_cast<C&>(ref); std::cout << "C identified from reference" << std::endl; } catch (std::exception & e) {}
}

int main()
{
    Base    *ptr = generate();

    identify_from_pointer(ptr);
    identify_from_reference(*ptr);

    return (0);
}