/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 00:07:57 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/09 00:07:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getAttr(std::string attr) const
{
	if (attr == "first_name")
		return (this->first_name);
	if (attr == "last_name")
		return (this->last_name);
	if (attr == "nickname")
		return (this->nickname);
	if (attr == "login")
		return (this->login);
	if (attr == "postal_address")
		return (this->postal_address);
	if (attr == "email_address")
		return (this->email_address);
	if (attr == "phone_number")
		return (this->phone_number);
	if (attr == "birthday_date")
		return (this->birthday_date);
	if (attr == "favorite_meal")
		return (this->favorite_meal);
	if (attr == "underwear_color")
		return (this->underwear_color);
	if (attr == "darkest_secret")
		return (this->darkest_secret);
	return (attr);
}

void		Contact::setFirst_name(std::string attr)
{
	this->first_name = attr;
	return ;
}

void		Contact::setLast_name(std::string attr)
{
	this->last_name = attr;
	return ;
}

void		Contact::setNickname(std::string attr)
{
	this->nickname = attr;
	return ;
}

void		Contact::setLogin(std::string attr)
{
	this->login = attr;
	return ;
}

void		Contact::setPostal_address(std::string attr)
{
	this->postal_address = attr;
	return ;
}

void		Contact::setEmail_address(std::string attr)
{
	this->email_address = attr;
	return ;
}

void		Contact::setPhone_number(std::string attr)
{
	this->phone_number = attr;
	return ;
}

void		Contact::setBirthday_date(std::string attr)
{
	this->birthday_date = attr;
	return ;
}

void		Contact::setFavorite_meal(std::string attr)
{
	this->favorite_meal = attr;
	return ;
}

void		Contact::setUnderwear_color(std::string attr)
{
	this->underwear_color = attr;
	return ;
}

void		Contact::setDarkest_secret(std::string attr)
{
	this->darkest_secret = attr;
	return ;
}