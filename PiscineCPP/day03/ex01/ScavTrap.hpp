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

# include <string>
# include <iostream>


class ScavTrap {

	public:

		ScavTrap(std::string name = "ScavTrap");
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &		operator=(ScavTrap const & rhs);
		unsigned int 	getHitPoints() const;
		unsigned int 	getMaxHitPoints() const;
		unsigned int 	getEnergyPoints() const;
		unsigned int 	getMaxEnergyPoints() const;
		unsigned int 	getLevel() const;
		std::string 	getName() const;
		unsigned int 	getMeleeAttackDamage() const;
		unsigned int 	getRangedAttackDamage() const;
		unsigned int 	getArmorDamageReduction() const;

		void 	rangedAttack(std::string const & target, int type) const;
		void 	meleeAttack(std::string const & target, int type) const;
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		
		void challengeNewcomer(std::string const & target);

	private:

		unsigned int	_HitPoints;
		unsigned int	_MaxHitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_MaxEnergyPoints;
		unsigned int	_Level;
		std::string 	_Name;
		unsigned int	_MeleeAttackDamage;
		unsigned int	_RangedAttackDamage;
		unsigned int	_ArmorDamageReduction;

};

#endif
