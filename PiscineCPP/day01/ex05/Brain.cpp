/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:00:36 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 20:00:37 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	this->neurons = 100;
	this->synaps = 1000;
	return ;
}

Brain::~Brain(void)
{
	return ;
}

std::string Brain::identify(void) const
{ 
	std::stringbuf buffer;
	std::ostream os (&buffer);
	os << std::hex << this;
	return (buffer.str());
}
