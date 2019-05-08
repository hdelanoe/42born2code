/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:43:24 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 14:43:25 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.class.hpp"

Pony::Pony(std::string name, std::string tail, std::string fur, int corn) : _name(name), _tail(tail), _fur(fur), _corn(corn)
{
	std::cout << this->_name << " has a " << this->_tail << " tail, a " << this->_fur
	<< " fur and " << this->_corn << " corn !" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << this->_name << " explode..." << std::endl;
}

std::string Pony::getName(void) const
{
	return (this->_name);
}
