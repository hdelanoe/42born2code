/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:07 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:08 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.class.hpp"

B::B(void) {}
B::B(const B & src) { *this = src; }
B::~B(void) {} 
B & B::operator= (const B & rhs) {static_cast<void>(rhs); return (*this); }

