/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:57:11 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/12 19:57:12 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string Brain = "HI THIS IS BRAIN";
	std::string	*BrainPtr = &Brain;
	std::string	&BrainRef = Brain;

	std::cout << *BrainPtr << std::endl << BrainRef << std::endl;
	return (0);
}
