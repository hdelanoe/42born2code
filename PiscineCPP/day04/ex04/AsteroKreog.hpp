/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:12 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include "IAsteroid.hpp"
# include <string>

class StripMiner;
class DeepCoreMiner;

class AsteroBocal : public IAsteroid {

	public:

		AsteroBocal(void);
		AsteroBocal(AsteroBocal const & src);
		~AsteroBocal(void);

		AsteroBocal &	operator=(AsteroBocal const & rhs);

		virtual std::string beMined(StripMiner*) const;
		virtual std::string beMined(DeepCoreMiner*) const;
		virtual std::string getName() const;
};

#endif
