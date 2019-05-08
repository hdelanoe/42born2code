/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:03:21 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/13 18:03:22 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{ 
	std::cout << "Melee Attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{ 
	std::cout << "Ranged Attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	int i = 0;
	void (Human::*arr[3])(std::string const &) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string action[3] = {"melee", "ranged", "shout"};
	while(action_name != action[i] && i < 3)
		i++;
	if (i < 3)
		(this->*arr[i])(target);
}