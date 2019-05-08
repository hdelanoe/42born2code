/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfosModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:31:33 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 16:57:00 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOSMODULE_HPP
# define OSINFOSMODULE_HPP

# include <sys/utsname.h>
# include "IMonitorModule.hpp"

class OSinfosModule : public IMonitorModule
{
	public:

		OSinfosModule(void);
		OSinfosModule(unsigned int);
		OSinfosModule(OSinfosModule const & src);
		~OSinfosModule(void);

		OSinfosModule & operator=(OSinfosModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

	private:

		struct utsname 	m_OS;
		char			m_model[256];
};
#endif
