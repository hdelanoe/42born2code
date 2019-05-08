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

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public:

		FragTrap(std::string const name = "FragTrap");
		FragTrap(FragTrap const & src);
		virtual ~FragTrap(void);

		virtual void 	rangedAttack(std::string const & target, int type) const;
		virtual void 	meleeAttack(std::string const & target, int type) const;
		void 	vaulthunter_dot_exe(std::string const & target);

	protected:
		FragTrap(unsigned int) {
			this->_HitPoints = 100; 
			this->_MaxHitPoints = 100;
			this->_RangedAttackDamage = 20;
			this->_ArmorDamageReduction = 5; }
};

#endif
