/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:19 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sysctl.h>
#include <sys/types.h>
#include <string>
#include <math.h>
#include <unistd.h>
#include "CPUModule.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

CPUModule::CPUModule(void) {}
CPUModule::CPUModule(unsigned int i)
{
	size_t buff = 256;
	m_n = i;
	sysctlbyname("machdep.cpu.brand_string", &m_CPUBrand, &buff, NULL, 0);
	buff = sizeof(m_CPUCores);
	sysctlbyname("hw.ncpu", &m_CPUCores, &buff, NULL,0);

}
CPUModule::CPUModule(CPUModule const & src) { *this = src; }
CPUModule::~CPUModule(void) {}
CPUModule & CPUModule::operator=(CPUModule const & rhs) { (void)rhs; return *this; }

void	CPUModule::update(void)
{
	m_start = rdtsc();
	sleep(1);
	m_end = rdtsc();
	m_frequency = m_end - m_start;

	m_CPULoad = getCPULoad() * 100.f;
}

void	CPUModule::shellDisplay(int const & nb)
{
	size_t len = strlen(m_CPUBrand);
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 4, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"%s", m_CPUBrand);
	len = strlen("Cores : ") + 1;
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 - 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		"Core(s) : %ld", m_CPUCores);
	len = strlen("CPU Clock :  Hz") + 10;
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 0, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		" CPU Clock : %llu Hz", m_frequency);
	len = strlen("CPU Load :  %") + 8;
	mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 2, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - static_cast<int>(len) / 2,
		" CPU Load : %f %%", m_CPULoad);

	float j = 0.f;
	for (int i = 0; i < 10 ; i++)
	{
		if (m_CPULoad >= j)
			attron(COLOR_PAIR(2));
		mvprintw(static_cast<int>(m_y) + static_cast<int>(m_h) / 2 + 4, static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 5 + i,
		"|");
		attroff(COLOR_PAIR(2));
		j += 10.f;
	}

	displayShellWindow(nb);

}

void	CPUModule::graphicalDisplay(sf::RenderWindow&, sf::Font&)
{
	return ;
}

float CPUModule::getCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&cpuinfo), &count) == KERN_SUCCESS)
   {
      unsigned long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return calculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}

float CPUModule::calculateCPULoad(unsigned long idleTicks, unsigned long totalTicks)
{
  unsigned long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
  unsigned long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? (static_cast<float>(idleTicksSinceLastTime))/totalTicksSinceLastTime : 0);
  m_previousTotalTicks = totalTicks;
  m_previousIdleTicks  = idleTicks;
  return ret;
}

void	CPUModule::displayShellWindow(int const & nb)
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
	mvprintw(static_cast<int>(m_y), static_cast<int>(m_x) + static_cast<int>(m_w) / 2 - 1, "CPU");
	attroff(COLOR_PAIR(2));
	wrefresh(win);
}

uint64_t CPUModule::rdtsc(void)
{
    uint32_t ret0[2];
    __asm__ __volatile__("rdtsc" : "=a"(ret0[0]), "=d"(ret0[1]));
    return ((uint64_t)ret0[1] << 32) | ret0[0];
}
