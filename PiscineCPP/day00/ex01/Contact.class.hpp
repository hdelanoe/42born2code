/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 23:23:59 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/08 23:29:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
public:

	Contact(void);
	~Contact(void);

	std::string	getAttr(std::string attr) const;
	void		setFirst_name(std::string attr);
	void		setLast_name(std::string attr);
	void		setNickname(std::string attr);
	void		setLogin(std::string attr);
	void		setPostal_address(std::string attr);
	void		setEmail_address(std::string attr);
	void		setPhone_number(std::string attr);
	void		setBirthday_date(std::string attr);
	void		setFavorite_meal(std::string attr);
	void		setUnderwear_color(std::string attr);
	void		setDarkest_secret(std::string attr);

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

private:

	std::string	login;
	std::string	postal_address;
	std::string	email_address;
	std::string	phone_number;
	std::string	birthday_date;
	std::string	favorite_meal;
	std::string	underwear_color;
	std::string	darkest_secret;

};

#endif
