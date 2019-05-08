/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AuteurModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:35:31 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/07 14:35:32 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTEURMODULE_HPP
# define AUTEURMODULE_HPP

# include "IMonitorModule.hpp"

class AuteurModule : public IMonitorModule
{
	public:
		AuteurModule(void);
		AuteurModule(unsigned int i);
		AuteurModule(AuteurModule const & src);
		virtual ~AuteurModule(void);

		AuteurModule & operator=(AuteurModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

};
#endif
