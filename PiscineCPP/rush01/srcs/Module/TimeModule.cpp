/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:31:57 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 17:11:49 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

TimeModule::TimeModule(void) {}
TimeModule::TimeModule(unsigned int i) { m_n = i; }
TimeModule::TimeModule(TimeModule const & src) { *this = src; }
TimeModule::~TimeModule(void) {}
TimeModule & TimeModule::operator=(TimeModule const & rhs) { (void)rhs; return *this; }

void	TimeModule::update(void)
{
	time(&m_time);
}

void	TimeModule::shellDisplay(int const & nb)
{
	size_t len = strlen("Date : ") + strlen(ctime(&m_time)); 
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Date : %s", ctime(&m_time));
	
	displayShellWindow(nb);
	
}

void	TimeModule::graphicalDisplay(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text		text(std::string("Date: ") + ctime(&m_time), font);
	sf::Vector2f	ws(window.getSize());
	m_x = (ws.x / 3) * (m_n % 3);
	m_y = (ws.y / 3) * (m_n / 3);
	text.setPosition(m_x, m_y);
	window.draw(text);
}

void	TimeModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 2, "TIME");
	attroff(COLOR_PAIR(2));
	wrefresh(win);
}
