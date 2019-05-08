/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_search.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:24:38 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/09 17:24:39 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string	point_size(std::string entry)
{
	int len;

	if (entry[10])
	{
		entry[9] = '.';
		entry.resize(10);
	}
	else
	{
		len = entry.size() - 1;
		entry.resize(10, ' ');
		while (++len < 10)
			entry[10] = ' ';
	}
	return (entry);
}

void	print_search(Contact entry, int i)
{
	std::string col;
	std::string	first;
	std::string	last;
	std::string	nick;

	first = point_size(entry.first_name);
	last = point_size(entry.last_name);
	nick = point_size(entry.nickname);
	col = " | " + first + " | " + last + " | " + nick + " | ";
	std::cout << "| " << i << "         " << col << std::endl;
}

void	print_result(Contact result)
{
	std::cout << "first name : " << result.getAttr("first_name") << std::endl;
	std::cout << "last name : " << result.getAttr("last_name") << std::endl;
	std::cout << "nickname : " << result.getAttr("nickname") << std::endl;
	std::cout << "login : " << result.getAttr("login") << std::endl;
	std::cout << "postal address : " << result.getAttr("postal_address") << std::endl;
	std::cout << "email address : " << result.getAttr("email_address") << std::endl;
	std::cout << "phone number : " << result.getAttr("phone_number") << std::endl;
	std::cout << "birthday date : " << result.getAttr("birthday_date") << std::endl;
	std::cout << "favorite meal : " << result.getAttr("favorite_meal") << std::endl;
	std::cout << "underwear color : " << result.getAttr("underwear_color") << std::endl;
	std::cout << "darkest secret : " << result.getAttr("darkest_secret") << std::endl;
	std:: cout << std::endl;
}
