/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfosModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:31:37 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 17:13:29 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSinfosModule.hpp"

#include <sys/sysctl.h>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

OSinfosModule::OSinfosModule(void) {}
OSinfosModule::OSinfosModule(unsigned int i) { m_n = i; }
OSinfosModule::OSinfosModule(OSinfosModule const & src) { *this = src; }
OSinfosModule::~OSinfosModule(void) {}
OSinfosModule & OSinfosModule::operator=(OSinfosModule const & rhs) { (void)rhs; return *this; }


void	OSinfosModule::update(void)
{
	size_t buff = 256;
	sysctlbyname("hw.model", &m_model, &buff, NULL, 0);
	uname(&m_OS);
}

void	OSinfosModule::shellDisplay(int const & nb)
{
	size_t len = strlen(m_model);
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"%s", m_model);
	len = strlen("Name : ") + strlen(m_OS.sysname); 
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Name : %s", m_OS.sysname);
	len = strlen("Release : ") + strlen(m_OS.release); 
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Release : %s", m_OS.release);
	len = strlen("Architecture : ") + strlen(m_OS.machine); 
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Architecture : %s", m_OS.machine);
	
	displayShellWindow(nb);

}

void	OSinfosModule::graphicalDisplay(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text	text(std::string("OS: ") + m_OS.sysname + '@' + m_OS.release + ' ' + m_OS.machine, font);
	sf::Vector2f	ws(window.getSize());
	text.setPosition(m_x * ws.x / 100.f, m_y * ws.y / 100.f);
	window.draw(text);
}

void	OSinfosModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 4, "OS INFOS");
	attroff(COLOR_PAIR(2));
	wrefresh(win);
}


