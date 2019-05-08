/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:00:21 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/04/13 18:02:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <iostream>

class Human
{
	private:
	void		meleeAttack(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		intimidatingShout(std::string const & target);

	public:
	void		action(std::string const & action_name, std::string const & target);
};

#endif