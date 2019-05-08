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

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const src) : _value(src << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const src) : _value(roundf(src  * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
	return ;	
}

int 	Fixed::getRawBits(void) const
{
	return this->_value;
}

void 	Fixed::setRawBits(int const raw)
{
	if (this->_value != raw)
		this->_value = raw;	
	return ;
}

float 	Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	return this->_value / (float)(1 << Fixed::_bits);
}

int 	Fixed::toInt(void) const {

	std::cout << "toInt member function called" << std::endl;
	return this->_value / (int)(1 << Fixed::_bits);
}

Fixed &		Fixed::operator=(Fixed const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	
	return *this;
}

std::ostream & 	operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat();
	return o;
}
