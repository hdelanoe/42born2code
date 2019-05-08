/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:03:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ISpaceMarine.hpp"

class ISquad {

	public:
			virtual ~ISquad() {}
			virtual	int getCount() const = 0;
			virtual ISpaceMarine* getUnit(int) const = 0;
			virtual int push(ISpaceMarine*) = 0;
};

#endif
