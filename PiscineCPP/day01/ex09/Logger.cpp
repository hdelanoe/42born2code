/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:10:14 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/07 12:10:39 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

void	Logger::logToConsole(std::string const & output)
{
	std::cout << output << std::endl;

}

void	Logger::logToFile(std::string const & output)
{
	std::ofstream logger;
	logger.open("logger.log", std::ios_base::app);
	logger << output << "\n";
	logger.close();
		
}

std::string Logger::makeLogEntry(std::string const & message)
{
	time_t now = time(0);
	std::string logTime = ctime(&now);
	logTime = logTime.substr(0, logTime.length() -1);
	std::stringstream ss;
	ss << "[" << logTime << "]: " << message;
	return ss.str();
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	void (Logger::*arr[2])(std::string const &) = {&Logger::logToConsole, &Logger::logToFile};
	std::string action[2] = {"console", "file"};
	int i = 0;
	while(dest != action[i] && i < 2) {
		i++;
	}
	std::string output = makeLogEntry(message);
	(this->*arr[i])(output);
}
