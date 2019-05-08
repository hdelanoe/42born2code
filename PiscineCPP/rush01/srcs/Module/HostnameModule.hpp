/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:31:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 16:56:59 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule
{
	public:
		HostnameModule(void);
		HostnameModule(unsigned int i);
		HostnameModule(HostnameModule const & src);
		virtual ~HostnameModule(void);

		HostnameModule & operator=(HostnameModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);	

		virtual void	displayShellWindow(int const & nb);


	private:

		char		_hostname[256];
		char		_username[256];
};
#endif
