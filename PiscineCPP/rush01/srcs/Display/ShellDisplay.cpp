/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellDisplay.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:30:08 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 15:56:43 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShellDisplay.hpp"
#include "../Module/HostnameModule.hpp"
#include <string>
#include <ncurses.h>

ShellDisplay::ShellDisplay()
{
	initscr();
	raw();
	curs_set(0);
	noecho();
	start_color();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_GREEN, COLOR_BLUE);
}

ShellDisplay::~ShellDisplay()
{
	endwin();
}

bool	ShellDisplay::update(std::vector<IMonitorModule*> const & modules)
{
	if (getch() == 'q')
		return false;

	erase();

	for(std::vector<IMonitorModule*>:: const_iterator it = modules.begin(); it != modules.end(); it++)
		(*it)->shellDisplay(modules.size());

	refresh();

	return true;
}

