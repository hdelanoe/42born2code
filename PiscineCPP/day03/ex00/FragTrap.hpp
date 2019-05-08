/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:09:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 14:09:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>


class FragTrap {

	public:

		FragTrap(std::string name = "FragTrap");
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &		operator=(FragTrap const & rhs);

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
		void  	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		
		void 	vaulthunter_dot_exe(std::string const & target);

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
