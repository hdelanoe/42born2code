/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:07:03 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/12 19:07:04 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
	return ;	
}

int 	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void 	Fixed::setRawBits(int const raw) {

	std::cout << "SetRawBits member function called" << std::endl;
	if (this->_value != raw)
		this->_value = raw;	
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	
	return *this;
}