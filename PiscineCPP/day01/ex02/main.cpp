/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:56:08 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:56:45 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent *start = new ZombieEvent();
	Zombie *zombie1 = new Zombie("Ghoul","Corpseslobber");
	start->setZombieType();
	Zombie *zombie2 = start->newZombie("Beetlejuice");
	Zombie *zombie3 = start->randomChump();
	
	zombie1->announce();
	zombie2->announce();

	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete start;
	while(42);
	return (0);
}
