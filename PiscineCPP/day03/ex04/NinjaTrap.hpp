/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:25:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 18:25:51 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

	public:

		NinjaTrap(std::string const name = "NinjaTrap");
		NinjaTrap(NinjaTrap const & src);
		virtual ~NinjaTrap(void);

		virtual void rangedAttack(std::string const & target, int type) const;
		virtual void meleeAttack(std::string const & target, int type) const;
		void ninjaShoebox(ClapTrap* trap);
		void ninjaShoebox(ScavTrap* trap);
		void ninjaShoebox(FragTrap* trap);
		void ninjaShoebox(NinjaTrap* trap);

	protected:

		NinjaTrap(unsigned int, std::string name) {
					this->_EnergyPoints = 120;
					this->_MaxEnergyPoints = 120;
					this->_MeleeAttackDamage = 60;
					this->_Name = name; }

};

#endif
