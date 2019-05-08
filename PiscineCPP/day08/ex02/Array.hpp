/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:27:56 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/03 18:27:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <typeinfo>
# include <stdexcept>

template<typename T>
class Array
{
	public:

		Array<T>(void) : _array(NULL), _size(0) {}
		Array<T>(unsigned int n) : _array(new T[n]), _size(n) {
			for (unsigned int i = 0 ; i < _size ; i++)
				_array[i] = * new T;
		}
		Array<T>(Array<T> const & src) : _array(new T[src.size()]), _size(src.size()) {
			for (unsigned int i = 0 ; i < _size ; i++)
				_array[i] = src._array[i];	
		}
		~Array<T>() {}

		Array<T> & operator=(Array<T> & rhs)
		{
			if (_array != NULL) delete[] _array;
			_array = new T[rhs.size()];
			_size = rhs.size();
			for (size_t i = 0; i < _size; i++) _array[i] = rhs[i];
			return *this;
		}


		T& operator[](unsigned int index) throw (std::out_of_range)
		{
			if (_size <= index) throw std::out_of_range("array index out of range");
			else return _array[index];
		}

		const T& operator[](unsigned int index) const throw (std::out_of_range)
		{
			if (_size <= index) throw std::out_of_range("array index out of range");
			else return _array[index];
		}

		T* 				array(void) const { return _array; }
		unsigned int 	size(void) const { return _size; }




	private:

		T* 				_array;
		unsigned int 	_size;
};

#endif
