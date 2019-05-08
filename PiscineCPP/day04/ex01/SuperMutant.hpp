/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:58:03 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:58:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {

	public:

		SuperMutant(int hp = 170, std::string const & type = "Super Mutant");
		SuperMutant(SuperMutant const & src);
		~SuperMutant(void);

		SuperMutant & operator=(SuperMutant const & rhs);

		virtual void takeDamage(int);


};

#endif
