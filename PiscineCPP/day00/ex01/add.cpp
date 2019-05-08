/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:00:01 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/09 17:00:03 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string	first_name()
{
	std::string cmd;

	std::cout << "first name : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	last_name()
{
	std::string cmd;

	std::cout << "last name : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	nickname()
{
	std::string cmd;

	std::cout << "nickname : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	login()
{
	std::string cmd;

	std::cout << "login : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	postal_address()
{
	std::string cmd;

	std::cout << "postal address : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	email_address()
{
	std::string cmd;

	std::cout << "email address : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	phone_number()
{
	std::string cmd;

	std::cout << "phone number : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	birthday_date()
{
	std::string cmd;

	std::cout << "birthday date : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	favorite_meal()
{
	std::string cmd;

	std::cout << "favorite meal : ";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	underwear_color()
{
	std::string cmd;

	std::cout << "underwear color :";
	std::getline(std::cin, cmd);
	return(cmd);
}

std::string	darkest_secret()
{
	std::string cmd;

	std::cout << "darkest secret : ";
	std::getline(std::cin, cmd);
	return(cmd);
}