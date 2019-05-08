/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:11:40 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/09 17:11:41 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <cstring>
# include <cstdlib>
# include "Contact.class.hpp"

std::string	first_name();
std::string	last_name();
std::string	nickname();
std::string	login();
std::string	postal_address();
std::string	email_address();
std::string	phone_number();
std::string	birthday_date();
std::string	favorite_meal();
std::string	underwear_color();
std::string	darkest_secret();

void	print_search(Contact entry, int i);
void	print_result(Contact result);

#endif