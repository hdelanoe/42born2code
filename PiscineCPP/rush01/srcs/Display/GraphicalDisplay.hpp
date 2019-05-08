/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalDisplay.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:30:27 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 16:53:52 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALDISPLAY_HPP
#define GRAPHICALDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class GraphicalDisplay : public IMonitorDisplay
{
public:
	GraphicalDisplay();
	~GraphicalDisplay();

	virtual bool update(const std::vector<IMonitorModule*>& modules);

private:
	GraphicalDisplay(GraphicalDisplay const & src);
	GraphicalDisplay & operator=(GraphicalDisplay const & rhs);

	sf::RenderWindow	m_window;
	sf::Font			m_font;
};

#endif
