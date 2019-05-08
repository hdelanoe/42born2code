/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:02:56 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 17:02:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad {

	public:

		Squad(void);
		Squad(std::string const & name);
		Squad(Squad const & src);
		~Squad(void);

		Squad &	operator=(Squad const & rhs);

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int u) const;
		virtual int push(ISpaceMarine* marine);

		ISpaceMarine** getSquad() const;

	private:

		ISpaceMarine	**_squad;
		int				_count;
};

#endif
