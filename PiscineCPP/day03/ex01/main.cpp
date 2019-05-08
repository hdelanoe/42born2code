/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:59:18 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/27 17:59:20 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int	main()
{
	FragTrap Fragtrap;
	Fragtrap.vaulthunter_dot_exe("a skag");
	Fragtrap.vaulthunter_dot_exe("the Vault Hunter");
	Fragtrap.vaulthunter_dot_exe("a bandit");
	Fragtrap.vaulthunter_dot_exe("a Gatling Turret");
	Fragtrap.vaulthunter_dot_exe("the Awesome Jack");
	Fragtrap.rangedAttack("a 42 student", 2);
	Fragtrap.meleeAttack("the big boss", 0);
	Fragtrap.beRepaired(50);
	Fragtrap.takeDamage(105);

	ScavTrap Scavtrap;
	Scavtrap.challengeNewcomer("a skag");
	Scavtrap.challengeNewcomer("the Vault Hunter");
	Scavtrap.challengeNewcomer("a bandit");
	Scavtrap.challengeNewcomer("a Gatling Turret");
	Scavtrap.challengeNewcomer("the Awesome Jack");
	Scavtrap.rangedAttack("a 42 student", 2);
	Scavtrap.meleeAttack("the big boss", 0);
	Scavtrap.beRepaired(50);
	Scavtrap.takeDamage(105);

	return (0) ;
}
