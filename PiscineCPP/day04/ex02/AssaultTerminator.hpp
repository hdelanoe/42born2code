/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:36 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"


class AssaultTerminator : public ISpaceMarine {

	public:

		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);
		~AssaultTerminator(void);

		virtual	ISpaceMarine* clone() const;
		virtual void battleCry() const ;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
		
		AssaultTerminator &	operator=(AssaultTerminator const & rhs);
};

#endif
