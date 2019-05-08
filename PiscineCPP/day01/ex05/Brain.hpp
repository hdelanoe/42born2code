/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:00:44 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 20:00:45 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
#include <sstream>
#include <ios>

class Brain
{
public:

	Brain(void);
	~Brain(void);
	std::string identify(void) const;

private:

	int	neurons;
	int	synaps;
};

#endif
