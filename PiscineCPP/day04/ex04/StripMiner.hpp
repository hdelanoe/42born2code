/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:09:52 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:09:54 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

	public:

		StripMiner(void);
		StripMiner(StripMiner const & src);
		~StripMiner(void);

		StripMiner &	operator=(StripMiner const & rhs);

		virtual void mine(IAsteroid*);

};

#endif
