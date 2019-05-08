/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:06:43 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/13 18:06:44 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int	main()
{
	Human Hunter;
	Hunter.action("melee", "target");
	Hunter.action("ranged", "target");
	Hunter.action("shout", "target");
	Hunter.action("die", "target");
}
