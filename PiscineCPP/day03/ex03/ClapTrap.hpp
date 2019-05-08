/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:05:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 18:05:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>


class ClapTrap {

	public:

		ClapTrap(std::string const name = "ClapTrap");
		ClapTrap(ClapTrap const & src);
		virtual ~ClapTrap(void);

		ClapTrap &		operator=(ClapTrap const & rhs);

		unsigned int 	getHitPoints() const;
		unsigned int 	getMaxHitPoints() const;
		unsigned int 	getEnergyPoints() const;
		unsigned int 	getMaxEnergyPoints() const;
		unsigned int 	getLevel() const;
		std::string 	getName() const;
		unsigned int 	getMeleeAttackDamage() const;
		unsigned int 	getRangedAttackDamage() const;
		unsigned int 	getArmorDamageReduction() const;

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


	protected:

		ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints,
					unsigned int maxEnergyPoints, unsigned int level, std::string name, 
					unsigned int MeleeAttackDamage, unsigned int rangedAttackDamage,
					unsigned int armorDamageReduction) :_HitPoints(hitPoints), _MaxHitPoints(maxHitPoints), _EnergyPoints(energyPoints),
														_MaxEnergyPoints(maxEnergyPoints), _Level(level), _Name(name),
														_MeleeAttackDamage(MeleeAttackDamage), _RangedAttackDamage(rangedAttackDamage),
														_ArmorDamageReduction(armorDamageReduction) {}

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
