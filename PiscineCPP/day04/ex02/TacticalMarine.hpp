/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:13 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

	public:

		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		~TacticalMarine(void);

		virtual	ISpaceMarine* clone() const;
		virtual void battleCry() const ;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
		
		TacticalMarine &	operator=(TacticalMarine const & rhs);
};

#endif
