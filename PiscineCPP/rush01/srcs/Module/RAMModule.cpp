/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:33 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:34 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RAMModule.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

RAMModule::RAMModule(void) { init(); }
RAMModule::RAMModule(unsigned int i) { m_n = i; init(); }
RAMModule::RAMModule(RAMModule const & src) { *this = src; }
RAMModule::~RAMModule(void) {}
RAMModule & RAMModule::operator=(RAMModule const & rhs) { (void)rhs; return *this; }

void	RAMModule::update(void)
{
	size_t buff = sizeof(uint64_t);
	sysctlbyname("hw.memsize", &m_memSize, &buff, NULL, 0);
	sysctlbyname("hw.usermem", &m_userMem, &buff, NULL, 0);
	sysctlbyname("dev.cpu.0.temperature", &m_physMem, &buff, NULL, 0);


	m_mach_port = mach_host_self();
	m_count = sizeof(m_vm_stats) / sizeof(natural_t);
	host_page_size(m_mach_port, &m_page_size);
	host_statistics64(m_mach_port, HOST_VM_INFO, reinterpret_cast<host_info64_t>(&m_vm_stats), &m_count);

	m_free_memory = static_cast<uint64_t>(m_vm_stats.free_count) * static_cast<uint64_t>(m_page_size);

	m_used_memory = (static_cast<uint64_t>(m_vm_stats.active_count) +
    				static_cast<uint64_t>(m_vm_stats.inactive_count) +
    				static_cast<uint64_t>(m_vm_stats.wire_count)) *  static_cast<uint64_t>(m_page_size);
}

void	RAMModule::shellDisplay(int const & nb)
{
	uint64_t used = 100 * m_used_memory / m_physical_memory;
	uint64_t user = 100 * m_userMem / m_physical_memory;

	size_t len = strlen("Total RAM available :  Gb") + 8;
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Total RAM available : %llf Gb", m_physical_memory * 9.31 * pow(10, -10));
	len = strlen("Total RAM free :  Gb") + 8;
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Total RAM free : %llf Gb", m_free_memory * 9.31 * pow(10, -10));
	len = strlen("Total RAM used :  Gb (%) witch % by user") + 11; 
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 1, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Total RAM used : %llf Gb (%llu%%) witch %llu%% by user",
		m_used_memory * 9.31 * pow(10, -10), 100 * m_used_memory / m_physical_memory, 100 * m_userMem / m_physical_memory);

	float j = 10.f;
	for (int i = 0; i < 10 ; i++)
	{
		if (user >= j)
			attron(COLOR_PAIR(1));
		else if (used >= j)
			attron(COLOR_PAIR(2));
		mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 3, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 5 + i,
		"|");
		attroff(COLOR_PAIR(2));
		attroff(COLOR_PAIR(1));
		j += 10.f;
	}

	displayShellWindow(nb);


}

void	RAMModule::graphicalDisplay(sf::RenderWindow&, sf::Font&)
{
	return ;
}

void RAMModule::init(void)
{
	

	m_mib = new int(2);
	m_mib[0] = CTL_HW;
	m_mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(m_mib, 2, &m_physical_memory, &length, NULL, 0);
}

void	RAMModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 1, "RAM");
	attroff(COLOR_PAIR(2));
	wrefresh(win);
}
