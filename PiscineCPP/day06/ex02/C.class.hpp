/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:25 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:26 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base
{
	public:
		C(void);
		C(C const & src);

		~C(void);

		C & operator= (C const & rhs);
};

#endif
