/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:00:51 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 20:00:54 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	return ;
}

Human::~Human(void)
{
	return ;
}

const Brain &Human::getBrain(void)
{ 
	return (this->_brain);
}

std::string Human::identify(void) const
{ 
	return (this->_brain.identify());
}
