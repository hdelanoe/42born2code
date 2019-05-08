/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:25:53 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/26 20:25:54 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

# include "Victim.hpp"
# include <string>
# include <iostream>


class Peon : public Victim {

	public:

		Peon(std::string name = "Thrall");
		Peon(Peon const & src);
		~Peon(void);

		Peon &	operator=(Peon const & rhs);

		virtual void	getPolymorphed() const;

		
};

#endif
