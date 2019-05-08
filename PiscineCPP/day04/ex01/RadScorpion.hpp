/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:19 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy {

	public:

		RadScorpion(int hp = 80, std::string const & type = "RadScorpion");
		RadScorpion(RadScorpion const & src);
		~RadScorpion(void);

		RadScorpion & operator=(RadScorpion const & rhs);

		virtual void takeDamage(int);


};

#endif
