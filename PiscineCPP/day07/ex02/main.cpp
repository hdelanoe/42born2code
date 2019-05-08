/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:25:03 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/03 18:25:04 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> array(10);
	try { array [10] = 10; } catch(std::out_of_range & e) { std::cout<< e.what() << std::endl; }
	array[5] = 42;

	std::cout << array[5] << std::endl;
	std::cout << array[8] << std::endl;

	
	Array<std::string> array2(42);
	array2[4] = "Hello";
	array2[6] = "World";

	try { array2[42] = "!"; } catch(std::out_of_range & e) { std::cout<< e.what() << std::endl; }


	std::cout << array2[4] << std::endl;
	std::cout << array2[2] << std::endl;
	std::cout << array2[6] << std::endl;

	try { std::cout << array2[42] << std::endl; } catch(std::out_of_range & e) { std::cout<< e.what() << std::endl; }

	Array<int> empty;
	Array<int> test(5);

	std::cout << "test[4] -> " << test[4] << std::endl;

	test = empty;

	try { test[10] = 10; } catch(std::out_of_range & e) { std::cout<< e.what() << std::endl; }	

	test = *new Array<int>(60);
	test[56] = 56;
	std::cout << test[56] << std::endl;
	test[56] = array[5];
	std::cout << test[56] << std::endl;

	return 0;
}
