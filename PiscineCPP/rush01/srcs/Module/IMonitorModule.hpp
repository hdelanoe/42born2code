/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:29:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 17:06:29 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <math.h>
# include <ncurses.h>

namespace sf
{
	class RenderWindow;
	class Font;
}

class IMonitorModule {

	public:

		virtual ~IMonitorModule(void);

		virtual void	update(void) = 0;
		virtual void	shellDisplay(int const & nb) = 0;
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&) = 0;

		virtual void	displayShellWindow(int const & nb) = 0;

	protected:

		unsigned int m_n;
		float	m_x;
		float	m_y;
		float	m_w;
		float	m_h;

};
#endif
