/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:31:53 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 16:56:56 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <time.h>
# include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule
{
	public:
		
		TimeModule(void);
		TimeModule(unsigned int i);
		TimeModule(TimeModule const & src);
		~TimeModule(void);

		TimeModule & operator=(TimeModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

	private:

		time_t	m_time;

};
#endif
