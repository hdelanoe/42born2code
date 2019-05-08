/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:43:38 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/31 17:24:21 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
#define FT_RETRO_HPP

// Player data
#define PLAYER_W 3
#define PLAYER_H 3
#define PLAYER_S "/  " \
				 "-->" \
				 "\\  "
#define PLAYER_SPD 1
#define PLAYER_HP 3
#define PLAYER_START_X 8
#define PLAYER_START_Y LINES / 2

// Enemy data
#define SENTINEL_W 5
#define SENTINEL_H 3
#define SENTINEL_S " /~  " \
				   "(~~~~" \
				   " \\~  "
#define SENTINEL_T "sentinel"
#define SENTINEL_HP 4
#define SENTINEL_SV 40
#define SENTINEL_SPD 1

#define DRONE_W 4
#define DRONE_H 1
#define DRONE_S "(~~<"
#define DRONE_T "drone"
#define DRONE_HP 1
#define DRONE_SV 10
#define DRONE_SPD 2

#define MISSILE_W 4
#define MISSILE_H 1
#define MISSILE_S "+=-~"
#define MISSILE_T "missile"
#define MISSILE_HP 1
#define MISSILE_SV 5
#define MISSILE_SPD 8

#define SATELITE_W 5
#define SATELITE_H 3
#define SATELITE_S "    /" \
				   "`(o) " \
				   "/   `"
#define SATELITE_T "satelite"
#define SATELITE_HP 1
#define SATELITE_SV 50
#define SATELITE_SPD 1

#endif
