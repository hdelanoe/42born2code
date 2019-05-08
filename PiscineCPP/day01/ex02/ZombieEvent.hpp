/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:55:09 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:56:00 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
public:

	ZombieEvent(void);
	~ZombieEvent(void);
	Zombie	*newZombie(std::string name);
	void	setZombieType();
	Zombie	*randomChump();

	std::string	type;

private:
	std::string	_list_name[10];
	std::string	_list_type[10];
};

#endif
