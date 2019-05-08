/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AuteurModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:35:12 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/07 14:35:36 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <string.h>

#include "AuteurModule.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

AuteurModule::AuteurModule(void) {}
AuteurModule::AuteurModule(unsigned int i) { m_n = i; }
AuteurModule::AuteurModule(AuteurModule const & src) { *this = src; }
AuteurModule::~AuteurModule(void) {}
AuteurModule & AuteurModule::operator=(AuteurModule const & rhs) { (void)rhs; return *this; }

void	AuteurModule::update(void) {}

void	AuteurModule::shellDisplay(int const & nb)
{
			attron(COLOR_PAIR(2));

	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		"   .        .           .  .        ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		",\" |-   ,-. | , ,-. ,-. |  |  ,-,-. ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		"|- |    | | |<  |   |-' |  |  | | | ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 0, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		"|  `'   `-| ' ` '   `-' `' `' ' ' ' ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		"\'     ~~ ,|           hdelanoe     ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 18,
		"         `\'                         ");
	
	displayShellWindow(nb);
	attroff(COLOR_PAIR(2));
}

void	AuteurModule::graphicalDisplay(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text 		text(std::string("FT_GKRELLM"), font);
	sf::Vector2f	ws(window.getSize());
	text.setPosition(m_x * ws.x / 100.f, m_y * ws.y / 100.f);
	window.draw(text);
}

void	AuteurModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 5, "FT_GKRELLM");
	wrefresh(win);

}
