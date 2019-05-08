/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:44 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:45 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"

class StripMiner;
class DeepCoreMiner;


class MiningBarge{

	public:

		MiningBarge(void);
		MiningBarge(MiningBarge const & src);
		~MiningBarge(void);

		MiningBarge &	operator=(MiningBarge const & rhs);

		void equip(IMiningLaser*);
		void mine(IAsteroid*) const;

		int			getCount() const;

	private:

		IMiningLaser* 	_laser[4];
		int				_count;
};

#endif
