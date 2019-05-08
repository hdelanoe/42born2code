/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 15:56:03 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MonitorManager.hpp"

bool	isOption(std::string s)
{
	if (s == "-s1" || s == "-s2" || s == "-s3")
		return true;
	return false;
}

int main(int argc, char** argv)
{
	std::string option;
	if (argc < 2)
		option = "";
	else
	{
		option = std::string(argv[1]);
		if (!isOption(option))
		{
			std::cout << "Usage: ./ft_gkrellm (otpion)" << std::endl;
			std::cout << "Option:   -s1 for step 1 modules" << std::endl;
			std::cout << "          -s2 for step 2 modules" << std::endl;
			std::cout << "          -s3 for step 3 module" << std::endl;
			std::cout << "          no option for default" << std::endl;
			return 0;
		}
	}
	MonitorManager manager(option);
	while (manager.update())
		;
}
