/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:08:31 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/13 12:08:32 by hdelanoe         ###   ########.fr       */
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

std::string	error(int argc, char **argv)
{
	int			i = 0;
	int			j = 0;
	std::string	file;
	
	while (++i < argc)
	{
		if (j += exist_file(argv[i]))
		{
			file = argv[i];
			break ;
		}
	}
	if (j > 1 || argc != 4 || i != 1)
	{
		std::cout << "usage : ./replace [FILE] [string 1] [string 2]" << std::endl;
		exit(42);
	}
	return (file);

}

void	replace(char *buffer, char *arg1, char *arg2, std::string name)
{
	std::string s1(arg1);
	std::string s2(arg2);
	std::string	res(buffer);

	std::size_t	pos = 0;

	if (s1 == s2)
	{
		std::cout << "[string 1] and [string 2] are not different" << std::endl;
		exit(42);
	}
	name += ".replace";
	while ((pos = res.find(s1, 0)) != std::string::npos)
	 {
		pos = res.find(s1);
		res.replace(pos, s1.length(), s2);
	 }
	std::ofstream	replace(name);

	replace << res;
	replace.close();
}

int		main(int argc, char **argv)
{
	std::string		name = error(argc, argv);
	std::ifstream	file(name, std::ifstream::binary);
	
	if (file)
	{
		file.seekg (0, file.end);
    	int length = file.tellg();
    	file.seekg (0, file.beg);
		char *buffer = new char[length];

		file.read(buffer, length);
		if (!file)
		{
			std::cout << "ERROR " << file.gcount() << " not read";
			return (0);
		}
		file.close();
		replace(buffer, argv[2], argv[3], name);
		delete [] buffer;
	}
	return (0);
}
