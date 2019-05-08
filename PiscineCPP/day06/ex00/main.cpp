/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:04:28 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 18:04:29 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

bool is_char( const std::string &in) {
	std::stringstream sstr(in);
	char c;
	return !((sstr >> c).rdstate() ^ std::ios_base::eofbit);
}

bool is_int( const std::string &in) {
	std::stringstream sstr(in);
	int i;
	return !((sstr >> i).rdstate() ^ std::ios_base::eofbit);
}

int to_int(const std::string &in) {
	std::stringstream sstr(in);
	int i;
	sstr >> i;
	return i;
}

bool is_float( const std::string &in) {
	std::stringstream sstr(in);
	float f;
	return !((sstr >> f).rdstate() ^ std::ios_base::eofbit);
}

float to_float( const std::string &in) {
	std::stringstream sstr(in);
	float f;
	sstr >> f;
	return f;
}

bool is_double( const std::string &in) {
	std::stringstream sstr(in);
	double d;
	return !((sstr >> d).rdstate() ^ std::ios_base::eofbit);
} 


int main (int argc, char **argv)
{
	if (argc != 2) { std::cout << "usage : ./convert [literal value]" << std::endl; return 0; }

	std::string value = std::string(argv[1]);
	if (value[value.size() -1] == 'f' && is_float(value.substr(0, value.size() -1)))
		value = value.substr(0, value.size() -1);

	std::string f = "f";

	if (is_char(value))
		std::cout << "char: \'" << value << "\'" << std::endl;
	else if ((is_int(value) && to_int(value) > 31 && to_int(value) < 127) ||
		(is_float(value) && static_cast<int>(to_float(value)) > 31 && static_cast<int>(to_float(value)) < 127))
		std::cout << "char: \'" << static_cast<char>(to_int(value)) << "\'" << std::endl;
	else if ((is_int(value) && to_int(value) < 255) ||
		(is_float(value) && static_cast<int>(to_float(value)) < 255 && static_cast<int>(to_float(value)) > 0))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (is_int(value))
		std::cout << "int: " << value << std::endl;
	else if (is_float(value) && (!(to_float(value) != to_float(value) || to_float(value) == -1.0 / 0.0 || to_float(value) == 1.0 / 0.0)))
		std::cout << "int: " << static_cast<int>(to_float(value)) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (is_float(value)){
		if (value[value.size() -1] == 'f' && (!(to_float(value) != to_float(value) || to_float(value) == -1.0 / 0.0 || to_float(value) == 1.0 / 0.0)))
			f = "";
		std::cout << "float: " << value << f << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;

	if (is_double(value))
		std::cout << "double: " << value << std::endl;
	else
		std::cout << "double: impossible" << std::endl;

	return 0;
}
