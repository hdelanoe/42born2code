/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:13 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:14 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base
{
	public:
		B(void);
		B(B const & src);

		~B(void);

		B & operator= (B const & rhs);
};

#endif

