/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:28:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 14:28:23 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

# include <iostream>
# include <string>

class Pony
{
public:

	Pony(std::string name, std::string tail, std::string fur, int corn);
	~Pony(void);
	std::string getName(void) const;



private:

	const std::string	_name;
	const std::string	_tail;
	const std::string	_fur;
	const int			_corn;
};

#endif
