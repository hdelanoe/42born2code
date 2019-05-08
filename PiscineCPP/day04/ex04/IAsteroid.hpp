/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:11:01 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:11:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IASTEROID_HPP
# define IASTEROID_HPP

# include <string>
# include "StripMiner.hpp"
# include "DeepCoreMiner.hpp"

class IAsteroid {

	public:
			virtual ~IAsteroid(void) {}
			virtual std::string beMined(DeepCoreMiner*) const = 0;
			virtual std::string beMined(StripMiner*) const = 0;
			virtual std::string getName() const = 0;

	protected:

			std::string	_name;
};

#endif
