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


int	main()
{
	FragTrap 	*fragTrap = new FragTrap();
	ScavTrap 	*scavTrap = new ScavTrap();
	ClapTrap 	*clapTrap = new ClapTrap();
	ClapTrap	*ninjaClap = new NinjaTrap();
	NinjaTrap	*ninjaTrap = new NinjaTrap();

	NinjaTrap 	*zaz = new NinjaTrap("zaz");

	std::cout << std::endl << std::endl << std::endl;


	zaz->ninjaShoebox(scavTrap);
	zaz->ninjaShoebox(ninjaClap);
	zaz->ninjaShoebox(clapTrap);
	zaz->ninjaShoebox(ninjaTrap);
	zaz->ninjaShoebox(fragTrap);

	std::cout << std::endl << std::endl << std::endl;
	delete fragTrap;
	delete scavTrap;
	delete clapTrap;
	delete ninjaClap;
	delete ninjaTrap;
	delete zaz;
	return (0) ;
}
