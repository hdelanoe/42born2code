/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:53:05 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 17:53:06 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

		ScavTrap(std::string name = "ScavTrap");
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		void rangedAttack(std::string const & target, int type) const;
		void meleeAttack(std::string const & target, int type) const;
		void challengeNewcomer(std::string const & target);

};

#endif
