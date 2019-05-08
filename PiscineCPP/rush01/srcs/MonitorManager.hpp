/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorManager.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:55:28 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 15:02:53 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORMANAGER_HPP
# define MONITORMANAGER_HPP

# include <string>
# include <vector>

class IMonitorDisplay;
class IMonitorModule;

class MonitorManager
{
public:

	MonitorManager(void);
	MonitorManager(std::string s);
	~MonitorManager(void);

	bool	update(void);
	void	display(void);

private:
	MonitorManager(MonitorManager const & src);
	MonitorManager & operator=(MonitorManager const & rhs);

	std::vector<IMonitorDisplay*>		m_display;
	std::vector<IMonitorModule*>		m_modules;
};

#endif
