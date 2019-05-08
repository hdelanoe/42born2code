/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:01:00 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 20:01:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <iostream>
#include <sstream>
#include <ios>
#include "Brain.hpp"

class Human
{
public:

	Human(void);
	~Human(void);
	std::string identify(void) const;
	const Brain &getBrain(void);

private:

	const Brain	_brain;
};

#endif
