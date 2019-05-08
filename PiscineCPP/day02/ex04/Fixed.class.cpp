/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:13:31 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/27 11:13:34 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _value(0)
{
	return ;
}

Fixed::Fixed(int const src) : _value(src << Fixed::_bits)
{
	return ;
}

Fixed::Fixed(float const src) : _value(roundf(src  * (1 << Fixed::_bits)))
{
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
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
	return this->_value / (float)(1 << Fixed::_bits);
}

int 	Fixed::toInt(void) const
{
	return this->_value / (int)(1 << Fixed::_bits);
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_value != rhs.getRawBits());
}

Fixed 	Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed 	Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed 	Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed 	Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}


std::ostream & 	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

Fixed const &	min(Fixed const & a, Fixed const & b)
{
	return (a < b) ? a : b;
}

Fixed &			min(Fixed & a, Fixed & b)
{
	return (a < b) ? a : b;
}

Fixed const &	max(Fixed const & a, Fixed const & b)
{
	return (a > b) ? a : b;
}

Fixed &			max(Fixed & a, Fixed & b)
{
	return (a > b) ? a : b;
}

