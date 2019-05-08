/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:03:41 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 18:03:42 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"


ZombieHorde::ZombieHorde(int N) : number(N)
{	
	int	i = -1;
	_list_type[0] = "Ghoul";
	_list_type[1] = "Skeleton";
	_list_type[2] = "Geist";
	_list_type[3] = "Mummy";
	_list_type[4] = "Banshee";
	_list_type[5] = "Lich";
	_list_type[6] = "Shade";
	_list_type[7] = "Ghost";
	_list_type[8] = "Gargoyle";
	_list_type[9] = "Abomination";
	_list_name[0] = "Corpseslobber";
	_list_name[1] = "Bonehead";
	_list_name[2] = "Skullbasher";
	_list_name[3] = "Casketface";
	_list_name[4] = "Wormdrinker";
	_list_name[5] = "Hammerswallower";
	_list_name[6] = "Beetlejuice";
	_list_name[7] = "Rockbender";
	_list_name[8] = "Ratkeeper";
	_list_name[9] = "Dirtchewer";

	this->_Horde =  new Zombie[number];
	while (++i < number) 
		randomChump(&this->_Horde[i]);
	announce();
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_Horde;
	return ;
}

void ZombieHorde::randomChump(Zombie *zombie)
{
	int	type = rand() % 10;
	int name = rand() % 10;
	zombie->setType( _list_type[type]);
	zombie->setName( _list_name[name]);
}

void ZombieHorde::announce()
{
	int i = -1;
	while (++i < number)
		_Horde[i].announce();

}