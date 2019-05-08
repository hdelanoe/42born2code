/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:45:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(void) {}
Base::Base(const Base & src) { *this = src; }
Base::~Base(void) {} 
Base & Base::operator= (const Base & rhs) {static_cast<void>(rhs); return (*this); }

