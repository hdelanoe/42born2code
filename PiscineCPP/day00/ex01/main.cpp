/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 23:08:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/08 23:08:35 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"


Contact	add_cmd(Contact add)
{
	std::cout << "REGISTER YOUR CONTACT" << std::endl;
	add.setFirst_name(first_name());
	add.setLast_name(last_name());
	add.setNickname(nickname());
	add.setLogin(login());
	add.setPostal_address(postal_address());
	add.setEmail_address(email_address());
	add.setPhone_number(phone_number());
	add.setBirthday_date(birthday_date());
	add.setFavorite_meal(favorite_meal());
	add.setUnderwear_color(underwear_color());
	add.setDarkest_secret(darkest_secret());
	return(add);
}

void	search_cmd(Contact *book)
{
	std::string	cmd;
	std::string col;

	int		i = -1;

	col = "|   index    | first name | last  name |  nickname  |";
	std::cout << std::endl << col << std::endl << std::endl;;
	while (!book[++i].getAttr("first_name").empty() ||
		!book[i].getAttr("last_name").empty() ||
		!book[i].getAttr("nickname").empty()) {
		print_search(book[i], i + 1);
	}
	if (i > 0) {	
		std::cout << "Enter the number of your contact : ";
		std::getline(std::cin, cmd);
		if (stoi(cmd) > i) {
			std::cout << std::endl << "You don't have as many contacts!" << std::endl;
			return ;
		}
		else if (stoi(cmd) < i) {
			std::cout << std::endl << "C'mon! The index starts at 1!" << std::endl;
			return ;
		}
		else
			print_result(book[stoi(cmd) - 1]);
	}
	else {
		std::cout << "Your Awesome PhoneBook is empty, add some contacts!" << std::endl;
	}
}

int		main()
{
	int i = -1;
	std::string cmd;
	Contact *add = new Contact[8];

	std::cout << "Welcome to your Awesome PhoneBook!" << std::endl;
	while (cmd != "EXIT")
	{
		std::cout << std::endl << "Enter your command:" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "ADD" && ++i < 8) {
			std::cout << i;
			add[i] = add_cmd(add[i]);
			if (add[i].getAttr("first_name") == "" &&
				add[i].getAttr("last_name") == "" &&
				add[i].getAttr("nickname") == "") {
				i--;
				std::cout << std::endl << "Sorry, your contact doesn't have a name so is not registred." << std::endl;
			}
		}
		else if (cmd == "ADD")
		{
			std::cout << " Your Awesome PhoneBook is full, sorry!" << std::endl;
			continue ;
		}
		else if (cmd == "SEARCH")
		{
			search_cmd(add);
			continue ;
		}
		else if (cmd != "EXIT")
			std::cout << "Sorry, it's an invalid command. Try ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return (0);
}