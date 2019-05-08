/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:53:43 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 15:54:28 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
public:

	Zombie(std::string type, std::string name);
	~Zombie(void);
	void announce(void) const;

private:

	const std::string	_type;
	const std::string	_name;
};

#endif
