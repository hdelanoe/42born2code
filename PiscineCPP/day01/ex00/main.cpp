/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:28:38 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 14:28:39 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.class.hpp"

void ponyOnTheHeap(void)
{
	Pony	*pony = new Pony("Twilight", "Pink", "Purple", 1);
	std::cout << pony->getName() << " is a beautiful pony !" << std::endl;
	delete pony;
	return ;
}

void ponyOnTheStack(void)
{
	Pony	pony = Pony("Dash", "Rainbow", "Azur", 0);
	std::cout << pony.getName() << " is a beautiful pony !" << std::endl;
	return ;
}

int main(void)
{

	ponyOnTheHeap();
	ponyOnTheStack();

	std::cout << "Does ponys explode ?" << std::endl;
	return (0); 
}
