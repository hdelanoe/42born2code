/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:01 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class A : public Base
{
	public:
		A(void);
		A(A const &src);

		~A(void);

		A & operator= (A const &rhs);
};

#endif
