/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:54:38 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:55:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
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
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie::Zombie(this->type, name);
	return (zombie);
}

void	ZombieEvent::setZombieType()
{
	this->type = _list_name[rand() % 10];
	return ;
}

Zombie *ZombieEvent::randomChump()
{
	int	type = rand() % 10;
	int name = rand() % 10;
	Zombie	*zombie = new Zombie(_list_type[type], _list_name[name]);
	zombie->announce();
	return (zombie);
}
