/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:32:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/12 13:32:30 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

inline bool	exist_file(const std::string &file)
{
	struct stat buffer;
	return (stat(file.c_str(), &buffer) == 0);
}

void cat(std::string s)
{
	if (exist_file(s)) {
		std::ifstream file(s, std::ifstream::binary);
		if (file) {
			file.seekg (0, file.end);
    		int length = file.tellg();
	    	file.seekg (0, file.beg);
			char *buffer = new char[length];

			file.read(buffer, length);
			if (!file)
			{
				std::cout << "[ERROR]: cannot read " << file.gcount() << std::endl;
				file.close();
				return ;
			}
			file.close();
			std::cout << buffer;		
		}
	}
	else {
		std::cout << "cato9tails: " << s << " : No such file or directory" << std::endl;
		return ;
	}

}

void stdinCat()
{
	std::string input;
	while(std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
    return ;
}

int		main(int argc, char **argv)
{
	if (argc < 2) {
		stdinCat();
		return(0);
	}
	int i = 0;
	while (argv[++i]) {
		std::string s(argv[i]);
		cat(s);
	}
	(void)argc;
	return (0);
}
