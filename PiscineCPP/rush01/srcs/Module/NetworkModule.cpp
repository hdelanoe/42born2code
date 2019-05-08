/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:33:10 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:33:11 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string>

#include "NetworkModule.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

NetworkModule::NetworkModule(void) {}
NetworkModule::NetworkModule(unsigned int i) { m_n = i; }
NetworkModule::NetworkModule(NetworkModule const & src) { *this = src; }
NetworkModule::~NetworkModule(void) {}
NetworkModule & NetworkModule::operator=(NetworkModule const & rhs) { (void)rhs; return *this; }

void	NetworkModule::update(void)
{
	void *oldp[1024];
  	size_t oldlen = sizeof(struct ipstat), newlen = 0;
  	void * newp = NULL;
 
  	sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);
  	m_ips = reinterpret_cast<struct ipstat*>(oldp);
  	m_startUp = m_ips->ips_total;
  	m_startDown = m_ips->ips_localout;
  	sleep(1);
  	sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);
  	m_ips = reinterpret_cast<struct ipstat*>(oldp);
  	m_endUp = m_ips->ips_total;
  	m_endDown = m_ips->ips_localout;
  	m_up.push_back(m_endUp - m_startUp);
  	m_down.push_back(m_endDown - m_startDown);
  	if (m_up.size() > 30 || m_down.size() > 30)
  	{
  		m_up.pop_front();
  		m_down.pop_front();
  	}


}

void	NetworkModule::shellDisplay(int const & nb)
{
		size_t len = strlen("IP packets received: %ld") + 10; 
	mvprintw(static_cast<int>(m_y)  + 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"IP packets received: %ld", m_ips->ips_total);
	len = strlen("IP packets sent: %ld") + 10; 
	mvprintw(static_cast<int>(m_y)  + 4, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"IP packets sent: %ld", m_ips->ips_localout);

	displayPacketsSec();

	displayShellWindow(nb);
}

void	NetworkModule::displayPacketsSec()
{
	int j = 0;
		std::deque<long>::iterator dit = m_down.begin(); 
	for (std::deque<long>::iterator it = m_up.begin() ; it != m_up.end() ; it++)
	{	
		long k = 10;
		for (int i = 0; i < 5 ; i++)
		{
			if (*it >= k)
			{
				attron(COLOR_PAIR(4));
				mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - i - 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 15 + j,
				"=");
				attroff(COLOR_PAIR(4));
			}
			mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 15 + j, "-");
			if (*dit >= k)
			{
				attron(COLOR_PAIR(1));
				mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + i + 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 15 + j,
				"=");
				attroff(COLOR_PAIR(1));
			}
			k += 10;
		}
		dit++;
		j++;
	}
	attron(COLOR_PAIR(4));
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 8, static_cast<int>(m_x) + 4,
	"Packets in/sec: %ld", m_up.back());
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(1));
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 8, static_cast<int>(m_x) + 4,
	"Packets out/sec: %ld", m_down.back());
	attroff(COLOR_PAIR(1));
}

void	NetworkModule::graphicalDisplay(sf::RenderWindow&, sf::Font&)
{
	return ;
}

void	NetworkModule::displayShellWindow(int const & nb)
{
	int offset_x = 0;
	int offset_y = 0;
	float sqr = sqrt(nb);
	if (sqr != truncf(sqr))
	{	if(round(sqr) == ceil(sqr))
			offset_y++;
		sqr = round(sqr);
		offset_x++;
	}
	m_x = COLS / (sqr + offset_x) *  (m_n % static_cast<int>(sqr + offset_x));
	m_y = LINES / (sqr - offset_y) * trunc(m_n / (sqr + offset_x));
	m_w = COLS / (sqr + offset_x);
	m_h = LINES / (sqr - offset_y);

	WINDOW *win = subwin(stdscr, LINES / (sqr - offset_y), COLS / (sqr + offset_x), static_cast<int>(m_y), static_cast<int>(m_x));
	box(win, ACS_VLINE, ACS_HLINE);
	attron(COLOR_PAIR(2));
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 3, "NETWORK");
	attroff(COLOR_PAIR(2));
	wrefresh(win);
}

