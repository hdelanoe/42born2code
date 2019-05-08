/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:33:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:33:08 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <netinet/ip.h>
# include <netinet/ip_var.h>
# include <deque>
# include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(void);
		NetworkModule(unsigned int i);
		NetworkModule(NetworkModule const & src);
		~NetworkModule(void);

		NetworkModule & operator=(NetworkModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		void			displayPacketsSec();
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

	private :

		struct ipstat*	m_ips;
		std::deque<long>		m_up;
		std::deque<long>		m_down;

		long			m_startUp;
		long			m_endUp;
		long			m_startDown;
		long			m_endDown;

};
#endif
