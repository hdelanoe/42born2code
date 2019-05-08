/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:55:39 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 17:02:05 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorManager.hpp"
#include "Display/ShellDisplay.hpp"
#include "Display/GraphicalDisplay.hpp"
#include "Module/HostnameModule.hpp"
#include "Module/OSinfosModule.hpp"
#include "Module/TimeModule.hpp"
#include "Module/RAMModule.hpp"
#include "Module/CPUModule.hpp"
#include "Module/NetworkModule.hpp"
#include "Module/CatModule.hpp"
#include "Module/AuteurModule.hpp"




MonitorManager::MonitorManager(void)
{
	int nb = -1;
	m_display.push_back(new ShellDisplay);
	//m_display.push_back(new GraphicalDisplay);
	m_modules.push_back(new HostnameModule(++nb));
	m_modules.push_back(new TimeModule(++nb));
	m_modules.push_back(new OSinfosModule(++nb));
	m_modules.push_back(new CPUModule(++nb));
	m_modules.push_back(new RAMModule(++nb));
	m_modules.push_back(new NetworkModule(++nb));
	m_modules.push_back(new CatModule(++nb));
	m_modules.push_back(new AuteurModule(++nb));
}

MonitorManager::MonitorManager(std::string s)
{
	int nb = -1;

	m_display.push_back(new ShellDisplay);
	//m_display.push_back(new GraphicalDisplay);
	if (s == "-s1")
	{
		m_modules.push_back(new HostnameModule(++nb));
		m_modules.push_back(new TimeModule(++nb));
		m_modules.push_back(new OSinfosModule(++nb));

	}
	else if (s == "-s2")
	{
		m_modules.push_back(new CPUModule(++nb));
		m_modules.push_back(new RAMModule(++nb));
	}
	else if (s == "-s3")
		m_modules.push_back(new NetworkModule(++nb));
	else
	{
		m_modules.push_back(new CatModule(++nb));
		m_modules.push_back(new OSinfosModule(++nb));
		m_modules.push_back(new CPUModule(++nb));
		m_modules.push_back(new TimeModule(++nb));
		m_modules.push_back(new HostnameModule(++nb));
		m_modules.push_back(new NetworkModule(++nb));
		m_modules.push_back(new RAMModule(++nb));
		m_modules.push_back(new AuteurModule(++nb));
	}

}

MonitorManager::~MonitorManager(void)
{
	for (std::size_t i = m_display.size(); i--;)
		delete m_display[i];

	for (std::size_t i = m_modules.size(); i--;)
		delete m_modules[i];
}

bool	MonitorManager::update(void)
{

	for (std::vector<IMonitorModule*>:: iterator it = m_modules.begin(); it != m_modules.end(); it++)
		(*it)->update();
	
	for(std::vector<IMonitorDisplay*>:: iterator it = m_display.begin(); it != m_display.end(); it++)
		if ((*it)->update(m_modules) == false)
		{
			delete *it;
			m_display.erase(it);
			if (m_display.size() == 0)
				return false;
			--it;
		}


	return true;
}
