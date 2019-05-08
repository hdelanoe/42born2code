/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:11:25 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:11:26 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMININGLASER_HPP
# define IMININGLASER_HPP

class IAsteroid;


class IMiningLaser {

	public:
			virtual ~IMiningLaser(void) {}
			virtual void mine(IAsteroid*) = 0;
};

#endif
