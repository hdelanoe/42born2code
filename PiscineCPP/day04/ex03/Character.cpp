/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:41 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("character"), _count(0)
{
	for (int i = 0; i < 4; i += 1)
    {
        _materia[i] = NULL;
    }
}

Character::Character(std::string const & name) : _name(name), _count(0)
{	
	for (int i = 0; i < 4; i += 1)
    {
        _materia[i] = NULL;
    }
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(void)
{
	return ;
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs) {
		_name = rhs.getName();
		for (int i = 0; i < 4; i += 1)
        {
            _materia[i] = NULL;
            _materia[i] = rhs._materia[0]->clone();
        }
        _count = rhs._count;

	}
	return *this;
}

void Character::equip(AMateria* materia)
{
	if (_count < 3)
	{
		_materia[_count] = materia;
		_count += 1;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
        _materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	_materia[idx]->use(target);
}


int			Character::getCount(void) const
{
	return _count;
}

std::string	const & Character::getName(void) const
{
	return _name;
}