/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:58:25 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 19:58:27 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"


class SuperTrap : public FragTrap, public NinjaTrap {

	public:

		SuperTrap(std::string name = "SuperTrap");
		SuperTrap(SuperTrap const & src);
		~SuperTrap(void);

		void 	rangedAttack(std::string const & target, int type) const;
		void 	meleeAttack(std::string const & target, int type) const;
};

#endif

