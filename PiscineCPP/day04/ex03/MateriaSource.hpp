/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:26:00 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 15:26:01 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & rhs);
		
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(std::string const & type);


		AMateria*	getMateria(void) const;
		int			getCount(void) const;

	private:

		AMateria*	_materia[4];
		int			_count;

};

#endif
