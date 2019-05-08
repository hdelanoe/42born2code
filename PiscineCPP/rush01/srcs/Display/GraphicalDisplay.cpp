/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalDisplay.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:30:22 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 16:59:19 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicalDisplay.hpp"

#include <SFML/Window/Event.hpp>

#include <iostream>

GraphicalDisplay::GraphicalDisplay() : m_window(sf::VideoMode(1280, 720), "ft_gkrellm")
{
	m_window.setVerticalSyncEnabled(true);
	m_font.loadFromFile("/System/Library/Fonts/Avenir.ttc");
}

GraphicalDisplay::~GraphicalDisplay()
{

}

bool	GraphicalDisplay::update(const std::vector<IMonitorModule*>& modules)
{
	/*sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
					case sf::Keyboard::Q:
						m_window.close();
						return false;
				}
				break;

			case sf::Event::Closed:
				m_window.close();
				return false;
		}
	}*/

	m_window.clear(sf::Color(128, 128, 128));

	std::vector<IMonitorModule*>::const_iterator	mod, end = modules.end();
	for (mod = modules.begin(); mod != end; ++mod)
	{
		(*mod)->graphicalDisplay(m_window, m_font);
	}

	m_window.display();

	return true;
}
