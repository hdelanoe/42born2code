/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:09:29 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:09:30 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"

class IAsteroid;

class DeepCoreMiner : public IMiningLaser {

	public:

		DeepCoreMiner(void);
		DeepCoreMiner(DeepCoreMiner const & src);
		~DeepCoreMiner(void);

		DeepCoreMiner &	operator=(DeepCoreMiner const & rhs);

		virtual void mine(IAsteroid*);

};

#endif
