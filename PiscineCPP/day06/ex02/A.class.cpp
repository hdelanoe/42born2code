/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:09:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:09:56 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.class.hpp"

A::A(void) {}
A::A(const A & src) { *this = src; }
A::~A(void) {} 
A & A::operator= (A const & rhs) {static_cast<void>(rhs); return (*this); }

