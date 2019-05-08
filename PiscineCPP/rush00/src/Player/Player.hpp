/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:08:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 16:54:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../AGameEntity.hpp"

class Player : public AGameEntity
{
  public:

		Player(void);
		Player(Player const &iRef);
		~Player(void);

		Player & operator=(Player const &iRef);

		AProjectile*	shoot(void) const;
		void			setShield(bool);	
		bool			getShield(void);
		void			checkShield(void);

		void			setTimer(int clock);	
		void			Input(int const &i);

		bool			getUp(void);
		bool			getDown(void);
		bool			getLeft(void);
		bool			getRight(void);



		virtual bool	isHit(void);

	private:

		bool	_shield;
		int		_timer;
		bool	_cs;

		bool 	_up;
		bool	_down;
		bool	_right;
		bool	_left;
};

#endif
