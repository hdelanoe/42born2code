/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:10:27 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:10:28 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"

class StripMiner;
class DeepCoreMiner;


class BocalSteroid : public IAsteroid {

	public:

		BocalSteroid(void);
		BocalSteroid(BocalSteroid const & src);
		~BocalSteroid(void);

		BocalSteroid &	operator=(BocalSteroid const & rhs);

		virtual std::string beMined(StripMiner*) const;
		virtual std::string beMined(DeepCoreMiner*) const;
		virtual std::string getName() const;
};

#endif
