/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:25:56 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) : _count(0)
{
	for (int i = 0; i < 4; i += 1)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < 4; i += 1)
        {
            _materia[i] = NULL;
            _materia[i] = rhs._materia[0]->clone();
        }
        _count = rhs._count;

	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (_count < 3)
	{
		_materia[_count] = materia;
		_count += 1;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = _count;
	while (i >= 0){
	if (_materia[i] && _materia[i]->getType() == type)
		return _materia[i];
		i--;
	}
	return 0;
}

int			MateriaSource::getCount(void) const
{
	return _count;
}
