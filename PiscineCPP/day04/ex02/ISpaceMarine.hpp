/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:51 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

# include <string>
# include <iostream>

class ISpaceMarine {

	public:
			virtual ~ISpaceMarine(void) {}
			virtual	ISpaceMarine* clone() const = 0;
			virtual void battleCry() const = 0;
			virtual void rangedAttack() const = 0;
			virtual void meleeAttack() const = 0;
};

#endif
