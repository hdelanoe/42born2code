/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:10:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:10:14 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void) : _squad(NULL), _count(0)
{

	return ;
}

Squad::Squad(Squad const & src)
{
	*this = src;
}

Squad::~Squad(void)
{
	for (int i = 0 ; i < this->_count; i++) {
        delete this->_squad[i];
    }
}

Squad & Squad::operator=(Squad const & rhs)
{
	if (this != &rhs) {
		this->_squad = rhs.getSquad();
		this->count = rhs.getCount();
	}
	return *this;
}

int				Squad::getCount() const
{
	return this->_count;
}

ISpaceMarine*	Squad::getUnit(int i) const
{
	if (i < this->_count && this->_squad)
		return this->_squad[i];
	return 0;
}

ISpaceMarine**	Squad::getSquad() const
{	
	return this->_squad;
}

int 			Squad::push(ISpaceMarine* marine)
{
	this->_count += 1;
	ISpaceMarine **tmp = new ISpaceMarine*[this->_count];
	for (int i = 0; i < this->_count - 1; i++) {
        tmp[i] = this->_squad[i];
    }
    delete this->_squad;
	tmp[this->_count - 1] = marine;
    this->_squad = tmp;
    return this->_count;
}
