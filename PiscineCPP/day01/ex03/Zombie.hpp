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

	Zombie(void);
	~Zombie(void);
	void 	announce(void) const;
	void	setType(std::string type);
	void	setName(std::string name);

private:

	std::string	_type;
	std::string	_name;
};

#endif