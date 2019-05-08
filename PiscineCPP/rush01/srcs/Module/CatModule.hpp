/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:33:47 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:33:48 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATMODULE_HPP
# define CATMODULE_HPP

# include "IMonitorModule.hpp"

class CatModule : public IMonitorModule
{
	public:
		CatModule(void);
		CatModule(unsigned int i);
		CatModule(CatModule const & src);
		virtual ~CatModule(void);

		CatModule & operator=(CatModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

};
#endif
