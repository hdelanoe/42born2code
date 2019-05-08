/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:03:49 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 18:03:50 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieHorde
{
public:

	ZombieHorde(int N);
	~ZombieHorde(void);
	void	randomChump(Zombie *zombie);
	void	announce();

	int			number;

private:
	Zombie		*_Horde;
	std::string	_list_name[10];
	std::string	_list_type[10];
};

#endif
