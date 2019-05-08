/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:47:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 10:47:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "CentralBureaucracy.hpp"
#include "Bureaucrat.hpp"


int main()
{
	std::string bureaucrats[9] = {"Will", "Jack", "Winston", "John", "Antonio", "Raoul", "Bill", "Bob", "Jimmy"};
	std::string targets[9] = {"Will", "Jack", "Winston", "John", "Antonio", "Raoul", "Bill", "Bob", "Jimmy"};

	srand(time(NULL));
	CentralBureaucracy* cb = new CentralBureaucracy();
	while (42) {
		try {
			cb->feedBureaucrat(new Bureaucrat(bureaucrats[rand() % 9], 1 + rand() % 150));

		} catch (std::exception & e) { std::cout << e.what() << std::endl; break ; }

	}
	for (int i = 0 ; i < 9 ; i++)
		cb->queueUp(targets[i]);
	cb->doBureaucracy();

	return 0;
}