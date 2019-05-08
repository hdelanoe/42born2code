/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:33:40 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:33:41 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <string.h>

#include "CatModule.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

CatModule::CatModule(void) {}
CatModule::CatModule(unsigned int i) { m_n = i; }
CatModule::CatModule(CatModule const & src) { *this = src; }
CatModule::~CatModule(void) {}
CatModule & CatModule::operator=(CatModule const & rhs) { (void)rhs; return *this; }

void	CatModule::update(void) {}

void	CatModule::shellDisplay(int const & nb)
{

	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 7, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       _                        ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 6, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       \\`*-.                    ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 5, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"        )  _`-.                 ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 4, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       .  : `. .                ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       : _   '  \\               ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       ; *` _.   `*-._          ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"       `-.-'          `-.       ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 0, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         ;       `       `.     ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         :.       .        \\    ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         . \\  .   :   .-'   .   ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         \'  `+.;  ;  \'      :   ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 4, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         :  \'  |    ;       ;-. ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 5, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"         ; \'   : :`-:     _.`* ;");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 6, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		"      .*\' /  .*' ; .*`- +\'  `*\' ");
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 7, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 16,
		 "      `*-*   `*-*  `*-*\'");
	
	displayShellWindow(nb);
}

void	CatModule::graphicalDisplay(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text	text(std::string("Cat"), font);
	sf::Vector2f	ws(window.getSize());
	text.setPosition(m_x * ws.x / 100.f, m_y * ws.y / 100.f);
	window.draw(text);
}

void	CatModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 1, "CAT");
	attroff(COLOR_PAIR(2));
	wrefresh(win);

}