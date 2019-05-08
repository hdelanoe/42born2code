/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:01:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/27 19:01:20 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"


int	main()
{
	NinjaTrap *a = new SuperTrap("Genji");
	NinjaTrap *b = new NinjaTrap("Hanzo");
	
	std::cout << a->getName() << " VS " << b->getName() << std::endl;
	a->meleeAttack(b->getName(), rand() % 3);
	a->rangedAttack(b->getName(), rand() % 3);
	b->ninjaShoebox(a);


	delete a;
	delete b;
	return (0);
}
