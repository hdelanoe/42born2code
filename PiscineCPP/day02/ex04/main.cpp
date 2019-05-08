/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:21:26 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/27 11:21:28 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>
#include <stdexcept>
#include "Fixed.class.hpp"

Fixed eval(std::string *arr) {

	Fixed nb1;
	Fixed nb2;
	Fixed ret;
	std::string op;

	int i = 0;
	while (arr[i + 2].length() > 0) {
		try {
			nb1 = Fixed(std::stof(arr[i]));
			nb2 = Fixed(std::stof(arr[i + 2]));
		} catch (const std::invalid_argument& ia){
			std::cout << "Sorry, your expression haven't a good format." << std::endl;
			exit(42);
		}
		if (arr[i + 1] == "+")
			ret = nb1 + nb2;
		else if (arr[i + 1] == "-")
			ret = nb1 - nb2;
		else
		{
			std::cout << "Sorry, your expression haven't a good format." << std::endl;
			exit(42);				
		}
		std::ostringstream ss;
		ss << ret.toFloat();
		arr[i + 2] = ss.str();
		i += 2;
	}
	return ret;
}

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "[USAGE]:  eval_expr \" your expression \"" << std::endl;
	}
	else {
		std::string input;
		std::stringstream ss;
		ss << argv[1];
		input = ss.str();
		for (std::string::iterator it = input.begin(); it < input.end(); it++) {
			if (std::isdigit(*it) == 0 && !(*it == '.' || *it == '+' || *it == '-' || *it == ' ')) {
				std::cout << "Sorry, \"" << input << "\" isn't a evaluable expressiondd." << std::endl;	
				return 0;
			}
		}

		size_t i = 0;
		size_t j = 0;
		while (input.find(" ", j) != std::string::npos) {
			j = input.find(" ", j) + 1;
			i++;
		}
		if (i == 0) {
			std::cout << "Sorry, \"" << input << "\" isn't a evaluable expression." << std::endl;			
			return (0);
		}
		std::string arr[i];
		j = -1;
		while (++j < i) {
			std::string tmp = input.substr(0, input.find(" "));
			arr[j] = tmp;
			input.erase(0, input.find(" ") + 1);
		}
		arr[j] = input.substr(0, input.find("\n"));
		Fixed ret = eval(arr);
		std::cout << ret << std::endl;
	}
	return (0);
}
