/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:00:57 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/12 19:06:55 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const src);
		Fixed(float const src);

		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;

	private:

		int					_value;
		static const int 	_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);


#endif
