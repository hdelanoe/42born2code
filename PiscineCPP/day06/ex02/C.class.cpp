/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:20 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:21 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.class.hpp"

C::C(void) {}
C::C(const C & src) { *this = src; }
C::~C(void) {} 
C & C::operator= (const C & rhs) {static_cast<void>(rhs); return (*this); }

