/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:57:51 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 10:57:53 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy {

	public:

		Enemy(void);
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual	~Enemy(void);

		Enemy & operator=(Enemy const & rhs);
		
		int 			getHP() const;
		std::string 	getType() const;


		virtual void takeDamage(int) = 0;

	protected:

		int				_HP;
		std::string		_type;

};

#endif