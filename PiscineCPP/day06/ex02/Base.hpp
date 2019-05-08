/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:09:42 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:09:43 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class A;
class B;
class C;

class Base
{
	public:
    	Base(void);
    	Base(Base const & src);

    	virtual ~Base(void);

    	Base &	operator= (Base const & rhs);
};

#endif
