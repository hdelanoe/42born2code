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

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:

		int	_value;
		static const int bits = 8;
};

#endif
