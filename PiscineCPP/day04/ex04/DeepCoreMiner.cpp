/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:09:21 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:09:23 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include <iostream>


DeepCoreMiner::DeepCoreMiner(void)
{
	return ;
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const & src)
{
	*this = src;
}

DeepCoreMiner::~DeepCoreMiner(void)
{
	return ;
}

DeepCoreMiner & DeepCoreMiner::operator=(DeepCoreMiner const & rhs)
{
	(void)rhs;	
	return *this;
}

void DeepCoreMiner::mine(IAsteroid* a)
{
	std::cout << "* mining deep ... got " << a->beMined(this) <<" *" << std::endl;
}
