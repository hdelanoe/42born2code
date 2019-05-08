/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:10:04 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 14:10:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
}
